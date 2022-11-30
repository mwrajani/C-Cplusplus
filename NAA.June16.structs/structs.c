#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include"structs.h"

#define SZ 3

int main(void)
{
	struct Records records[SZ] = { {0} };
	int i;

	for ( i = 0; i < SZ; i++)
	{
		printf("Enter the user id and name for user %d followed by the amount borrowed and interest rate: ", i + 1);
		//%s reads characters froom the buffer until it hits a space or a new line, copies the characters to the 
		//C string 
		//specified, and clears the buffer if it reads a new line, if it hits a space the remaining chars are 
		//left in the buffer
		/*scanf("%d", &records[i].user.id);
		scanf("%15[^\n]%*c", &records[i].user.name);
		scanf("%lf", &records[i].amountBorrowed);
		scanf("%lf", &records[i].interest);*/
		scanf("%d %s %lf %lf", &records[i].user.id, &records[i].user.name, &records[i].amountBorrowed,
					&records[i].interest);
		//while (getchar() != '\n');
	}
	printf("\n\n");
	for ( i = 0; i < SZ; i++)
	{
		printf("Member %d, %s has borrowed $%.2lf at %.2lf interest\n", records[i].user.id, records[i].user.name,
			records[i].amountBorrowed, records[i].interest);
	}


	//struct Record record = { 3, 2345.6, .10 };//sets id to 3, borrowed to 2345.6 and interest to .10
	//struct Record records[SZ] = { {0} };//instantiates all the records to a safe state, all members are set to 0
	//int i;

	//for ( i = 0; i < SZ; i++)
	//{
	//	printf("Enter the id, amount borrowed and interest rate for user %d: ", i + 1);
	//	scanf(" %d %lf %lf", &records[i].id, &records[i].amountBorrowed, &records[i].interest);
	//}
	//for ( i = 0; i < SZ; i++)
	//{
	//	printf("User id == %d, amount borrowed == $%.2lf, interest == %.2lf\n", records[i].id, records[i].amountBorrowed,
	//		records[i].interest);
	//}

	return 0;
}
