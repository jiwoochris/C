#include <stdio.h>

int main() {
	char str[20];

	printf("%p", &str);
	scanf_s("%s", &str, 20);
	printf("%p", str);
	printf("%p", &str);

	return 0;
}