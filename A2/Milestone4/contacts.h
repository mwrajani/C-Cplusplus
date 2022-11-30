// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

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

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+


//--------------------------------
// Structure Types
//--------------------------------
// Structure type Name declaration (Milestone 1)
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration (Milestone 1)
// Place your code here...
struct Address {
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

// Structure type Numbers declaration (Milestone 1)
// Place your code here...
struct Numbers
{
    char cell[11];
    char home[11];
    char business[11];
};

// Structure type Contact declaration (Milestone 3)
// Place your code here...
struct Contact
{
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        contents below...                        |
// +-------------------------------------------------+


//--------------------------------
// Function Prototypes
//--------------------------------

// Get and store from standard input the values for Name
void getName(struct Name* name);

// Get and store from standard input the values for Address
void getAddress(struct Address* address);

// Get and store from standard input the values for Numbers
void getNumbers(struct Numbers* numbers);

// +-------------------------------------------------+
// |    ====== Assignment 2 | Milestone 1 =======    |
// |                                                 |
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function prototypes here...              |
// +-------------------------------------------------+
void getContact(struct Contact* contact);



// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)



// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_
