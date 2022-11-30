/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/6/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Train.h"
using namespace std;
namespace sdds {
	Train::Train() {
		this->set(nullptr, -1, -1);
	}
	Train::~Train() {}
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
	double Train::getSpeed() const {
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
			printf("NAME OF THE TRAIN : %s\n", this->nameTrain);
			printf("NUMBER OF PEOPLE  : %d\n", this->totalPeople);
			printf("SPEED             : %.2lf km/h\n", this->trainSpeed);
		}
		else {
			cout << "Safe Empty State!" << endl;
		}
	}
	bool Train::loadPeople(int numPeople) {
		if (!this->isSafeEmpty()) {
			this->totalPeople += numPeople;
			if (this->totalPeople > MAX_PEOPLE) {
				this->totalPeople = MAX_PEOPLE;
			}
			else if (this->totalPeople < 0) {
				this->totalPeople = 0;
			}
			return true;
		}
		else {
			return false;
		}
	}
	bool Train::changeSpeed(double speedChange) {
		if (!this->isSafeEmpty()) {
			this->trainSpeed += speedChange;
			if (this->trainSpeed > MAX_SPEED) {
				this->trainSpeed = MAX_SPEED;
			}
			else if (this->trainSpeed < 0) {
				this->trainSpeed = 0;
			}
			return true;
		}
		else {
			return false;
		}
	}
	int transfer(Train& movingTo, Train& movingFrom) {
		int iniMovingTo = movingTo.getNumberOfPeople();
		int iniMovingFro = movingFrom.getNumberOfPeople();
		int aftMovTo = 0;
		int returnValue = 0;
		aftMovTo = iniMovingFro + iniMovingTo;
		if (!movingTo.isSafeEmpty() && !movingFrom.isSafeEmpty()) {
			if (aftMovTo > MAX_PEOPLE) {
				aftMovTo = MAX_PEOPLE;
				movingTo.loadPeople(aftMovTo);
				returnValue = aftMovTo - iniMovingTo;
				movingFrom.loadPeople(-returnValue);
			}
			else {
				movingTo.loadPeople(aftMovTo); 
				returnValue = aftMovTo - iniMovingTo;
				movingFrom.loadPeople(-returnValue);
			}
		}
		else {
			returnValue = -1;
		}
		return returnValue;
	}
}