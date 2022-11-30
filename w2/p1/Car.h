#pragma once
/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 1/28/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_Car_H // replace with relevant names
#define SDDS_Car_H
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string>
namespace sdds {
 struct Car 
	{
	 char LicenseN[9] = { 0 };
	 int time;
	 char *makeNdModel;
 };
 void VBPLE_Title();
 void initialize(int allocSize);
 void deallocate(Car &C);
 bool read(Car& C);
 void record(const Car& C);
 void endOfDay();
 void print(const Car& C);
}
#endif