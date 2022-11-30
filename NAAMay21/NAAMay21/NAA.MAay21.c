#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int how_many_allah = 0;
	/*oranges = 2;<- used to put int the value of oranges*/
	printf("i like my religion! how_many_allah?");//(it does not give each stement another line) %d is a placeholder that tells printf to look at the arguments and
	// print the value inside a variable 
	// the first place holder gets the values stored in side the first argument, scanf reads from input buffer, and it requires address not name of variable
	scanf("%d", &how_many_allah);
	
	printf("if answered any thing else then 1 you're wrong as there is only one infinity.\n");/*this lets you coment as many lines as much you 
								                                                            want*/
	return 0;
}