#include <stdio.h>

struct Date {
	int month;
	int day;
	int year;
};

struct Date recent(Date date1, Date date2) {
	int date1_r, date2_r;

	date1_r = (date1.year - 2000) * 360 + (date1.month - 1) * 30 + date1.day - 1;
	date2_r = (date2.year - 2000) * 360 + (date2.month - 1) * 30 + date2.day - 1;

	if (date1_r > date2_r)
		return date1;
	else if (date2_r > date1_r)
		return date2;
	else
		printf("---------- same date ----------"); return date1;
}

int main() {

	struct Date Date_arr1[4] = {
		{ 12, 2, 2001 },
		{ 3, 25, 2008},
		{9, 27, 2021},
		{1, 2, 2000}
	};

	struct Date Date_arr2[4] = {
		{ 12, 2, 2001 },
		{ 8, 25, 2008},
		{9, 27, 2011},
		{6, 5, 2021}
	};

	for (int i = 0; i < 4; i++){
		printf(" Between %d/%d/%d, %d/%d/%d\n", Date_arr1[i].year, Date_arr1[i].month, Date_arr1[i].day, Date_arr2[i].year, Date_arr2[i].month, Date_arr2[i].day);
		
		struct Date later_date = recent(Date_arr1[i], Date_arr2[i]);

		printf(" Later date : %d/%d/%d\n\n", later_date.year, later_date.month, later_date.day);
	}

	return 0;
}