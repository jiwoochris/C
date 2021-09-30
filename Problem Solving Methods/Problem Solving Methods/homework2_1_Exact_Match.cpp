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

int main() {
	char string[TESTSET][256] = {
		"A thief named hong gil dong lived with friends named hong gil don and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gil dong village.",
		"A thief named hong gil dong lived with friends named hong gil don and hong gil ja and hhhong gil dong and kong gil dong and honggil dong and hong gil donggg in a village named hong gil dong village.",
		"hello mister monkey",
		"hello mister monkey",
		"My name is hong gil dong. My brother is hong je dong. My sister is hong gilja,and her friend is hongdong."
	};

	char search_string[TESTSET][128] = {
			"hong gil dong",
			"hong gil",
			"money",
			"monkey",
			"is"
	};

	for (int i = 0; i < TESTSET; i++) {
		printf("\n String : %s", string[i]);
		printf("\n Search : %s", search_string[i]);
		printf("\n Num matches : %d", exact_match(search_string[i], string[i]));
		printf("\n");
	}
	

	return 0;
}