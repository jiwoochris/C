#include <stdio.h>

int main() {
	struct car {
		int car_number;
		int mile;
		int gallons;
	};

	struct car cars[5] = { //구조체 초기화
		{25, 1450,62},
		{36,3240,136},
		{44,1792,76},
		{52,2360,105},
		{68,2114,67}
	};

	float avg = 0;

	for (int i = 0; i < 5; i++) {
		printf(" Car number : %d\n miles per gallon : %f\n", cars[i].car_number, cars[i].mile / float(cars[i].gallons));
		avg += cars[i].mile / float(cars[i].gallons);
	}

	avg /= 5;
	printf("\n average miles per gallon is %f", avg);

	return 0;
}