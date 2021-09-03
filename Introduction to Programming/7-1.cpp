#include<stdio.h>

int main()
{
	char a = 'a';
	int b = 10;
	double c = 3.14;
	
	char* p1 = &a;
	int* p2 = &b;
	double* p3 = &c;

	*p1 += 1;
	*p2 += 1;
	*p3 += 1;

	printf("a: %c\nb: %d\nc: %lf\np1: %p\np2: %p\np3: %p", a, b, c, p1, p2, p3);
}