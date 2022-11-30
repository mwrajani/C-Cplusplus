//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//4 / 8 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/* Citation and Sources...
Final Project Milestone ?
Module: Status
Filename: Status.h
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
#pragma once
#ifndef SDDS_AidMan_H
#define SDDS_AidMan_H
#include "iProduct.h"
#include "Utils.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	const int sdds_max_num_items = 100;
	class AidMan
	{
		iProduct* iProductArray[sdds_max_num_items];
		int noOfIprod;
		char* fileName;
		Menu menuObj;
		int menu();
		void deallocate();
		bool load();
		void save();
	public:
		void Update();
		void sort();
		void add();
		void shipping();
		void remove(int index);
		int search(int sku) const;
		AidMan();
		~AidMan();
		AidMan(const AidMan& AidMan) = delete;
		AidMan& operator=(const AidMan& AidMan) = delete;
		void run();
		int list(const char* sub_desc = nullptr);
	};
}
#endif