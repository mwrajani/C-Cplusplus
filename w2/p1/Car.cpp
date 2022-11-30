/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 1/28/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "Car.h"
#include "cStrTools.h"
using namespace std;

namespace sdds {
    Car *carList = nullptr;
    int totalCars = 0;
    int allocationSize = 0;
    int arrSize = 0;
    void VBPLE_Title() {
        cout<< "Vehicle Border Passing Log Entry\nEnter the data in the following format:\nMake and model,LicensePlate,MilitaryTime<ENTER>\nExit the program by entering the following:\nX,< ENTER>" << endl;
    }
    void initialize(int allocSize) {
        totalCars = 0;
        allocationSize = allocSize;
        carList = new Car[allocSize];
    }

    void deallocate(Car& C){
        if (C.makeNdModel != nullptr){
            delete [] C.makeNdModel;
        }
    }
    bool read(Car& C) {
        bool carRecorded = false;
        char makeNdModel[61];
        char time[10];
        read(makeNdModel, 60, ',');
        if (strCmp(makeNdModel, "X") != 0){
            carRecorded = true;
            C.makeNdModel = new char[strLen(makeNdModel) + 1];
            strCpy(C.makeNdModel, makeNdModel);
            read(C.LicenseN, 8, ',');
            read(time, 6);
            C.time = stoi(time);
        }
        return carRecorded;
    }
    void print(const Car& C) {
        cout << C.time << ": " << C.makeNdModel << "," << C.LicenseN << endl;
    }
    void record(const Car&C) {
        if (totalCars == arrSize) {
            int i = 0;
            Car* tempAr = new Car[arrSize + allocationSize];
            for (i = 0; i < arrSize; i++) {
                strCpy(tempAr[i].LicenseN, carList[i].LicenseN);
                tempAr[i].time = carList[i].time;
                tempAr[i].makeNdModel = carList[i].makeNdModel;
            }
            arrSize += allocationSize;
            delete[] carList;
            carList = tempAr;
            tempAr = nullptr;
        }
        strCpy(carList[totalCars].LicenseN, C.LicenseN);
        carList[totalCars].time = C.time;
        carList[totalCars].makeNdModel = C.makeNdModel;
        totalCars++;
    }
    void endOfDay() {
        int i = 0;
        for ( i = 0; i < totalCars; i++)
        {
            print(carList[i]);
            deallocate(carList[i]);
        }
        delete[] carList;
    }
}