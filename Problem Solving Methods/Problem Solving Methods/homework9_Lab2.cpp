#include <stdio.h>
#include <stdlib.h>

struct NUM {
	int key;
	struct NUM* next;
};

int insert(struct NUM* head, int value) {
	struct NUM* p = head->next, *prev = head;
	int count = 0;

	while (p) {
		if (p->key == value) return -1;
		if (p->key > value) break;
		prev = p;
		p = p->next;
	}

	struct NUM* new_num = (struct NUM*)malloc(sizeof(struct NUM));
	if (new_num == NULL) {
		printf("failed to allocate!\n");
		exit(0);
	}
	new_num->key = value;
	new_num->next = p;
	prev->next = new_num;

	p = head->next;
	while (p) {
		count++;
		p = p->next;
	}
	head->key = count;

	printf("Inserting Key : %d\n", value);

	return 0;
}

void Traverse(struct NUM * head) {
	int count = 0;
	struct NUM* p;
	p = head->next;

	printf("\nTraversing the linked list...\n");

	while (p != NULL) {
		printf("node[%d] key : %d\n", count, p->key);
		p = p->next;
		count++;
	}
}

void ClearList(struct NUM* head) {
	int count = 0;
	struct NUM* p = NULL;
	struct NUM* temp = NULL;
	p = head->next;

	printf("\nDeleting the linked list...\n");

	while (p != NULL) {
		temp = p;
		p = p->next;
		free(temp);
		printf("node[%d] deleted...\n", count);
		count++;
	}

	free(head);
}

int main() {
	int nums[10] = { 17, 39, 11, 9, 42, 12, 15, 8, 13, 41 };

	struct NUM* head = (struct NUM*)malloc(sizeof(struct NUM));

	if (head == NULL) {
		printf("Failed to allocate\n");
		exit(0);
	}
	head->key = 0;
	head->next = NULL;

	for (int i = 0; i < 10; i++) {
		if (insert(head, nums[i]) == 0) {
			printf("[%d] elements, key inserted\n", head->key);
		}
		else
			printf("Key already exists!\n");
	}

	Traverse(head);

	ClearList(head);

	return 0;
}