#include <stdio.h>

void secs(int hours, int minutes, int seconds, int* totSec) {
	seconds = hours * 3600 + minutes * 60 + seconds;
	*totSec = seconds;
}


int main() {
	int hours[] = { 5, 3, 12, 0 };
	int minutes[] = { 1, 40, 59, 23 };
	int seconds[] = { 4, 47, 20, 0 };
	int totSec;

	for (int i = 0; i < 4; i++) {
		secs(hours[i], minutes[i], seconds[i], &totSec);

		printf("\n");
		printf(" hours : %d, minutes : %d, second : %d", hours[i], minutes[i], seconds[i]);
		printf(" ==> total number of seconds : %d", totSec);
		printf("\n");
	}

	return 0;
}