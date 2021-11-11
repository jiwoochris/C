#include <stdio.h>

int main() {
	int test_set[10] = { 1, 10, 11, 12, 30, 80, 258, 809, 900, 999 };
	int mask = 128;
	int bin = 0;

	for (int i = 0; i < 10; i++) {
		printf("DEC : %d\tBIN : ", test_set[i]);
		for (int j = 0; j < 8; j++) {
			bin *= 10;
			if (test_set[i] & mask)
				bin += 1;
			mask = mask >> 1;
		}
		printf("%d\tHEX : %X\n", bin, test_set[i]);
		mask = 128;
		bin = 0;
	}


	return 0;
}