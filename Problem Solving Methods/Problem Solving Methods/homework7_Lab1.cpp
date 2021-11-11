#include <stdio.h>

int main() {
	int mask = 128;

	char test_set[6] = { 'a', 'b', 'c', 'A', 'B', 'C' };

	for (int i = 0; i < 6; i++) {
		printf("%c : ", test_set[i]);
		for (int j = 0; j < 8; j++) {
			if (mask & test_set[i])
				printf("1");
			else
				printf("0");
			test_set[i] = test_set[i] << 1;
		}
		printf("\n");
	}

	return 0;
}