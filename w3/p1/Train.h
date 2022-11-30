/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 2/3/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_Train_H // replace with relevant names
#define SDDS_DNA_H
#define MAX_NAME_LEN 20
#define MAX_PEOPLE 1000
#define MAX_SPEED 320
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
namespace sdds {
    class Train
    {
            char nameTrain[MAX_NAME_LEN + 1];
            int totalPeople;
            double trainSpeed;
    public:
        Train();
        ~Train();
        void set(const char*inNameTrain, int inTotalPeople, double inTrainSpeed);
        int getNumberOfPeople() const;
        const char* getName() const;
        double getSpeed() const;
        bool isSafeEmpty() const;
        void display() const;
    };
}
#endif 
