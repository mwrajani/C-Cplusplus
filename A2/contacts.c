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
#include"contacts.h"
#include"contactHelpers.h"
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               | 
// +-------------------------------------------------+
void getName(struct Name* name)
{
   
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    

    printf("Do you want to enter a middle initial(s)? (y or n): ");
    //scanf("%s%*c", &yesNo); //<--- Incorrect, not a c string, must be a char
    clearKeyboard();
    if (yes())
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
    }
    clearKeyboard();
    printf("Please enter the contact's last name: ");
    
    
    scanf("%35[^\n]", name->lastName);
}

// getAddress:
void getAddress(struct Address* address)
{
    printf("Please enter the contact's street number: ");
    do
    {
        address->streetNumber = getInt();
        if (address->streetNumber < 0)
        {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
        }
    } while (address->streetNumber < 1); 
    
   
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);

    printf("Do you want to enter an apartment number? (y or n): ");
    clearKeyboard();
    

    if (yes())
    {
        printf("Please enter the contact's apartment number: ");
        do
        {
            address->apartmentNumber = getInt();
            if (address->apartmentNumber < 0)
            {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            }
        } while (address->apartmentNumber < 1);
    }

    printf("Please enter the contact's postal code: ");
   
    scanf("%7[^\n]", address->postalCode);

    printf("Please enter the contact's city: ");
    clearKeyboard();
    scanf("%40[^\n]", address->city);
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{

    clearKeyboard();
    printf("Please enter the contact's cell phone number: ");
   
    scanf("%10[^\n]", numbers->cell);


    printf("Do you want to enter a home phone number? (y or n): ");
    clearKeyboard();

    //if (yesNo == 'y' && yesNo == 'Y') // <-- No! can't be both 'y' AND 'Y' (should be OR ||)
    if (yes())
    {
        printf("Please enter the contact's home phone number: ");
        
        scanf("%10[^\n]", numbers->home);
    }

    printf("Do you want to enter a business phone number? (y or n): ");
 

    if (yes())
    {
        printf("Please enter the contact's business phone number: ");
        
        scanf("%10[^\n]", numbers->business);
    }
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:
void getContact(struct Contact* contact)
{
    // Use an open and close curly brace with a blank line
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}