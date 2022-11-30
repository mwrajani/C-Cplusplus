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
#include "ProteinDatabase.h"

using namespace std;
namespace sdds {
	ProteinDatabase::ProteinDatabase() {
		typeArray = nullptr;
		arraySize = 0;
	}
	ProteinDatabase::~ProteinDatabase() {
		delete[] typeArray;
		typeArray = nullptr;
	}
	ProteinDatabase::ProteinDatabase(const char* tName) {
		ifstream ifs(tName);
		string proteinSeq;
		arraySize = 0;
		int counter = -1;
		if (ifs.good()) {
			while (!ifs.eof()) {
				getline(ifs, proteinSeq);
				if (proteinSeq[0] == '>') {
					arraySize++;
				}
			}
			typeArray = new string[arraySize + 1];
			ifs.clear();
			ifs.seekg(std::ios::beg);
			proteinSeq.clear();
			while (!ifs.eof()) {
				getline(ifs, proteinSeq);
				if (proteinSeq[0] == '>') {
					counter++;

				}
				else {
					typeArray[counter] += proteinSeq;
				}
			}
		}
	}

	ProteinDatabase::ProteinDatabase(ProteinDatabase&& moveIt){
		*this = std::move(moveIt);
	}
	ProteinDatabase::ProteinDatabase(const ProteinDatabase& copyIt){
		*this = copyIt;
	}
	ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& copyIt) {
		if (this != &copyIt) {
			if (typeArray != nullptr) {
				delete[] typeArray;
				typeArray = nullptr;
			}
			typeArray = new string[copyIt.arraySize + 1];
			arraySize = copyIt.arraySize;
			for (int i = 0; i < arraySize; i++) {
				typeArray[i] = copyIt.typeArray[i];
			}
		}
		return *this;
	}
	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& moveIt){
		if (this != &moveIt)
		{
			if (typeArray != nullptr) {
				delete[] typeArray;
				typeArray = nullptr;
			}
			typeArray = moveIt.typeArray;
			moveIt.typeArray = nullptr;
			arraySize = moveIt.arraySize;
			moveIt.arraySize = 0;
		}
		return *this;
	}
    size_t ProteinDatabase::size(){
		return arraySize;
	}
    std::string ProteinDatabase::operator[](size_t idx){
		string returnVal = "";
		if (idx >= 0 && idx< arraySize)
		{
			returnVal = typeArray[idx];
		}
		return returnVal;
	}
}
