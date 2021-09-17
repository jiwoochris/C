#include <stdio.h>
#include <math.h>

void liquid(int number,int* gallons, int* quarts, int* pints, int* cups) {
	*pints = ceil(number / float(2));
	*quarts = ceil(number / float(4));
	*gallons = ceil(number / float(16));
	*cups = ceil(number);
}


int main() {
	int number[] = { 5, 34, 12, 0 };
	int gallons, quarts, pints, cups;

	for (int i = 0; i < 4; i++) {
		liquid(number[i], &gallons, &quarts, &pints, &cups);

		printf("\n");
		printf(" the total number of cups : %d", number[i]);
		printf(" ==> gallons : %d, quarts : %d, pints : %d, cups : %d", gallons, quarts, pints, cups);
		printf("\n");
	}

	return 0;
}