#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define RMAX 100
#define MAX 200

typedef struct node		// node of binary tree
{
	int data;
	struct node* left, * right;
	int ht;
}node;

int height(node* T)		// height of tree
{
	int lh, rh;
	if (T == NULL)
		return(0);

	if (T->left == NULL)
		lh = 0;

	else
		lh = 1 + T->left->ht;

	if (T->right == NULL)
		rh = 0;

	else
		rh = 1 + T->right->ht;

	if (lh > rh)
		return(lh);

	return(rh);
}

node* rotateright(node* x)
{
	node* y;

	y = x->left;
	x->left = y->right;
	y->right = x;

	x->ht = height(x);
	y->ht = height(y);

	return(y);
}

node* rotateleft(node* x)
{
	node* y;

	y = x->right;
	x->right = y->left;
	y->left = x;

	x->ht = height(x);
	y->ht = height(y);

	return(y);
}

node* RR(node* T)
{
	T = rotateleft(T);

	return(T);
}

node* LL(node* T)
{
	T = rotateright(T);

	return(T);
}

node* LR(node* T)
{
	T->left = rotateleft(T->left);
	T = rotateright(T);

	return(T);
}

node* RL(node* T)
{
	T->right = rotateright(T->right);
	T = rotateleft(T);

	return(T);
}

int BF(node* T)		// Balance Factor
{
	int lh, rh;
	if (T == NULL)
		return(0);

	if (T->left == NULL)
		lh = 0;

	else
		lh = 1 + T->left->ht;

	if (T->right == NULL)
		rh = 0;
	else
		rh = 1 + T->right->ht;

	return(lh - rh);
}

node* insert(node* T, int x)		// Insert node
{
	if (T == NULL)		// allocate and insert in empty address
	{
		T = (node*)malloc(sizeof(node));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
	}

	else
		if (x > T->data) // insert in right subtree
		{
			T->right = insert(T->right, x);

			if (BF(T) == -2)
				if (x > T->right->data)
					T = RR(T);
				else
					T = RL(T);
		}
		else {
			if (x < T->data) {
				T->left = insert(T->left, x);

				if (BF(T) == 2)
					if (x < T->left->data)
						T = LL(T);
					else
						T = LR(T);
			}
		}

	T->ht = height(T);

	return(T);
}

void preorder(node* T)
{
	if (T != NULL)
	{
		printf("%d(Bf=%d) ", T->data, BF(T));

		preorder(T->left);

		preorder(T->right);
	}
}

void inorder(node* T)
{
	if (T != NULL)
	{
		inorder(T->left);

		printf("%d(Bf=%d) ", T->data, BF(T));

		inorder(T->right);
	}
}

void postorder(node* T)
{
	if (T != NULL)
	{
		inorder(T->left);

		inorder(T->right);

		printf("%d(Bf=%d) ", T->data, BF(T));
	}
}

int count_num(node* T, int* num)		// Whenever visiting node, num++ for counting number of tree
{
	if (T != NULL)
	{
		(*num)++;

		count_num(T->left, num);

		count_num(T->right, num);
	}

	return *num;
}

int count_tree(node* T)		// declare int num and call count_num function
{
	int num = 0;

	count_num(T, &num);

	return num;
}

void add_random_number(int list[], int num) {		// add random number to list
	int random_num;
	srand(time(NULL));

	for (int i = 2; i < num + 2; i++) {
		random_num = 1 + (int)rand() % RMAX;
		list[i] = random_num;
	}
}

node* list_to_tree(node* T, int list[]) {		// insert keys in list to tree				// 이거 void로 바꾸면 왜 작동 안하는지 궁금
	int i = 0;

	while (count_tree(T) < 50 && i < 200) {		// count number of nodes in tree, for inserting first 50 unique keys
		T = insert(T, list[i]);
		i++;
	}

	return T;
}

void search(node* T, int x)
{
	if (T == NULL)
		printf("Search : Couldn't find %d\n\n", x);

	else {
		if (x > T->data)
			search(T->right, x);

		else if (x < T->data)
			search(T->left, x);

		else
			printf("Search : Found the key => %d\n\n", T->data);
	}
}

void search_highest_key(node* T)
{
	if (T == NULL)
		printf("There's no node in this tree");

	else {
		while (T->right != NULL) {
			T = T->right;
		}

		printf("The highest key : %d\n\n", T->data);
	}
}

void search_less_than(node* T, int x) {

	if (T != NULL) {

		search_less_than(T->left, x);

		if (T->data < x)
			printf("%d ", T->data);

		search_less_than(T->right, x);

	}
}

void search_greater_than(node* T, int x) {

	if (T != NULL) {

		search_greater_than(T->left, x);

		if (T->data > x)
			printf("%d ", T->data);

		search_greater_than(T->right, x);

	}
}

void search_between(node* T, int x, int y) {

	if (T != NULL) {

		search_between(T->left, x, y);

		if (T->data > x && T->data < y)
			printf("%d ", T->data);

		search_between(T->right, x, y);

	}
}


int main() {
	node* root = NULL;
	int list[MAX] = { 15, 50, };

	add_random_number(list, 198);

	root = list_to_tree(root, list);

	printf("Inorder traverse : \n");
	inorder(root);

	printf("\n\nPreorder traverse : \n");
	preorder(root);

	printf("\n\nPostorder traverse : \n");
	postorder(root);
	printf("\n\n");


	search(root, 15);
	search(root, 20);
	search(root, 50);
	search(root, 70);
	search(root, 90);

	search_highest_key(root);

	printf("all keys < 15 : ");
	search_less_than(root, 15);

	printf("\n\nall keys > 50 : ");
	search_greater_than(root, 50);

	printf("\n\nall keys between 15 and 50 : ");
	search_between(root, 15, 50);

	return 0;
}