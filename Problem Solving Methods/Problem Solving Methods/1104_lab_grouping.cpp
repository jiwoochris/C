#include <stdio.h>
#include <string.h>

struct PERSON {
	char name[30];
	int age;
	char hobby[30];
}person[30];

void copy_element(const PERSON src[], PERSON dest[]) {
	strcpy(dest->name, src->name);
	dest->age = src->age;
	strcpy(dest->hobby, src->hobby);
}

void group_by_age(const PERSON original[], const int num, PERSON grouped[]) {
	int index = 0;

	for (int i = 0; i < num; i++) {
		if (original[i].age < 20) {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}

	for (int i = 0; i < num; i++) {
		if (original[i].age >= 20 && original[i].age < 30) {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}

	for (int i = 0; i < num; i++) {
		if (original[i].age >= 30 && original[i].age < 40) {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}

	for (int i = 0; i < num; i++) {
		if (original[i].age >= 40) {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}
}

void group_by_hobby(const PERSON original[], const int num, PERSON grouped[]) {
	int index = 0;

	for (int i = 0; i < num; i++) {
		if (original[i].hobby[0] == 'G') {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}

	for (int i = 0; i < num; i++) {
		if (original[i].hobby[0] == 'P') {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}

	for (int i = 0; i < num; i++) {
		if (original[i].hobby[0] == 'S') {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}

	for (int i = 0; i < num; i++) {
		if (original[i].hobby[0] == 'T') {
			copy_element(&original[i], &grouped[index]);
			index++;
		}
	}
}

bool file_write(const PERSON p[], const int num, const char fname[30]) {

	FILE* f = NULL;
	f = fopen(fname, "w");
	if (f == NULL) {
		printf("Cannot open the file!");
		return false;
	}

	for (int i = 0; i < num; i++) {
		fprintf(f, "%8s %d %8s\n",
			p[i].name, p[i].age, p[i].hobby);
	}

	fclose(f);

	return true;
}

int main() {
	int i = 0;
	char name[30];
	int age;
	char hobby[30];

	FILE* f = NULL;
	f = fopen("personal.txt", "r");
	if (f == NULL) {
		printf("Cannot open the file!");
		return false;
	}

	while (fscanf(f, "%s %d %s", &name, &age, &hobby) == 3) {
		strcpy(person[i].name, name);
		person[i].age = age;
		strcpy(person[i].hobby, hobby);
		i++;
	}

	fclose(f);

	struct PERSON group_age[30];

	group_by_age(person, i, group_age);
	if (!file_write(group_age, i, "age.txt")) {
		return -1;
	}

	struct PERSON group_hobby[30];
	group_by_hobby(person, i, group_hobby);
	if (!file_write(group_hobby, i, "hobby.txt")) {
		return -1;
	}

	return 0;
}