/**
 * @brief Problem Solving Methods Finals Term Project
 *
 * @todo (남종수) 1-1. search for "Choi". (array)
 * @todo (남종수) 1-2. search for "Choi". (linked list)
 *
 * @todo (남종수) 2-1. search for "Gachon University". (array)
 * @todo (남종수) 2-2. search for "Gachon University". (linked list)
 *
 * @todo (정지우) 3-1. sort data in tag order.
 * @todo (남소미) 4-1. create linked list using sorted data.
 * @todo (남소미) 4-2. sort data in age order using selection sort.
 * @todo (남종수) 5-1. write sorted data to text file. (linked list)
 *
 * @todo (정지우) 6-1. remove all "Choi" data. (array)
 * @todo (정지우) 6-2. remove all "Choi" data. (linked list)
 *
 * @todo (권혜민) 7-1. add student "Paik" to data. (array)
 * @todo (권혜민) 7-2. add student "Paik" to data. (linked list)
 *
 * @todo (남소미) 8-1. copy the most recent data and write text file. (array)
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

/* Registration Structure (Linked List) */
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

bool store_in_arr(const char* file_name, struct REGISTRATION_arr arr[], int* arr_length);
void search_name_in_arr(const char* search_key, struct REGISTRATION_arr arr[], const int arr_length);
void search_name_in_ll(const char* search_key, struct REGISTRATION_ll* head);
void search_org_in_arr(const char* search_key, struct REGISTRATION_arr arr[], const int arr_length);
void search_org_in_ll(const char* search_key, struct REGISTRATION_ll* head);
void sort_arr(struct REGISTRATION_arr arr[], const int arr_length);
void create_ll(REGISTRATION_ll* new_head, struct REGISTRATION_arr arr[], const int arr_length);
void selection_sort(struct REGISTRATION_arr arr[], const int arr_length);
bool write_sorted_data(const char* new_file_name, struct REGISTRATION_arr arr[], const int arr_length);
void remove_data_from_arr(const char* remove_key, struct REGISTRATION_arr arr[], int* arr_length);
void remove_data_from_ll(const char* remove_key, struct REGISTRATION_ll* head);
void insert_data_to_arr(struct REGISTRATION_arr* new_person, struct REGISTRATION_arr arr[], int* arr_length);
void insert_data_to_ll(struct REGISTRATION_ll* new_person, struct REGISTRATION_ll* head);
bool check_sum(struct REGISTRATION_arr arr[], const int arr_length);
void print_arr(struct REGISTRATION_arr arr[], const int arr_length);
void print_ll(struct REGISTRATION_ll* head);

/* Print Dashes */
#define DASH_NUM 136
void print_dashes(int dash_num)
{
    for (int i = 0; i < dash_num; i++)
    {
        printf("-");
    }

    puts("");
}

int main()
{
    const char* file_name = "registration_data.txt";

    struct REGISTRATION_arr registration[MAX_REGISTRATION_NUM];
    int arr_length;

    struct REGISTRATION_ll* head = (struct REGISTRATION_ll*)malloc(sizeof(struct REGISTRATION_ll));
    if (head == NULL)
    {
        printf("Error\n");
        return -1;
    }

    if (!store_in_arr(file_name, registration, &arr_length))
    {
        printf("Error\n");
        return -1;
    }

    create_ll(head, registration, arr_length);
    search_name_in_arr("Choi", registration, arr_length);
    search_name_in_ll("Choi", head);
    search_org_in_arr("Gachon University", registration, arr_length);
    search_org_in_ll("Gachon University", head);
    sort_arr(registration, arr_length);

    struct REGISTRATION_ll* new_head = (struct REGISTRATION_ll*)malloc(sizeof(struct REGISTRATION_ll));
    if (new_head == NULL)
    {
        printf("Error\n");
        return -1;
    }

    create_ll(new_head, registration, arr_length);

    selection_sort(registration, arr_length);

    const char* new_file_name = "sorted_registration_data.txt";
    if (!write_sorted_data(new_file_name, registration, arr_length))
    {
        printf("Error\n");
        return -1;
    }

    remove_data_from_arr("Choi", registration, &arr_length);
    remove_data_from_ll("Choi", new_head);

    struct REGISTRATION_arr new_person_arr = { 11, "2020-11-30", "yes", "Gildong Paik", 35, "Gachon University", "student" };
    struct REGISTRATION_ll new_person_ll = { 11, "2020-11-30", "yes", "Gildong Paik", 35, "Gachon University", "student", NULL };

    insert_data_to_arr(&new_person_arr, registration, &arr_length);
    insert_data_to_ll(&new_person_ll, new_head);

    if (check_sum(registration, arr_length))
    {
        printf("Two data are the same\n");
    }

    return 0;
}

