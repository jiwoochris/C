#include <stdio.h>

void show(float rates[], int size){
	for (int i = 0; i < size; i++) {
		printf(" %f\n", rates[i]);
	}
}


int main() {
	float rates[] = { 6.5, 8.2, 8.5, 8.3, 8.6, 9.4, 9.6, 9.8, 10.0 };

	show(rates, sizeof(rates) / 4);

	return 0;
}