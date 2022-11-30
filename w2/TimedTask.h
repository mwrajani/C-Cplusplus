////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#include <chrono>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_
using namespace std; 
namespace sdds {
    class TimedTask {
        #define maximumNoEvents 10 
        int noOfRecords;
        std::chrono::steady_clock::time_point ts;
        std::chrono::steady_clock::time_point te;
        struct Task{
            string taskName;
            string unitTime;
            std::chrono::steady_clock::duration td;
        }taskObj[maximumNoEvents];
    public:
       TimedTask();
       void startClock();
       void stopClock();
       void addTask(const char* tName);
       friend std::ostream& operator<< (std::ostream & ostr, const TimedTask& timeTask);
    };
}
#endif 

