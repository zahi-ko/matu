void  bubbleSort(int data[],int n)
{
	int tmp,i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(data[j]>data[j+1])
			{
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
	}
}