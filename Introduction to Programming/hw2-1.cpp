#include <stdio.h>

int main()
{
	int hours=0;
	double rate=0;
	double salary=0;

	while(hours != -1)
	{
		printf("Enter # of hours worked. (-1 to end) : ");
		scanf_s("%d", &hours);
		
		if (hours == -1)
			break;

		printf("Enter hourly rate of the worker. ($00.00) : ");
		scanf_s("%lf", &rate);

		if (hours >= 40)
			salary = 40 * rate + (hours - 40.0) * 1.5 * rate; 
		else  if (0 <= hours)
			salary = hours * rate;
		else
			printf("Error.\n");		
			
		printf("Salary is $ %.2f \n\n", salary);
	}
	printf("Program ends.");
}