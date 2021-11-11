#include <stdio.h>
#include <string.h>

struct VOTE {
	char region[20];
	int age;
	char candidate_voted[20];
}vote[2000];

bool read_file(const char fname[30], VOTE v[]) {

	FILE* f = NULL;
	f = fopen(fname, "r");
	if (f == NULL) {
		printf("Cannot open the file!");
		return false;
	}

	char region[20];
	int age;
	char candidate_voted[20];
	int index = 0;

	while (fscanf(f, "%s %d %s", region, &age, candidate_voted) == 3) {
		strcpy(v[index].region, region);
		v[index].age = age;
		strcpy(v[index].candidate_voted, candidate_voted);
		index++;
	}

	fclose(f);

	return true;
}

void compute_all(const VOTE v[]) {
	int washington = 0;
	int lincoln = 0;
	int roosevelt = 0;
	int sum;
	

	for (int i = 0; i < 2000; i++) {
		if (strcmp(v[i].candidate_voted, "Washington") == 0) {
			washington++;
		}
		else if (strcmp(v[i].candidate_voted, "Lincoln") == 0) {
			lincoln++;
		}
		else if (strcmp(v[i].candidate_voted, "Roosevelt") == 0) {
			roosevelt++;
		}
		else {
			printf("Error");
		}
	}

	sum = washington + lincoln + roosevelt;

	printf("Washington %.1f%%, Lincoln %.1f%%, Roosevelt %.1f%%\n",
		washington / double(sum) * 100, lincoln / double(sum) * 100, roosevelt / double(sum) * 100);

	printf("Washington %d, Lincoln %d, Roosevelt %d\n\n",
		washington, lincoln, roosevelt);
}

void compute_third(const VOTE v[]) {
	int washington = 0;
	int lincoln = 0;
	int roosevelt = 0;
	int sum;


	for (int i = 0; i < 2000; i = i+3) {
		if (strcmp(v[i].candidate_voted, "Washington") == 0) {
			washington++;
		}
		else if (strcmp(v[i].candidate_voted, "Lincoln") == 0) {
			lincoln++;
		}
		else if (strcmp(v[i].candidate_voted, "Roosevelt") == 0) {
			roosevelt++;
		}
		else {
			printf("Error");
		}
	}

	sum = washington + lincoln + roosevelt;

	printf("Washington %.1f%%, Lincoln %.1f%%, Roosevelt %.1f%%\n",
		washington / double(sum) * 100, lincoln / double(sum) * 100, roosevelt / double(sum) * 100);

	printf("Washington %d, Lincoln %d, Roosevelt %d\n\n",
		washington, lincoln, roosevelt);
}

void compute_tenth(const VOTE v[]) {
	int washington = 0;
	int lincoln = 0;
	int roosevelt = 0;
	int sum;


	for (int i = 0; i < 2000; i = i + 10) {
		if (strcmp(v[i].candidate_voted, "Washington") == 0) {
			washington++;
		}
		else if (strcmp(v[i].candidate_voted, "Lincoln") == 0) {
			lincoln++;
		}
		else if (strcmp(v[i].candidate_voted, "Roosevelt") == 0) {
			roosevelt++;
		}
		else {
			printf("Error");
		}
	}

	sum = washington + lincoln + roosevelt;

	printf("Washington %.1f%%, Lincoln %.1f%%, Roosevelt %.1f%%\n",
		washington / double(sum) * 100, lincoln / double(sum) * 100, roosevelt / double(sum) * 100);

	printf("Washington %d, Lincoln %d, Roosevelt %d\n\n",
		washington, lincoln, roosevelt);
}

int main() {
	if (!read_file("vote.txt", vote)) {
		return -1;
	}

	compute_all(vote);

	compute_third(vote);

	compute_tenth(vote);

	return 0;
}