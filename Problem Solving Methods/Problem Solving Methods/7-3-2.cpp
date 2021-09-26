#include <stdio.h>

void change(float cash, int* cent25, int* cent10, int* cent5, int* cent1) {

	int cashf = cash * 100;
	cashf %= 100;

	int q = cashf / 25;
	*cent25 = q;
	cashf = cashf - q * 25;

	int d = cashf / 10;
	*cent10 = d;
	cashf = cashf - d * 10;

	int n = cashf / 5;
	*cent5 = n;
	cashf = cashf - n * 5;

	int p = cashf / 1;
	*cent1 = p;
	cashf = cashf - p * 1;

}


int main() {

	float cash[] = { 10.53f, 0.03f, 52.98f, 1.99f };

	int cent25, cent10, cent5, cent1;

	for (int i=0; i < sizeof(cash) / 4 ; i++)
	{
		change(cash[i], &cent25, &cent10, &cent5, &cent1);

		printf("\n Cash %f Change --> (%d) cent25, (%d) cent10, (%d) cent5, (%d) cent1\n",
			cash[i], cent25, cent10, cent5, cent1);
	}

	return 0;
}