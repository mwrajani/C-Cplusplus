#include<stdio.h>
#include"prototypes.h"


int main(void)
{
	int first = 7, second = 9, third = 0, fourth = 0;

	third = add(first, second);

	printf("first + second == %d\n", third);

	//pass the address of 4 ints to the function, using the ampersand &
	arithmetic(&second, &first, &third, &fourth);

	printf("first/second == %d\n", third);

	printf("first * second == %d\n", fourth);

	return 0;
}


