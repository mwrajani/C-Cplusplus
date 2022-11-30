/*
	==================================================
	Workshop #6 (Part-1):
	==================================================
	Name   : Muhammad Wajih Rajani
	ID     : 142199207
	Email  : Mwrajani@myseneca.ca
	Section: NAA
*/
#define maxProducts 3
#define numGrains 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int skuNum;
	double prodPrice;
	int caloriPerServ;
	double prodWeighPound;
};




// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *validationPositiveInt);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* validationPositiveDouble);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int sequenceNumber);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int sequenceNumber);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(int* sku, double* price, double* weight, int* calorie);

// 7. Logic entry point
void start(void);
