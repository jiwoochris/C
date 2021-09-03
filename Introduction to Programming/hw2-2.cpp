#include <stdio.h>

int main()
{
	int num, nine;
	int count = 0;
	printf("Enter an integer (5 digits or fewer)\n");
	scanf_s("%d", &num);

	while (num > 0)
	{
		nine = num % 10; 
		num = num / 10;
		if (nine == 9)
			count++;
	}
	printf("how many digits in the integer are 9s : %d\n",count);
}