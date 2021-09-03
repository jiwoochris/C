#include  <stdio.h>

int main(void)
{
    int second, hour, minute;

    printf("Enter the total time elapsed in seconds.\n");
    printf("I will convert the time to hours, minutes and seconds.\n");
    scanf_s("%d", &second);

    minute = second / 60;
    hour = minute / 60;
    second %= 60;
    minute %= 60;

    printf("%d : %d : %d\n", hour, minute, second);
}