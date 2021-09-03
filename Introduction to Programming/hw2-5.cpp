#include <stdio.h>

int main()
{
	int i;
	printf("I will convert and print the characters for the ASCII values 0 to 127\n\n");

    for (i = 0; i <= 127; i++)
    {
        if (i%10==0)
            printf("\n%c", i); 
        else
            printf("%c", i);
    }
}