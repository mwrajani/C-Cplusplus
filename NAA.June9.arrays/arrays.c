#include<stdio.h>

#define SZ 6

int main(void)
{
	int i;//iterator
	//{ 0 } is an alias for {0,0,0,0,0,0}
	int ar[SZ] = { 0 };//instantiate an int array that holds SZ elements and set it to a safe state
	//an array is a collection of values of the same type stored in contiguous memory
	//ar[0|0|0|0|0|0|] //the address of the array is stored in its name and is the address of the 1st byte
	//in the block of memory assigned to the array

	for ( i = 0; i < SZ; i++)
	{

		printf("i == %d, ar[i] == %d ", i, ar[i]);
		ar[i] = i + 1;
	}

	printf("\n\n");

	for ( i = 0; i < SZ; i++)
	{
		printf("%d ", ar[i]);
	}

	return 0;
}

//ar[i] is calling for the value stored in ar at index (offset) i, if i is equal to 2, we get the 3rd value
//ar[ value 1, index 0|value 2, index 1| and so on to |value 6 at index 5]
//offset is referring to the fact that the index of an array member is a value representing the amount needed
//to add to the array address to find the required value
//index 0 (ar[0]) means add nothing to ther address of the array
//index 2 (ar[2]) means add the size of 2 elements (integers are usually 4 or 8 bytes in size) 
//to the base address to find the 3rd element.