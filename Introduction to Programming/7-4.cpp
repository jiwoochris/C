#include<stdio.h>

int sum(int *num1, int *num2) {
	return *num1 + *num2;
}

int product(int* num1, int* num2) {
	return *num1 * *num2;
}

int main()
{
	int a;
	int b;
	printf("Enter two integers: ");
	scanf_s("%d %d", &a, &b);

	printf("Result: sum = %d, product = %d", sum(&a, &b), product(&a, &b));
}