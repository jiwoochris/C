#include  <stdio.h>

int main(void)
{
    float  a = 0;
    float  b = 0;
    float  c = 0;
    float  d = 0;
    float  e = 0;
    float  total=0.00;

    printf("I will display your cost per day of driving to work.\n\n");

    printf("Enter your total miles driven per day.\n");
    scanf_s("%f", &a);

    printf("Enter your cost per gallon of gasoline.\n");
    scanf_s("%f", &b);

    printf("Enter your average miles per gallon.\n");
    scanf_s("%f", &c);

    printf("Enter your parking fees per day.\n");
    scanf_s("%f", &d);

    printf("Enter your tolls per day.\n");
    scanf_s("%f", &e);

    total = ((a * b) / c) + d + e;

    printf("Your cost per day of driving to work is %.3f", total);
}