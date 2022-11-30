#pragma once
#include <cstdio>
#include <iostream>
#include <iomanip>

//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//1 / 23 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
namespace sdds {
	struct dirRecords{
		int totalNoOfRecords;
		char name[50];
		char prefix[11];
		char area[11];
		char number[11];
};
	void startStatement(const char *programTitle);
	void scanDir(const char* fileName, const char* programTitle, dirRecords* records);
	void askpName();
	void getpName(char *pName);
	void phoneDir(const char* programTitle, const char* fileName);

}