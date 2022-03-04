#include <stdio.h>

int queue[10];
int front = -1;
int rear = -1;

int queue_full() {
	if (rear == 9) {
		return 1;
	}
	else
		return 0;
}

int queue_empty() {
	if (rear - front == -1 || front == -1) {	// if rear - front == -1, queue is empty, or front == -1, queue is initial statement
		return 1;
	}
	else
		return 0;
}

void enqueue(int p) {
	if (!queue_full()) {	// if queue is full, do nothing
		if (front == -1)	// if queue is intital statement
			front++;
		rear++;
		queue[rear] = p;
	}
}

int dequeue() {
	if (!queue_empty()) {	// if queue is empty, do nothing
		int f = queue[front];
		front++;

		return f;
	}
	return -1;
}

int main() {

	enqueue(10);
	enqueue(100);
	dequeue();
	enqueue(15);

	for (int i = front; i <= rear - front + 1; i++) {
		printf("%d\n", queue[i]);
	}

	return 0;
}