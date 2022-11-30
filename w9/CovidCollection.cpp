//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include "CovidCollection.h"
using namespace std;
namespace sdds
{
std::string& trimmer(std::string& edit)
{
	edit.erase(0, edit.find_first_not_of(' '));
	edit.erase(edit.find_last_not_of(' ') + 1);
	return edit;
}
CovidCollection::CovidCollection(const char* file) {
	ifstream filename(file);
	string edit;
	if (!file)
	{
		std::cerr << "ERROR: Cannot open file [" << file << "].\n";
	}
	while (getline(filename, edit, '\n')) {
		char number[6];
		Covid temp;
		string trimming;
		strcpy(temp.country, edit.substr(0, 25).c_str());
		trimming = temp.country;
		trimming = trimmer(trimming);
		strcpy(temp.country, trimming.c_str());
		strcpy(temp.city, edit.substr(25, 25).c_str());
		trimming = temp.city;
		trimming = trimmer(trimming);
		strcpy(temp.city, trimming.c_str());
		strcpy(temp.variant, edit.substr(50, 25).c_str());
		trimming = temp.variant;
		trimming = trimmer(trimming);
		strcpy(temp.variant, trimming.c_str());
		strcpy(number, edit.substr(75, 5).c_str());
		trimming = number;
		trimming = trimmer(trimming);
		temp.year = stoi(trimming);
		strcpy(number, edit.substr(80, 5).c_str());
		trimming = number;
		trimming = trimmer(trimming);
		temp.numberOfCases = stoi(number);
		strcpy(number, edit.substr(85, 5).c_str());
		trimming = number;
		trimming = trimmer(trimming);
		temp.numberOfDeaths = stoi(number);
		covidData.push_back(temp);
	}
}
	void CovidCollection::display(std::ostream& out) const {
		size_t cases = 0;
		size_t deaths = 0;
		for_each(covidData.begin(), covidData.end(), [&out, &deaths, &cases](Covid theCovid) {
			cases = cases + theCovid.numberOfCases;
			deaths = deaths + theCovid.numberOfDeaths;
			out << theCovid << endl;
			});
		out << "----------------------------------------------------------------------------------------"<<endl;
		out << "| " << right << setw(78) << "Total Cases Around the World: " << right << setw(6) << cases<< " |"<<endl;
		out << "| " << right << setw(78) << "Total Deaths Around the World: " << right << setw(6) << deaths << " |" << endl;
	}
	std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
		int outp = NULL;
		out << "| " << left << setw(21) << theCovid.country << " | " << left << setw(15) << theCovid.city << " | " << left << setw(20) << theCovid.variant << " | " << right << setw(6);
		if (theCovid.year > 0)
		{
		out	<< theCovid.year<< " | " << right << setw(4) << theCovid.numberOfCases << " | " << right << setw(3) << theCovid.numberOfDeaths << " |";
		}
		else {
			out << "       | " << right << setw(4) << theCovid.numberOfCases << " | " << right << setw(3) << theCovid.numberOfDeaths << " |";
		}
		return out;
	}
void CovidCollection::sort(const char* param) {
		if (strcmp(param, "country") == 0)
		{
			std::sort(covidData.begin(), covidData.end(), [](Covid first, Covid second) {
				if (strcmp(first.country, second.country) > 0) {
					return false;
				}
				if (strcmp(first.country, second.country) < 0) { return true; }
				});
		}
			if (strcmp(param, "variant") == 0)
			{
				std::sort(covidData.begin(), covidData.end(), [](Covid first, Covid second) { 
					if (strcmp(first.variant, second.variant) > 0) {
						return false;
					}
					if (strcmp(first.variant, second.variant) < 0) { return true; }
					});
			}
			if (strcmp(param, "deaths") == 0)
			{
				std::sort(covidData.begin(), covidData.end(), [](Covid first, Covid second) { return first.numberOfDeaths< second.numberOfDeaths; });
			}
			if (strcmp(param, "cases") == 0)
			{
				std::sort(covidData.begin(), covidData.end(), [](Covid first, Covid second) { return first.numberOfCases < second.numberOfCases; });
			}
	}
	void CovidCollection::cleanList() {
		for_each(covidData.begin(), covidData.end(), [](Covid& theCovid) {
			if (strcmp(theCovid.variant, "[None]") == 0) {
				for (int i = 0; i < 25; i++) {
					theCovid.variant[i] = '\0';
				}
			}
			});
	}
	bool CovidCollection::inCollection(const char* param) const {
		bool returnVal = false;
		for_each(covidData.begin(), covidData.end(), [&param, &returnVal](Covid theCovid) {
			if (strcmp(theCovid.variant, param) == 0 && strcmp(theCovid.variant, "") != 0) {
				returnVal = true;
			} });

		return returnVal;
	}
	std::list<Covid> CovidCollection::getListForCountry(const char* param) const {
		list<Covid> returnVal;
		for_each(covidData.begin(), covidData.end(), [&param, &returnVal](Covid theCovid) {
			if (strcmp(theCovid.country, param) == 0) {
				returnVal.push_back(theCovid);
			}
			});

		return returnVal;
	}
	std::list<Covid> CovidCollection::getListForVariant(const char* param) const {
		list<Covid> returnVal;
		for_each(covidData.begin(), covidData.end(), [&param, &returnVal](Covid theCovid) {
			if (strcmp(theCovid.variant, param) == 0) {
				returnVal.push_back(theCovid);
			}
			});

		return returnVal;
	}
};