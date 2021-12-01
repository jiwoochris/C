/*
 * @brief Problem Solving Methods Finals Term Project
 * 
 * @todo set up for linkd list
 * 
 * @todo (남종수) 1-2. search for "Choi". (linked list)
 *
 * @todo (남종수) 2-2. search for "Gachon University". (linked list)
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTRATION_NUM 50

/* Registration Structure (Array) */
struct REGISTRATION_arr
{
    int tag;
    char date[15];
    char is_fee_paid[5];
    char name[25];
    int age;
    char org[35];
    char job[15];
};

struct REGISTRATION_ll
{
    int tag;
    char date[15];
    char is_fee_paid[5];
    char name[25];
    int age;
    char org[35];
    char job[15];
    struct REGISTRATION_ll* next;
};

bool store_in_arr(const char* file_name, struct REGISTRATION_arr arr[], int * arr_length);  // set up
bool store_in_ll(const char* file_name, struct REGISTRATION_ll * head);  // set up

void search_name_in_arr(const char* search_key, struct REGISTRATION_arr arr[], const int arr_length);   // (남종수) 1-1. search for "Choi". (array)
void search_name_in_ll(const char* search_key, struct REGISTRATION_ll* head);   // (남종수)1 - 2. search for "Choi". (linked list)
void search_org_in_arr(const char* search_key, struct REGISTRATION_arr arr[], const int arr_length);    // (남종수) 2-1. search for "Gachon University". (array)
void search_org_in_ll(const char* search_key, struct REGISTRATION_ll* head);    // (남종수) 2-2. search for "Gachon University". (linked list)
void sort_arr(struct REGISTRATION_arr arr[], const int arr_length);   // (정지우) 3-1. sort age in tag order.
void sort_ll(REGISTRATION_ll* new_head, struct REGISTRATION_arr arr[]);    // (남소미) 4-1. create linked list using sorted data.

void Selection_sort(struct REGISTRATION_arr arr[], const int arr_length);    // Self study
bool write_sorted_data(const char* new_file_name, struct REGISTRATION_arr arr[], const int arr_length);  // (남종수) 5-1. write sorted data to text file.
void remove_data_from_arr(const char* remove_key, struct REGISTRATION_arr arr[], int* arr_length);  // (정지우) 6-1. remove all "Choi" data. (array)
void remove_data_from_ll(const char* remove_key, struct REGISTRATION_ll* head);     // (정지우) 6-2. remove all "Choi" data. (linked list)

void insert_data_to_arr(struct REGISTRATION_arr* new_person, struct REGISTRATION_arr arr[], int* arr_length);   // (권혜민) 7-1. add student "Paik" to data. (array)
void insert_data_to_ll(struct REGISTRATION_ll* new_person, struct REGISTRATION_ll* head);   // (권혜민) 7-2. add student "Paik" to data. (linked list)

bool check_sum(struct REGISTRATION_arr arr[], const int arr_length);    // (남소미) 8-1. copy the most recent data and write text file. (array)

void print_arr(struct REGISTRATION_arr arr[], const int arr_length);
void print_ll(struct REGISTRATION_ll* head);

int main() {
    const char* file_name = "registraion_data.txt";

    struct REGISTRATION_arr registration[MAX_REGISTRATION_NUM];
    int arr_length;

    struct REGISTRATION_ll * head = NULL;

    if (!store_in_arr(file_name, registration, &arr_length))
    {
        printf("Error\n");
        return -1;
    }

    /*if (!store_in_ll(file_name, head))
    {
        printf("Error\n");
        return -1;
    }*/

    //search_name_in_arr("Choi", registration, arr_length);
    ///*search_name_in_ll("Choi", head);*/

    //search_org_in_arr("Gachon University", registration, arr_length);
    ///*search_org_in_ll("Gachon University", head);*/
    

    sort_arr(registration, arr_length);

    struct REGISTRATION_ll* new_head = (struct REGISTRATION_ll*)malloc(sizeof(struct REGISTRATION_ll));
    if (new_head == NULL) {
        printf("Error\n");
        return -1;
    }

    sort_ll(new_head, registration);

    Selection_sort(registration, arr_length);

    const char* new_file_name = "sorted_registraion_data.txt";
    if (!write_sorted_data(new_file_name, registration, arr_length))
    {
        printf("Error\n");
        return -1;
    }

    remove_data_from_arr("Choi", registration, &arr_length);
    remove_data_from_ll("Choi", new_head);

    print_ll(new_head);

    struct REGISTRATION_arr new_person_arr = { 33, "2020-11-30", "yes", "Gildong Paik", 35, "Gachon University", "Student" };
    struct REGISTRATION_ll new_person_ll = { 33, "2020-11-30", "yes", "Gildong Paik", 35, "Gachon University", "Student", NULL};

    insert_data_to_arr(&new_person_arr, registration, &arr_length);
    insert_data_to_ll(&new_person_ll, new_head);

    if (check_sum(registration, arr_length)) {
        printf("Two data are the same\n");
    }

    return 0;
}


