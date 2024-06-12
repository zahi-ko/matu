#include<stdio.h>
struct STU{
	char name[25];
	int gender;
	int birthday;
	float height;
	int scoreC;
	int scorec;
}stu[10];
int main()
{
	int n,C_ave,C_max[10]={-1},C_min=200,c_ave,c_max[10]={-1},c_min=200,C_sum=0,c_sum=0,C_num=0,c_num=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s %d %d %f %d %d",stu[i].name,&stu[i].gender,&stu[i].birthday,&stu[i].height,&stu[i].scoreC,&stu[i].scorec);
		C_sum+=stu[i].scoreC;
		c_sum+=stu[i].scorec;
		if(stu[i].scoreC>C_max[0]) C_max[0]=stu[i].scoreC;
		if(stu[i].scoreC<C_min) C_min=stu[i].scoreC;
		if(stu[i].scorec>c_max[0]) c_max[0]=stu[i].scorec;
		if(stu[i].scorec<c_min) c_min=stu[i].scorec;
	}
	for(int i=1;i<=n;i++)
	{
		if(stu[i].scoreC==C_max[0])
		{
			C_num++;
			C_max[C_num]=i;
		}
		if(stu[i].scorec==c_max[0])
		{
			c_num++;
			c_max[c_num]=i;
		}
	}
	C_ave=C_sum/n;
	c_ave=c_sum/n;
	printf("C_average:%d\nC_max:%d\n",C_ave,C_max[0]);
	for(int i=1;i<=C_num;i++)
		printf("%s %d %d %.2f %d %d\n",stu[C_max[i]].name,stu[C_max[i]].gender,stu[C_max[i]].birthday,stu[C_max[i]].height,stu[C_max[i]].scoreC,stu[C_max[i]].scorec);
	printf("C_min:%d\nCalculus_average:%d\nCalculus_max:%d\n",C_min,c_ave,c_max[0]);
	for(int i=1;i<=c_num;i++)
		printf("%s %d %d %.2f %d %d\n",stu[c_max[i]].name,stu[c_max[i]].gender,stu[c_max[i]].birthday,stu[c_max[i]].height,stu[c_max[i]].scoreC,stu[c_max[i]].scorec);
	printf("Calculus_min:%d\n",c_min);
	return 0;
}