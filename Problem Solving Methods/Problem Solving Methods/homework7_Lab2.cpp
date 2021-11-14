#include <stdio.h>

int main() {
	int mask = 1024;
	int bin = 0;
	int hex;
	int hex_num;
	char hex_char[10];

	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < 10; j++) {
			bin *= 10;
			if (i & mask)
				bin += 1;
			mask = mask >> 1;
		}
		printf("DEC : %d\tBIN : %d\t", i, bin);

		hex = i;
		hex_num = 0;
		
		for (int j = 0; j < 3; j++) {
			if (hex % 16 < 10)
				hex_char[j] = 48 + hex % 16;
			else
				hex_char[j] = 65 + (hex % 16 - 10);

			hex /= 16;
			hex_num++;
			if (hex == 0)
				break;
		}

		printf("HEX : ");
		for (int j = hex_num - 1; j >= 0; j--) {
			printf("%c", hex_char[j]);
		}
		printf("\n");
		mask = 1024;
		bin = 0;
	}

	return 0;
}