/* Data Preprocessing (Store File in Array) */
bool store_in_arr(const char* file_name, struct REGISTRATION_arr arr[], int* arr_length)
{
    printf("\t\t\t\t\t\t\tStoring File\n");

    // declare file
    FILE* file;

    // open file in read mode
    file = fopen(file_name, "r");

    // file not present
    if (file == NULL)
    {
        printf("Opening %s failed!\n", file_name);
        return false;
    }

    // file present
    printf("Opening %s success!\n", file_name);

    // read file
    int i = 0;
    char buffer[1024];
    char* field;
    int field_num;
    while (fgets(buffer, 1024, file))
    {
        field_num = 0;
        field = strtok(buffer, "/");
        while (field)
        {
            switch (field_num)
            {
            case 0:
                arr[i].tag = atoi(field);
                break;
            case 1:
                strcpy(arr[i].date, field);
                break;
            case 2:
                strcpy(arr[i].is_fee_paid, field);
                break;
            case 3:
                strcpy(arr[i].name, field);
                break;
            case 4:
                arr[i].age = atoi(field);
                break;
            case 5:
                strcpy(arr[i].org, field);
                break;
            case 6:
                strcpy(arr[i].job, field);
                break;
            }
            // get next field
            field = strtok(NULL, "/");
            field_num++;
        }
        printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            arr[i].tag, arr[i].date, arr[i].is_fee_paid, arr[i].name, arr[i].age, arr[i].org, arr[i].job);
        i++;
    }
    printf("Storing %s success!\n", file_name);

    // close file
    fclose(file);

    *arr_length = i;
    return true;
}

void search_name_in_arr(const char* search_key, struct REGISTRATION_arr arr[], const int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        char cmpstr[25] = " ";
        if (strcmp(strrchr(arr[i].name, ' '), strcat(cmpstr, search_key)) == 0) {
            printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
                arr[i].tag, arr[i].date, arr[i].is_fee_paid, arr[i].name, arr[i].age, arr[i].org, arr[i].job);
        }
    }
}

void search_name_in_ll(const char* search_key, struct REGISTRATION_ll* head) {

}

void search_org_in_arr(const char* search_key, struct REGISTRATION_arr arr[], const int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        if (strcmp(arr[i].org, search_key) == 0) {
            printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
                arr[i].tag, arr[i].date, arr[i].is_fee_paid, arr[i].name, arr[i].age, arr[i].org, arr[i].job);
        }
    }
}

void search_org_in_ll(const char* search_key, struct REGISTRATION_ll* head) {

}


