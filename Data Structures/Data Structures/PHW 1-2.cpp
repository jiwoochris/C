#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10 

// global variables
struct STACK {
    int p;
    struct STACK* next;
}stack[MAX_SIZE];
int top = -1;

int stack_full(struct STACK s) {
    struct STACK* p = s.next;
    int num = -1;

    while (p) {
        num++;
        if (p->next == NULL)
            break;
        p = p->next;
    }

    if (num >= MAX_SIZE - 1)
        return 1;
    return 0; // return 0 only if the above condition is false
}

int stack_empty(struct STACK s) {
    struct STACK* p = s.next;
    
    if (p->next == NULL)
        return 1;
    return 0; // return 0 only if the above condition is false
}

void push(int x, struct STACK s) {
    struct STACK* p = s.next, *prev = &s;
    int num = -1;

    while (p) {
        num++;
        if (p->next == NULL)
            break;
        prev = p; 
        p = p->next;
    }

    prev = p;
    p = p->next;

    struct STACK* n = (struct STACK*)malloc(sizeof(struct STACK));
    p->next = n;
    n->p = x;
    n->next = NULL;
}

int pop(struct STACK* s) {
    struct STACK* p = s->next, *prev = s;

    while (p) {
        
    }

    int temp = stack[top];
    top--;
    return temp;
}

// helper function: print the current stack
void print_stack() {
    printf("stack = ");
    for (int i = 0; i <= top; i++)
        printf(" %d", stack[i]);
    printf(" (top=%d)\n", top);
}

// helper function: run a series of pushes
// input arguments: int arr[] <- an array from which input values are taken
// input arguments: int num <- total number of elements to push
void run_pushes(int arr[], int num) {
    for (int i = 0; i < num; i++) {
        printf("push(%d) , ", arr[i]);
        if (!stack_full()) { // if stack is not full (!1 = 0)
            push(arr[i]);
        }
        else {
            printf("stack full! ");
        }
        print_stack();
    }
}

// helper function: run a series of pops
// input argument: int num <- total number of elements to pop
void run_pops(int num) {
    int value;
    for (int i = 0; i < num; i++) {
        printf("pop() ");
        if (!stack_empty()) { // if stack is not empty (!1 = 0)
            value = pop();
            printf("-> %d , ", value);
        }
        else {
            printf("stack empty! ");
        }
        print_stack();
    }
}

int main() {
    struct STACK head;
    head.next = NULL;



    int numbers[] = { 3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8 };

    print_stack();
    run_pushes(numbers, 5);
    run_pops(3);
    run_pushes(numbers, 10);
    run_pops(11);
}
