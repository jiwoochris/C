#include <stdio.h>

int main()
{
	FILE* myFile;
	char myFileName[15] = "price.txt";
	myFile = fopen(myFileName, "w");

	if (myFile == NULL) {
		printf("\nFile Could Not Be Opened");
		return - 1;
	}

	fclose(myFile);

	return 0;
}