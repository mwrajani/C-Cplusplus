/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 1/30/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#pragma once
#ifndef SDDS_DNA_H // replace with relevant names
#define SDDS_DNA_H

#include <cstdio>
#include <iostream>
#include <iomanip>
namespace sdds {
	struct DNA {
		int	sr = 0;
		char* DNAVal = nullptr;
	};
	bool beginSearch(const char* filename);
	bool read(const char* subDNA);
	void sort();
	void displayMatches();
	void deallocate();
	void endSearch();
}

#endif