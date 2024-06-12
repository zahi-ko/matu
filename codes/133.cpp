#include<stdio.h>
 
void Matrix_Mul(int a[3][2], int b[2][4])
{
	int result[3][4] = {};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result[i][j] = (a[i][0] * b[0][j] + a[i][1] * b[1][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
}