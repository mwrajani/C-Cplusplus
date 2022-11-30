////Muhammad Wajih Rajani
////mwrajani@myseneca.ca
////142199207
////5 / 22 / 2022 
////I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#pragma once
#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
extern double g_taxrate;
extern double g_dailydiscount;
namespace sdds {
    class FoodOrder{
        char custName[10];
        char* foodDesc;
        double price;
        bool isSpecial;
    public:
        FoodOrder(const FoodOrder& ord);
        FoodOrder& operator=(const FoodOrder& ord);
        FoodOrder();
        ~FoodOrder();
        void read(std::istream&);
        void display()const;
    };
}
#endif 
