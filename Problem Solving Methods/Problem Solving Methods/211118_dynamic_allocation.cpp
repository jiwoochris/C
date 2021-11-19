#include <stdio.h>
#include <stdlib.h>

int main() {

	int* nums = NULL;

	nums = (int *)malloc(10 * sizeof(int));

	if (nums == (int*)NULL) {
		printf("malloc failed");
		exit(1);
	}

	for (int i = 0; i < 10; i++) {
		nums[i] = i;
		printf("%d\n", nums[i]);
	}

	free(nums);

	return 0;
}