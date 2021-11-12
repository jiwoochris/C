#include <stdio.h>

int main() {
	int mask = 1024;
	int bin = 0;

	for (int i = 1; i <= 1000; i++) {
		printf("DEC : %d\tBIN : ", i);
		for (int j = 0; j < 10; j++) {
			bin *= 10;
			if (i & mask)
				bin += 1;
			mask = mask >> 1;
		}
		printf("%d\tHEX : %X\n", bin, i);
		mask = 1024;
		bin = 0;
	}


	return 0;
}