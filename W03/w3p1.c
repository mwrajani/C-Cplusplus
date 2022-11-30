/*
	==================================================
	Workshop #3 (Part-1):
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
#include<stdio.h>
int main(void)
{
	const int JAN = 1, DEC = 12;
	int inputyear = 0, inputmonth = 0;
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
	printf("\n*** Log date set! ***\n\n");
	switch (inputmonth)
	{
	case 1:
		printf("Log starting date: %d-JAN-01", inputyear);
		break;
	case 2:
		printf("Log starting date: %d-FEB-01", inputyear);
		break;
	case 3:
		printf("Log starting date: %d-MAR-01", inputyear);
		break;
	case 4:
		printf("Log starting date: %d-APR-01", inputyear);
		break;
	case 5:
		printf("Log starting date: %d-MAY-01", inputyear);
		break;
	case 6:
		printf("Log starting date: %d-JUN-01", inputyear);
		break;
	case 7:
		printf("Log starting date: %d-JUL-01", inputyear);
		break;
	case 8:
		printf("Log starting date: %d-AUG-01", inputyear);
		break;
	case 9:
		printf("Log starting date: %d-SEPT-01", inputyear);
		break;
	case 10:
		printf("Log starting date: %d-OCT-01", inputyear);
		break;
	case 11:
		printf("Log starting date: %d-NOV-01", inputyear);
		break;
	case 12:
		printf("Log starting date: %d-DEC-01", inputyear);
		break;
	default:
		break;
	}
	return 0;
}


