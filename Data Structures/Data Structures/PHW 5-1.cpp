#include <stdio.h>
#include <stdlib.h>
#include <string.h>	


struct node {
    char key[10];
	struct node* next;
}buckets[33];


// sum the ASCII code of each alphabet in the key, and then use the modulo function(sum % 33)
int hash(const char* input) {   

    int result = 0;
    int i = 0;

    while (input[i] != '\0') {
        result += input[i];
        i++;
    }

    result %= 33;

    return result;
}

void map(const char* data, int i) {
    struct node* p = (&buckets[i])->next, * prev = &buckets[i];

    while (p) {
        prev = p;
        p = p->next;
    }

    p = (struct node*)malloc(sizeof(struct node));
    if (p) {
        p->next = nullptr;
        strcpy(p->key, data);
        prev->next = p;
    }
}

void print_key(int i) {
    struct node* p = (&buckets[i])->next;

    if (p == nullptr) {
        printf("NULL");
    }

    while (p) {
        printf("%s \t", p->key);
        p = p->next;
    }
    printf("\n");
}

void print_table() {
    for (int i = 0; i < 33; i++) {
        printf("%d : ", i);
        print_key(i);
    }
    printf("\n\n");
}


void search_key(const char* input) {

    printf("Search for %s : ", input);

    struct node* p = (&buckets[hash(input)])->next;

    while (p) {
        if (strcmp(input, p->key) == 0) {
            printf("found\n\n");
            return;
        }
        
        p = p->next;
    }

    printf("not found\n\n");
}

void delete_key (const char* input) {
    struct node* p = (&buckets[hash(input)])->next, * prev = &buckets[hash(input)];

    printf("Delete for %s : ", input);

    while (p) {

        if (strcmp(input, p->key) == 0) {
            printf("deleted\n\n");
            prev->next = p->next;
            return;
        }

        prev = p;
        p = p->next;
    }

    printf("not found\n\n");
}

void insert_key(const char* input) {
    struct node* p = (&buckets[hash(input)])->next, * prev = &buckets[hash(input)];

    printf("Insert for %s : ", input);

    while (p) {

        if (strcmp(input, p->key) == 0) {
            printf("exists\n\n");
            return;
        }

        prev = p;
        p = p->next;
    }

    p = (struct node*)malloc(sizeof(struct node));
    if (p) {
        p->next = nullptr;
        strcpy(p->key, input);
        prev->next = p;
    }

    printf("inserted\n\n");
}


int main() {

    FILE* fp;
    fp = fopen("keyinput.txt", "r");


    char input[10] = "";

    while (fscanf(fp, "%s\n", input) == 1)
        map(input, hash(input));


    // Print the contents of the hash table (including the overflow) for each index(If the bucket is empty, print ¡°NULL¡±)
    print_table();
    

    // Search for Blue, black, Purple (print ¡°found¡± or ¡°not found¡±)
    search_key("Blue");
    search_key("black");
    search_key("Purple");
    printf("\n\n");

    // Delete Purple, Blue, Green (print ¡°deleted¡± or ¡°not found¡±)
    delete_key("Purple");
    delete_key("Blue");
    delete_key("Green");
    printf("\n\n");

    // Insert Green, White, Golden, nedloG (print ¡°exists¡± or  ¡°inserted¡±)
    insert_key("Green");
    insert_key("White");
    insert_key("Golden");
    insert_key("nedloG");
    printf("\n\n");

    // Search for Blue, nedloG, Yellow, Green (print ¡°found¡± or ¡°not  found¡±)'
    search_key("Blue");
    search_key("nedloG");
    search_key("Yellow");
    search_key("Green");
    printf("\n\n");

    // Print the contents of the final hash table (including the  overflow) for each index (If the bucket is empty, print¡°NULL¡±)
    print_table();


    fclose(fp);
    
    
	return 0;
}
