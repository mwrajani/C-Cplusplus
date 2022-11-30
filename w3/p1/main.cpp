/* ------------------------------------------------------
Workshop 3 part 1
Module: N/A
Filename: main.cpp
Version 1.1
Author: Peter Liu   1/29/2022
Original Author: Cornel Barna
Revision History
-----------------------------------------------------------
Date          Reason
31/01/2022    Minor fixed, use diff to see the changes
-----------------------------------------------------------*/
/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/3/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Train.h"
using namespace sdds;

int main() {

	Train trains[7];

	trains[0].set(nullptr, 100, 123.55);;
	trains[1].set("", 100, 123.55);
	trains[2].set("VIA Rail Abitibi", -100, 123.45);
	trains[3].set("VIA Rail Abitibi", 100, -123.45);
	trains[4].set("VIA Rail Abitibi", 100, 5000);
	trains[5].set("Seneca Express", -1, -1);
	trains[6].set("VIA Rail Abitibi", 333, 115.95);

	cout << "----------------------------------------" << endl;
	cout << "1. Testing the validation logic." << endl;
	cout << "(only trains[6] should be valid)" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 7; ++i)
	{
		cout << "trains[" << i << "]: "
			<< (trains[i].isSafeEmpty() ? "not valid" : "valid") << endl;
	}
	cout << "----------------------------------------" << endl << endl;

	//
	cout << "----------------------------------------" << endl;
	cout << "2. Testing the display function." << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i < 7; ++i)
	{
		trains[i].display();
	}
	cout << "----------------------------------------" << endl << endl;

	cout << "----------------------------------------" << endl;
	cout << "3. Testing the member functions." << endl;
	cout << "----------------------------------------" << endl;

	Train t2;

	t2.set("Bullet Train", 100, 245.95);

	cout << t2.getNumberOfPeople()
		 << ','
		 << t2.getName()
		 << ','
		 << t2.getSpeed() << endl;
	cout << "----------------------------------------" << endl << endl;

	return 0;
}