#include<stdio.h>

int main()
{
	int a = 10;
	int b = 20;

	int* p1 = &a;
	int* p2 = &b;

	p1 = &b;
	p2 = &a;

	printf("a: %d\nb: %d\np1: %p\np2: %p", a, b, p1, p2);
}