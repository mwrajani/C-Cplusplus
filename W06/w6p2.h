/*
	==================================================
	Workshop #6 (Part-2):
	==================================================
	Name   : Muhammad Wajih Rajani
	ID     : 142199207
	Email  : Mwrajani@myseneca.ca
	Section: NAA
*/

// ----------------------------------------------------------------------------
// defines/macros
#define maxProducts 3
#define numGrains 64
#define lbsToKg 2.20462



// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
	int skuNum;
	double prodPrice;
	int caloriPerServ;
	double prodWeighPound;
};
struct ReportData
{
	int prodSkuNum;
	double prodPrice;
	int caloriPerServ;
	double prodWeighPound;
	double prodWeighKilo;
	int prodWeighGram;
	double totalServ;
	double costPerServing;
	double costCaloriePerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* validationPositiveInt);

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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* pounds, double* kiloGrams);



// 9. convert lbs: g
int convertLbsG(const double* pounds, int* grams);

// 10. convert lbs: kg / g
void convertLbs(const double* pounds, double* kiloGrams, int* grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int serveSizGrams, const int totalGramsProd, double* totalServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* prodPrice, const double* totalServes, double* costServe);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* prodPrice, const double* totalCal, double* costCalori);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo itemProd);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData rowData, const int ifCheapest);


// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapestProduct);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start(void);