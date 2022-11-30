#include<stdio.h>

int main(void)
{
	double cost = 69.2945672;
    int remainder = 0, whole = 0;
	int first = 7, second = 9, third = 3;

	whole = first * second + third;


	//whole = cost;//implicit cast
	whole = (int)cost;//explicit cast, preferred or best practice
	printf("whole == %d\n", whole);

	return 0;
}