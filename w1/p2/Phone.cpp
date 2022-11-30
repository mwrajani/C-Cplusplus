#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include "cStrTools.h"

//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//1 / 23 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
using namespace std;
namespace sdds{

	void startStatement(const char *programTitle){
		cout << programTitle<<" phone direcotry search\n-------------------------------------------------------" << endl;
	}

	void scanDir(const char *fileName, const char* programTitle, dirRecords *records) {
		int i = 0;
		
		FILE* fptr = fopen(fileName, "r");
		if (fptr == NULL) {
			cout<<"badDataFile.txt file not found!\n";
		    cout<<"Thank you for using "<< programTitle<< " directory." << endl;
		}
		else {
			do
			{
				fscanf(fptr, "%[^\t]\t%s\t%s\t%s", records[i].name, records[i].area, records[i].prefix, records[i].number);
				i++;
			} while (fgetc(fptr) != EOF);
			fclose(fptr);
			records->totalNoOfRecords = i;	
		}
	}

	void askpName() {
		cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
    } 

	void getpName(char *pName) {
		cout << "> ";
		cin >> pName;
		toLowerCaseAndCopy(pName, pName);
	}

	void phoneDir(const char* programTitle, const char* fileName) {
		char pName[50] = {0};
		dirRecords records[200] = { 0 };
		char LowerName[50];
        int recordNo, i;
		startStatement(programTitle);
		scanDir(fileName, programTitle, records);
		recordNo = records->totalNoOfRecords;
		if (recordNo != 0){
			while (strCmp(pName, "!") != 0) {
				i = 0;
				askpName();
				getpName(pName);
				while (i < recordNo && strCmp(pName, "!") != 0) {
					toLowerCaseAndCopy(LowerName, records[i].name);
					if (strStr(LowerName, pName)) {		
						
						cout << records[i].name << ": (" << records[i].area << ") " << records[i].prefix << "-" << records[i].number << endl;
					}
					i++;
				}
				if (strCmp(pName, "!") == 0)
				{
					cout << "Thank you for using "<< programTitle <<" directory.\n";
				}
				
			}
		}
	}
}



