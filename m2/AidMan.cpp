//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/* Citation and Sources...
Final Project Milestone ?
Module: Status
Filename: Status.cpp
Version 1.0
Author	Muhammad Wajih
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AidMan.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	int AidMan::menu(){
		int year;
		int month;
		int day;
		ut.getSystemDate(&year, &month, &day);
		cout << "Aid Management System Version 0.1" << endl << "Date: " << year << '/';
		cout.fill('0');
		cout.width(2);
		cout <<month << '/';
		cout.fill('0');
		cout.width(2);
		cout << day<<endl;
		cout<< "Data file: " << ((fileName == nullptr) ? "No file" : fileName) << endl << "---------------------------------\n";
		
		return menuObj.run();
	}
	AidMan::AidMan():menuObj(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n"){
		fileName = nullptr;
	}
	AidMan::~AidMan(){
		delete [] fileName;
		fileName = nullptr;
	}
	void AidMan::run(){
		int returnVal =-1;
		while (returnVal != 0){
			returnVal = menu();
			switch (returnVal) {
			case 1:
				cout << endl << "****List Items****" << endl << endl;
				break;
			case 2:
				cout << endl << "****Add Item****" << endl << endl;
				break;
			case 3:
				cout << endl << "****Remove Item****" << endl << endl;
				break;
			case 4:
				cout << endl << "****Update Quantity****" << endl << endl;
				break;
			case 5:
				cout << endl << "****Sort****" << endl << endl;
				break;
			case 6:
				cout << endl << "****Ship Items****" << endl << endl;
				break;
			case 7:
				cout << endl << "****New/Open Aid Database****" << endl << endl;
				break;
			case 0:
				cout << "Exiting Program!" << endl;
				break;
			}
		}
	}

}
