#include <stdio.h>

void liquid(int number, float* gallons, float* quarts, float* pints, float* cups) {
	*pints = number / float(2);
	*quarts = number / float(4);
	*gallons = number / float(16);
	*cups = number;
}


int main() {
	int number[] = { 5, 34, 12, 0 };
	float gallons, quarts, pints, cups;

	for (int i = 0; i < 4; i++) {
		liquid(number[i], &gallons, &quarts, &pints, &cups);

		printf("\n");
		printf(" the total number of cups : %d", number[i]);
		printf(" ==> gallons : %f, quarts : %f, pints : %f, cups : %f", gallons, quarts, pints, cups);
		printf("\n");
	}

	return 0;
}