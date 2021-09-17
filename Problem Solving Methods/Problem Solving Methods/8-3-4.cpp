#include <stdio.h>
#define MAX 10

void extend(float price[], float quantity[], float amount[]) {
	for (int i = 0; i < MAX; i++)
		amount[i] = price[i] * quantity[i];
}

int main() {

	float price[MAX] = { 10.62, 14.89, 13.21, 16.55, 18.62, 9.47, 6.58, 18.32, 12.15, 3.98 };
	float quantity[MAX] = { 4, 8.5, 6, 8.35, 9, 15.3, 3, 5.4, 2.9, 4.8 };
	float amount[MAX];

	extend(price, quantity, amount);

	for (int i = 0; i < MAX; i++)
		printf( "%f\n", amount[i]);

	return 0;
}