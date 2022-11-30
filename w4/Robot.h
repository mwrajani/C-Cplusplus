/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/14/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef _SDDS_ROBOT_H // replace with relevant names
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
namespace sdds {
	class Robot
	{
		char* Name;
		char* Location;
		double Weight;
		double Width;
		double Height;
		double Speed;
		char Deployed[4];
		void resetInfo();
	public:
		Robot();
		Robot(const char* name,const char* location, double weight, double width, double height, double speed, bool deployment);
		~Robot();
		Robot& set(const char* name,const char* location, double weight, double width, double height, double speed, bool deployment);
		void setLocation(const char* location);
		void setDeployed(bool deployment);
		char* getName() const;
		char* getLocation() const;
		bool isDeployed() const;
		bool isValid() const;
		double speed() const;
		void display() const;
	};
	int conrtolRooomReport(const Robot robot[], int num_robots);
	}
#endif