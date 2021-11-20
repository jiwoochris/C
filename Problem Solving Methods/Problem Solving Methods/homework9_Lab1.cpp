#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int key;
	struct NODE* next;
};

int InsertKey(int new_key, struct NODE* head, struct NODE ** address) {
	struct NODE* p = head->next, *prev = head;
	struct NODE* new_node;

	printf("Inserting key : %d\n", new_key);

	while (p) {
		if (p->key == new_key) return -1;
		if (p->key > new_key) break;
		prev = p;
		p = p->next;
	}

	new_node = (struct NODE*)malloc(sizeof(struct NODE));
	if (new_node == NULL) {
		printf("failed");
		exit(0);
	}

	new_node->key = new_key;
	prev->next = new_node;
	new_node->next = p;

	if (*address == head->next) {
		*address = NULL;
	}
	else {
		*address = head->next;
	}

	return 0;
}

void scanList(struct NODE* head) {
	struct NODE* p = head->next;
	int count = 0;

	printf("--- Traversing the linked list ---\n");

	while (p) {
		printf("node[%d] : %d\n", count, p->key);
		p = p->next;

		count++;
	}
}

int main() {
	struct NODE node[7];
	struct NODE * head = (struct NODE*)malloc(sizeof(struct NODE));

	struct NODE** first_address = (struct NODE**)malloc(sizeof(struct NODE*));

	if (head == NULL || first_address == NULL) {
		printf("failed");
		exit(0);
	}
	
	head->next = &node[0];

	node[0].key = 100;
	node[1].key = 250;
	node[2].key = 467;

	node[0].next = &node[1];
	node[1].next = &node[2];
	node[2].next = NULL;

	*first_address = &node[0];

	if (InsertKey(250, head, first_address) == 0) {
		printf("Key inserted!\n");
		if (*first_address != NULL) {
			printf("New first node created!\n");
			*first_address = (head->next);
		}
	}
	else
		printf("Key already exists!\n");
		

	if (InsertKey(300, head, first_address) == 0) {
		printf("Key inserted!\n");
		if (*first_address != NULL) {
			printf("New first node created!\n");
			*first_address = (head->next);
		}
	}
	else
		printf("Key already exists!\n");

	if (InsertKey(50, head, first_address) == 0) {
		printf("Key inserted!\n");
		if (*first_address != NULL) {
			printf("New first node created!\n");
			*first_address = (head->next);
		}
	}
	else
		printf("Key already exists!\n");

	if (InsertKey(500, head, first_address) == 0) {
		printf("Key inserted!\n");
		if (*first_address != NULL) {
			printf("New first node created!\n");
			*first_address = (head->next);
		}
	}
	else
		printf("Key already exists!\n");

	scanList(head);

	return 0;
}