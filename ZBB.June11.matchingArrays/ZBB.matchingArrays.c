#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define SZ 3

int main(void)
{
	//const int sz = 3; //don't do this 
	char key[SZ] = {0};//sets all the elements of key to zero 0
	double loanAmount[SZ] = { 0.0 };
	double interest[SZ] = { 0.0 };
	char id = 0;
	int found = 0;
	int i;

	for ( i = 0; i < SZ; i++)
	{
		printf("Enter the identifier for the customer: ");
		scanf("%c", &key[i]);
		printf("Enter the loan amount for borower %c: ",key[i]);
		scanf("%lf", &loanAmount[i]);
		printf("Enter the interest rate for the loan: ");
		scanf("%lf", &interest[i]);
		//getchar() reads characters from the input buffer, the while loop iterates until a new line is read, 
		//which clears the input buffer
		while (getchar() != '\n') {};
	}
	for ( i = 0; i < SZ; i++)
	{
		//%-5c left justifies the output and sets the width of the output
		//%5c right justify and set the width
		printf("key == %-5c | loan amount == $%10.2lf| interest == %-7.2lf|\n", key[i], loanAmount[i], interest[i]);
	}
	printf("Enter the user id: ");
	scanf("%c", &id);
	i = 0;
	while (!found)
	{
		if (key[i] == id)
		{
			printf("User %c owes $%.2lf interest for this month\n", key[i], loanAmount[i] * interest[i]);
			found = 1;
		}
		i++;
		if (i == SZ && !found)
		{
			printf("User not found, re-enter user id\n");
			scanf("%c", &id);
			i = 0;
		}
		if (found)
		{
			printf("Success\n");
		}
	}

	return 0;
}