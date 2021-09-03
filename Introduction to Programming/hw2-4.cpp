#include <stdio.h>

int main()
{
	int i, j;
	int count=0;
	for (i = 1; i <= 100; i++)
	{
		for (j = i - 1; j >= 2; j--)
		{
			if (i % j == 0)
				count++;
		}
		if (count == 0)
			printf("%d\n", i);
		else
			count = 0;
	}
}