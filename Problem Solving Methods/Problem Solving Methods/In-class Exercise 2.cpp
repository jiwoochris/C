#include <stdio.h>

void calculate(int* n1, int* n2, int* re1, int* re2, int* re3, int* re4) {
	*re1 = *n1 * *n2;

	if (*n2 == 0) {
		printf("\nerror : divided by 0");
		*re2 = 0;
		*re3 = 0;
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

	n1 = 100000, n2 = 5;
	calculate(&n1, &n2, &re1, &re2, &re3, &re4);
	printf("\n%d * %d = %d\n%d / %d = %d\n%d %% %d = %d\n%d + %d = %d\n", n1, n2, re1, n1, n2, re2, n1, n2, re3, n1, n2, re4);

	n1 = 13;
	n2 = 4;
	calculate(&n1, &n2, &re1, &re2, &re3, &re4);
	printf("\n%d * %d = %d\n%d / %d = %d\n%d %% %d = %d\n%d + %d = %d\n", n1, n2, re1, n1, n2, re2, n1, n2, re3, n1, n2, re4);

	n1 = 20;
	n2 = -5;
	calculate(&n1, &n2, &re1, &re2, &re3, &re4);
	printf("\n%d * %d = %d\n%d / %d = %d\n%d %% %d = %d\n%d + %d = %d\n", n1, n2, re1, n1, n2, re2, n1, n2, re3, n1, n2, re4);

	n1 = 40;
	n2 = 0;
	calculate(&n1, &n2, &re1, &re2, &re3, &re4);
	printf("\n%d * %d = %d\n%d / %d = %d\n%d %% %d = %d\n%d + %d = %d\n", n1, n2, re1, n1, n2, re2, n1, n2, re3, n1, n2, re4);

}