#include <stdio.h>

#include <stdlib.h>

struct Node {

    int data;

    struct Node* link;

};

struct Node* front = NULL; // front is empty initially

struct Node* rear = NULL; // rear is empty initially

int n_nodes = 0; // a variable to store number of nodes in queue


int queue_empty() {

    if (n_nodes == 0)

        return 1;

    return 0;

}




void enqueue(int x) {

    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    // test if memory allocation failed

    if (temp == NULL) {

        printf("Memory allocation failed.\n");

        exit(1);

    }



    temp->data = x;

    temp->link = NULL; // temp will be added at the tail of the linked list (become rear)

    if (front == NULL && rear == NULL) {

        front = rear = temp;

        n_nodes++; // to count the number of nodes in stack

        return;

    }

    rear->link = temp; // temp added at the tail of linked list

    rear = temp; // temp becomes a new rear

    n_nodes++; // to count the number of nodes in stack

}



int dequeue() {

    struct Node* temp = front;

    int value;


    value = front->data;

    front = front->link; // make the next node front

    free(temp);

    n_nodes--; // to count the number of nodes in stack

    return value;

}



// helper function: traverse queue from front to rear and print elements

void print_queue() {

    struct Node* n;

    n = front;

    printf("queue =");

    while (n != NULL) {

        printf(" %d ", n->data);

        n = n->link;

    }

    printf("\n");

}



// helper function: run a series of enqueues

// input arguments: int arr[] <- an array from which input values are taken

// input arguments: int num <- total number of elements to push

void run_enqueues(int arr[], int num) {

    for (int i = 0; i < num; i++) {


        printf("enqueue(%d) , ", arr[i]);

        enqueue(arr[i]);

        print_queue();

    }

}



// helper function: run a series of pops

// input argument: int num <- total number of elements to pop

void run_dequeues(int num) {

    int value;

    for (int i = 0; i < num; i++) {

        printf("dequeue() ");

        if (!queue_empty()) {

            value = dequeue();

            printf("-> %d , ", value);

        }

        else {

            printf("queue empty! ");

            front = rear = NULL;


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

    run_enqueues(numbers, 11);

}