#include <stdio.h>
#include <string.h>
#include <math.h>

struct info{
	char RRN[14]; // constraint: unique
	char name[20];
	float salary;
	float bonus; // constraint: bonus < salary
} employee[1000];

int check_constraint(int insertion_cursor, info test_set) {
	for (int j = 0; j < insertion_cursor; j++) {
		if (strcmp(employee[j].RRN, test_set.RRN) == 0)
			return -1;
	}

	if (test_set.bonus > test_set.salary)
		return -2;

	return 0;
}

int main() {
	struct info test_set[5] = {
		{"0112023111111", "Jung", 300.5, 30},
		{"0112023111222", "Kim", 400, 51.1},
		{"0112023111111", "Hong", 513, 70},
		{"9903081410511", "Park", 50, 5},
		{"9710023156111", "Lee", 100, 130}
	};

	int insertion_cursor = 0;

	for (int i = 0; i < 5; i++) {
		
		if (check_constraint(insertion_cursor, test_set[i]) == 0) {
			strcpy_s(employee[insertion_cursor].RRN, test_set[i].RRN);
			strcpy_s(employee[insertion_cursor].name, test_set[i].name);
			employee[insertion_cursor].salary = test_set[i].salary;
			employee[insertion_cursor].bonus = test_set[i].bonus;

			insertion_cursor++;
			printf("[Success] Insertion complete!\n");
		}

		else if (check_constraint(insertion_cursor, test_set[i]) == -1)
			printf("[Error] RRN_constraint : unique\n");

		else if (check_constraint(insertion_cursor, test_set[i]) == -2)
			printf("[Error] Bonus_constraint : bonus < salary\n");
		
	}

	printf("\n[employee list]\n");
	for (int i = 0; i < insertion_cursor; i++) {
		printf("%s %s %lf %lf\n", employee[i].RRN, employee[i].name, employee[i].salary, employee[i].bonus);
	}

	return 0;
}