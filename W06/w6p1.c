/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Muhammad Wajih Rajani
	ID     : 142199207
	Email  : Mwrajani@myseneca.ca
	Section: NAA
*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include<stdio.h>

// User Libraries
#include "w6p1.h"


// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* validationPositiveInt)
{   
	int numInt = 0;
	scanf("%d", &numInt);
	while (numInt == 0 || numInt < 0)
	{
		printf("ERROR: Enter a positive value: ");
		scanf("%d", &numInt);
	}
	if (validationPositiveInt != NULL)
	{
		*validationPositiveInt = numInt;
	}
	return numInt;
}
// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* validationPositiveDouble)
{
	double numDouble = 0;
	scanf("%lf", &numDouble);
	while (numDouble == 0 || numDouble < 0)
	{
		printf("ERROR: Enter a positive value: ");
		scanf("%lf", &numDouble);
	}
	if ( validationPositiveDouble != NULL)
	{
		*validationPositiveDouble = numDouble;
	}
	return numDouble;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessage( const int sequenceNumber )
{
	printf("Cat Food Cost Analysis\n======================\n\nEnter the details for %d dry food bags of product data for analysis.\nNOTE: A 'serving' is %dg\n\n", maxProducts, numGrains);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber)
{
	struct CatFoodInfo CatFood;
	    printf("Cat Food Product #%d\n", sequenceNumber + 1);
		printf("--------------------\n");
		printf("SKU           : ");
		getIntPositive(&CatFood.skuNum);
		printf("PRICE         : $");
		getDoublePositive(&CatFood.prodPrice);
		printf("WEIGHT (LBS)  : ");
		getDoublePositive(&CatFood.prodWeighPound);
		printf("CALORIES/SERV.: ");
		getIntPositive(&CatFood.caloriPerServ);
		printf("\n");
		return CatFood;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(int *sku, double *price, double *weight, int *calorie)
{    
		printf("%07d %10.2f %10.1lf %8d\n", * sku, * price, * weight, * calorie);
}




// 7. Logic entry point
void start(void)
{
	int i = 0;
	struct CatFoodInfo CatFood[maxProducts] = { { 0 } };
		openingMessage(maxProducts);
		for (i = 0; i < maxProducts; i++)
		{
			CatFood[i] = getCatFoodInfo(i);
		}
		displayCatFoodHeader();
		for (i = 0; i < maxProducts; i++)
		{
			displayCatFoodData(&CatFood[i].skuNum, &CatFood[i].prodPrice, &CatFood[i].prodWeighPound, &CatFood[i].caloriPerServ);
		}
}

