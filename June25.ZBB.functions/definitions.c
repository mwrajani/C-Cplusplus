//these are the definitions of the functions, the header file must be included in order to get the pattern
//if the syntax is correct during compilation, the compiler inserts the function code into main
//and produces an executable program

#include"prototypes.h"

int add(int one, int two)
{
	return one + two;
}

void arithmetic(int* numerator, int* denominator, int* result, int* secondResult)
{
	*result = *numerator / *denominator;
	*secondResult = (*numerator) * (*denominator);
}