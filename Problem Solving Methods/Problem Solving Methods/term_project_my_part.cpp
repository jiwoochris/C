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

// P3-1
void sort_array_data(struct Registration r[]) {
	int arr_length = sizeof(r) / sizeof(struct Registration);
	int min, min_index;
	struct Registration temp;

	

	for (int i = 0; i < arr_length; i++) {
		min = r[i].tag;
		min_index = i;

		for (int j = i; j < arr_length; j++) {
			if (min > r[i].tag) {
				min = r[i].tag;
				min_index = i;
			}
		}

		temp = r[min_index];
		r[min_index] = r[i];
		r[i] = temp;
	}
}

// P6-1
void remove_data_from_array(struct Registration r[], int * length, const char * dest_name) {
	struct Registration temp;
	int arr_length = *length;

	for (int i = 0; i < arr_length; i++) {
		if (strcmp(r[i].name, dest_name) == 0) {
			r[i].tag = 0;
			(*length)--;
		}
	}

	for (int i = 0; i < arr_length; i++) {
		if (r[i].tag == 0) {
			for (int j = 0; j < arr_length; j++) {
				if (r[j].tag != 0) {
					temp = r[j];
					r[j] = r[i];
					r[i] = temp;
					break;
				}
			}
		}
	}
}

// P6-2
void remove_data_from_array(struct Registration* head, const char* dest_name) {
	struct Registration* p = head->next, * prev = head;

	while (p) {
		if (strcmp(p->name, dest_name) == 0) {
			prev->next = p->next;
			free(p);
		}
		prev = p;
		p = p->next;
	}
}