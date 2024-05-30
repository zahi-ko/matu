#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 40

/**
 * 模拟LRU（最近最少使用）缓存算法。
 * 
 * @param input 一个整数数组，表示页面请求的序列。
 * @param output 一个整数数组，用于存储缓存命中或未命中。
 * @param listNum 输入数组的元素数量。
 * @param cacheSize 缓存的大小。
 */
void LRUcache(int input[], int output[], int listNum, int cacheSize) {
    int cache[MAXSIZE];
    int lastUsed[MAXSIZE];
    
    // 初始化缓存和最近使用数组
    for (int i = 0; i < cacheSize; i++) {
        cache[i] = -1;
        lastUsed[i] = -1;
    }

    // 处理每个页面请求
    for (int i = 0; i < listNum; i++) {
        int page = input[i];
        int found = 0;

        // 检查页面是否已经在缓存中
        for (int j = 0; j < cacheSize; j++) {
            if (cache[j] == page) {
                found = 1;
                lastUsed[j] = i;
                output[i] = -1; // 缓存命中
                break;
            }
        }

        // 如果页面不在缓存中，找到最近最少使用的页面
        if (found == 0) {
            int oldest = MAXSIZE;
            int idx = -1;

            // 在缓存中找到最近最少使用的页面
            for (int j = 0; j < cacheSize; j++) {
                if (lastUsed[j] < oldest) {
                    oldest = lastUsed[j];
                    idx = j;
                }
            }
            output[i] = cache[idx]; // 缓存未命中

            // 用新页面替换最近最少使用的页面
            cache[idx] = page;
            lastUsed[idx] = i;
        }
    }
}