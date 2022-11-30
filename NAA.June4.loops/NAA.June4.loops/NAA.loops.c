#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

#define MAX 7
#define MIN -4

//const int maximum = 7;//not as efficient as a macro - #define MAX 7

int main(void)
{
	int result = 0, result2 = 0;//flag
	int big = 0, small = 0, entered = 0;
	double value = 0.0;
	int i;//iterator//int i = 0;// ok
	int returned = 0;


	while (!result)
	{
		printf("Enter 2 values between %d and %d inclusive: ", MIN, MAX);
		returned = scanf("%d %d", &small, &big);//returned captures the return from scanf, the number of successful reads
		printf("returned == %d\n", returned);
		if (big <= MAX && small >= MIN)
		{
			result = 1;
		}
		else
		{
			printf("Error, try again!\n\n");
		}
		if (result)
		{
			while (!result2)//while result2 == 0
			{
				printf("Enter a value greater than $0.0: $");
				scanf("%lf", &value);
				result2 = value > 0 ? 1 : 0;
			}
			//printf("value == $%.2lf\n", &value);//tries to print the address of value which is returned in hexadecimal
			printf("value == $%.2lf\n", value);
		}
	}

	printf("\nbig == %d, small == %d\n", big, small);

	/*do
	{
		printf("Enter 2 values between %d and %d inclusive: ", MIN, MAX);
		scanf("%d %d", &small, &big);
		if (big <= MAX && small >= MIN)
		{
			result = 1;
		}
		else
		{
			printf("Error, try again!\n\n");
		}
	} while (!result);*/


	/*for (i = 0; i < MAX; i++)
	{
		printf("inside loop i == %d\n", i);
	}
	printf("\n\nAfter loop i == %d\n", i);*/
	//i = 0;
	//while (i < 5)
	//{
	//	printf("%d ", i++);//i++ post increment operator, adds 1 to i after the statement executes
	//}
	//printf("\n\n%d\n", i);
	//16 - i is set to zero
	//17 - i < 5 T, enter loop
	//19 - print 0, i is set to 1
	//17 - i < 5 T, enter loop
	//19 - print 1 and then add 1 to i, i is set to 2
	//17 - i < 5 T, enter loop
	//19 - print 2 and then add 1 to i, i is set to 3
	//17 - i < 5 T, enter loop
	//19 - print 3 and then add 1 to i, i is set to 4
	//17 - i < 5 T, enter loop
	//19 - print 4 and then add 1 to i, i is set to 5
	//17 - i < 5 F, exit loop
	//21 - print 5

	//result = !result2 ? 7 : 8; //conditional statement - same as if(5 > 6){result = 7;} else{result = 8;}
	////!result is true if result is equal to 0, or if result evaluates to false
	//printf("result == %d\n", result);

	return 0;
}