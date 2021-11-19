#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int key;
	struct NODE* next;
};

int main() {

	struct NODE * node = NULL;

	node = (struct NODE*)malloc(10 * sizeof(struct NODE));

	if (node == (struct NODE*)NULL) {
		printf("malloc failed");
		exit(1);
	}

	for (int i = 0; i < 10; i++) {
		node[i].key = i;
		if (i == 9)
			break;
		node[i].next = &node[i + 1];
		printf("%d\n", node[i].key);
	}

	free(node);

	return 0;
}