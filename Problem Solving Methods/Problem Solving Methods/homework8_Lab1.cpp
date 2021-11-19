#include <stdio.h>

struct ADDRESS {
	char first[4];
	char second[5];
}address[1000];

bool compress(const char src[20], const char dest[20]) {
	FILE* fread = NULL;
	FILE* fwrite = NULL;

	fread = fopen(src, "r");
	fwrite = fopen(dest, "w");

	if (fread == NULL || fwrite == NULL) {
		return false;
	}

	while (fscanf(fread, "%s - %s   ", address[0].first, address[0].second) == 2) {
		fprintf(fwrite, "%s%s ", address[0].first, address[0].second);
	}

	fclose(fread);
	fclose(fwrite);

	return true;
}

bool decompress(const char src[20], const char dest[20]) {
	FILE* fread = NULL;
	FILE* fwrite = NULL;

	fread = fopen(src, "r");
	fwrite = fopen(dest, "w");

	if (fread == NULL || fwrite == NULL) {
		return false;
	}

	char src_address[10];

	while (fscanf(fread, "%s ", src_address) == 1) {
		for (int i = 0; i < 3; i++) {
			fprintf(fwrite, "%c", src_address[i]);
		}
		fprintf(fwrite, " - ");
		for (int i = 3; i < 7; i++) {
			fprintf(fwrite, "%c", src_address[i]);
		}
		fprintf(fwrite, "   ");
	}

	fclose(fread);
	fclose(fwrite);

	return true;
}

int main() {
	
	if (!compress("address.txt", "compressed.txt")) {
		return -1;
	}
	
	if (!decompress("compressed.txt", "decompressed.txt")) {
		return -1;
	}

	return 0;
}