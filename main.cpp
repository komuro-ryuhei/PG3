#include "AddClass.h"
#include <stdio.h>

int main() {

	AddClass<int> addInt;
	AddClass<float> addFloat;
	AddClass<double> addDouble;

	printf("Add(2,5) : %d\n", addInt.Add(2, 5));
	printf("Add(3.0f,5.0f) : %3.2f\n", addFloat.Add(3.0f, 5.0f));
	printf("Add(6.0,8.0) : %3.2f\n", addDouble.Add(6.0, 8.0));

	return 0;
}