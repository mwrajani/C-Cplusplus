//these are function prototypes, they are the patterns for your functions
//during compilation the compiler first checks the syntax of your code, like a grammar check,
//if their are syntax errors the code is not compiled and an error message is returned

//add recieves two int values, adds them together and returns the result
int add(int one, int two);

//subtract recieves three pointers to int, divides the value stored at the first
//by the value stored at the second, and stores the result in result by dereferencing it's address
//then multiplies the value stored at numerator by the value stored at dennominator,
//and stores the result in result by dereferencing it's address
void arithmetic(int* numerator, int* denominator, int* result, int*secondResult);
