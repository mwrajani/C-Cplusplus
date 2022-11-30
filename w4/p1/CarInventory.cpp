/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/11/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "CarInventory.h"
using namespace std;
namespace sdds {
	void CarInventory::resetInfo() {
		 this->m_type = nullptr;
		 this->m_brand = nullptr;
		 this->m_model = nullptr;
		 this->m_year = 0;
		 this->m_code = 0;
		 this->m_price = 0;
	}
	CarInventory::CarInventory() {
		this->resetInfo();
	}
	CarInventory::~CarInventory() {
		delete[] this->m_type;
		delete[] this->m_brand;
		delete[] this->m_model;
	}

	CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
		this->resetInfo();
		this->setInfo(type, brand, model, year, code, price);
	}
	CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year, int code, double price) {
			this->~CarInventory();
		if (type != nullptr && brand != nullptr && model != nullptr && year > 1990 && code > 99 && code < 1000 && price > 0) {
			this->m_type = new char[strlen(type) + 1];
			this->m_brand = new char[strlen(brand) + 1];
			this->m_model = new char[strlen(model) + 1];
			strcpy(this->m_type, type);
			strcpy(this->m_brand, brand);
			strcpy(this->m_model, model);
			m_year = year;
			m_code = code;
			m_price = price;
		}
		else {
			this->resetInfo();
		}
		return *this;
	}
void CarInventory::printInfo() const {
			cout << "| "<< setw(10)<< left<< m_type<< " | "<< setw(16)<< left<< m_brand<< " | "<< setw(16)<< left<< m_model;
			cout << " | " << setw(4) << right << m_year << " | " << setw(4) << right << m_code << " | " << fixed << setprecision(2) << setw(9) << right << m_price << " |" << endl;
}
	bool CarInventory::isValid() const {
		return (m_type != nullptr && m_brand != nullptr && m_model != nullptr && m_year > 1990 && m_code > 99 && m_code < 1000 && m_price > 0);
	}
	bool CarInventory::isSimilarTo(const CarInventory& car) const {
		bool returnValue = false;
		if(car.isValid() && this->isValid()){
			returnValue = (strcmp(car.m_type, this->m_type) == 0 && strcmp(car.m_brand, this->m_brand) == 0 && strcmp(car.m_model, this->m_model) == 0 && car.m_price == this->m_price && car.m_year == this->m_year && car.m_code == this->m_code);
		}
		else if (!car.isValid() && !this->isValid()) {
			returnValue = true;
		}
		return returnValue;
	}
	bool find_similar(CarInventory car[], const int num_cars) {
		bool retVal = false;
		for (int i = 0; i < num_cars; i++) {
			for (int j = i + 1; j < num_cars; j++) {
				if (car[i].isSimilarTo(car[j])) {
					retVal = true;
				}
			}
		}
		return retVal;
	}

}
