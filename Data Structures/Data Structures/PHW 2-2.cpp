#include <stdio.h>
#include <stdlib.h>

struct general_tree {
	int level;
	int key;
	int child_key;
};

struct binary_tree {
	int key;
	struct binary_tree* left_child;
	struct binary_tree* right_child;
};

struct binary_tree* make_binary_tree(struct general_tree input[], int num) {	// return output binary tree
	struct binary_tree* temp;
	int level = 0;	// current level

	temp = (struct binary_tree*)malloc(sizeof(struct binary_tree) * num);	// dynamic allocation depending on number of nodes in input general tree
	if (temp == NULL) {
		exit(1);
	}

	for (int i = 0; i < num; i++) {		// constructs a binary tree in sequence
		temp[i].key = input[i].key;		// insert key
		
		if (level != input[i].level) {		// if the node's level changed
			level++;		// note that we'll handle next level
			temp[i - 1].right_child = NULL;		// there's no sibling node because the level is changed
		}

		int found = 0;	// default

		for (int j = 0; j < i; j++) {
			if (input[j].level == input[i].level - 1 && input[j].child_key == input[i].key) {	// if there is a parent node
				found = 1;		// verify that we found a parent node

				temp[j].left_child = &temp[i];	// link it from parent's left child
				temp[i - 1].right_child = NULL;		// from now on, siblings will link in this node's right child. so there's no sibling in previous node.
				break;
			}
		}

		if (found == 0) {		// if couldn't find a parent node
			temp[i - 1].right_child = &temp[i];		// link it from previous node.
		}

		if (input[i].child_key == NULL) {	// if input says there's no child
			temp[i].left_child = NULL;
		}

		if (i == num - 1) {		// if it is last node
			temp[i].left_child = NULL;
			temp[i].right_child = NULL;
		}

	}

	return temp;
}

void preorder(binary_tree* ptr)		// traverse the tree (preorder)
{
	if (ptr) {
		printf("%d ", ptr->key); // visit node
		preorder(ptr->left_child);
		preorder(ptr->right_child);
	}
}

int main() {

	struct general_tree tree1[] = {
		{1, 100, 200},
		{2, 200, NULL}, {2, 75, 25}, {2, 300, NULL},
		{3, 25, NULL}, {3, 50, NULL}, {3, 30, 120}, {3, 150, NULL},
		{4, 120, NULL}, {4, 55, NULL}
	};

	struct general_tree tree2[] = {
		{1, 100, 200},
		{2, 200, NULL}, {2, 75, 25}, {2, 300, NULL}, {2, 95, 150},
		{3, 25, NULL}, {3, 50, NULL}, {3, 30, 120}, {3, 150, NULL},
		{4, 120, NULL}
	};


	binary_tree* output1 = make_binary_tree(tree1, 10);		// input : put general tree and its number of nodes
	printf("\n Tree 1 : ");
	preorder(output1);		// traverse


	binary_tree* output2 = make_binary_tree(tree2, 10);		// input : put general tree and its number of nodes
	printf("\n Tree 2 : ");
	preorder(output2);		// traverse

	printf("\n");

	return 0;
}