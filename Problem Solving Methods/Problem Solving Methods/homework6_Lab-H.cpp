#include <stdio.h>
#include <string.h>

struct PERSONAL {
	char name[20];
	int age;
	char hobby[20];
}personal[50];

bool read_file(const char fname[30], PERSONAL p[], int * index_num) {

	FILE* f = NULL;
	f = fopen(fname, "r");
	if (f == NULL) {
		printf("Cannot open the file!");
		return false;
	}

	char name[20];
	int age;
	char hobby[20];
	*index_num = 0;

	while (fscanf(f, "%s %d %s", name, &age, hobby) == 3) {
		strcpy(p[*index_num].name, name);
		p[*index_num].age = age;
		strcpy(p[*index_num].hobby, hobby);
		(*index_num)++;
	}

	fclose(f);

	return true;
}

void output_by_age(const char fname[30], const PERSONAL p[], int index_num) {
	FILE* f = NULL;
	f = fopen(fname, "w");
	if (f == NULL) {
		printf("Cannot open the file!");
	}

	fprintf(f, "\nAge from 10 to 19\n");
	fprintf(f, "----------------------------\n");
	for (int i = 0; i < index_num; i++) {
		if (p[i].age >= 10 && p[i].age < 20) {
			fprintf(f, "%8s %d %8s\n",
				p[i].name, p[i].age, p[i].hobby);
		}
	}

	fprintf(f, "\nAge from 20 to 29\n");
	fprintf(f, "----------------------------\n");
	for (int i = 0; i < index_num; i++) {
		if (p[i].age >= 20 && p[i].age < 30) {
			fprintf(f, "%8s %d %8s\n",
				p[i].name, p[i].age, p[i].hobby);
		}
	}

	fprintf(f, "\nAge from 30 to 39\n");
	fprintf(f, "----------------------------\n");
	for (int i = 0; i < index_num; i++) {
		if (p[i].age >= 30 && p[i].age < 40) {
			fprintf(f, "%8s %d %8s\n",
				p[i].name, p[i].age, p[i].hobby);
		}
	}

	fprintf(f, "\nAge from 40 to 49\n");
	fprintf(f, "----------------------------\n");
	for (int i = 0; i < index_num; i++) {
		if (p[i].age >= 40 && p[i].age < 50) {
			fprintf(f, "%8s %d %8s\n",
				p[i].name, p[i].age, p[i].hobby);
		}
	}

	fclose(f);
}

int main() {
	int index_num;
	if (!read_file("personal.txt", personal, &index_num)) {
		return -1;
	}

	output_by_age("output.txt", personal, index_num);

	return 0;
}