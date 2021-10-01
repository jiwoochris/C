#include <stdio.h>
#include <string.h>

struct DATASET {
	char name[30];
	int age;
	char hobby[64];
	int* key_ptr;
};

struct INDEX {
	char key[30];
	int index;
};

int search(const char name[], INDEX index[]) {
	for (int i = 0; i < 5; i++) {
		if (strcmp(name, index[i].key) == 0)
			return index[i].index;
	}

	return -1;
}


int main() {
	struct DATASET array[5] = {
		{"Kim", 39, "Tennis" },
		{"Ko", 15, "Soccer"},
		{"Lee", 17, "Soccer"},
		{"Choi", 21, "Tennis" },
		{"Park", 10, "Tennis" },
	};

	struct INDEX index[5]{
		{"Kim", 0},
		{"Ko", 1},
		{"Lee", 2},
		{"Choi", 3},
		{"Park", 4}
	};

	char test_search_key[3][30] = {
		"Cha", "Lee", "Park"
	};

	int num;

	for (int i = 0; i < 3; i++) {
		num = search(test_search_key[i], index);

		printf("Key : %s\n", test_search_key[i]);
		if (num == -1)
			printf("The Key does not exist!\n\n");
		else
			printf("Index : %d, Name : %s, Age : %d, Hobby : %s\n\n", num, array[num].name, array[num].age, array[num].hobby);
	}

	return 0;
}