/* Data Preprocessing (Store File in Array) */
bool store_in_arr(const char* file_name, struct REGISTRATION_arr arr[], int* arr_length)
{
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tStoring File\n");
    print_dashes(DASH_NUM);

    // declare file
    FILE* file;

    // open file in read mode
    file = fopen(file_name, "r");

    // file not present
    if (file == NULL)
    {
        printf("Opening %s failed!\n", file_name);
        print_dashes(DASH_NUM);
        return false;
    }

    // file present
    printf("Opening %s success!\n", file_name);
    print_dashes(DASH_NUM);

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
    print_dashes(DASH_NUM);
    printf("Storing %s success!\n", file_name);

    // close file
    fclose(file);

    *arr_length = i;
    return true;
}

// 1-1
void search_name_in_arr(const char* search_key, struct REGISTRATION_arr arr[], const int arr_length)
{
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tSearch Choi in Array\n");
    print_dashes(DASH_NUM);

    for (int i = 0; i < arr_length; i++)
    {
        char cmpstr[25] = " ";
        if (strcmp(strrchr(arr[i].name, ' '), strcat(cmpstr, search_key)) == 0)
        {
            printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
                arr[i].tag, arr[i].date, arr[i].is_fee_paid, arr[i].name, arr[i].age, arr[i].org, arr[i].job);
        }
    }
}

// 1-2
void search_name_in_ll(const char* search_key, struct REGISTRATION_ll* head)
{
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tSearch Choi in Linked List\n");
    print_dashes(DASH_NUM);

    struct REGISTRATION_ll* p = head->next;
    while (p)
    {
        char cmpstr[25] = " ";
        if (strcmp(strrchr(p->name, ' '), strcat(cmpstr, search_key)) == 0)
            printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
                p->tag, p->date, p->is_fee_paid, p->name, p->age, p->org, p->job);

        p = p->next;
    }
}

// 2-1
void search_org_in_arr(const char* search_key, struct REGISTRATION_arr arr[], const int arr_length)
{
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tSearch Gachon University in Array\n");
    print_dashes(DASH_NUM);

    for (int i = 0; i < arr_length; i++)
    {
        if (strcmp(arr[i].org, search_key) == 0)
        {
            printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
                arr[i].tag, arr[i].date, arr[i].is_fee_paid, arr[i].name, arr[i].age, arr[i].org, arr[i].job);
        }
    }
}

// 2-2
void search_org_in_ll(const char* search_key, struct REGISTRATION_ll* head)
{
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tSearch Gachon University in Linked List\n");
    print_dashes(DASH_NUM);
    struct REGISTRATION_ll* p = head->next;
    while (p)
    {
        if (strcmp(p->org, search_key) == 0)
            printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
                p->tag, p->date, p->is_fee_paid, p->name, p->age, p->org, p->job);

        p = p->next;
    }
}

// 3-1
void sort_arr(struct REGISTRATION_arr arr[], const int arr_length)
{
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tSort Data in Tag Order\n");

    int min, min_index;
    struct REGISTRATION_arr temp;

    for (int i = 0; i < arr_length; i++)
    {
        min = arr[i].tag;
        min_index = i;

        for (int j = i; j < arr_length; j++)
        {
            if (min > arr[j].tag)
            {
                min = arr[j].tag;
                min_index = j;
            }
        }

        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }

    print_arr(arr, arr_length);
}

