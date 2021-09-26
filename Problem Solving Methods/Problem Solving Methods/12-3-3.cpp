#include <stdio.h>

struct Date {
	int month;
	int day;
	int year;
};

int Days(Date date) {
	return (date.year - 2000) * 360 + (date.month - 1) * 30 + date.day - 1;
}

int main() {

	struct Date Date_arr[4] = {
		{ 12, 2, 2001 },
		{ 3, 25, 2008},
		{9, 27, 2021},
		{1, 2, 2000}
	};

	for (int i = 0; i < 4; i++)
		printf(" %d/%d/%d is passed %d day from 2000/1/1\n", Date_arr[i].year, Date_arr[i].month, Date_arr[i].day, Days(Date_arr[i]));


	return 0;
}