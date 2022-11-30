////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "foodorder.h"


using namespace std;
double g_taxrate = 0;
double g_dailydiscount = 0;
namespace sdds {
	FoodOrder& FoodOrder::operator=(const FoodOrder& order) {
		strcpy(custName, order.custName);
		custName[9] = '\0'; 
		/*delete[] foodDesc;
		foodDesc = nullptr;*/
				foodDesc = new char[strlen(order.foodDesc) + 1];
				strcpy(foodDesc, order.foodDesc);
			price = order.price;
			isSpecial = order.isSpecial;
		return *this;
	}
	FoodOrder::FoodOrder(const FoodOrder& order) {
		*this = order;
	}
	FoodOrder::FoodOrder(){
		custName[0]= '\0';
		foodDesc = nullptr;
		price = 0;
		isSpecial = false;
	}
	FoodOrder::~FoodOrder() {
		if (foodDesc!= nullptr) {
			delete[] foodDesc;
			foodDesc = nullptr;
		}
	}
	void FoodOrder::read(std::istream& is){
		string description;
		char isspecial;
		if (is.good()) {
			is.getline(custName,10,',');
			getline(is, description, ',');
			if (foodDesc != nullptr) {
				delete[] foodDesc;
				foodDesc = nullptr;
			}
			foodDesc = new char[strlen(description.c_str()) + 1];
			strcpy(foodDesc, description.c_str());
			is >> price;
			is.ignore(2000, ',');
			is >> isspecial;
			isSpecial = (isspecial == 'Y' ? true : false);
		}
	}
	void FoodOrder::display()const{
		static int counter = 1;
		if (custName[0] != '\0') {
			if (isSpecial) {
				cout << setw(2) << left << counter << ". " << setw(10) << custName << "|" << setw(25) << left << foodDesc << left << "|" << fixed << setprecision(2) << setw(12) << price + (price * g_taxrate) << right << "|" << fixed << setprecision(2) << setw(13) << (price + (price * g_taxrate) ) - g_dailydiscount << endl;
			}
			else
			{
				cout << setw(2) << left << counter << ". " << setw(10) << custName << "|" << setw(25) << left << foodDesc << left << "|" << fixed << setprecision(2) << setw(12) << price + (price * g_taxrate) << right << "|"<< endl;
			}
		}
		else {
			cout << setw(2) << left << counter << ". " << "No Order" << endl;
		}
		counter++;
	}
}
