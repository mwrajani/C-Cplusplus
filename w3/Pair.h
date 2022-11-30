////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////4 / 10 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/*------------------------------------------------------
Workshop 10 part 1
Module: Collection
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date       Reason
----------------------------------------------------------- */
#pragma once
#include <string>
#ifndef SDDS_PAIR_H_
#define SDDS_PAIR_H_
namespace sdds {
	class Pair
	{
		std::string key{};
		std::string value{};
	public:
		const std::string& getKey()const;
		const std::string& getValue()const;
		Pair();
		Pair(const std::string& key, const std::string& value);
		bool operator==(const Pair& other);
		// TODO: Add here the missing prototypes for the members
		//           that are necessary if this class is to be used
		//           with the template classes described below.
		//       Implement them in the Pair.cpp file.
	};
	std::ostream& operator<< (std::ostream& ostr, const Pair& pair);
}
#endif