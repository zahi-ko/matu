#include <iostream>

using namespace std;
 
//��ѭ������ʵ��
struct Node {
	int id;
	Node* next;
};
 
//ʵ��int * solve(int N,int M,int K)������
int* solve(int N, int M, int K) {
	Node* head = new Node;
	head->id = 1;
	head->next = NULL;
	Node* cur = head;
	
	// ����ѭ����
	for (int i = 2; i <= N; ++i) {
		cur->next = new Node;
		cur->next->id = i;
		cur->next->next = NULL;
		cur = cur->next;
	}
	cur->next = head;//ͷβ���
	
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
	
	return result;//��������ֵΪ��˳�����´󺣳˿ͱ�ŵ����顣
}
 
int main() {
	//��������Ϊ�˿�����N���������M��ʣ��˿�����K��1<=N<=1000��1<=M<=500000��0<=K<N��
	int N = 9, M = 3, K = 2;
	int* res = solve(N, M, K);
	for (int i = 0; i < N-K; ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
	
	delete[] res;
	
	return 0;
}