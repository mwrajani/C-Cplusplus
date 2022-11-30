/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/11/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef _SDDS_CARINVENTORY_H // replace with relevant names
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
namespace sdds {
	class CarInventory
	{
		char* m_type;
		char* m_brand;
		char* m_model;
		int m_year;
		int m_code;
		double m_price;
		void resetInfo();
	public:
		CarInventory();
		CarInventory(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1);
		~CarInventory();
		CarInventory& setInfo(const char* type, const char* brand, const char* model, int year, int code, double price);
		void printInfo() const;
		bool isValid() const;
		bool isSimilarTo(const CarInventory& car) const;
	};
	bool find_similar(CarInventory car[], const int num_cars);
}
#endif 