#include <stdio.h>

struct STACK {
	int buf[10];
	int top;
} Stack = { {0,}, -1 };

bool stack_full() {

	return Stack.top >= 9;
}

bool stack_empty() {

	return Stack.top < 0;
}

void push(const int value) {
	if (!stack_full()) {
		Stack.top++;
		Stack.buf[Stack.top] = value;
		printf("push[%d]: %d\n", Stack.top, value);
	}
	else {
		printf("push(): Stack is Full\n");
	}
}

int pop() {
	if (!stack_empty()) {
		int value = Stack.buf[Stack.top];
		Stack.buf[Stack.top] = NULL;
		printf("pop[%d]: %d\n", Stack.top, value);
		Stack.top--;
		
		return value;
	}
	else {
		printf("pop(): Stack is Empty\n");
		return 0;
	}
}

int main() {

	for (int i = 0; i < 20; i++) {
		push(200);
	}


	push(100);
	push(200);
	pop();
	pop();
	pop();
	

	return 0;
}