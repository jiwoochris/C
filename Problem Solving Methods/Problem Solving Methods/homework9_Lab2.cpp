#include <stdio.h>
#include <stdlib.h>

struct NUM {
	int key;
	struct NUM* next;
};

void insert(struct NUM* head, int value) {
	struct NUM* p = head->next;
	struct NUM* prev = head;

	while (p) {	
		if (p->key > value) break;
		prev = p;
		p = p->next;
	}

	struct NUM* new_num = (struct NUM*)malloc(sizeof(struct NUM));
	new_num->key = value;
	new_num->next = p;
}

int main() {
	int nums[10] = { 17, 39, 11, 9, 42, 12, 15, 8, 13, 41 };

	struct NUM* head = (struct NUM*)malloc(sizeof(struct NUM));

	for (int i = 0; i < 10; i++) {
		insert(head, i);
	}

	struct NUM* p;
	p = head;

	while (head != NULL) {
		printf("%d\n", p->key);
		p = p->next;
	}

	return 0;
}