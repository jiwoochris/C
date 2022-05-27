#include <stdio.h>
#include<stdlib.h>
#include<time.h>

struct table1 {
	int c[3];
}t1[15];

struct table2 {
	int c[3];
}t2[10];

void print_table() {

	printf("\nTable 1\n");
	for (int i = 0; i < 15; i++) {
		printf("\t %d \t %d \t %d\n", t1[i].c[0], t1[i].c[1], t1[i].c[2]);
	}

	printf("\n\nTable 2\n");
	for (int i = 0; i < 10; i++) {
		printf("\t %d \t %d \t %d\n", t2[i].c[0], t2[i].c[1], t2[i].c[2]);
	}
	printf("\n\n");
}

void change_row_t1(int a, int b) {

	int temp;

	temp = t1[a].c[0];
	t1[a].c[0] = t1[b].c[0];
	t1[b].c[0] = temp;

	temp = t1[a].c[1];
	t1[a].c[1] = t1[b].c[1];
	t1[b].c[1] = temp;

	temp = t1[a].c[2];
	t1[a].c[2] = t1[b].c[2];
	t1[b].c[2] = temp;
}

void change_row_t2(int a, int b) {

	int temp;

	temp = t2[a].c[0];
	t2[a].c[0] = t2[b].c[0];
	t2[b].c[0] = temp;

	temp = t2[a].c[1];
	t2[a].c[1] = t2[b].c[1];
	t2[b].c[1] = temp;

	temp = t2[a].c[2];
	t2[a].c[2] = t2[b].c[2];
	t2[b].c[2] = temp;
}

// sort Table 1 (on column 3)
void duplex_selection_sort_t1() {
	int max;
	int min;
	int min_i;
	int max_i;

	for (int i = 0; i < 8; i++) {
		max = -1;
		min = 999;

		for (int j = i; j < 15-i; j++) {
			if (min > t1[j].c[2]) {
				min = t1[j].c[2];
				min_i = j;
			}

			if (max < t1[j].c[2]) {
				max = t1[j].c[2];
				max_i = j;
			}
		}

		change_row_t1(14 - i, max_i);

		change_row_t1(i, min_i);
	}
}

// sort Table 2 (on column 1)
void duplex_selection_sort_t2() {
	int max;
	int min;
	int min_i;
	int max_i;

	for (int i = 0; i < 5; i++) {
		max = -1;
		min = 999;


		for (int j = i; j < 10 - i; j++) {
			if (min > t2[j].c[0]) {
				min = t2[j].c[0];
				min_i = j;
			}
				
			if (max < t2[j].c[0]) {
				max = t2[j].c[0];
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
			while (t1[i].c[2] <= t1[pivot].c[2] && i < last)
				i++;
			while (t1[j].c[2] > t1[pivot].c[2])
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
			while (t2[i].c[0] <= t2[pivot].c[0] && i < last)
				i++;
			while (t2[j].c[0] > t2[pivot].c[0])
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

// a function that joins 2 tables,
// where t1c is the array index for a column of table1,
// and t2c is the array index for a column of table2;
// and val1 is the user - specified value for the t1c column

void join(int t1c, int t2c, int val) {
	int r1 = 0;
	int r2 = 0;

	printf("\nMerge Join\n");

	while (r1 < 15 && r2 < 10) {
		if (t1[r1].c[t1c] == t2[r2].c[t2c] && t2[r2].c[t2c] == val) {
			printf("\t %d \t %d \t %d \t %d \t %d\n", t1[r1].c[0], t1[r1].c[1], t1[r1].c[2], t2[r2].c[1], t2[r2].c[2]);
			
			if (r1 != 14 && t1[r1 + 1].c[t1c] == t2[r2].c[t2c])
				r1++;
			else if (r2 != 10 && t1[r1].c[t1c] == t2[r2 + 1].c[t2c])
				r2++;
			else {
				r1++;
				r2++;
			}
		}

		else if (t1[r1].c[t1c] < t2[r2].c[t2c])
			r1++;
		else
			r2++;
	}
}

int main() {

	// Fill the tables with random integers between 1 and 100.

	srand((unsigned)time(NULL));

	for (int i = 0; i < 15; i++) {
		t1[i].c[0] = rand() % 100 + 1;
		t1[i].c[1] = rand() % 100 + 1;
		t1[i].c[2] = rand() % 100 + 1;
	}

	for (int i = 0; i < 10; i++) {
		t2[i].c[0] = rand() % 100 + 1;
		t2[i].c[1] = rand() % 100 + 1;
		t2[i].c[2] = rand() % 100 + 1;
	}


	// Print the 2 tables (in a nice table form)
	print_table();


	// Update the tables
	t1[10].c[2] = 55;
	t1[14].c[2] = 55;

	t2[5].c[0] = 55;


	// Duplex selection sort program
	duplex_selection_sort_t1();

	duplex_selection_sort_t2();

	print_table();


	// quick sort
	quick_sort_t1(0, 14);

	quick_sort_t2(0, 9);

	print_table();


	// merge join of the two tables
	// Test that the join function joins the 2 tables based on the value 55 for column 3 of table1 and the value of column1 of table 2. (Print the concatenated rows.)
	join(2, 0, 55);
		

	return 0;
}