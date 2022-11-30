#include "prototypes.h"

int add(int one, int two)
{
	return one + two;
}

void arithmetic(int* numerator, int* denominator, int* result, int* secondResult, int* thirdResult)
{
	*result = *numerator / *denominator;
	*secondResult = *numerator % *denominator;
	*thirdResult = (*numerator) * (*denominator);//brackets are needed to control order of operation
}