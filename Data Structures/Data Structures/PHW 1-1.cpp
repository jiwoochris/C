#include <stdio.h>
#define MAX_SIZE 5

// global variables
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int queue_full() {
    if (front % MAX_SIZE == rear % MAX_SIZE + 1)
        return 1;
    return 0; // return 0 only if the above condition is false
}

int queue_empty() {
    if (front == rear == -1) // front cannot be greater than rear
        return 1;
    return 0; // return 0 only if the above condition is false
}

void enqueue(int x) {
    rear++;
    rear %= MAX_SIZE;
    queue[rear] = x;
    if (front == -1) // increase front only initially
        front++;
}

int dequeue() {
    int temp = queue[front];
    front++;
    front %= MAX_SIZE;
    return temp;
}

// helper function: print the current queue
void print_queue() {
    printf("queue = ");
    for (int i = front; i <= rear; i++)
        printf(" %d", queue[i]);
    printf(" (front=%d, rear=%d)\n", front, rear);
}

// helper function: run a series of enqueues
// input arguments: int arr[] <- an array from which input values are taken
// input arguments: int num <- total number of elements to enqueue
void run_enqueues(int arr[], int num) {
    for (int i = 0; i < num; i++) {
        printf("enqueue(%d) , ", arr[i]);
        if (!queue_full()) { // if queue is not full (!1 = 0)
            enqueue(arr[i]);
        }
        else {
            printf("queue full! ");
        }
        print_queue();
    }
}

// helper function: run a series of dequeues
// input argument: int num <- total number of elements to dequeue
void run_dequeues(int num) {
    int value;
    for (int i = 0; i < num; i++) {
        printf("dequeue() ");
        if (!queue_empty()) { // if queue is not empty (!1 = 0)
            value = dequeue();
            printf("-> %d , ", value);
        }
        else {
            printf("queue empty! ");
        }
        print_queue();
    }
}

int main() {
    int numbers[] = { 3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8 };

    print_queue();
    run_enqueues(numbers, 5);
    run_dequeues(3);
    run_enqueues(numbers, 10);
    run_dequeues(11);
    run_enqueues(numbers, 3);
}
