#include <stdio.h>

int stack[10];
int top = -1;

int stack_full() {
	if (top == 9) {
		return 1;
	}
	else
		return 0;
}

int stack_empty() {
	if (top == -1) {
		return 1;
	}
	else
		return 0;
}

void push(int p) {
	if (!stack_full()) {	// if stack is full, do nothing
		top++;
		stack[top] = p;
	}
}

int pop() {
	int t = stack[top];

	if (!stack_empty()) {	// if stack is empty, do nothing
		top--;
		return t;
	}
	return -1;
}

int main() {

	push(10);
	push(100);
	pop();
	push(15);


	for (int i = 0; i <= top; i++) {
		printf("%d\n", stack[i]);
	}

	return 0;
}