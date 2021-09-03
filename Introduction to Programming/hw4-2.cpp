#include<stdio.h>

void asterisk(int side1, int side2, char fill)
{
	for (int i = 0; i < side1; i++)
	{
		printf("\n");
		for (int j = 0; j < side2; j++)
		{
			printf("%c ", fill);
		}
	}
}

int main()
{
	int side1, side2;
	char fill;

	printf("Enter a character to fill the rectangle: ");
	scanf_s("%c", &fill);

	printf("\nEnter sides: ");
	scanf_s("%d %d", &side1, &side2);

	asterisk(side1, side2, fill);
}