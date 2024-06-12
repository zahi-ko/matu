#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b) {a=a+b; b=a-b; a=a-b;}
int main()
{
	int n,*a,i,j;
	scanf("%d",&n);
	a=(int *)malloc(sizeof(int)*n);
	for(i=0;i<n;scanf("%d",a+i++));
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(a[j]>a[j+1])
				SWAP(a[j],a[j+1]);
	for(i=0;i<n;printf(i==n?"%d\n":"%d,",a[i++]));
	free(a);
	return 0;
}