#include<stdio.h>

void asterisk(int side1, int side2)
{
	for (int i = 0; i < side1; i++)
	{
		printf("\n"); 
		for (int j = 0; j < side2; j++)
		{
			printf("*");
		}
	}
}

int main()
{
	int side1, side2;
	printf("Enter sides: ");
	scanf_s("%d %d", &side1, &side2);

	asterisk(side1, side2);
}