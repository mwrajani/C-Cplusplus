#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#define SZ 3

int main(void)
{
	char id[SZ] = { 0 };//key
	double amountBorrowed[SZ] = { 0.0 };//value
	double interest[SZ] = { 0.0 };//value//key - value triplet
	int i;
	int found = 0;//flag
	char userId = 0;

	for ( i = 0; i < SZ; i++)
	{
		printf("Enter the user id: ");
		scanf("%c", &id[i]);
		printf("Enter the amount borrowed: ");
		scanf("%lf", &amountBorrowed[i]);
		printf("Enter the interest rate: ");
		scanf("%lf", &interest[i]);
		//getchar reads the buffer and returns the character read
		//the while loop will continue until the \n is read, thus clearing the buffer
		while (getchar() != '\n');//clear the buffer
	}
	for ( i = 0; i < SZ; i++)
	{
		printf("Id == %-5c| amount borrowed == $%-9.2lf| interest == %7.2lf|\n", id[i], amountBorrowed[i], interest[i]);
	}
	

	while (!found)
	{
		printf("Enter a user id: ");
		scanf("%c", &userId);
		for ( i = 0; i < SZ && !found; i++)
		{
			if (id[i] == userId)
			{
				found = 1;
				printf("User %c owes $%.2lf in interest for this month.\n", id[i], (amountBorrowed[i] * interest[i])/12);
			}
		}
		if (!found)
		{
			printf("User not found\n");
			while (getchar() != '\n');//clear the buffer
		}
	}

	return 0;
}