// P3-1
void sort_arr(struct REGISTRATION_arr arr[], const int arr_length) {
    int min, min_index;
    struct REGISTRATION_arr temp;

    for (int i = 0; i < arr_length; i++) {
        min = arr[i].tag;
        min_index = i;

        for (int j = i; j < arr_length; j++) {
            if (min > arr[j].tag) {
                min = arr[j].tag;
                min_index = j;
            }
        }

        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

//4-1
void sort_ll(REGISTRATION_ll* new_head, struct REGISTRATION_arr arr[])
{
    int i;
    struct REGISTRATION_ll* node = (struct REGISTRATION_ll*)malloc(30 * sizeof(struct REGISTRATION_ll));
    struct REGISTRATION_ll* ptr;
    new_head->next = &node[0];
    ptr = new_head->next;
    if (node != NULL) {
        for (i = 0; i < 30; i++) {
            node[i].tag = arr[i].tag;
            strcpy(node[i].date, arr[i].date);
            strcpy(node[i].is_fee_paid, arr[i].is_fee_paid);
            strcpy(node[i].name, arr[i].name);
            node[i].age = arr[i].age;
            strcpy(node[i].org, arr[i].org);
            strcpy(node[i].job, arr[i].job);
            if (i > 0) {
                ptr->next = &node[i];
                ptr = &node[i];
            }
        }
        node[29].next = NULL;
        print_ll(new_head);
    }
}



//self study
void Selection_sort(struct REGISTRATION_arr arr[], const int arr_length)
{
    int i, j, min, age_group, min_arr;
    struct REGISTRATION_arr temp;
    for (i = 0; i < arr_length - 1; i++) {
        min = arr[i].age / 10;
        for (j = i + 1; j < arr_length; j++) {
            age_group = arr[j].age / 10;
            if (age_group < min)
                min = age_group;
            min_arr = j;
        }
        temp = arr[min_arr];
        arr[min_arr] = arr[i];
        arr[i] = temp;
    }
    print_arr(arr, arr_length);
}


// 5-1 /* Write File */
bool write_sorted_data(const char* new_file_name, struct REGISTRATION_arr arr[], const int arr_length)
{
    // declare file
    FILE* new_file;

    // open file in write mode
    new_file = fopen(new_file_name, "w");

    // file not present
    if (new_file == NULL)
    {
        printf("Opening %s failed!\n", new_file_name);
        return false;
    }

    // file present
    printf("Opening %s success!\n", new_file_name);
    for (int i = 0; i < arr_length; i++)
    {
        // write structure data to file
        fprintf(new_file, "Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            arr[i].tag, arr[i].date, arr[i].is_fee_paid, arr[i].name, arr[i].age, arr[i].org, arr[i].job);
    }
    printf("Writing %s success!\n", new_file_name);

    // close file
    fclose(new_file);

    return true;
}

// 6-1
void remove_data_from_arr(const char* remove_key, struct REGISTRATION_arr arr[], int* arr_length) {
    struct REGISTRATION_arr temp;
    int prev_length = *arr_length;

    for (int i = 0; i < prev_length; i++) {
        char cmpstr[25] = " ";
        if (strcmp(strrchr(arr[i].name, ' '), strcat(cmpstr, remove_key)) == 0) {
            arr[i].tag = 0;
            (*arr_length)--;
        }
    }

    for (int i = 0; i < prev_length; i++) {
        if (arr[i].tag == 0) {
            for (int j = i; j < prev_length; j++) {
                if (arr[j].tag != 0) {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    break;
                }
            }
        }
    }
}

// 6-2
void remove_data_from_ll(const char* remove_key, struct REGISTRATION_ll* head) {
    struct REGISTRATION_ll* p = head->next, * prev = head;
    struct REGISTRATION_ll* temp = NULL;

    while (p != NULL) {
        char cmpstr[25] = " ";
        if (strcmp(strrchr(p -> name, ' '), strcat(cmpstr, remove_key)) == 0) {
            prev->next = p->next;
            temp = p;
            p = p->next;
            free(temp);
        }
        else {
            prev = p;
            p = p->next;
        }
    }
}

// 7-1
void insert_data_to_arr(struct REGISTRATION_arr * new_person, struct REGISTRATION_arr arr[], int* arr_length) {
    struct REGISTRATION_arr temp1, temp2;
    int prev_length = *arr_length;
    int i, j;

    for (i = 0; i <= prev_length; i++) {
        if (arr[i].tag > new_person->tag) {
            break;
        }
    }

    temp1 = arr[i];
    arr[i] = *new_person;
    (*arr_length)++;

    for (j = i; j < prev_length; j++) {
        temp2 = arr[j + 1];
        arr[j + 1] = temp1;
        temp1 = temp2;
    }
}

// 7-2
void insert_data_to_ll(struct REGISTRATION_ll* new_person, struct REGISTRATION_ll* head) {
    struct REGISTRATION_ll* p = head->next, * prev = head;
    struct REGISTRATION_ll* new_node;

    while (p) {
        if (p->tag > new_person->tag) break;
        prev = p;
        p = p->next;
    }
    new_node = (struct REGISTRATION_ll*)malloc(sizeof(struct REGISTRATION_ll));
    new_node = new_person;

    prev->next = new_node;
    new_node->next = p;
}

//8-1
bool check_sum(struct REGISTRATION_arr arr[], const int arr_length)
{
    int checksum_org = 0;      // the original checksum
    int checksum_copy = 0;     // the copied checksum
    char namechar;
    char ch;

    for (int i = 20; i <= arr_length; i++) {
        for (int j = 0; arr[i].name[j] != '\0'; j++) {
            ch = arr[i].name[j];
            checksum_org ^= (int)ch;           // The value of original checksum
        }
    }
    FILE* myFile;
    myFile = fopen("8-1.txt", "w");

    fprintf(myFile, "%0x\n", checksum_org);
    for (int k = 20; k <= arr_length; k++) {
        fprintf(myFile, "%s\n", arr[k].name); // write the last 10 name to the txt file 
    }

    fclose(myFile);

    myFile = fopen("8-1.txt", "r");

    fscanf(myFile, "%0x", &checksum_org);
    printf("%0x", checksum_org);

    fseek(myFile, 2, SEEK_CUR);    // The size of '\n' is 2byte, so move to the next line

    namechar = fgetc(myFile);
    while (namechar != EOF) {         // read the txt file and print the result
        if (namechar == '\0') {
            fseek(myFile, 2, SEEK_CUR);
        }
        putchar(namechar);
        checksum_copy ^= (int)namechar;
        namechar = fgetc(myFile);
    }

    printf("First checksum : %0x\n", checksum_org);
    printf("Second checksum : %0x\n", checksum_copy);

    fclose(myFile);

    if (checksum_org == checksum_copy) {                         // compare the original checksum with the copied checksum
        return 1;
    }
}


void print_arr(struct REGISTRATION_arr arr[], const int arr_length) {
    printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    for (int i = 0; i < arr_length; i++) {
        printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            arr[i].tag, arr[i].date, arr[i].is_fee_paid, arr[i].name, arr[i].age, arr[i].org, arr[i].job);
    }
}

void print_ll(struct REGISTRATION_ll* head) {
    struct REGISTRATION_ll* p = head->next;
    printf("\n\n------------------------------------------------------------------------------------------------------------------------------------------------\n\n");

    while (p) {
        printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            p->tag, p->date, p->is_fee_paid, p->name, p->age, p->org, p->job);
        p = p->next;
    }
}