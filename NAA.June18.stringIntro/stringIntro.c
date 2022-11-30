#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#define SZ 31

int main(void)
{
	int i;
	//creates a char array (C string) that can hold upo to SZ-1 characters plus the NUll ('\0' or just 0)
	//str1 is instantiated in a safe state by setting all elements to 0, which is the same as '\0'
	char str1[SZ] = { 0 };
	//the programmer is responsible for keeping track of the number of characters stored in a string
	char str2[SZ] = "Hello world!";

	
	printf("Enter your name: ");//Bob Smith
	//reads up to 30 characters, stops at 30 or the new line
	//if the new line is read, the buffer is cleared
	scanf("%30[^\n]", str1);
	printf("%s\n", str1);
	while (getchar() != '\n');
	scanf("%s", str1);
	printf("%s\n", str1);

	//scanf("%s reads characters from stdin and stores thaem in the char array passed as an argument (str1)
	//scanf(%s stops reading when a space or new line is encountered
	//printf("Enter your name: ");//Bob Smith
	//scanf("%s", str1);
	//printf("%s\n", str1);
	//scanf("%s", str1);
	//printf("%s\n", str1);

	//strcpy(str1, str2);//programmer is responsible for providing an argument of the correct size
	//printf("%s\n", str1);
	//strcpy(str1, "Bye bye");
	//printf("%s\n", str1);

	//putchar outputs a provided char to the screen and returns a copy of the char that is output
	//when putchar reads the NULL byte from the string it returns the NULL which is evaluated as false
	//and the loop ends
	//for (i = 0; i < SZ && putchar(str2[i]); i++);

	//scanf("%s reads characters from stdin and stores thaem in the char array passed as an argument (str1)
	//scanf(%s stops reading when a space or new line is encountered
	//printf("Enter your name: ");//Bob Smith
	//scanf("%s", str1);
	//printf("%s\n", str1);
	//scanf("%s", str1);
	//printf("%s\n", str1);

	/*for ( i = 0; i < SZ + 3; i++)
	{
	//This will overflow the memory allocated to str1, causing a program crash or worse
		str1[i] = 'a';
	}
	printf("%s\n", str1);*/
	return 0;
}
