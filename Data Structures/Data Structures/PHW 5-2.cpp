#include <stdio.h>
#include<stdlib.h>
#include<time.h>

struct table1 {
	int c1;
	int c2;
	int c3;
}t1[15];

struct table2 {
	int c1;
	int c2;
	int c3;
}t2[10];

void print_table() {

	printf("\nTable 1\n");
	for (int i = 0; i < 15; i++) {
		printf("\t %d \t %d \t %d\n", t1[i].c1, t1[i].c2, t1[i].c3);
	}

	printf("\n\nTable 2\n");
	for (int i = 0; i < 10; i++) {
		printf("\t %d \t %d \t %d\n", t2[i].c1, t2[i].c2, t2[i].c3);
	}
	printf("\n\n");
}

void change_row_t1(int a, int b) {

	int temp;

	temp = t1[a].c1;
	t1[a].c1 = t1[b].c1;
	t1[b].c1 = temp;

	temp = t1[a].c2;
	t1[a].c2 = t1[b].c2;
	t1[b].c2 = temp;

	temp = t1[a].c3;
	t1[a].c3 = t1[b].c3;
	t1[b].c3 = temp;
}

void change_row_t2(int a, int b) {

	int temp;

	temp = t2[a].c1;
	t2[a].c1 = t2[b].c1;
	t2[b].c1 = temp;

	temp = t2[a].c2;
	t2[a].c2 = t2[b].c2;
	t2[b].c2 = temp;

	temp = t2[a].c3;
	t2[a].c3 = t2[b].c3;
	t2[b].c3 = temp;
}

void duplex_selection_sort_t1() {
	int max;
	int min;
	int min_i;
	int max_i;

	for (int i = 0; i < 8; i++) {
		max = -1;
		min = 999;

		for (int j = i; j < 15-i; j++) {
			if (min > t1[j].c3) {
				min = t1[j].c3;
				min_i = j;
			}

			if (max < t1[j].c3) {
				max = t1[j].c3;
				max_i = j;
			}
		}

		change_row_t1(14 - i, max_i);

		change_row_t1(i, min_i);
	}
}

void duplex_selection_sort_t2() {
	int max;
	int min;
	int min_i;
	int max_i;

	for (int i = 0; i < 5; i++) {
		max = -1;
		min = 999;


		for (int j = i; j < 10 - i; j++) {
			if (min > t2[j].c1) {
				min = t2[j].c1;
				min_i = j;
			}
				
			if (max < t2[j].c1) {
				max = t2[j].c1;
				max_i = j;
			}
		}

		change_row_t2(9 - i, max_i);

		change_row_t2(i, min_i);

	}
}

void quick_sort_t1(int first, int last) {
	int i, j, pivot;
	if (first < last) {
		pivot = first;
		i = first;
		j = last;
		while (i < j) {
			while (t1[i].c3 <= t1[pivot].c3 && i < last)
				i++;
			while (t1[j].c3 > t1[pivot].c3)
				j--;
			if (i < j) {
				change_row_t1(i, j);
			}
		}
		change_row_t1(pivot, j);
		quick_sort_t1(first, j - 1);
		quick_sort_t1(j + 1, last);
	}
}

void quick_sort_t2(int first, int last) {
	int i, j, pivot;
	if (first < last) {
		pivot = first;
		i = first;
		j = last;
		while (i < j) {
			while (t2[i].c1 <= t2[pivot].c1 && i < last)
				i++;
			while (t2[j].c1 > t2[pivot].c1)
				j--;
			if (i < j) {
				change_row_t2(i, j);
			}
		}
		change_row_t2(pivot, j);
		quick_sort_t2(first, j - 1);
		quick_sort_t2(j + 1, last);
	}
}

void merge_join() {
	int r1 = 0;
	int r2 = 0;

	printf("\nMerge Join\n");

	while (r1 < 15 && r2 < 10) {
		if (t1[r1].c3 == t2[r2].c1) {
			printf("\t %d \t %d \t %d \t %d \t %d\n", t1[r1].c1, t1[r1].c2, t1[r1].c3, t2[r2].c2, t2[r2].c3);
			
			if (r1 != 14 && t1[r1 + 1].c3 == t2[r2].c1)
				r1++;
			else if (r2 != 10 && t1[r1].c3 == t2[r2 + 1].c1)
				r2++;
			else {
				r1++;
				r2++;
			}
		}

		else if (t1[r1].c3 < t2[r2].c1)
			r1++;
		else
			r2++;
	}
}

int main() {

	// Fill the tables with random integers between 1 and 100.

	srand((unsigned)time(NULL));

	for (int i = 0; i < 15; i++) {
		t1[i].c1 = rand() % 100 + 1;
		t1[i].c2 = rand() % 100 + 1;
		t1[i].c3 = rand() % 100 + 1;
	}

	for (int i = 0; i < 10; i++) {
		t2[i].c1 = rand() % 100 + 1;
		t2[i].c2 = rand() % 100 + 1;
		t2[i].c3 = rand() % 100 + 1;
	}


	// Print the 2 tables (in a nice table form)
	print_table();


	// Update the tables
	t1[10].c3 = 55;
	t1[14].c3 = 55;

	t2[5].c1 = 55;


	// Duplex selection sort program
	duplex_selection_sort_t1();

	duplex_selection_sort_t2();

	print_table();


	// quick sort
	quick_sort_t1(0, 14);

	quick_sort_t2(0, 9);

	print_table();


	// merge join of the two tables
	merge_join();
		

	return 0;
}