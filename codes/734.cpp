#include<stdio.h>
 
int buyTickets(int* tickets, int n, int k)
{
	//考虑奇怪的情况
	if (tickets == NULL || n <= 0 || k < 0 || k>=n) return -1;
	//山峰截断法
	int ticket = tickets[k];
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (tickets[i] <= 0 ) return -1;
		else if (tickets[i] >= ticket)
		{
			count += ticket - 1;
			//考虑剩下的
			if (i <= k) count++;
		}
		else  count += tickets[i];
	}
	return count;
}