/*
	==================================================
	Workshop #3 (Part-2):
	==================================================
	Name   :Muhammad Wajih Rajani
	ID     :142199207
	Email  :mwrajani@myseneca.ca
	Section:NAA
*/
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2010
#define MAX_YEAR 2021
#define LOG_DAYS 3
#include<stdio.h>
int main(void)
{
	const int JAN = 1, DEC = 12;
	int day = 0, inputyear = 0, inputmonth = 0, i = 0;
	double morningRating = 0.0, eveningRating = 0.0, morningTotalRating = 0.0, overallTotalRating = 0.0, eveningTotalRating = 0.0;
	printf("General Well-being Log\n");
	printf("======================\n");
	printf("Set the year and month for the well-being log (YYYY MM): ");
	scanf("%d %d", &inputyear, &inputmonth);

	while ((inputyear<MIN_YEAR || inputyear>MAX_YEAR) && (inputmonth < (DEC + 1) && inputmonth >(JAN - 1)))
	{
		printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &inputyear, &inputmonth);
	}

	while ((inputyear > (MIN_YEAR - 1) && inputyear < (MAX_YEAR + 1)) && (inputmonth > DEC || inputmonth < JAN))
	{
		printf("   ERROR: Jan.(1) - Dec.(12)\n");
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &inputyear, &inputmonth);
	}
    while ((inputyear < MIN_YEAR || inputyear>MAX_YEAR) && (inputmonth > DEC || inputmonth < JAN))
	{
		printf("   ERROR: The year must be between 2010 and 2021 inclusive\n");
		printf("   ERROR: Jan.(1) - Dec.(12)\n");
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &inputyear, &inputmonth);
	}
	printf("\n*** Log date set! ***\n");
	for (i = 0; i < LOG_DAYS; i++)
	{
		day = 1 + i;
		switch (inputmonth)
		{
		case 1:
			printf("\n%d-JAN-0%d\n", inputyear, day);
			break;
		case 2:
			printf("\n%d-FEB-0%d\n", inputyear, day);
			break;
		case 3:
			printf("\n%d-MAR-0%d\n", inputyear, day);
			break;
		case 4:
			printf("\n%d-APR-0%d\n", inputyear, day);
			break;
		case 5:
			printf("\n%d-MAY-0%d\n", inputyear, day);
			break;
		case 6:
			printf("\n%d-JUN-0%d\n", inputyear, day);
			break;
		case 7:
			printf("\n%d-JUL-0%d\n", inputyear, day);
			break;
		case 8:
			printf("\n%d-AUG-0%d\n", inputyear, day);
			break;
		case 9:
			printf("\n%d-SEPT-0%d\n", inputyear, day);
			break;
		case 10:
			printf("\n%d-OCT-0%d\n", inputyear, day);
			break;
		case 11:
			printf("\n%d-NOV-0%d\n", inputyear, day);
			break;
		case 12:
			printf("%d-DEC-0%d\n", inputyear, day);
			break;
		default:
			break;
		}
		printf("   Morning rating (0.0-5.0): ");
		scanf("%lf", &morningRating);
		while (morningRating > 5.0 || morningRating < 0.0)
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &morningRating);
		}
		morningTotalRating = morningTotalRating + morningRating;
		printf("   Evening rating (0.0-5.0): ");
		scanf("%lf", &eveningRating);
		while (eveningRating > 5.0 || eveningRating < 0.0)
		{
			printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &eveningRating);
		}
		eveningTotalRating = eveningTotalRating + eveningRating;
	}
	overallTotalRating = eveningTotalRating + morningTotalRating;
	printf("\nSummary\n");
	printf("=======\n");
	printf("Morning total rating:%6.3lf\n", morningTotalRating);
	printf("Evening total rating:%6.3lf\n", eveningTotalRating);
	printf("----------------------------\n");
	printf("Overall total rating:%7.3lf\n\n", overallTotalRating);
	printf("Average morning rating:%5.1lf\n", morningTotalRating / 3);
	printf("Average evening rating:%5.1lf\n", eveningTotalRating / 3);
	printf("----------------------------\n");
	printf("Average overall rating:%5.1lf\n", overallTotalRating / 6);
return 0;
}


