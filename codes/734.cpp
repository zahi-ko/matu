#include<stdio.h>
 
int buyTickets(int* tickets, int n, int k)
{
	//������ֵ����
	if (tickets == NULL || n <= 0 || k < 0 || k>=n) return -1;
	//ɽ��ضϷ�
	int ticket = tickets[k];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (tickets[i] <= 0 ) return -1;
		else if (tickets[i] >= ticket)
		{
			count += ticket - 1;
			//����ʣ�µ�
			if (i <= k) count++;
		}
		else  count += tickets[i];
	}
	return count;
}