#include <iostream>

using namespace std;
 
//用循环链表实现
struct Node {
	int id;
	Node* next;
};
 
//实现int * solve(int N,int M,int K)函数。
int* solve(int N, int M, int K) {
	Node* head = new Node;
	head->id = 1;
	head->next = NULL;
	Node* cur = head;
	
	// 生成循环表
	for (int i = 2; i <= N; ++i) {
		cur->next = new Node;
		cur->next->id = i;
		cur->next->next = NULL;
		cur = cur->next;
	}
	cur->next = head;//头尾相接
	
	int count = N - K;
	int* result = new int[count];
	
	Node* prev = cur;
	cur = head;
	for (int i = 0; i < count; ++i) {
		for (int j = 1; j < M; ++j) {
			prev = cur;
			cur = cur->next;
		}
		result[i] = cur->id;
		prev->next = cur->next;
		delete cur;
		cur = prev->next;
	}
	
	return result;//函数返回值为按顺序被扔下大海乘客编号的数组。
}
 
int main() {
	//函数参数为乘客人数N、间隔人数M和剩余乘客人数K，1<=N<=1000，1<=M<=500000，0<=K<N。
	int N = 9, M = 3, K = 2;
	int* res = solve(N, M, K);
	for (int i = 0; i < N-K; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	
	delete[] res;
	
	return 0;
}