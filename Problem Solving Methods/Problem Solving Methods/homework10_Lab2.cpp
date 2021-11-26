#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 10

struct QUEUE {
	int buf[MAX_QUEUE_SIZE];
	int front;
	int back;
};

struct QUEUE* q = (struct QUEUE*)malloc(sizeof(struct QUEUE));
struct QUEUE Queue = *q;

bool queue_full() {
	return Queue.back >= MAX_QUEUE_SIZE - 1;
}

bool queue_empty() {
	if (Queue.front == -1 && Queue.back == -1)
		return true;

	return Queue.front > Queue.back;
}

void enqueue(int val) {
	if (queue_full()) {
		printf("enqueue() : queue is full\n");
	}
	else {
		if (Queue.back == -1 && Queue.front == -1) {
			Queue.front++;
		}
		
		Queue.back++;
		Queue.buf[Queue.back] = val;
		printf("enqueue[%d] : %d\n", Queue.back, val);
	}
}

int dequeue() {
	if (queue_empty()) {
		printf("dequeue() : queue is empty\n");
		return 0;
	}
	else {
		int val = Queue.buf[Queue.front];		
		printf("dequeue[%d] : %d\n", Queue.front, val);
		Queue.front++;
		return val;
	}
}

int main() {

	Queue = { {0,}, -1, -1 };

	int i = 1;

	while (!queue_full()) {
		enqueue(100 * i);
		i++;
	}

	while (!queue_empty()) {
		dequeue();
	}
	
	dequeue();
	enqueue(9999);

	free(q);

	return 0;
}