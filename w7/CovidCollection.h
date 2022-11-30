//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef _SDDS_COVIDCOLLECTION_H
#define _SDDS_COVIDCOLLECTION_H
#include <vector>
#include <iostream>
#include <list>
#include <fstream>
#include <cstring>
using namespace std;
namespace sdds {
	struct Covid
	{
		char country[26];
		char city[26];
		char variant[26];
		size_t numberOfCases;
		int year;
		size_t numberOfDeaths;
	};
	class CovidCollection
	{
	private:
		std::vector<Covid> covidData;
	public:
		CovidCollection(const char*);
		void display(std::ostream& out) const;
		void sort(const char*);
		void cleanList();
		bool inCollection(const char*) const;
		std::list<Covid> getListForCountry(const char*) const;
		std::list<Covid> getListForVariant(const char*) const;
	};
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}
#endif