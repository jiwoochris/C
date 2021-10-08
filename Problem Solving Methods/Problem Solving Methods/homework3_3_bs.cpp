# include <stdio.h>

int bs(int list[], int lo, int hi, int key) {
	int mid;
	if (lo > hi)
		return
		-1;
	mid = (lo + hi) / 2;
	if (list[mid] == key)
		return mid;
	else if (list[mid] > key)
		return bs(list, lo, mid- 1, key);
	else if (list[mid] < key)
		return bs(list, mid + 1, hi, key);
	return
		-1;
}

int main() {
	int list[8] = { 10,20,30,50,100,500,1000,1900 };

	printf("%d", bs(list, 0, 8, 30));

	return 0;
}