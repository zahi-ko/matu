#include<stdio.h>
void main()
{
	char str1[100], str2[100], c;
	int i = 0, s = 0;
	gets(str1);
	gets(str2); 
	while ((str1[i] == str2[i] && str1[i] != '\0')) i++;
	s = str1[i] - str2[i];
	printf("%d\n", s);
}
