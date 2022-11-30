#include<stdio.h>

int main(void)
{
	int bananas = 8;
	const double costOfBananas = 1.87;//constant or immutable value

	//double cost_oranges = 1.36;//old style naming, don't do this //costOfOranges

	//double total = 0;

	//cost = .74;//immutable

	//total = cost * bananas;//8 * .87 -> 8.0 * 8.7
	//total = (double)cost * bananas;//good

	///total = (int)cost * bananas;//bad

	printf("Cost of bananas is $%.2lf\n", costOfBananas * bananas);//best

	return 0;
}