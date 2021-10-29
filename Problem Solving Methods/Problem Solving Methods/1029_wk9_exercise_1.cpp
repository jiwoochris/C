#include <stdio.h>
#include <stdlib.h>

struct CAR {
	char name[20];
	int year;
} car[2];

int main() {
	car[0] = { "Avante", 2007 };
	car[1] = { "Sonata", 2008 };

	FILE* f;
	f = fopen("cars.txt", "w");

	if (f == NULL) {
		printf("\nCouldn't open file");
		exit(1);
	}
	else {
		for (int i = 0; i < 2; i++) {
			fprintf(f, "%s %d\n", car[i].name, car[i].year);
		}
	}
	fclose(f);

	f = fopen("cars.txt", "r");
	if (f == NULL) {
		printf("\nCouldn't open file");
		exit(1);
	}
	else {
		struct CAR fcar[2];

		int i = 0;
		while (fscanf(f, "%s %d", &fcar[i].name, &fcar[i].year) == 2) {
			printf("%s %d\n", fcar[i].name, fcar[i].year);
			i++;
		}
	}
	fclose(f);


	return 0;
}