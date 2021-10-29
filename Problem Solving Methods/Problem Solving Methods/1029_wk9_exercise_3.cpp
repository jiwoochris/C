#include <stdio.h>
#include <stdlib.h>

struct EMPLOYEE {
	char name[20];
	char name2[20];
	int id;
	double salary;
	char date[20];
};

bool Create_employee_file(const char* fname) {
	struct EMPLOYEE emp[5];

	emp[0] = { "Anthony", "A.J.", 10031, 7.82, "12/18/1962" };
	emp[1] = { "Burrows", "W.K..", 10067, 9.14, "6/9/1963" };
	emp[2] = { "Fain", "B.D.", 10083, 8.79, "5/18/1959" };
	emp[3] = { "Janney", "P.", 10095, 10.57, "9/28/1962" };
	emp[4] = { "Smith", "G.J.", 10105, 8.5, "12/20/1961" };

	FILE* pFile = NULL;
	pFile = fopen(fname, "w");
	if (pFile == NULL) {
		printf("Cannot open the file");
		return false;
	}

	for (int i = 0; i < 5; i++) {
		fprintf(pFile, "%s %s %d %lf %s\n",
			emp[i].name,
			emp[i].name2,
			emp[i].id,
			emp[i].salary,
			emp[i].date);
	}

	fclose(pFile);
	return true;

}

bool fcopy(const char* src, const char* dest) {
	FILE* pInfile = NULL, * pOutfile = NULL;

	pInfile = fopen(src, "r");
	if (pInfile == NULL) {
		printf("Cannot open the file");
		return false;
	}

	pOutfile = fopen(dest, "w");
	if (pOutfile == NULL) {
		printf("Cannot open the file");
		return false;
	}

	char ch;

	while ((ch = fgetc(pInfile)) != EOF)
		fputc(ch, pOutfile);

	fclose(pInfile);
	fclose(pOutfile);
}

int main(int argc, char* argv[]) {

	if (argc < 3) {
		printf("Usage : [Command] [Source_FileName] [Dest_FileName]");
		return -1;
	}

	if (!Create_employee_file("employee.txt")) {
		return -1;
	}

	if (!fcopy(argv[1], argv[2])) {
		return -1;
	}

	return 0;
}