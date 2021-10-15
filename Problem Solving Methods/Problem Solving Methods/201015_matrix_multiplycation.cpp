#include <stdio.h>

void multiplication(int matrix1[3][3], int matrix2[3][3], int result[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
}

int main() {
	int matrix1[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int matrix2[3][3] = {
		{1, 2, 1},
		{2, 4, 6},
		{7, 2, 5}
	};

	int result[3][3] = {
		{0, 0 ,0},
		{0, 0, 0},
		{0, 0, 0}
	};

	multiplication(matrix1, matrix2, result);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}