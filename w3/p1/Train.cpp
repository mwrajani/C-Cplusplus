/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/3/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
using namespace std;
namespace sdds {
	Train::Train() {
		this->set(nullptr, -1, -1);
	}
	Train::~Train(){}
	void Train::set(const char* inNameTrain, int inTotalPeople, double inTrainSpeed) {
		if (inNameTrain != nullptr && strlen(inNameTrain) > 0 && inTotalPeople >= 0 && inTotalPeople <= MAX_PEOPLE && inTrainSpeed >= 0 && inTrainSpeed <= MAX_SPEED) {
			strncpy(this->nameTrain, inNameTrain, MAX_NAME_LEN);
			this->trainSpeed = inTrainSpeed;
			this->totalPeople = inTotalPeople;
		}
		else {
			this->nameTrain[0] = '\0';// if there is any name, then it's first character should not be null.
			this->trainSpeed = -1;// train speed can never be a negative value.
			this->totalPeople = -1;// the number of people can never be a negative value.
		}

	}
	int Train::getNumberOfPeople() const {
		return this->totalPeople;
	}
	const char* Train::getName() const {
		return this->nameTrain;
	}
	double Train::getSpeed() const{
		return this->trainSpeed;
	}
	bool Train::isSafeEmpty() const {
		if (this->nameTrain[0] == '\0' && this->trainSpeed == -1 && this->totalPeople == -1) {
			return true;
		}
		else {
			return false;
		}
	}
	void Train::display() const {
		if (!this->isSafeEmpty()) {
			cout << "NAME OF THE TRAIN : " << this->nameTrain << endl;
			cout << "NUMBER OF PEOPLE  : " << this->totalPeople << endl;
			cout << "SPEED             : " << this->trainSpeed << " km/h" << endl;
		}
		else {
			cout << "Safe Empty State!"<< endl;
		}
	}
}