#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 40

void LRUcache(int input[], int output[], int listNum, int cacheSize) {
    int cache[MAXSIZE];
    int lastUsed[MAXSIZE];
    
    for (int i = 0; i < cacheSize; i++) {
        cache[i] = -1;
        lastUsed[i] = -1;
    }

    for (int i = 0; i < listNum; i++) {
        int page = input[i];
        int found = 0;

        for (int j = 0; j < cacheSize; j++) {
            // 查找是否存在缓存中
            if (cache[j] == page) {
                found = 1;
                lastUsed[j] = i;
                output[i] = -1;
                break;
            }
        }

        if (found == 0) {
            int oldest = MAXSIZE;
            int idx = -1;

            for (int j = 0; j < cacheSize; j++) {
                if (lastUsed[j] < oldest) {
                    oldest = lastUsed[j];
                    idx = j;
                }
            }
            output[i] = cache[idx];

            cache[idx] = page;
            lastUsed[idx] = i;
        }
    }
}