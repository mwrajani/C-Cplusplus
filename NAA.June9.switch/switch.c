#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
//Define MAXand MIN//preprocessor directives - done
//Set variables to a safe state – 0
//Output the title
//Enter while loop
//if the year is not in the range 2010 – 2021 or the month is not in the range 1 – 12
//prompt user to enter year and month
//check that year is in range, if not output error message
//check that month is in range, if not output error message
//Note – while loop will continue to run until both yearand month are entered correctly.
//Output the results
//Note – a switch statement is the best way to handle outputting the month.


int main(void)
{
	int someVar = 0;

	printf("Enter a value between 1 and 3, inclusive: ");
	scanf("%d", &someVar);

	switch (someVar)
	{
	case 1:
		printf("One\n");
		break;
	case 2:
		printf("Two\n");
		break;
	case 3:
		printf("Three\n");
		break;
	default:
		break;
	}

	return 0;
}