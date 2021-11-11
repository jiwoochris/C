#include <stdio.h>
#include <string.h>

struct PERSONAL {
	char name[20];
	int age;
	char hobby[20];
}personal[50];

bool read_file(const char fname[30], PERSONAL p[], int* index_num) {

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

void write_age(const char fname[30], const PERSONAL p[], int index_num) {
	FILE* f = NULL;
	f = fopen(fname, "w");
	if (f == NULL) {
		printf("Cannot open the file!");
	}

	else {
		for (int i = 0; i < index_num; i++) {
			fprintf(f, "%s %d\n", p[i].name, p[i].age);
		}

		fclose(f);
	}
}

void write_hobby(const char fname[30], const PERSONAL p[], int index_num) {
	FILE* f = NULL;
	f = fopen(fname, "w");
	if (f == NULL) {
		printf("Cannot open the file!");
	}

	else {
		for (int i = 0; i < index_num; i++) {
			fprintf(f, "%s %s\n", p[i].name, p[i].hobby);
		}

		fclose(f);
	}
}

int main() {
	int index_num;
	if (!read_file("personal.txt", personal, &index_num)) {
		return -1;
	}

	write_age("age.txt", personal, index_num);

	write_hobby("hobby.txt", personal, index_num);

	return 0;
}