#include<stdio.h>
 
int countStudents(int* students, int studentsSize, int* sandwiches, int sandwichesSize)
{
	int Ss0 = 0, Ss1 = 0;
	for (int i = 0; i < studentsSize; i++)
	{
		if (*(students++) == 0) Ss0++;
		else Ss1++;
	}
	for (int i = 0; i < sandwichesSize; i++)
	{
		if (*sandwiches == 0)
		{
			Ss0--;
			if (Ss0 == -1)		return Ss1;
		}
		else if (*sandwiches == 1)
		{
			Ss1--;
			if (Ss1 == -1) return Ss0;
		}
		sandwiches++;
	}
	if (Ss0 == 0 && Ss1 == 0)
	{
		return 0;
	}
	else return Ss0 + Ss1;
}
 