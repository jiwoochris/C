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
    if (front == -1 && rear == -1) // empty only if front == rear == -1
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
    if (front == rear) { // if there is only one element in this circular queue, reinitialize queue
        front = -1;
        rear = -1;
        return temp;
    }

    front++;
    front %= MAX_SIZE;
    return temp;
}

// helper function: print the current queue
void print_queue() {
    printf("queue = ");
    if (front == -1 && rear == -1) {
        printf("");
    }
    else if (front <= rear) {    // if front <= rear, same as normal queue
        for (int i = 0; i <= rear - front; i++)
            printf(" %d", queue[front + i]);
    }
    else {  // if not
        for (int i = 0; i <= 5 + rear - front; i++)
            printf(" %d", queue[(front + i) % MAX_SIZE]);
    }
    
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
    int list1[] = { 10, 50, 20, 70};
    int list2[] = { 100, 40, 140 };


    print_queue();
    run_enqueues(list1, 4);
    run_dequeues(1);
    run_enqueues(list2, 3);
    run_dequeues(3);


    printf("-------------------- empty queue test --------------------\n");
    run_dequeues(3);
    run_enqueues(list1, 4);
}
