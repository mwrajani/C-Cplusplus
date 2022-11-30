/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Muhammad Wajih Rajani
	ID     : 142199207
	Email  : Mwrajani@myseneca.ca
	Section: NAA
*/
#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include<stdio.h>

// User-Defined Libraries
#include"w6p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
	if ( validationPositiveInt != NULL)
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
void openingMessage(const int sequenceNumber)
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
void displayCatFoodData(int* sku, double* price, double* weight, int* calorie)
{
	printf("%07d %10.2f %10.1lf %8d\n", *sku, *price, *weight, *calorie);
}





// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* pounds, double* kiloGrams)
{
	double kilo = 0;
	kilo = *pounds / lbsToKg;
	if ( kiloGrams != NULL)
	{
		*kiloGrams = kilo;
	}
	return kilo;
}


// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* pounds, int* grams)
{
	double doubleValue = 0;
	doubleValue = (*pounds / lbsToKg) * 1000;
	if (grams != NULL)
	{
		*grams = doubleValue;
	}
	return doubleValue;
}



// 10. convert lbs: kg and g

void convertLbs(const double* pounds, double* kiloGrams, int* grams)
{
		double kilo = 0, doubleValue = 0;
		kilo = *pounds / lbsToKg;
			*kiloGrams = kilo;
		doubleValue = kilo * 1000;
			*grams = doubleValue;
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int serveSizGrams, const int totalGramsProd, double* totalServings)
{
	double total_Servings = 0, serveSizGram = 0, totalGramsPro = 0;
	totalGramsPro = totalGramsProd;
	serveSizGram = serveSizGrams;
	total_Servings = totalGramsPro / serveSizGram;
	if (totalServings != NULL)
	{
		*totalServings = total_Servings;
	}
	return total_Servings;
}


// 12. calculate: cost per serving
double calculateCostPerServing(const double* prodPrice, const double* totalServes, double* costServe)
{
	double cost_Serve = 0, prodPric = 0, totServes = 0;
	prodPric = *prodPrice;
	totServes = *totalServes;
	cost_Serve = prodPric / totServes;
	if (costServe != NULL)
	{
		*costServe = cost_Serve;
	}
	return cost_Serve;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* prodPrice, const double* totalCal, double* costCalori)
{
	double caloriePrice = 0, prodPric = 0, totCal = 0;
	totCal = *totalCal;
	prodPric = *prodPrice;
	caloriePrice = prodPric / totCal;
	if (costCalori != NULL)
	{
		*costCalori = caloriePrice;
	}
	return caloriePrice;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo itemProdu)
{
	struct ReportData report = { 0 };
	double totalCalories = 0;
	report.prodPrice = itemProdu.prodPrice;
    report.prodSkuNum = itemProdu.skuNum; 
    report.caloriPerServ = itemProdu.caloriPerServ;
    report.prodWeighPound = itemProdu.prodWeighPound;
	report.prodWeighKilo = convertLbsKg( &itemProdu.prodWeighPound, &report.prodWeighKilo);
	report.prodWeighGram = convertLbsG( &itemProdu.prodWeighPound, &report.prodWeighGram);
	report.totalServ = calculateServings( numGrains, report.prodWeighGram, &report.totalServ);
	totalCalories = report.caloriPerServ * report.totalServ;
	report.costPerServing = calculateCostPerServing( &report.prodPrice, &report.totalServ, &report.costPerServing);
	report.costCaloriePerServing = calculateCostPerCal( &report.prodPrice, &totalCalories, &report.costCaloriePerServing);
	return report;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg\n", numGrains);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rowData, const int ifCheapest)
{
		printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", rowData.prodSkuNum, rowData.prodPrice, rowData.prodWeighPound, rowData.prodWeighKilo, rowData.prodWeighGram, rowData.caloriPerServ, rowData.totalServ, rowData.costPerServing, rowData.costCaloriePerServing);
}


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProd)
{
	printf("\nFinal Analysis\n--------------\nBased on the comparison data, the PURRR-fect economical option is:\nSKU:%07d Price: $%4.2lf\n\nHappy shopping!", cheapestProd.skuNum, cheapestProd.prodPrice);
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int i = 0;
	struct CatFoodInfo CatFood[maxProducts] = { { 0 } };
	struct ReportData Report[maxProducts] = { { 0 } };
	int cheapestProduct = 0, cheapestProductCal = 0;
	openingMessage(maxProducts);
	for (i = 0; i < maxProducts; i++)
	{
		CatFood[i] = getCatFoodInfo(i);
	}
	for (i = 0; i < maxProducts; i++)
	{
		Report[i] = calculateReportData( CatFood[i]);
	}
displayCatFoodHeader();
    for (i = 0; i < maxProducts; i++)
	{
		displayCatFoodData(&CatFood[i].skuNum, &CatFood[i].prodPrice, &CatFood[i].prodWeighPound, &CatFood[i].caloriPerServ);
	}
	cheapestProductCal = Report[0].costPerServing;
	for (i = 0; i < maxProducts; i++)
	{
		if (cheapestProductCal > Report[i].costPerServing)
		{
			cheapestProductCal = Report[i].costPerServing;
			cheapestProduct = i;
		}
	}
displayReportHeader();
	for (i = 0; i < maxProducts; i++)
	{
		displayReportData(Report[i], cheapestProduct);
		if (i == cheapestProduct)
		{
			printf(" ***\n");
		}
		else
		{
			printf("\n");
		}
	}
displayFinalAnalysis(CatFood[cheapestProduct]);
}
	