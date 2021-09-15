#include <stdio.h>

void change(float cash, int* cent25, int* cent10, int* cent5, int* cent1) {
	/*ceil(n)
	round(n)
	floor(n)*/

	float cashf = cash;

	if (cash >= 1)
		cashf = cash - (int)cash;
		
	printf("%f", cashf);

	int a = cashf / 0.25;
	printf("%d", a);
}


int main() {

	float cash = 10.53f; // 0.33
	int cent25, cent10, cent5, cent1;

	change(cash, &cent25, &cent10, &cent5, &cent1);

	printf("\n\nCash %f Change --> (%d) cent25, (%d) cent10, (%d) cent5, (%d) cent1",
		cash, cent25, cent10, cent5, cent1);

	return 0;
}