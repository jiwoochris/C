#include <stdio.h>
#include "circle.h"
#include "rectangle.h"
#include "mydef.h"

int main() {
	printf("%f\n", GetCircleArea(1.5));
	printf("%f\n", GetRectangleArea(3, 5));
}