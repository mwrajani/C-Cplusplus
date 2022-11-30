/* ------------------------------------------------------
Final project Milestone 2
Module: Menu and AidMan
Filename: main.cpp
Version 1.0
Author: Fardad Soleimanloo   2022-03-03
Revision History
-----------------------------------------------------------
Date          Reason
-----------------------------------------------------------*/
//Muhammad Wajih Rajani
//mwrajani@myseneca.ca
//142199207
//3 / 21 / 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/* Citation and Sources...
Final Project Milestone ?
Module: Date
Filename: Date.h
Version 1.0
Author	Muhammad Wajih
Revision History
-----------------------------------------------------------
Date      Reason
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "AidMan.h"
#include "Utils.h"
int main() {
   std::cout << "Enter the following:\nabc\n1\n2\n3\n4\n5\n6\n7\n8\n0\n--------\n";
   sdds::ut.testMode();
   sdds::AidMan().run();
   return 0;
}