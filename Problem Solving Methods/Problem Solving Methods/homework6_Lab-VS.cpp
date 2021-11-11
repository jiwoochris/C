#include <stdio.h>
#include <string.h>

struct SALARY {
	char name[20];
	int age;
	double salary;
}salary[50];

bool read_file(const char fname[30], SALARY s[], int* index_num) {

	FILE* f = NULL;
	f = fopen(fname, "r");
	if (f == NULL) {
		printf("Cannot open the file!");
		return false;
	}

	char name[20];
	int age;
	double salary;
	*index_num = 0;

	while (fscanf(f, "%s %d %lf", name, &age, &salary) == 3) {
		strcpy(s[*index_num].name, name);
		s[*index_num].age = age;
		s[*index_num].salary = salary;
		(*index_num)++;
	}

	fclose(f);

	return true;
}

bool write_file(const char fname[30], const SALARY s[], int index_num) {

	FILE* f = NULL;
	f = fopen(fname, "w");
	if (f == NULL) {
		printf("Cannot open the file!");
		return false;
	}


	for (int i = 0; i < index_num; i++) {
		fprintf(f, "%8s %d %.1f\n", s[i].name, s[i].age, s[i].salary);
	}

	fclose(f);

	return true;
}

void update_version_2(SALARY s[], int index_num) {
	for (int i = 0; i < index_num; i++) {
		if (s[i].age >= 40 && s[i].age < 50) {
			s[i].salary = s[i].salary * 1.1;
		}
	}
}

void update_version_3(SALARY s[], int index_num) {
	for (int i = 0; i < index_num; i++) {
		if (s[i].age >= 30 && s[i].age < 40) {
			s[i].salary = s[i].salary * 1.2;
		}
	}
}

bool compare(const char fname1[30], const char fname2[30], int index_num) {
	SALARY salary1[50];
	SALARY salary2[50];

	if (!read_file("salary_v1.txt", salary1, &index_num)) {
		return false;
	}

	if (!read_file("salary_v3.txt", salary2, &index_num)) {
		return false;
	}

	for (int i = 0; i < index_num; i++) {
		if (salary1[i].salary != salary2[i].salary) {
			printf("%8s %d %.1f -> %.1f Different\n", salary1[i].name, salary1[i].age, salary1[i].salary, salary2[i].salary);
		}
		else {
			printf("%8s %d %.1f\n", salary1[i].name, salary1[i].age, salary1[i].salary);
		}
	}

	return true;
}

int main() {
	int index_num;
	if (!read_file("salary_v1.txt", salary, &index_num)) {
		return -1;
	}

	update_version_2(salary, index_num);
	write_file("salary_v2.txt", salary, index_num);

	if (!read_file("salary_v2.txt", salary, &index_num)) {
		return -1;
	}

	update_version_3(salary, index_num);
	write_file("salary_v3.txt", salary, index_num);

	if (!compare("salary_v1.txt", "salary_v3.txt", index_num)) {
		return -1;
	}

	return 0;
}