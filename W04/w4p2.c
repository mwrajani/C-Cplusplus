/*
	==================================================
	Workshop #4 (Part-2):
	==================================================
	Name   :Muhammad Wajih Rajani
	ID     :142199207
	Email  :mwrajani@myseneca.ca
	Section:NAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define maxItems 10
int main(void)
{
	double const maxIncome = 400000.00, minIncome = 500.00, minCost = 100.00;
	double doubleValue = 0, doubleForcastMonths = 0, monthlyNetIncome = 0.0, prioritizedCost = 0, itemCost[maxItems] = { 0 }, totalCost = 0;
	int noWishListItems = 0, i = 0, forcastMonths = 0, forcastYears = 0, priority = 0, importanceNum[maxItems] = { 0 },noteFlag = 1, exitFlag = 1;
	char financingOptions[maxItems] = { 0 };
	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");
	printf("Enter your monthly NET income: $");
	scanf("%lf", &monthlyNetIncome);
	while (getchar() != '\n');
	while (monthlyNetIncome < minIncome)
	{
		printf("ERROR: You must have a consistent monthly income of at least $500.00\n");
		printf("\nEnter your monthly NET income: $");
		scanf("%lf", &monthlyNetIncome);
		while (getchar() != '\n');
	}
	while (monthlyNetIncome >= maxIncome)
	{
		printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
		printf("Enter your monthly NET income: $");
		scanf("%lf", &monthlyNetIncome);
		while (getchar() != '\n');
	}
	printf("\nHow many wish list items do you want to forecast?: ");
	scanf("%d", &noWishListItems);
	while (getchar() != '\n');
	while (noWishListItems > 10 || noWishListItems < 1)
	{
		printf("ERROR: List is restricted to between 1 and 10 items.\n");
		printf("\nHow many wish list items do you want to forecast?: ");
		scanf("%d", &noWishListItems);
		while (getchar() != '\n');
	}
	for (i = 0; i < noWishListItems; i++)
	{
		printf("\nItem-%d Details:\n", i + 1);
		printf("   Item cost: $");
		scanf("%lf", &itemCost[i]);

		while (itemCost[i] < minCost)
		{
			printf("      ERROR: Cost must be at least $100.00\n");
			printf("   Item cost: $");
			scanf("%lf", &itemCost[i]);
			while (getchar() != '\n');
		}
		printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
		scanf("%d", &importanceNum[i]);
		while (getchar() != '\n');
		while (importanceNum[i] > 3 || importanceNum[i] < 1)
		{
			printf("      ERROR: Value must be between 1 and 3\n");
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf("%d", &importanceNum[i]);
			while (getchar() != '\n');
		}
		printf("   Does this item have financing options? [y/n]: ");
		scanf("%c", &financingOptions[i]);
		while (financingOptions[i] != 'n' && financingOptions[i] != 'y')
		{
			printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			printf("   Does this item have financing options? [y/n]: ");
			scanf("%c", &financingOptions[i]);
			while (getchar() != '\n');

		}

	}
	printf("\nItem Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");
	for (i = 0; i < noWishListItems; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf\n", i + 1, importanceNum[i], financingOptions[i], itemCost[i]);
		totalCost = totalCost + itemCost[i];
	}
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf", totalCost);
	while (exitFlag != 0)
	{
		printf("\n\nHow do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &exitFlag);

		while (exitFlag > 2 || exitFlag < 0)
		{
			printf("\nERROR: Invalid menu selection.\n\n");
			printf("How do you want to forecast your wish list?\n");
			printf(" 1. All items (no filter)\n");
			printf(" 2. By priority\n");
			printf(" 0. Quit/Exit\n");
			printf("Selection: ");
			scanf("%d", &exitFlag);
		}
		if (exitFlag == 1)
		{
			printf("\n====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%.2lf\n", totalCost);

			doubleForcastMonths = totalCost / monthlyNetIncome;
			forcastMonths = (int)doubleForcastMonths;
			doubleValue = doubleForcastMonths - forcastMonths;
			if (doubleValue > 0 && doubleValue < 1)
			{
				doubleValue = doubleValue + 1;
				forcastYears = (int)(doubleForcastMonths + 1);
			}
			forcastMonths = forcastYears % 12;
			forcastYears /= 12;
			for (i = 0; i < noWishListItems; i++)
			{
				
					if (financingOptions[i] == 'y')
					{
						noteFlag = 0;
					}
				
			}
			printf("Forecast: %d years, %d months", forcastYears, forcastMonths);
			if (noteFlag == 0)
			{
				printf("\nNOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.");
			}
                        noteFlag = 1;
			printf("\n====================================================");
		}
		if (exitFlag == 2)
		{   
			printf("\nWhat priority do you want to filter by? [1-3]: ");
			scanf("%d", &priority);
			printf("\n====================================================\n");
			printf("Filter:   by priority (%d)", priority);
			for (i = 0; i < noWishListItems ; i++)
			{
				if (importanceNum[i] == priority)
				{  
					prioritizedCost += itemCost[i];
				}
			}
			printf("\nAmount:   $%.2lf\n", prioritizedCost);

			doubleForcastMonths = prioritizedCost / monthlyNetIncome;
			forcastMonths = (int)doubleForcastMonths;
			doubleValue = doubleForcastMonths - forcastMonths;
			if (doubleValue > 0 && doubleValue < 1)
			{
				doubleValue = doubleValue + 1;
				forcastYears = (int)(doubleForcastMonths + 1);
			}
			forcastMonths = forcastYears % 12;
			forcastYears /= 12;
			for (i = 0; i < noWishListItems; i++)
			{
				if (importanceNum[i] == priority)
				{    
					if (financingOptions[i] == 'y')
					{
						noteFlag = 0;
					}
				}
			}
			printf("Forecast: %d years, %d months", forcastYears, forcastMonths);
			if (noteFlag == 0)
			{
				printf("\nNOTE: Financing options are available on some items.\n");
				printf("      You can likely reduce the estimated months.");
			}
                        noteFlag = 1;
			printf("\n====================================================");
			prioritizedCost = 0;
		}
	}
		printf("\nBest of luck in all your future endeavours!");
		return 0;
	
}
		

			





			
	



	
	
	
	
	
	
	
	
	
	
	
	


