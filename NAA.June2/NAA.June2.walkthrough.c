#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main(void)
{
	double userEntered = 0.0;
	int whole = 0, remainder = 0;
	printf("Enter a ploating point value: ");//user enters 87.897653
	scanf("%lf", &userEntered);
	printf("You entered %lf\n", userEntered);
	//if(userEntered < 10 && userEntered > 0)//both statements must be true
	//if (userEntered > 0 || userEntered < 10)//1st is true, so 2nd is not checked
	if (userEntered < 10 || userEntered > 0)//first comparison is false, so the 2nd is checked, true so statement is true
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}

	whole = (int)userEntered;//the values to the right of the decimal point are lost
	userEntered -= whole;//subtract whole from userEntered
	remainder = (int)(userEntered * 1000000);
	printf("whole = %d, userEntered = %lf, remainder = %d\n", whole, userEntered, remainder);
	return 0;
}

//5 - userEntered is set to 0.0
//6 - whole and remainder are set to a safe state
//7 - prompt user to enter fp value //print Enter a floating point value
//8 - userEntered is set to 87.897653
//12 - if userEntered is less than 10 or greater than 0? true, enter if
//14 - print true
//21 - whole is set to 87
//22 - userEntered is set to .897653
//23 - remainder is set to 897653
//24 - print whole = 87, userEntered = .897653, remainder = 897653
//25 - program exits and returns 0 to OS
