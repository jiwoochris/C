#include <stdio.h>
#define MAX_SIZE 10

// global variables
int queue1[MAX_SIZE]; // main queue that represents stack
int front1 = -1;
int rear1 = -1;

int queue2[MAX_SIZE]; // sub queue for queue1
int front2 = -1;
int rear2 = -1;

int queue1_full() {
    if (rear1 >= MAX_SIZE - 1)
        return 1;
    return 0; // return 0 only if the above condition is false
}

int queue1_empty() {
    if (front1 == -1 || front1 > rear1) // front cannot be greater than rear
        return 1;
    return 0; // return 0 only if the above condition is false
}

int queue2_full() {
    if (rear2 >= MAX_SIZE - 1)
        return 1;
    return 0; // return 0 only if the above condition is false
}

int queue2_empty() {
    if (front2 == -1 || front2 > rear2) // front cannot be greater than rear
        return 1;
    return 0; // return 0 only if the above condition is false
}

void enqueue1(int x) {
    rear1++;
    queue1[rear1] = x;
    if (front1 == -1) // increase front only initially
        front1++;
}

int dequeue1() {
    int temp = queue1[front1];
    front1++;
    return temp;
}

void enqueue2(int x) {
    rear2++;
    queue2[rear2] = x;
    if (front2 == -1) // increase front only initially
        front2++;
}

int dequeue2() {
    int temp = queue2[front2];
    front2++;
    return temp;
}

// helper function: print the current queue
void print_stack() {
    printf("queue1 = ");
    for (int i = 0; i <= rear1; i++)
        printf(" %d", queue1[i]);
    printf(" (front=%d, rear=%d   i.e. top=%d) \n", front1, rear1, rear1);
}

// helper function: run a series of enqueues
// input arguments: int arr[] <- an array from which input values are taken
// input arguments: int num <- total number of elements to enqueue
void run_pushes(int arr[], int num) { // just enqueue queue1
    for (int i = 0; i < num; i++) {
        printf("push(%d) , ", arr[i]);
        if (!queue1_full()) { // if queue is not full (!1 = 0)
            enqueue1(arr[i]);
        }
        else {
            printf("queue1 full! ");
        }
        print_stack();
    }
}

// helper function: run a series of dequeues
// input argument: int num <- total number of elements to dequeue
void run_pops(int num) {
    int value;
    int stack_num;
    for (int i = 0; i < num; i++) {
        printf("pop() ");
        if (!queue1_empty()) { // if queue is not empty (!1 = 0)
            stack_num = rear1 - front1 + 1;

            for (int i = 0; i < stack_num; i++) {
                value = dequeue1();
                enqueue2(value);
            }

            front1 = -1;    // Reinitialize queue1
            rear1 = -1;

            for (int i = 0; i < stack_num; i++) {
                value = dequeue2();
                if (i < stack_num - 1)
                    enqueue1(value);
            }

            front2 = -1;  // Reinitialize queue2
            rear2 = -1;

            printf("-> %d , ", value);
        }
        else {
            printf("stack empty! ");
        }
        print_stack();
    }
}

int main() {
    int numbers[] = { 3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8 };

    print_stack();
    run_pushes(numbers, 5);
    run_pops(3);
    run_pushes(numbers, 10);
    run_pops(11);
    run_pushes(numbers, 3);
}
