#include <stdio.h>
#include <string.h>
#define TESTSET 5

int exact_match(char search[], char string[]) {
	int count = 0;
	int exact = 1;

	for (int i = 0; i < strlen(string); i++) {
		if (string[i] == search[0]) {
			exact = 1;

			for (int j = 0; j < strlen(search); j++) {
				if (string[i + j] != search[j])
					exact = -1;
			}

			if (exact == 1)
				count += 1;
		}
	}

	return count;
}

int partial_match(char search[], char string[]) {
	int count = 0;
	int exact = 1;
	int partial = -1;

	int wildcard = 0;

	for (int i = 0; i < strlen(search); i++) {
		if (search[i] == '*')
			wildcard = i;
	}



	for (int i = 0; i < strlen(string); i++) {
		if (partial == -1) {
			if (string[i] == search[0]) {
				exact = 1;

				for (int j = 0; j < wildcard; j++) {
					if (string[i + j] != search[j])
						exact = -1;
				}

				if (exact == 1) {
					partial = 1;
				}
			}
		}

		else if (partial == 1) {
			if (string[i] == search[wildcard + 1]) {
				exact = 1;

				for (int j = 0; j < strlen(search) - wildcard - 1; j++) {
					if (string[i + j] != search[wildcard + 1 + j])
						exact = -1;
				}

				if (exact == 1) {
					count += 1;
					partial = -1;
				}
			}
		}

		else
			return -1;
	}

	return count;
}

int match(char search[], char string[]) {
	int matches = 0;
	int partial = 0;

	for (int i = 0; i < strlen(search); i++) {
		if (search[i] == '*')
			partial = 1;
	}

	if (partial == 0)
		matches = exact_match(search, string);
	else if (partial == 1)
		matches = partial_match(search, string);
	else
		return -1;

	return matches;
}

int main() {
	char string[TESTSET][256] = {
		"hello mister monkey",
		"hello mister monkey",
		"hello mister monkey",
		"hong hong dong dong",
		"My name is hong gil dong. My brother is hong je dong. My sister is hong gilja,and her friend is hongdong."
	};

	char search_string[TESTSET][128] = {
			"money",
			"mon*ey",
			"m*y",
			"hong*dong",
			"hong*dong"
	};


	for (int i = 0; i < TESTSET; i++) {
		printf("\n String : %s", string[i]);
		printf("\n Search : %s", search_string[i]);
		printf("\n Num matches : %d", match(search_string[i], string[i]));
		printf("\n");
	}

	return 0;
}