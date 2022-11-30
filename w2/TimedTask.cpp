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
#include "TimedTask.h"

using namespace std;
namespace sdds {
	TimedTask::TimedTask() {
		noOfRecords = 0;
	}
	void TimedTask::startClock() {
		ts = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock() {
		te = std::chrono::steady_clock::now();
	}
	void TimedTask::addTask(const char* tName) {
		if (noOfRecords < maximumNoEvents) {
			this->taskObj[noOfRecords].taskName = tName;
			this->taskObj[noOfRecords].unitTime = "nanoseconds";
			this->taskObj[noOfRecords].td = std::chrono::duration_cast<std::chrono::nanoseconds>(te - ts);
			noOfRecords++;
		}
	}

	std::ostream& operator<< (std::ostream& ostr, const TimedTask& timeTask) {
		ostr << "--------------------------" << endl << "Execution Times:" << endl << "--------------------------" << endl;
		for (int i = 0; i < timeTask.noOfRecords; i++)
		{
			ostr << setw(21) << left << timeTask.taskObj[i].taskName << ' ' << setw(13) << right << timeTask.taskObj[i].td.count()<<' '<< timeTask.taskObj[i].unitTime << endl;
		}
		return ostr;
	}
}
