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
#include <fstream>
#include <cstring>
#include "Menu.h"
#include "Utils.h"

using namespace std;
namespace sdds {
	Menu::Menu(int noOpt, const char* listOpt)	{
		if (listOpt != nullptr && noOpt < 16 && noOpt > -1 ) {
			ut.alocpy(this->listOptions, listOpt);
			noOptions = noOpt;
		}
		else {
			this->listOptions = nullptr;
			this->noOptions = 0;
		}
	}
	Menu::~Menu() {
		delete[] listOptions;
		listOptions = nullptr;
	}
	int Menu::run() {
		int enter = -1;
		cout << listOptions<< "0- Exit"<<endl<< "> ";
		cin >> enter;
		while (cin.fail() || enter > noOptions || enter < 0) {
			if (cin.fail()){
				cin.clear();
				cin.ignore(2000, '\n');
				cout << "Invalid Integer, retry: ";
				cin >> enter;
			}
			if (enter > noOptions || enter < 0){
				cout << "Value out of range [0<=val<="<< noOptions <<"]: ";
				cin >> enter;
			}
		}
		return enter;
	}
}
