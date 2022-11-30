//==============================================
// Name:           Muhammad Wajih Rajani
// Student Number: 142199207
// Email:          mwrajanimyseneca.ca
// Section:        NAA
// Date:           19 July, 2021
//==============================================
// Assignment:     2
// Milestone:      2
//==============================================

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contactHelpers.h"
#include "contacts.h"
// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:


//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n' );// empty execution code block on purpose
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
		c = 0;
		v = 0;
		scanf("%c%c", &c, &v);
		if ((c != 'y' && c != 'n' && c != 'Y' && c != 'N') || v != '\n')
		{
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
			clearKeyboard();
		}
		else if (c == 'y' || c == 'Y')
		{
			if (v == '\n')
			{
				y = 1;
			}
			else
			{
				clearKeyboard();
			}
		}
		else if (c == 'n' || c == 'N')
		{
			if (v == '\n')
			{
				y = 0;
			}
			else
			{
				clearKeyboard();
			}
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
	do
	{
		y = menu();
		for (i = 1; i < 7; i++)
		{
			if (y == i)
			{
				printf("\n<<< Feature %d is unavailable >>>\n\n", y);
				pause();
				printf("\n");
			}
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