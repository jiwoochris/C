#include <stdio.h>

bool encryption(const char* src, const char* dest, int encryption_key) {
	FILE* fread = NULL;
	FILE* fwrite = NULL;
	char fc;

	fread = fopen(src, "r");
	fwrite = fopen(dest, "w");
		
	if (fread == NULL || fwrite == NULL) {
		return false;
	}

	while ((fc = fgetc(fread)) != EOF)
		fputc(fc + encryption_key, fwrite);

	fclose(fread);
	fclose(fwrite);

	return true;
}

bool decryption(const char* src, const char* dest, int decryption_key) {
	FILE* fread = NULL;
	FILE* fwrite = NULL;
	char fc;

	fread = fopen(src, "r");
	fwrite = fopen(dest, "w");

	if (fread == NULL || fwrite == NULL) {
		return false;
	}

	while ((fc = fgetc(fread)) != EOF)
		fputc(fc - decryption_key, fwrite);

	fclose(fread);
	fclose(fwrite);

	return true;
}

int main() {

	if (!encryption("original.txt", "cypher.txt", 7)) {
		return -1;
	}

	if (!decryption("cypher.txt", "decrypted.txt", 7)) {
		return -1;
	}

	return 0;
}