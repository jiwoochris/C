#include <stdio.h>
#include <stdlib.h>
#include <string.h>



 P6-1
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

 P6-2
void remove_data_from_linked_list(struct Registration* head, const char* dest_name) {
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