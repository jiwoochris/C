#include <stdio.h>

void calculate(int* n1, int* n2, int* re1, int* re2, int* re3, int* re4) {
	*re1 = *n1 * *n2;

	if (*n2 == 0) {
		printf("\nerror : divided by 0");
		*re2 = *re3 = 0;
	}

	else {
		*re2 = *n1 / *n2;
		*re3 = *n1 % *n2;
	}

	*re4 = *n1 + *n2;
}

int main() {
	int n1, n2;
	int re1, re2, re3, re4;
	int n1_arr[] = { 100000, 13, 20, 40 };
	int n2_arr[] = { 5, 4, -5, 0 };

	for (int i = 0; i < 4; i++) {
		n1 = n1_arr[i];
		n2 = n2_arr[i];
		calculate(&n1, &n2, &re1, &re2, &re3, &re4);
		printf("\n%d * %d = %d\n%d / %d = %d\n%d %% %d = %d\n%d + %d = %d\n", n1, n2, re1, n1, n2, re2, n1, n2, re3, n1, n2, re4);
	}
	
}