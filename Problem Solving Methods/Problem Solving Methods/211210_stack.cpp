#include <stdio.h>
#include <stdlib.h>

struct STACK {
	int size;
	int top;
	int* buffer;

	STACK(const int);
	~STACK();

	void push(int);
	int pop();
	bool stack_full();
	bool stack_empty();
};

STACK::STACK(const int size_) {
	size = size_;
	top = -1;
	buffer = (int*)malloc(size * sizeof(int));
}

STACK :: ~STACK() {
	free(buffer);
}

void STACK :: push(int key) {
	if (stack_full()) {
		return;
	}
	else {
		top++;

		buffer[top] = key;
	}
}

int STACK::pop() {
	if (stack_empty()) {
		return 0;
	}
	else {
		top--;
		return buffer[top + 1];
	}
}

bool STACK::stack_full() {
	return top > size - 1;
}

bool STACK::stack_empty() {
	return top < 0;
}

int main() {

	struct STACK s = STACK(10);

	s.push(10);
	s.push(40);
	printf("%d", s.pop());

	return 0;
}