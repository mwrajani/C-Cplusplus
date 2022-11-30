//==============================================
// Name:           Muhammad Wajih Rajani
// Student Number: 142199207
// Email:          mwrajanimyseneca.ca
// Section:        NAA
// Date:           2 August, 2021
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include"contactHelpers.h"
#include"contacts.h"
#define MAXCONTACTS 5
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+
// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n');// empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}


// getInt function definition goes here:

int getInt(void)
{
	int y = 0;
	char j = 0;
	scanf("%d%c", &y, &j);
	while (j != '\n')
	{
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		clearKeyboard();
		scanf("%d%c", &y, &j);
	}
	return y;
}
// getIntInRange function definition goes here:
int getIntInRange(int min, int max)
{
	int y = 0;
	do
	{
		y = getInt();
		if (y > max || y < min)
		{
			printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		}
	} while (y > max || y < min);
	return y;
}

// yes function definition goes here:
int yes(void)
{
	int y = -1;
	char c = 0, v = 0;
	do
	{
		scanf("%c", &c);
		if (getchar() != '\n')
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
		else if (c == 'y' || c == 'Y')
		{
			y = 1;
		}
		else if (c == 'n' || c == 'N')
		{
			y = 0;
		}
	} while (y == -1);
	return y;
}


// menu function definition goes here:
int menu(void)
{
	int y = 0;
	printf("Contact Management System\n-------------------------\n1. Display contacts\n2. Add a contact\n3. Update a contact\n4. Delete a contact\n5. Search contacts by cell phone number\n6. Sort contacts by cell phone number\n0. Exit\n\nSelect an option:> ");
	y = getIntInRange(0, 6);
	return y;
}

// contactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
	int y = 0, i = 0, u = 0;
	struct Contact contacts[MAXCONTACTS] = { { { "Rick", {'\0'}, "Grimes" },
		                                       { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		                                       { "4161112222", "4162223333", "4163334444" } },
		                                    {
			                                   { "Maggie", "R.", "Greene" },
			                                   { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			                                   { "9051112222", "9052223333", "9053334444" } },
		                                    {
			                                   { "Morgan", "A.", "Jones" },
			                                   { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			                                   { "7051112222", "7052223333", "7053334444" } },
		                                    {
			                                   { "Sasha", {'\0'}, "Williams" },
			                                   { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			                                   { "9052223333", "9052223333", "9054445555" } },
	                                                                                        };
	do
	{
		y = -4;
		y = menu();
			if (y == 1)
			{
				displayContacts(contacts, MAXCONTACTS);
			}
			if (y == 2)
			{
				addContact(contacts, MAXCONTACTS);
			}
			if (y == 3)
			{
				updateContact(contacts, MAXCONTACTS);
			}
			if (y == 4)
			{
				deleteContact(contacts,MAXCONTACTS);
			}
			if (y == 5)
			{
				searchContacts(contacts, MAXCONTACTS);
			}
			if (y == 6)
			{
				sortContacts(contacts, MAXCONTACTS);
			}
			
		if (y == 0)
		{
			printf("\n");
			printf("Exit the program? (Y)es/(N)o: ");
			u = yes();
			printf("\n");
		}
		if (u == 1)
		{
			printf("Contact Management System: terminated\n");
		}
	} while (u == 0);
}





// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
	int needInput = 1, j = 0;

	while (needInput == 1)
	{
		
		scanf("%10s", phoneNum);
		clearKeyboard();
		while (strlen(phoneNum) != 10 || isdigit(phoneNum[0]) == 0 || isdigit(phoneNum[1]) == 0|| isdigit(phoneNum[2]) == 0 || isdigit(phoneNum[3]) == 0 || isdigit(phoneNum[4]) == 0 || isdigit(phoneNum[5] == 0) || isdigit(phoneNum[6]) == 0 || isdigit(phoneNum[7]) == 0 || isdigit(phoneNum[8]) == 0|| isdigit(phoneNum[9]) == 0)
		{
			j = 1;
			
			printf("Enter a 10-digit phone number: ");
			scanf("%10s", phoneNum);
			clearKeyboard();
		}
		

		// (String Length Function: validate entry of 10 characters)
		
			needInput = 0;
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
	int i = 0, j = 0;
	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0)
		{
			return i;
			j = 1;
		}
	}
	if (j == 0)
	{
		return -1;
	}
}


// displayContactHeader
// Put empty function definition below:
void displayContactHeader(void)
{
	printf("+-----------------------------------------------------------------------------+\n|                              Contacts Listing                               |\n+-----------------------------------------------------------------------------+\n");
}


// displayContactFooter
// Put empty function definition below:
void displayContactFooter(int count)
{
	printf("+-----------------------------------------------------------------------------+\nTotal contacts : %d\n\n", count);
}


// displayContact:
// Put empty function definition below:
void displayContact(const struct Contact* contact)
{
	printf("%s",contact->name.firstName);
	if (isalpha(contact->name.middleInitial[1]) != '0' )
	{
		printf(" %s", contact->name.middleInitial);
	}
	printf(" %s\n", contact->name.lastName);
	printf("    C: %-10s   H : %-10s   B : %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0)
	{
		printf("Apt#  %d, ", contact->address.apartmentNumber);
	}
	printf(" %s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:
// Put empty function definition below:
void displayContacts(const struct Contact contacts[], int size)
{
	int i = 0, y = 0;
	printf("\n");
	displayContactHeader();
	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) == 10)
		{
			y++;
			displayContact(&contacts[i]);
		}
	}
	displayContactFooter(y);
	pause();
	printf("\n");
}


// searchContacts:
// Put empty function definition below:
void searchContacts(const struct Contact contacts[], int size)
{
	int i = 0, j = 0;
	char cellNo[11] = { 0 };
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(cellNo);
	i = findContactIndex(contacts, size, cellNo);
			if (findContactIndex(contacts, size, cellNo) != -1)
			{
				j = 1;
				printf("\n");
				displayContact(&contacts[i]);
			}
	if (j == 0)
	{
		printf("*** Contact NOT FOUND ***\n\n");
	}
	printf("\n");
	pause();
	printf("\n");
}



// addContact:
// Put empty function definition below:
void addContact(struct Contact contacts[], int size)
{	
	printf("\n");
	int i = 0, j = 0;
	while (i < size && j == 0)
	{
		if (strlen(contacts[i].numbers.cell) != 10)
		{
			j = 1;
			getContact(&contacts[i]);
			printf("--- New contact added! ---\n\n");
		}
		i++;
	}
	if (j != 1)
	{
		printf("*** ERROR: The contact list is full! ***\n\n");
	}
	pause();
	printf("\n");
}


// updateContact:
// Put empty function definition below:
	void updateContact(struct Contact contacts[], int size)
    {
		char cellNo[11];
		int i = 0;
		printf("\n");
		printf("Enter the cell number for the contact: ");
	getTenDigitPhone(&cellNo);
	i = findContactIndex(contacts, size, cellNo);
	if (findContactIndex(contacts, size, cellNo) == -1)
	{
		printf("* Contact NOT FOUND *\n\n");
	}
	else
	{
		printf("\nContact found: ");
		displayContact(&contacts[i]);
		printf("\nDo you want to update the name? (y or n): ");
		if (yes())
		{
			getName(&contacts[i].name);
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes())
		{
			getAddress(&contacts[i].address);
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes())
		{
			getNumbers(&contacts[i].numbers);
		}
		printf("--- Contact Updated! ---\n\n");
	}
	pause();
	printf("\n");
    }


// deleteContact:
// Put empty function definition below:
	void deleteContact(struct Contact contacts[], int size)
	{
		char cellNo[11];
		int i = 0, j = 0;
		printf("\nEnter the cell number for the contact: ");
		getTenDigitPhone(cellNo);
		printf("\n");
			if (findContactIndex(contacts,size,cellNo) != -1)
			{
				i = findContactIndex(contacts, size, cellNo);
				printf("Contact found:\n");
				displayContact(&contacts[i]);
				printf("\n");
			}
			printf("CONFIRM: Delete this contact? (y or n): ");
			if (yes())
			{
				*contacts[i].numbers.cell = '\0';
				printf("--- Contact deleted! ---\n\n");
			}
			else
			{
				printf("\n");
			}
			pause();
			printf("\n");
		
	}


// sortContacts:
// Put empty function definition below:
void sortContacts(struct Contact contacts[], int size)
{
	int j = 0;
	struct Contact contactTemp;
		j = size - 1;
	while (j != 0)
	{
		for (int i = 0; i < j; i++)
		{
			if (strcmp(contacts[i].numbers.cell,contacts[i + 1].numbers.cell) == 1)
			{
				contactTemp = contacts[i + 1];
				contacts[i + 1] = contacts[i];
				contacts[i] = contactTemp;
			}
		}
		j--;
	}
	printf("\n--- Contacts sorted! ---\n\n");
	pause();
	printf("\n");
}

