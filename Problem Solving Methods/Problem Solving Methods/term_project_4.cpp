#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Registration {
	int tag;
	char date_registered[25];
	char name[25];
	int age;
	char organization[35];
	char job[15];

	struct Registration* next;
}r[5];

//4-1 
void InsertKey(struct Registration r[])
{
	struct Registration* node = NULL, * ptr = NULL;
	for (int i = 0; i < 30; i++) {
		node = (struct Registration*)malloc(sizeof(struct Registration)); // make new node
		while (ptr) {
			if (i == 0) // store first node
			{
				ptr = node;
				node = &r[i];
				node->next = NULL;
			}
			else {
				ptr->next = node;
				node = &r[i];
				node->next = NULL;
				ptr = ptr->next;
			}
		}
	}
}
void Selection_sort(struct Registration r[])
{
	int cursor = 0;
	int min=7;
	for (int i = 0; i < 30; i++) {
		int temp;
		for (int j = cursor; j < 30; j++) {
			int age_group = r[i].age / 10;
			if (age_group < min) {
				min = r[i].age;
			}
		}
		temp = r[cursor].age;
		r[cursor].age = min;
		r[i].age = temp;
		min= r[i].age / 10;
		cursor++;
	}
}
//8-1
void Check_sum(struct Registration* data)
{
	int checksum_org = 0;      // the original checksum
	int checksum_copy = 0;     // the copied checksum
	char namechar;
	char ch;

	for (int i = 26; i <= 30; i++) {
		for (int j = 0; data[i].name[j] != '\0'; j++) {
			ch = data[i].name[j];
			checksum_org ^= (int)ch;           // The value of original checksum
		}
	}
	FILE* myFile;
	myFile = fopen("8-1.txt", "w");

	fprintf(myFile, "%0x\n", checksum_org);
	for (int k = 20; k <= 30; k++) {
		fprintf(myFile, "%s\n", data[k].name); // write the last 10 name to the txt file 
	}

	fclose(myFile);

	myFile = fopen("8-1.txt", "r");

	fscanf(myFile, "%0x", &checksum_org);
	printf("%0x", checksum_org);

	fseek(myFile, 2, SEEK_CUR);    // The size of '\n' is 2byte, so move to the next line

	namechar = fgetc(myFile);
	while (namechar != EOF) {         // read the txt file and print the result
		if (namechar == '\0') {
			fseek(myFile, 2, SEEK_CUR);
		}
		putchar(namechar);
		checksum_copy ^= (int)namechar;
		namechar = fgetc(myFile);
	}

	printf("First checksum : %0x\n", checksum_org);
	printf("Second checksum : %0x\n", checksum_copy);

	if (checksum_org == checksum_copy) {                         // compare the original checksum with the copied checksum
		printf("Checksum is same. \n");
	}

	fclose(myFile);
}
