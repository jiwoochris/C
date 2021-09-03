#include <stdio.h>
#include <math.h>
void check(double a, double b, double c);

int main()
{
	double a, b, c;

	printf("The coefficients of a Quadratic Equation ax^2=bx+c=0 are a, b and c\n");
	printf("Enter values fo a, b and c : \n");
	scanf_s("%lf", &a);
	scanf_s("%lf", &b);
	scanf_s("%lf", &c);

	check(a, b, c);
}

void check(double a, double b, double c)
{
	if (b*b-4*a*c<0)
		printf("imaginary roots\n");
	else
	{
		printf("\nTwo real and equal roots");
		printf("\nRoots are %lf and %lf", (-b + sqrt(b * b - 4 * a * c)) / (2 * a), (-b - sqrt(b * b - 4 * a * c)) / (2 * a));
	}
}