#pragma warning(disable :4996)
#include <stdio.h>
#include <time.h>
#include "Sorting-ActiveLearning.h"

int keylist[100000];
int keylist_sorted[100000];
char filename_keylist[128] = "Num_list2.txt";
char filename_keylist_sorted[128] = "Num_list2_sorted.txt";

int count[100000000];


// verify your sorting results with the validation sequence
int check_sorted(int* sorting_result)
{
    int verfiedResult = 0;

    // Read the sorted result of the test sequence
    FILE* fs;
    fs = fopen(filename_keylist_sorted, "r");

    if (fs == NULL)
    {
        printf("The test seqeunce file (%s) is not accessible\n", filename_keylist_sorted);
        return verfiedResult;
    }


    int index = 0;
    while (fscanf(fs, "%d", &keylist_sorted[index]) == 1)
    {
        if (sorting_result[index] == keylist_sorted[index])
        {
            verfiedResult++;
        }
        index++;
    }

    fclose(fs);

    return verfiedResult;

}

// program your bubble sorting algorithm
void bubbleSorting(int* original_list, int numofkeys)
{
    int temp;

    for (int i = 0; i < numofkeys - 1; i++) {
        for (int j = 0; j < numofkeys - 1 - i; j++) {
            if (original_list[j] > original_list[j + 1]) {
                temp = original_list[j];
                original_list[j] = original_list[j + 1];
                original_list[j + 1] = temp;
            }
        }
    }
}

// program your second sorting algorithm
void yourSecondSorting(int* original_list, int numofkeys)
{
    int max = original_list[0];
    for (int i = 1; i < numofkeys; i++) {
        if (original_list[i] > max)
            max = original_list[i];
    }

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < numofkeys; i++) {
        count[original_list[i]]++;
    }


    int k = 0;
    for (int i = 0; i <= max; i++) {
        for (int j = 0; j < count[i]; j++) {
            original_list[k] = i;
            k++;
        }
    }

}


void sorting(int* original_list, int numofkeys)
{
	 //bubbleSorting(original_list, numofkeys);
    yourSecondSorting(original_list, numofkeys);
    return ;
}


int main()
{
    
    // read the test sequence
    int numofkeys = 0;
    FILE* fs = fopen(filename_keylist, "r");
    if (fs == NULL)
    {
        printf("The test seqeunce file (%s) is not accessible\n", filename_keylist);
        return 0;
    }

    while (fscanf(fs, "%d", &keylist[numofkeys]) == 1)
    {
        numofkeys++;

    }

    fclose(fs);


    // begin sorting with the test sequence
    clock_t start, end;
    start = (double)clock(); 
    sorting(keylist, numofkeys);
    end = (double)clock(); 

    // compute the time of sorting
    float computationTime = (double)(end - start); // get the total time cost 
    printf("Total time cost(ms) : %lf \n", computationTime);


    // verify with the validation sequence
    int verifiedResult = check_sorted(keylist);

    printf("=============== RESULT =============== \n");
    if (verifiedResult == numofkeys)
    {
        printf("Your sorting algorithm resulted in the correct ascending order for the given list \n\n");
    }
    else
        printf("Your sorting algorithm failed to produce the correct ascending order for the given list \n\n");

}
