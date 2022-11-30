#include"manipulating.h"

void manipulating() {
	printf("*** Start of Concatenating Strings Demo ***\n");
	char string1[80];
	char string2[80];
	while (TRUE) {
		printf("Type the 1st string (q - to quit): \n");
		gets(string1);
		if (strcmp(string1, "q") == 0) break;
		printf("Type the 2nd string:\n");
		gets(string2);
		strcat(string1,string2);
		printf("Concatenated string is \'%s\'\n", string1);
	}
	printf("*** End of Concatenating Strings Demo ***\n\n");
}