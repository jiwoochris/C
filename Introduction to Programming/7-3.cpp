#include<stdio.h>

void call_by_value(int num) {
	num += 10;
	printf("In the call_by_value function : \n value %d, Address %p\n", num, &num);
}

void call_by_reference(int *num) {
	*num += 10;
	printf("In the call_by_reference function : \n value %d, Address %p\n", *num, num);
}

int main()
{
	printf("Enter an integer: ");
	int a;
	scanf_s("%d", &a);

	printf("Before the call_by_value function : \n value %d, Address %p\n", a, &a);
	call_by_value(a);
	printf("After the call_by_value function : \n value %d, Address %p\n", a, &a);
	printf("Before the call_by_reference function : \n value %d, Address %p\n", a, &a);
	call_by_reference(&a);
	printf("After the call_by_reference function : \n value %d, Address %p\n", a, &a);
}