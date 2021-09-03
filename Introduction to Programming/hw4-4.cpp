#include <stdio.h>
int sum(int);

int main()
{
	int number;
	printf("Enter a number between 1 and 9999: ");
	scanf_s("%d", &number);

	printf("\n\n The sum of the digits of the number %d is %d", number, sum(number));
}

int sum(int number)
{
	int digit1, digit2, digit3, digit4;
	digit1 = number / 1000;
	number %= 1000;
	digit2 = number / 100;
	number %= 100;
	digit3 = number / 10;
	number %= 10;
	digit4 = number;

	return digit1 + digit2 + digit3 + digit4;
}