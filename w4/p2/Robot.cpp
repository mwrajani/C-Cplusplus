/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/14/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Robot.h"
using namespace std;
namespace sdds {
	void Robot::resetInfo() {
		this->Name = nullptr;
		this->Location = nullptr;
		this->Weight = 0;
		this->Width = 0;
		this->Height = 0;
		this->Speed = 0;
		strcpy(this->Deployed, "0");
	}
	Robot::Robot(){
		this->resetInfo();
	}
	Robot::~Robot() {
		delete[] this->Name;
		delete[] this->Location;
	}
	Robot::Robot(const char* name,const char* location, double weight, double width, double height, double speed, bool deployment){
		this->resetInfo();
		this->set(name, location, weight, width, height, speed,  deployment);
	}
	Robot& Robot::set(const char* name,const char* location, double weight, double width, double height, double speed, bool deployment) {
		this->~Robot();
		this->resetInfo();
		this->setLocation(location);
		this->Name = new char[strlen(name)+1];
        strcpy(this->Name, name);
		this->Weight = weight;
		this->Height = height;
		this->Width = width;
		this->Speed = speed;
		this->setDeployed(deployment);
		return *this;
	}
	void Robot::setLocation(const char* location){
		this->Location = nullptr;
		this->Location = new char[strlen(location)+1];
		strcpy(this->Location, location);
	}
	void Robot::setDeployed(bool deployment){
		strcpy(this->Deployed, "0");
		if (deployment) {
			strcpy(this->Deployed, "YES");
		}
		else {
			strcpy(this->Deployed, "NO");
		}
	}
	char* Robot::getName() const{
		return this->Name;
	}
	char* Robot::getLocation() const{
		return this->Location;
	}
	bool Robot::isDeployed() const {
		bool returnValue = false;
		if (strcmp(this->Deployed, "YES") == 0) {
			returnValue = true;
		}
		return returnValue;
	}
	bool Robot::isValid()const {
		return (this->Name != nullptr && this->Location != nullptr && this->Weight > 0 && this->Width > 0 && this->Height > 0 && this->Speed > 0);
	}
	double Robot::speed()const {
		return this->Speed;
	}
	void Robot::display() const{
		cout << "| " << setw(10) << left << this->getName() << " | " << setw(15) << left << this->getLocation() << " | " << fixed << setprecision(1) << setw(6) << right << this->Weight << " | " << setprecision(1) << setw(6) << right << this->Width << " | " << setprecision(1) << setw(6) << right << this->Height << " | " << setw(6) << right << this->speed() << " | " << setw(8) << left << this->Deployed<< " |" << endl;
	}
	int conrtolRooomReport(const Robot robot[], int num_robots) {
		int i = 0, returnValue = -1, fastest = -1, deployed = 0;
		cout <<"                        ------ Robot Control Room -----"<< endl;
		cout <<"                    ---------------------------------------" << endl;
		
		cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |"<< endl;
		cout << "|------------+-----------------+--------+--------+--------+--------+----------|"<< endl;
		while (returnValue == -1 && i < num_robots)
		{
			if (robot[i].isValid() == true) {
				robot[i].display();
				if (robot[i].isDeployed()) {
					deployed++;
				}
				if (i < num_robots -1) {
					if (robot[i].speed() > robot[i + 1].speed()) {
						fastest = i;
					}
				}
				}
			else {
				returnValue = i;
				return returnValue;
			}
			i++;
		}
			cout << "|=============================================================================|" << endl;
			cout << "| SUMMARY:                                                                    |" << endl;
			cout << "| " << deployed << "  robots are deployed.                                                     |" << endl;
			cout << "| The fastest robot is:                                                       |" << endl;
			cout << "| Robot ID   | Location        | Weight |  Width | Height |  Speed | Deployed |" << endl;
			cout << "|------------+-----------------+--------+--------+--------+--------+----------|" << endl;
			robot[fastest].display();
			cout << "|=============================================================================|" << endl;
		i++;
		return returnValue;
    }
}