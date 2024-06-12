#include<stdio.h>
int main()
{
	int n,i,a[100001],min=99999999,pos_min,max=-99999999,pos_max;
	int * A=&a[0];
	scanf("%d",&n);
	if(n<=0)
	{
		printf("error");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",(A+i));
		if(*(A+i)>max)
		{
			max=*(A+i);
			pos_max=i+1;
		}
		if(*(A+i)<min)
		{
			min=*(A+i);
			pos_min=i+1;
		}
	}
	printf("max:%d,position:%d\n",max,pos_max);
	printf("min:%d,position:%d\n",min,pos_min);
	return 0;
}