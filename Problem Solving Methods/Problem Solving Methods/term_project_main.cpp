#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REGISTRATION_NUM 35

/* Registration Structure (Array) */
struct REGISTRATION
{
    int tag;
    char date[24];
    char is_fee_paid[16];
    char name[24];
    int age;
    char org[35];
    char job[15];
} registration[MAX_REGISTRATION_NUM];

/* Print Dashes */
#define DASH_NUM 136
void printDashes(int dash_num)
{
    for (int i = 0; i < dash_num; i++)
    {
        printf("-");
    }

    puts("");
}

/* Read File */
bool isFileRead(const char* file_name)
{
    printf("\t\t\t\t\t\t\tReading File\n");
    printDashes(DASH_NUM);

    // declare file
    FILE* file;

    // open file in read mode
    file = fopen(file_name, "r");

    // file not present
    if (file == NULL)
    {
        printf("Opening %s failed!\n", file_name);
        printDashes(DASH_NUM);
        return false;
    }

    // file present
    printf("Opening %s success!\n", file_name);
    printDashes(DASH_NUM);

    // read file
    char line[100];
    int lcount = 0;
    while (fgets(line, sizeof(line), file) != NULL)
    {
        // print next from file to screen
        lcount++;
        printf("Line %2d: %s", lcount, line);
    }
    printDashes(DASH_NUM);
    printf("Reading %s success!\n", file_name);

    // close file
    fclose(file);

    return true;
}

/* Split File */
bool isFileSplit(const char* file_name)
{
    printf("\t\t\t\t\t\t\tSplitting File\n");
    printDashes(DASH_NUM);

    // declare file
    FILE* file;

    // open file in read mode
    file = fopen(file_name, "r");

    // file not present
    if (file == NULL)
    {
        printf("Opening %s failed!\n", file_name);
        printDashes(DASH_NUM);
        return false;
    }

    // file present
    printf("Opening %s success!\n", file_name);
    printDashes(DASH_NUM);

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
                registration[i].tag = atoi(field);
                break;
            case 1:
                strcpy(registration[i].date, field);
                break;
            case 2:
                strcpy(registration[i].is_fee_paid, field);
                break;
            case 3:
                strcpy(registration[i].name, field);
                break;
            case 4:
                registration[i].age = atoi(field);
                break;
            case 5:
                strcpy(registration[i].org, field);
                break;
            case 6:
                strcpy(registration[i].job, field);
                break;
            }
            // get next field
            field = strtok(NULL, "/");
            field_num++;
        }
        printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            registration[i].tag, registration[i].date, registration[i].is_fee_paid, registration[i].name, registration[i].age, registration[i].org, registration[i].job);
        // move the index for elements to the next one
        i++;
    }
    printDashes(DASH_NUM);
    printf("Splitting %s success!\n", file_name);

    // close file
    fclose(file);

    return true;
}

/* Regex Exact Match */
void searchArray(char* string, const char* search, int i)
{
    int len_str = strlen(string);
    int len_search = strlen(search);
    int count = 0;

    // for loop (1 through string length)
    for (int cursor = 0; cursor < len_str - len_search + 1; cursor++)
    {
        // if first character of search-string found
        if (string[cursor] == search[0])
        {
            // for loop (1 through length of search-string)
            bool found = true;
            for (int i = 1; i < len_search; i++)
            {
                // if substring matches the search-string, found
                if (string[cursor + i] != search[i])
                {
                    found = false;
                    break;
                }
            }

            // match found
            if (found)
            {
                printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
                    registration[i].tag, registration[i].date, registration[i].is_fee_paid, registration[i].name, registration[i].age, registration[i].org, registration[i].job);
                count++;
            }
        }
    }
}

// P3-1
void sort_array_data(struct REGISTRATION r[]) {
    //int arr_length = sizeof(r) / sizeof(struct REGISTRATION);

    int arr_length = 30;
    int min, min_index;
    struct REGISTRATION temp;

    for (int i = 0; i < arr_length; i++) {
        min = r[i].tag;
        min_index = i;

        for (int j = i; j < arr_length; j++) {
            if (min > r[j].tag) {
                min = r[j].tag;
                min_index = j;
            }
        }

        temp = r[min_index];
        r[min_index] = r[i];
        r[i] = temp;
    }
}


