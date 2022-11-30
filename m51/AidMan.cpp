//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//4 / 6 / 2022
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
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include "AidMan.h"
#include "Utils.h"
#include "Perishable.h"
#include "Item.h"

using namespace std;
namespace sdds {
	int AidMan::menu() {
		int year;
		int month;
		int day;
		ut.getSystemDate(&year, &month, &day);
		cout << "Aid Management System" << endl << "Date: " << year << '/';
		cout.fill('0');
		cout.width(2);
		cout << month << '/';
		cout.fill('0');
		cout.width(2);
		cout << day << endl;
		cout << "Data file: " << ((fileName == nullptr) ? "No file" : fileName) << endl << "---------------------------------\n";

		return menuObj.run();
	}
	AidMan::AidMan() :menuObj(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n") {
		fileName = nullptr;
		noOfIprod = 0;
	}
	AidMan::~AidMan() {
		delete[] fileName;
		fileName = nullptr;
		for (int i = 0; i < noOfIprod; i++) {
			delete iProductArray[i];
			iProductArray[i] = nullptr;
		}
		noOfIprod = 0;
	}
	void AidMan::deallocate() {
		for (int i = 0; i < noOfIprod; i++) {
			delete iProductArray[i];
			iProductArray[i] = nullptr;
		}
	}
	void AidMan::run() {
		int returnVal = -1;
		while (returnVal != 0) {
			returnVal = menu();
			if (fileName == nullptr && returnVal != 7 && returnVal != 0) {
				returnVal = 7;
			}
			cout << endl;
			if (returnVal == 1) {
				cout << "****List Items****"<< endl;
				list();
			}
			else if (returnVal == 2) {
				cout << endl << "****Add Item****" << endl << endl;
			}
			else if (returnVal == 3) {
				cout << endl << "****Remove Item****" << endl << endl;
			}
			else if (returnVal == 4) {
				cout << endl << "****Update Quantity****" << endl << endl;
			}
			else if (returnVal == 5) {
				cout << endl << "****Sort****" << endl << endl;
			}

			else if (returnVal == 6) {
				cout << endl << "****Ship Items****" << endl << endl;
			}
			else if (returnVal == 7) {
				cout << "****New/Open Aid Database****" << endl << "Enter file name: ";
				cin.ignore(2000, '\n');
				cin.clear();
				delete[] fileName;
				string filename;
				filename[0] = '\0';
				cin >> filename;
				deallocate();
				if (filename[0] != '\0')
				{
					fileName = new char[strlen(filename.c_str()) + 1];
					strcpy(fileName, filename.c_str());
				}
				this->load();
				cout << noOfIprod << " records loaded!" << endl<<endl;
			}
			else if (returnVal == 0) {
				cout << "Exiting Program!" << endl;
			}
		}
	}
	void AidMan::save(){
		if (fileName != nullptr && noOfIprod > 0) {
			ofstream ofstr(fileName);
			for (int i = 0; i < noOfIprod; i++) {
				iProductArray[i]->save(ofstr);

			}
		}
	}
	int AidMan::list(const char* sub_desc) {
		int retVal = 0, enter = 0;
		if (sub_desc == nullptr)
		{
			cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			for (int i = 0; i < noOfIprod; i++) {
				cout.fill(' ');
				cout << " " << fixed << right << setw(3) << i + 1 << " | ";
				iProductArray[i]->linear(true);
				iProductArray[i]->display(cout);
				cout << endl;
				retVal = i;
			}
			cout<<"-----+-------+-------------------------------------+------+------+---------+-----------"<<endl;

		}
		else {
			for (int i = 0; i < noOfIprod; i++) {
				if (*iProductArray[i] == sub_desc)
				{
					iProductArray[i]->linear(false);
					iProductArray[i]->display(cout);
					retVal++;
				}
			}
		}

		if (noOfIprod < 1)
		{
			cout << "The list is emtpy!" << endl;
		}
		if (noOfIprod > 0)
		{
				cout << "Enter row number to display details or <ENTER> to continue:" << endl << "> ";

				cin.ignore(2000, '\n');
				char c = cin.peek();
				if (c != '\n') {
					enter = ut.getint();
					for (int i = 0; i < noOfIprod; i++) {
						if (enter-1 == i)
						{
							iProductArray[i]->linear(false);
							iProductArray[i]->display(cout);
							retVal++;
							cout << endl << endl;
						}
					}
				}
				else {
					cout << endl;
				}
		}
		return retVal;
	}
	bool AidMan::load() {
		save();
		deallocate();
		int enter = -1;
		bool retVal = false;
		ifstream ifstr(fileName);
		if (!ifstr.is_open()) {
			cout << "Failed to open" << fileName << "for reading" << endl << "Would you like to create a new data file?" << endl;
			while (enter != 1 && enter != 0) {
				cout << "1- Yes!" << endl << "0- Exit" << "> ";
				cin >> enter;
				if (enter == 1) {
					ifstream ifstr(fileName);
				}
			}
		}
		else {
			while (!ifstr.eof()) {
				char first = ifstr.peek();
				if (first >= '1' && first <= '3') {
					retVal = true;
					iProductArray[noOfIprod] = new Perishable;
					iProductArray[noOfIprod]->load(ifstr);
					if (iProductArray[noOfIprod]->operator bool()) {
						noOfIprod++;
					}
					else {
						delete[] iProductArray[noOfIprod];
					}
				}
				else if (first >= '4' && first <= '9') {
					retVal = true;
					iProductArray[noOfIprod] = new Item;
					iProductArray[noOfIprod]->load(ifstr);
					if (iProductArray[noOfIprod]->operator bool()) {
						noOfIprod++;
					}
					else {
						delete iProductArray[noOfIprod];
					}
				}
				else {
					ifstr.bad();
				}
			}

		}
		return retVal;
	}
}