// 4-1
void create_ll(REGISTRATION_ll* new_head, struct REGISTRATION_arr arr[], const int arr_length)
{
    int i;
    struct REGISTRATION_ll* node = (struct REGISTRATION_ll*)malloc(arr_length * sizeof(struct REGISTRATION_ll));
    struct REGISTRATION_ll* ptr;
    new_head->next = &node[0];
    ptr = new_head->next;
    if (node != NULL)
    {
        for (i = 0; i < arr_length; i++)
        {
            node[i].tag = arr[i].tag;
            strcpy(node[i].date, arr[i].date);
            strcpy(node[i].is_fee_paid, arr[i].is_fee_paid);
            strcpy(node[i].name, arr[i].name);
            node[i].age = arr[i].age;
            strcpy(node[i].org, arr[i].org);
            strcpy(node[i].job, arr[i].job);
            if (i > 0)
            {
                ptr->next = &node[i];
                ptr = &node[i];
            }
        }
        node[arr_length - 1].next = NULL;

        print_dashes(DASH_NUM);
        printf("\t\t\t\t\t\t\tCreate Linked List\n");
        print_ll(new_head);
    }
}

// 4-2 Self Study
void selection_sort(struct REGISTRATION_arr arr[], const int arr_length)
{
    int i, j, min, age_group;
    struct REGISTRATION_arr temp;
    for (i = 0; i < arr_length - 1; i++)
    {
        min = arr[i].age / 10;
        for (j = i + 1; j < arr_length; j++)
        {
            age_group = arr[j].age / 10;
            if (age_group < min)
            {
                min = age_group;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tSort Data in Age Order (Selection Sort)\n");
    print_arr(arr, arr_length);
}

// 5-1
bool write_sorted_data(const char* new_file_name, struct REGISTRATION_arr arr[], const int arr_length)
{
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tWrite Sorted Data in Tag Order\n");
    print_dashes(DASH_NUM);

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

    struct REGISTRATION_arr temp;
    int min, min_index;
    for (int i = 0; i < arr_length; i++)
    {
        min = arr[i].tag;
        min_index = i;

        for (int j = i; j < arr_length; j++)
        {
            if (min > arr[j].tag)
            {
                min = arr[j].tag;
                min_index = j;
            }
        }

        temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;

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
void remove_data_from_arr(const char* remove_key, struct REGISTRATION_arr arr[], int* arr_length)
{
    struct REGISTRATION_arr temp;
    int prev_length = *arr_length;

    for (int i = 0; i < prev_length; i++)
    {
        char cmpstr[25] = " ";
        if (strcmp(strrchr(arr[i].name, ' '), strcat(cmpstr, remove_key)) == 0)
        {
            arr[i].tag = 99999;
            (*arr_length)--;
        }
    }

    for (int i = 0; i < prev_length; i++)
    {
        if (arr[i].tag == 99999)
        {
            for (int j = i; j < prev_length; j++)
            {
                if (arr[j].tag != 99999)
                {
                    temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    break;
                }
            }
        }
    }
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tRemove Data from Array\n");
    print_arr(arr, *arr_length);
}

// 6-2
void remove_data_from_ll(const char* remove_key, struct REGISTRATION_ll* head)
{
    struct REGISTRATION_ll* p = head->next, * prev = head;
    struct REGISTRATION_ll* temp = NULL;

    while (p)
    {
        char cmpstr[25] = " ";
        if (strcmp(strrchr(p->name, ' '), strcat(cmpstr, remove_key)) == 0)
        {
            temp = p;
            prev->next = p->next;
            p = p->next;

            /*free(temp);*/
        }
        else
        {
            prev = p;
            p = p->next;
        }
    }

    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tRemove Data from Linked List\n");
    print_ll(head);
}

// 7-1
void insert_data_to_arr(struct REGISTRATION_arr* new_person, struct REGISTRATION_arr arr[], int* arr_length)
{
    struct REGISTRATION_arr temp1, temp2;
    int prev_length = *arr_length;
    int i, j;

    for (i = 0; i <= prev_length; i++)
    {
        if (arr[i].tag > new_person->tag)
            break;
    }

    (*arr_length)++;

    temp1 = arr[i];

    arr[i].tag = new_person->tag;
    strcpy(arr[i].date, new_person->date);
    strcpy(arr[i].is_fee_paid, new_person->is_fee_paid);
    strcpy(arr[i].name, new_person->name);
    arr[i].age = new_person->age;
    strcpy(arr[i].org, new_person->org);
    strcpy(arr[i].job, new_person->job);
    strcat(arr[i].job, "\n");

    for (j = i; j < prev_length; j++)
    {
        temp2 = arr[j + 1];
        arr[j + 1] = temp1;
        temp1 = temp2;
    }

    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tInsert Data to Array\n");
    print_arr(arr, *arr_length);
}

// 7-2
void insert_data_to_ll(struct REGISTRATION_ll* new_person, struct REGISTRATION_ll* head)
{
    struct REGISTRATION_ll* p = head->next, * prev = head;
    struct REGISTRATION_ll* new_node;

    while (p != NULL)
    {
        if (p->tag > new_person->tag)
        {
            break;
        }
        prev = p;
        p = p->next;
    }
    new_node = (struct REGISTRATION_ll*)malloc(sizeof(struct REGISTRATION_ll));
    new_node = new_person;
    strcat(new_node->job, "\n");

    prev->next = new_node;
    new_node->next = p;

    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tInsert Data to Linked List\n");
    print_ll(head);
}

// 8-1
bool check_sum(struct REGISTRATION_arr arr[], const int arr_length)
{
    print_dashes(DASH_NUM);
    printf("\t\t\t\t\t\t\tChecksum\n");
    print_dashes(DASH_NUM);
    int checksum_org = 0;  // the original checksum
    int checksum_copy = 0; // the copied checksum
    char namechar;
    char ch;

    for (int i = arr_length - 10; i < arr_length; i++)
    {
        for (int j = 0; arr[i].name[j] != '\0'; j++)
        {
            ch = arr[i].name[j];
            checksum_org ^= (int)ch; // The value of original checksum
        }
    }
    FILE* myFile;
    myFile = fopen("8-1.txt", "w");

    fprintf(myFile, "%0x\n", checksum_org);
    for (int k = arr_length - 10; k < arr_length; k++)
    {
        fprintf(myFile, "%s\n", arr[k].name); // write the last 10 name to the txt file
    }

    fclose(myFile);

    myFile = fopen("8-1.txt", "r");

    if (fscanf(myFile, "%x", &checksum_org) != 1)
        return false;
    printf("%0x\n", checksum_org);

    fseek(myFile, 2, SEEK_CUR); // The size of '\n' is 2byte, so move to the next line

    namechar = fgetc(myFile);
    while (namechar != EOF)
    {
        // read the txt file and print the result
        if (namechar == '\0')
        {
            fseek(myFile, 2, SEEK_CUR);
        }
        putchar(namechar);
        checksum_copy ^= (int)namechar;
        namechar = fgetc(myFile);
    }
    print_dashes(DASH_NUM);
    printf("First checksum : %0x\n", checksum_org);
    printf("Second checksum : %0x\n", checksum_copy);
    print_dashes(DASH_NUM);

    fclose(myFile);

    if (checksum_org == checksum_copy)
    { // compare the original checksum with the copied checksum
        return true;
    }
    else
        return false;
}

void print_arr(struct REGISTRATION_arr arr[], const int arr_length)
{
    print_dashes(DASH_NUM);
    for (int i = 0; i < arr_length; i++)
    {
        printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            arr[i].tag, arr[i].date, arr[i].is_fee_paid, arr[i].name, arr[i].age, arr[i].org, arr[i].job);
    }
}

void print_ll(struct REGISTRATION_ll* head)
{
    print_dashes(DASH_NUM);
    struct REGISTRATION_ll* p = head->next;

    while (p)
    {
        printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            p->tag, p->date, p->is_fee_paid, p->name, p->age, p->org, p->job);
        p = p->next;
    }
}