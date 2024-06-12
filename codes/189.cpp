#include <stdio.h>
int main()
{
	int n, b[108], aim, i, j;
	scanf("%d", &n);
	j = n / 2;
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &b[i]);
		getchar();
	}
	scanf("%d", &aim);
	while (b[j] != aim)
	{
		if (b[j] > aim)
		{
			j /= 2;
		}
		else
		{
			j = (n + j) / 2 + 1;
		}
	}
	printf("%d\n", j);
	return 0;
}