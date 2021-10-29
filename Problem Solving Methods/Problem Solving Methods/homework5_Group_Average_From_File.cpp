#include <stdio.h>

bool store_data(const char* fname, const char* input) {
	FILE* f = NULL;
	f = fopen(fname, "w");
	if (f == NULL) {
		printf("Cannot open the file!");
		return false;
	}

	fprintf(f, input);
	fclose(f);
	return true;
}

bool calculate(const char* fname) {
	FILE* f = NULL;
	f = fopen(fname, "r");
	if (f == NULL) {
		printf("Cannot open the file!");
		return false;
	}

	int first_number;
	int n;
	int group = 1;

	while (fscanf(f, "%d", &first_number) != EOF) {
		int sum = 0;
		for (int i = 0; i < first_number; i++) {
			if(fscanf(f, "%d", &n) == 1)
				sum += n;
		}
		double avg = sum / double(first_number);
		printf("group %d's avg : %lf\n", group, avg);
		group++;
	}
	fclose(f);
	return true;
}

int main() {

	if (!store_data("hw5_input.txt", "5 96 87 78 93 21 4 92 82 85 87 6 72 69 85 75 81 73")) {
		return -1;
	}

	if (!calculate("hw5_input.txt")) {
		return -1;
	}

	return 0;
}