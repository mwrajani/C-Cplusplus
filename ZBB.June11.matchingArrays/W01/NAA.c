#include<stdio.h>
//Muhammad Wajih Rajani
//142199207
//Mwrajani@myseneca.ca
//NAA
int main(void)
{
	int bananas = 8;
	const double cost = .87;//constant or immutable value
	double total = 0;

	total = cost * bananas;
	printf("Cost of bananas is $%.2lf\n", total);// cost* bananas);

	return 0;
}