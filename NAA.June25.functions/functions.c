#include<stdio.h>
#include"prototypes.h"


int main(void)
{
	int Bob = 9, Jane = 7, Mary = 0, Theophilus = 0, Mao = 0;

	Mary = add(Bob, Jane);
	printf("Mary == %d\n", Mary);

	arithmetic(&Bob, &Jane, &Mary, &Theophilus, &Mao);//pass by reference
	printf("\nMary == %d, Theophilus == %d, Mao == %d\n", Mary, Theophilus, Mao);

	return 0;
}

