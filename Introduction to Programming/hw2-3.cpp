#include <stdio.h>

int main()
{
	double cel, fah;
	printf("I will convert from Celsius to Fahrenheit scale.\n");
	printf("Enter temperatures from 30 to 50.\n");

	scanf_s("%lf", &cel);
	fah = cel * 1.8 + 32;

	printf("Celsius : %.2f \t Fahrenheit : %.2f", cel, fah);
}