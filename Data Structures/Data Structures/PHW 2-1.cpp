#include <stdio.h>

#include <stdlib.h>

struct Node {

    int data;

    struct Node* link;

};

struct Node* front = NULL; // front is empty initially

int n_nodes = 0; // a variable to store number of nodes in stack


int stack_empty() {

    if (n_nodes == 0)

        return 1;

    return 0;

}




void push(int x) {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    struct Node* p = front, * prev = NULL;

    // test if memory allocation failed

    if (temp == NULL) {

        printf("Memory allocation failed.\n");

        exit(1);

    }

    temp->data = x;
    temp->link = NULL; // temp will be added at the tail of the linked list (become rear)

    if (front == NULL) {

        front = temp;

        n_nodes++; // to count the number of nodes in stack

    }
    else {
        while (p) {     // traverse stack from front
            prev = p;
            p = p->link;
        }
        prev->link = temp;   // temp added at the tail of linked list

        n_nodes++; // to count the number of nodes in stack
    }
}



int pop() {

    struct Node* p = front, * prev = NULL;

    int value;

    while (p->link) {        // traverse stack from front
        prev = p;
        p = p->link;
    }

    value = p->data;

    if (prev == NULL) {
        front = NULL;
    }
    else {
        prev->link = NULL;
        free(p);
    }

    n_nodes--; // to count the number of nodes in stack

    return value;
}



// helper function: traverse stack from front to rear and print elements

void print_stack() {

    struct Node* n;

    n = front;

    printf("stack =");

    while (n != NULL) {

        printf(" %d ", n->data);

        n = n->link;

    }

    printf("\n");

}



// helper function: run a series of pushs

// input arguments: int arr[] <- an array from which input values are taken

// input arguments: int num <- total number of elements to push

void run_push(int num) {

    /*printf("push(%d) , ", num);*/

    push(num);

    /*print_stack();*/
}



// helper function: run a series of pops

// input argument: int num <- total number of elements to pop

void run_pop() {

    int value;
    
    /*printf("pop() ");*/
    
    if (!stack_empty()) {       // if stack is not empty
        value = pop();

        printf("%d ", value);
        
        /*printf("-> %d , ", value);*/
    }
    
    else {
        
        /*printf("stack empty! ");*/
        
        front = NULL;
    
    }
    
    /*print_stack();*/

}

void decimal_to_binary(int num) {       // convert decimal number to binary number
    int input = num;
    do {
        run_push(num % 2);
        num = num / 2;
    } while (num != 0);

    printf("%d => ", input);

    while (front != NULL) {         // pop elements until the stack is empty
        run_pop();
    }

    printf("\n");
}


int main() {
    int test_set[] = { 0, 233, 1000, 4, 2048 };

    for (int i = 0; i < 5; i++) {
        decimal_to_binary(test_set[i]);
    }
    
}