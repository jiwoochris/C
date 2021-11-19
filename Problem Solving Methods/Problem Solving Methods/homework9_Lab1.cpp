#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int key;
	struct NODE* next;
};

int InsertKey(int new_key, struct NODE* head, struct NODE ** address) {
	struct NODE* p = head->next, *prev = head;
	struct NODE* new_node;

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

	return 0;
}

void scanList(struct NODE* head) {
	struct NODE* p = head->next;

	while (p) {
		printf("%d\n", p->key);
		p = p->next;
	}
}

int main() {
	struct NODE node[7];
	struct NODE * head = (struct NODE*)malloc(sizeof(struct NODE));

	if (head == NULL) {
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

	if (InsertKey(250, head) == 0)
		printf("Success\n");

	if (InsertKey(300, head) == 0)
		printf("Success\n");

	if (InsertKey(50, head) == 0)
		printf("Success\n");

	if (InsertKey(500, head) == 0)
		printf("Success\n");

	scanList(head);

	return 0;
}