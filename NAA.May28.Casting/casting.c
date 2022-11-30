#include<stdio.h>

int main(void)
{
	double cost = 75.2945672, balance = 0.0;
	int remainder = 0, whole = 0, preciseValue = 0;
	int first = 7, second = 9, third = 3;

	whole = (int)cost;
	balance = cost - whole;//.2945672 4 places of precision == .2946

	printf("w == %d, b == %.4lf, c == %lf\n", whole, balance, cost);

	cost -= whole;

	cost += .00005;//4 places of precision requires adding 5 to the fifth place of precision

	preciseValue = (int)(cost * 10000);

	printf("cost == %lf, pV == %d\n", cost, preciseValue);

	//whole = first * (second + third);

	//whole = second + third;
	//whole *= first;//equals: whole = whole * first, similarly: +=, /=,  %=

	//the % operator returns the remainder, it is know as the modulus or remainder operator
	/*remainder = whole % 8;

	printf("remainder == %d, whole == %d, cost == %lf\n",remainder, whole, cost);*/

	//when casting a floating point value to an int, the value to the right of 
	// the decimal is discarded because an integer can only hold a whole value
	//whole = cost;//implicit cast
	//whole = (int)cost;//explicit cast, preferred or best practice

	//printf("whole == %d, cost == %lf\n", (int)cost, cost);

	return 0;
}