/* 5-1. Write File. */
bool ifFileWritten(const char* file_name, struct REGISTRATION registrations[])
{
    printf("------------------------------------\n");
    printf("%25s", "Writing file\n");
    printf("------------------------------------\n");

    // declare file
    FILE* file;

    // open file in write mode
    file = fopen(file_name, "w");

    // file not present
    if (file == NULL)
    {
        printf("Opening %s failed!\n", file_name);
        printDashes(DASH_NUM);
        return false;
    }

    // file present
    printf("Opening %s success!\n", file_name);
    printDashes(DASH_NUM);
    for (int i = 0; i < MAX_REGISTRATION_NUM; i++)
    {
        // write structure data to file
        fprintf(file, "Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            registration[i].tag, registration[i].date, registration[i].is_fee_paid, registration[i].name, registration[i].age, registration[i].org, registration[i].job);
    }
    printDashes(DASH_NUM);

    // close file
    fclose(file);

    return true;
}


// P7-1
void insert_data_from_array(struct REGISTRATION r[], int* length, struct REGISTRATION person) {
    struct REGISTRATION temp1, temp2;
    int arr_length = *length;
    int i, j=0;

    for (i = 0; i < arr_length; i++) {
        if (r[i].tag > person.tag)
            break;
    }

    temp1 = r[j];
    for (j = i; j < arr_length; j++) {
        temp2 = r[j + 1];
        r[j] = person;
        r[i + 1] = temp1;
        temp1 = temp2;
    }
}


//8-1
void Check_sum(struct REGISTRATION * data)
{
    int checksum_org = 0;      // the original checksum
    int checksum_copy = 0;     // the copied checksum
    char namechar;
    char ch;

    for (int i = 26; i <= 30; i++) {
        for (int j = 0; data[i].name[j] != '\0'; j++) {
            ch = data[i].name[j];
            checksum_org ^= (int)ch;           // The value of original checksum
        }
    }
    FILE* myFile;
    myFile = fopen("8-1.txt", "w");

    fprintf(myFile, "%0x\n", checksum_org);
    for (int k = 20; k <= 30; k++) {
        fprintf(myFile, "%s\n", data[k].name); // write the last 10 name to the txt file 
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

    if (checksum_org == checksum_copy) {                         // compare the original checksum with the copied checksum
        printf("Checksum is same. \n");
    }

    fclose(myFile);
}

// P6 - 1
void remove_data_from_array(struct REGISTRATION r[], int* length, const char* dest_name) {
    struct REGISTRATION temp;
    int arr_length = *length;

    for (int i = 0; i < arr_length; i++) {
        printf("%s\n", strrchr(r[i].name, ' '));
        char cmpstr[25] = " ";
        if (strcmp(strrchr(r[i].name, ' '), strcat(cmpstr, dest_name)) == 0) {
            r[i].tag = 0;
            (*length)--;
        }
    }

    for (int i = 0; i < arr_length; i++) {
        if (r[i].tag == 0) {
            for (int j = i; j < arr_length; j++) {
                if (r[j].tag != 0) {
                    temp = r[j];
                    r[j] = r[i];
                    r[i] = temp;
                    break;
                }
            }
        }
    }
}


int main() {
    const char* file_name = "registraion_data.txt";

    //* split and save data to array
    printDashes(DASH_NUM);
    if (!isFileSplit(file_name))
    {
        return -1;
    }
    int length = 30;
    remove_data_from_array(registration, &length, "Choi");

    for (int i = 0; i < MAX_REGISTRATION_NUM; i++) {
        printf("Tag = %2d, Date = %10s, Fee Paid = %3s, Name = %16s, Age = %2d, Org = %32s, Job = %12s",
            registration[i].tag, registration[i].date, registration[i].is_fee_paid, registration[i].name, registration[i].age, registration[i].org, registration[i].job);
    }



   

	return 0;
}