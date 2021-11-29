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
} registration[MAX_REGISTRATION_NUM];

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
void sort_arr(struct REGISTRATION_arr r[], const int arr_length);   // (정지우) 3-1. sort age in tag order.
void sort_ll(REGISTRATION_ll* head);    // (남소미) 4-1. create linked list using sorted data.

bool write_sorted_data(const char* new_file_name, struct REGISTRATION_arr arr[], int* arr_length);  // (남종수) 5-1. write sorted data to text file.
void remove_data_from_arr(const char* remove_key, struct REGISTRATION_arr arr[], int* arr_length);  // (정지우) 6-1. remove all "Choi" data. (array)
void remove_data_from_ll(const char* remove_key, struct REGISTRATION_ll* head);     // (정지우) 6-2. remove all "Choi" data. (linked list)

void insert_data_to_arr(struct REGISTRATION_arr* new_person, struct REGISTRATION_arr arr[], int* arr_length);   // (권혜민) 7-1. add student "Paik" to data. (array)
void insert_data_to_ll(struct REGISTRATION_ll* new_person, struct REGISTRATION_ll* head);   // (권혜민) 7-2. add student "Paik" to data. (linked list)

bool check_sum(struct REGISTRATION_arr arr[], const int arr_length);    // (남소미) 8-1. copy the most recent data and write text file. (array)


void print_arr(struct REGISTRATION_arr arr[], const int arr_length) {
    for (int i = 0; i < arr_length; i++) {
        printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            arr[i].tag, arr[i].date, arr[i].is_fee_paid, arr[i].name, arr[i].age, arr[i].org, arr[i].job);
    }
}

void print_ll(struct REGISTRATION_ll * head) {
    struct REGISTRATION_ll* p = head->next;
    while(p){
        printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            p->tag, p->date, p->is_fee_paid, p->name, p->age, p->org, p->job);
        p = p->next;
    }
}

int main() {
    const char* file_name = "registraion_data.txt";

    int arr_length;
    struct REGISTRATION_ll * head =NULL;

    if (!store_in_arr(file_name, registration, &arr_length))
    {
        printf("Error\n");
        return -1;
    }

    if (!store_in_ll(file_name, head))
    {
        printf("Error\n");
        return -1;
    }

    search_name_in_arr("Choi", registration, arr_length);
    
    search_name_in_ll("Choi", head);

    search_org_in_arr("Gachon University", registration, arr_length);

    search_org_in_ll("Gachon University", head);

    sort_arr(registration, arr_length);

    sort_ll(head);

    const char* new_file_name = "sorted_registraion_data.txt";

    if (!write_sorted_data(new_file_name, registration, &arr_length))
    {
        printf("Error\n");
        return -1;
    }

    remove_data_from_arr("Choi", registration, &arr_length);

    remove_data_from_ll("Choi", head);


    struct REGISTRATION_arr new_person_arr = { 33, "2020-11-30", "yes", "Gildong Paik", 35, "Gachon University", "Student" };
    struct REGISTRATION_ll new_person_ll = { 33, "2020-11-30", "yes", "Gildong Paik", 35, "Gachon University", "Student", NULL};

    insert_data_to_arr(&new_person_arr, registration, &arr_length);

    insert_data_to_ll(&new_person_ll, head);

    if (check_sum(registration, arr_length)) {
        printf("Two data are the same\n");
    }

    return 0;
}