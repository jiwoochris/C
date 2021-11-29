//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct Registration {
//	int  tag;
//	char date[24];
//	char is_fee_paid[16];
//	char name[24];
//	int  age;
//	char org[35];
//	char job[15];
//
//	struct Registration* next;
//}r[30];
//
//
//
//// P7-2
//void insert_data_from_linked_list(struct Registration* head, struct Registration* person) {
//	struct Registration* p = head->next, * prev = head;
//	struct Registration* new_node;
//
//	while (p) {
//		if (p->tag > person->tag) break;
//		prev = p;
//		p = p->next;
//	}
//	new_node = (struct Registration*)malloc(sizeof(struct Registration));
//	new_node = person;
//
//	prev->next = new_node;
//	new_node->next = p;
//}