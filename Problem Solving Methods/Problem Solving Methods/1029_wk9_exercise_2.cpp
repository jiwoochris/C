#include <stdio.h>
#include <stdlib.h>

struct CAR {
	char name[20];
	int year;
	double price;
} car[4];

int main() {
	car[0] = { "Avante", 2007, 13000.00 };
	car[1] = { "Sonata", 2008, 18000.00 };
	car[2] = { "SM7", 2009, 22000.00 };
	car[3] = { "Equus", 2010, 35000.00 };

	FILE* f;
	f = fopen("cars.txt", "w");

	if (f == NULL) {
		printf("\nCouldn't open file");
		exit(1);
	}
	else {
		for (int i = 0; i < 4; i++) {
			fprintf(f, "%s %d %lf\n", car[i].name, car[i].year, car[i].price);
		}
	}
	fclose(f);

	f = fopen("cars.txt", "r");
	if (f == NULL) {
		printf("\nCouldn't open file");
		exit(1);
	}
	else {
		char name[20];
		int year;
		double price;
		
		printf("---------------------------------\n");
		printf("|Name     |Year     |Price     |\n");
		printf("---------------------------------\n");

		while (fscanf(f, "%s %d %lf", &name, &year, &price) == 3) {
			printf("|%-5s     |%d     |%lf     |\n", name, year, price);
		}
		printf("---------------------------------\n");
	}
	fclose(f);


	return 0;
}