#include  <stdio.h>

int main(void)
{
    int first, second, third, fourth, fifth, number;

    printf("Enter one five-digit number.\n");
    printf("I will separate the number into its individual digits.\n");
    scanf_s("%d", &number);

    first = number / 10000;
    second= (number / 1000)%10;
    third = (number / 100) % 10;
    fourth = (number / 10) % 10;
    fifth = number % 10;

    printf("%d   %d   %d   %d   %d", first, second, third, fourth, fifth);
}