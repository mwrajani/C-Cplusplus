/*
Name: Muhammad Wajih Rajani
email: mwrajani@myseneca.ca
Student id: 142199207
Date: 1/30/2022
*/
//> I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//dna.csv
//gttaacca
//gttaaccaa
//!

#define _CRT_SECURE_NO_WARNINGS
#include "cStrTools.h"
#include "DNA.h"
using namespace std;
namespace sdds {
	DNA* dna = nullptr;
	DNA* dnaMatch = nullptr;
	int allocationSize = 0;
	int count = 0;
	FILE* fptr = nullptr;
	
	bool beginSearch(const char* filename) {
		cout << "DNA search program\n";
		fptr = fopen(filename, "r");
		if (fptr == NULL) {
			return false;
		}
		else {
			return true;
		}
	}
	bool read(const char* subDNA) {
		bool matchFound = false;
		count = 0;
		allocationSize = 0;
		char ch = '\0';
		rewind(fptr);
		while (ch != EOF) {
			ch = fgetc(fptr);
			if (ch == '\n') {
				allocationSize++;
			}
		}
		dnaMatch = new DNA[allocationSize];
		dna = new DNA[allocationSize];
		rewind(fptr);
		for (int i = 0; i < allocationSize; i++) {
			dna[i].DNAVal = new char[1001];
			fscanf(fptr, "%d,%[^\n]", &dna[i].sr, dna[i].DNAVal);
		}
		for (int i = 0; i < allocationSize; i++) {
			if (strStr(dna[i].DNAVal, subDNA)) {
				dnaMatch[count].DNAVal = new char[1001];
				strCpy(dnaMatch[count].DNAVal,dna[i].DNAVal);
				dnaMatch[count].sr = dna[i].sr;
				matchFound = true;
				count++;
			}
		}
		return matchFound;
	}
	void sort() {
		char tempMS[1001] = "\0";
		int tempMN = 0;
		for (int j = 0; j < count; j++)
		{
			for(int i = 0; i < count-1; i++)
			{
				if (dnaMatch[i].sr > dnaMatch[i + 1].sr)
				{
					strCpy(tempMS,dnaMatch[i + 1].DNAVal);
					tempMN = dnaMatch[i + 1].sr;
					strCpy(dnaMatch[i + 1].DNAVal,dnaMatch[i].DNAVal);
					dnaMatch[i + 1].sr = dnaMatch[i].sr;
					strCpy(dnaMatch[i].DNAVal,tempMS);
					dnaMatch[i].sr = tempMN;
				}
			}
		}
	}
	void displayMatches() {
		cout << count <<" matches found:\n";
		for (int i = 0; i < count; i++)
		{
			cout << i + 1 << ") " << dnaMatch[i].sr << ":\n" << dnaMatch[i].DNAVal << endl << "======================================================================\n";
		}
	}
	void deallocate() {
		for (int i = 0; i < allocationSize; i++)
		{
			
			delete[] dna[i].DNAVal;			
			delete[] dnaMatch[i].DNAVal;
		}
		delete[] dna;
		delete[] dnaMatch;
	}
	void endSearch() {
		fclose(fptr);
		cout << "DNA Search Program Closed.\n";
		deallocate();
	}
}
