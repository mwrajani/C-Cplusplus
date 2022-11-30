/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Muhammad Wajih Rajani
	ID     : 142199207
	Email  : mwrajani@myseneca.ca
	Section: NAA
*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"user defined data types.h"
int main(void)
{
	struct PlayerInfo playerInfo;
	struct GameInfo gameInfo;
	playerInfo.treasureCount = 0;
	int i = 0, positionCalculator = 0, positionValue = 0, positionValue1 = 0;
	int j = 0;
	int nextMove = 0;
	int treasureFlag = 0;
	int bombFlag = 0;
	char gamePlayVariables[70] = { 0 };
	int gamePlayVariables1Workings = 1;

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf("%c", &playerInfo.symbolUser);
	printf("Set the number of lives: ");
	scanf(" %d", &playerInfo.numberOfLives);
	while (playerInfo.numberOfLives > 10 || playerInfo.numberOfLives < 1)
	{
		printf("     Must be between 1 and 10!");
		printf("\nSet the number of lives: ");
		scanf(" %d", &playerInfo.numberOfLives);
	}
	printf("Player configuration set-up is complete\n\n");
	printf("GAME Configuration\n");
	printf("------------------\n");
	printf("Set the path length (a multiple of 5 between 10-70): ");
	scanf("%d", &gameInfo.pathLength);
	while (gameInfo.pathLength > 70 || gameInfo.pathLength < 10 || gameInfo.pathLength % 5 != 0)
	{
		printf("     Must be a multiple of 5 and between 10-70!!!");
		printf("\nSet the path length (a multiple of 5 between 10-70): ");
		scanf("%d", &gameInfo.pathLength);
	}
	printf("Set the limit for number of moves allowed: ");
	scanf("%d", &gameInfo.maximumNumOfMoves);
	while (gameInfo.maximumNumOfMoves > (gameInfo.pathLength * 75 / 100) || gameInfo.maximumNumOfMoves < playerInfo.numberOfLives)
	{
		printf("    Value must be between %d and %d", playerInfo.numberOfLives, gameInfo.pathLength * 75 / 100);
		printf("\nSet the limit for number of moves allowed: ");
		scanf("%d", &gameInfo.maximumNumOfMoves);
	}
	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameInfo.pathLength);
	positionCalculator = gameInfo.pathLength;

	positionValue = 0;
	positionValue1 = 4;

	while (positionCalculator > 0)
	{

		positionCalculator -= 5;

		printf("   Positions [%2d-%2d]: ", 1 + positionValue, positionValue1 + 1);
		scanf("%d %d %d %d %d",
			&gameInfo.bombLocations[positionValue + 1], &gameInfo.bombLocations[positionValue + 2], &gameInfo.bombLocations[positionValue + 3], &gameInfo.bombLocations[positionValue + 4], &gameInfo.bombLocations[positionValue + 5]);
		positionValue += 5;
		positionValue1 += 5;
	}
	printf("BOMB placement set\n");
	printf("\nTREASURE Placement");
	printf("\n------------------");
	printf("\nEnter the treasure placements in sets of 5 where a value");
	printf("\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.");
	printf("\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gameInfo.pathLength);
	positionCalculator = gameInfo.pathLength;
	positionValue = 0;
	positionValue1 = 4;

	while (positionCalculator > 0)
	{

		positionCalculator -= 5;

		printf("   Positions [%2d-%2d]: ", 1 + positionValue, positionValue1 + 1);
		scanf("%d %d %d %d %d",
			&gameInfo.treasureLocations[positionValue + 1], &gameInfo.treasureLocations[positionValue + 2], &gameInfo.treasureLocations[positionValue + 3], &gameInfo.treasureLocations[positionValue + 4], &gameInfo.treasureLocations[positionValue + 5]);


		positionValue += 5;
		positionValue1 += 5;
	}

	printf("TREASURE placement set\n");
	printf("\nGAME configuration set-up is complete...\n");
	printf("\n------------------------------------");
	printf("\nTREASURE HUNT Configuration Settings");
	printf("\n------------------------------------");
	printf("\nPlayer:");
	printf("\n   Symbol     : %c", playerInfo.symbolUser);
	printf("\n   Lives      : %d", playerInfo.numberOfLives);
	printf("\n   Treasure   : [ready for gameplay]");
	printf("\n   History    : [ready for gameplay]\n");
	printf("\nGame:");
	printf("\n   Path Length: %d", gameInfo.pathLength);
	printf("\n   Bombs      : ");
	for (i = 1; i < (gameInfo.pathLength + 1); i++)
	{
		printf("%d", gameInfo.bombLocations[i]);
	}
	printf("\n   Treasure   : ");
	for (i = 1; i < (gameInfo.pathLength + 1); i++)
	{
		printf("%d", gameInfo.treasureLocations[i]);
	}
	printf("\n\n====================================");
	printf("\n~ Get ready to play TREASURE HUNT! ~");
	printf("\n====================================\n\n");
	for (i = 1; i < (gameInfo.pathLength + 1); i++)
	{
		playerInfo.pastEnteredPositions[i] = '-';
	}
	for (i = 1; i < (gameInfo.pathLength + 1); i++)
	{
		gamePlayVariables[i] = '|';
	}
	printf("  ");
	for (i = 1; i < (gameInfo.pathLength + 1); i++)
	{
		printf("%c", playerInfo.pastEnteredPositions[i]);
	}
	printf("\n");
	printf("  ");
	for (i = 1; i < (gameInfo.pathLength + 1); i++)
	{
		if (i % 10 != 0)
		{
			printf("%c", gamePlayVariables[i]);
		}
		else
		{
			printf("%d", i / 10);
		}
	}
	printf("\n");
	printf("  ");
	if (gameInfo.pathLength < 10)
	{
		for (i = 1; i < (gameInfo.pathLength + 1); i++)
		{
			printf("%d", i);
		}
	}
	gamePlayVariables1Workings = gameInfo.pathLength;
	while (gamePlayVariables1Workings >= 10)
	{
		for (i = 1; i < 10; i++)
		{
			printf("%d", i);
		}
		printf("%d", 0);
		gamePlayVariables1Workings -= 10;
	}
	if (gamePlayVariables1Workings != 0)
	{
		for (i = 1; i < (gamePlayVariables1Workings + 1); i++)
		{
			printf("%d", i);
		}
	}
	printf("\n+---------------------------------------------------+\n");
	printf("  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d", playerInfo.numberOfLives, playerInfo.treasureCount, gameInfo.maximumNumOfMoves);
	printf("\n+---------------------------------------------------+\n");
	i = 1;
	while (i < gameInfo.pathLength + 1 && gameInfo.maximumNumOfMoves != 0 && playerInfo.numberOfLives != 0)
	{
		treasureFlag = 0; bombFlag = 0;
		printf("Next Move [1-%d]: ", gameInfo.pathLength);
		scanf("%d", &nextMove);
		while (nextMove > gameInfo.pathLength || nextMove < 1)
		{
			printf("  Out of Range!!!\n");
			printf("Next Move [1-%d]: ", gameInfo.pathLength);
			scanf("%d", &nextMove);
		}
		while (playerInfo.pastEnteredPositions[nextMove] != '-')
		{
			printf("\n===============> Dope! You've been here before!\n\n");
			for (j = 0; j < nextMove - 1; j++)
			{
				printf(" ");
			}
			printf("  ");
			printf("%c", playerInfo.symbolUser);
			for (j = nextMove; j < gameInfo.pathLength; j++)
			{
				printf(" ");
			}
			printf("\n");
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				printf("%c", playerInfo.pastEnteredPositions[i]);
			}
			printf("\n");
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				if (i % 10 != 0)
				{
					printf("%c", gamePlayVariables[i]);
				}
				else
				{
					printf("%d", i / 10);
				}
			}
			printf("\n");
			printf("  ");
			if (gameInfo.pathLength < 10)
			{
				for (i = 1; i < (gameInfo.pathLength + 1); i++)
				{
					printf("%d", i);
				}
			}
			gamePlayVariables1Workings = gameInfo.pathLength;
			while (gamePlayVariables1Workings >= 10)
			{
				for (i = 1; i < 10; i++)
				{
					printf("%d", i);
				}
				printf("%d", 0);
				gamePlayVariables1Workings -= 10;
			}
			if (gamePlayVariables1Workings != 0)
			{
				for (i = 1; i < (gamePlayVariables1Workings + 1); i++)
				{
					printf("%d", i);
				}
			}
			printf("\n+---------------------------------------------------+\n");
			printf("  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d", playerInfo.numberOfLives, playerInfo.treasureCount, gameInfo.maximumNumOfMoves);
			printf("\n+---------------------------------------------------+\n");
			printf("Next Move [1-%d]: ", gameInfo.pathLength);
			scanf("%d", &nextMove);
		}
		if (gameInfo.treasureLocations[nextMove] == 1)
		{
			treasureFlag = 1;
		}

		if (gameInfo.bombLocations[nextMove] == 1)
		{
			bombFlag = 1;
		}
		if (bombFlag == 1 && treasureFlag == 1)
		{
			playerInfo.pastEnteredPositions[nextMove] = '&';
			printf("\n===============> [&] !!! BOOOOOM !!! [&]");
			if (playerInfo.numberOfLives != 0)
			{
				printf("\n===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
			}
			else
			{
				printf("No more LIVES remaining!\n\n");
			}
			if (gameInfo.maximumNumOfMoves == 0)
			{
				printf("No more MOVES remaining!\n\n");
			}
			gameInfo.maximumNumOfMoves -= 1;
			playerInfo.treasureCount += 1;
			playerInfo.numberOfLives -= 1;
			for (j = 0; j < nextMove - 1; j++)
			{
				printf(" ");
			}
			printf("  ");
			printf("%c", playerInfo.symbolUser);
			for (j = nextMove; j < gameInfo.pathLength; j++)
			{
				printf(" ");
			}
			printf("\n"); 
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				printf("%c", playerInfo.pastEnteredPositions[i]);
			}
			printf("\n");
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				if (i % 10 != 0)
				{
					printf("%c", gamePlayVariables[i]);
				}
				else
				{
					printf("%d", i / 10);
				}
			}
			printf("\n");
			printf("  ");
			if (gameInfo.pathLength < 10)
			{
				for (i = 1; i < (gameInfo.pathLength + 1); i++)
				{
					printf("%d", i);
				}
			}
			gamePlayVariables1Workings = gameInfo.pathLength;
			while (gamePlayVariables1Workings >= 10)
			{
				for (i = 1; i < 10; i++)
				{
					printf("%d", i);
				}
				printf("%d", 0);
				gamePlayVariables1Workings -= 10;
			}
			if (gamePlayVariables1Workings != 0)
			{
				for (i = 1; i < (gamePlayVariables1Workings + 1); i++)
				{
					printf("%d", i);
				}
			}
			printf("\n+---------------------------------------------------+\n");
			printf("  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d", playerInfo.numberOfLives, playerInfo.treasureCount, gameInfo.maximumNumOfMoves);
			printf("\n+---------------------------------------------------+\n");
		}
		if (bombFlag == 0 && treasureFlag == 0)
		{
			playerInfo.pastEnteredPositions[nextMove] = '.';
			printf("\n===============> [.] ...Nothing found here... [.]\n\n");
			gameInfo.maximumNumOfMoves -= 1;
			if (gameInfo.maximumNumOfMoves == 0)
			{
				printf("No more MOVES remaining!\n\n");
			}
			for (j = 0; j < nextMove - 1; j++)
			{
				printf(" ");
			}
			printf("  ");
			printf("%c", playerInfo.symbolUser);
			for (j = nextMove; j < gameInfo.pathLength; j++)
			{
				printf(" ");
			}
			printf("\n");
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				printf("%c", playerInfo.pastEnteredPositions[i]);
			}
			printf("\n");
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				if (i % 10 != 0)
				{
					printf("%c", gamePlayVariables[i]);
				}
				else
				{
					printf("%d", i / 10);
				}
			}
			printf("\n");
			printf("  ");
			if (gameInfo.pathLength < 10)
			{
				for (i = 1; i < (gameInfo.pathLength + 1); i++)
				{
					printf("%d", i);
				}
			}
			gamePlayVariables1Workings = gameInfo.pathLength;
			while (gamePlayVariables1Workings >= 10)
			{
				for (i = 1; i < 10; i++)
				{
					printf("%d", i);
				}
				printf("%d", 0);
				gamePlayVariables1Workings -= 10;
			}
			if (gamePlayVariables1Workings != 0)
			{
				for (i = 1; i < (gamePlayVariables1Workings + 1); i++)
				{
					printf("%d", i);
				}
			}
			printf("\n+---------------------------------------------------+\n");
			printf("  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d", playerInfo.numberOfLives, playerInfo.treasureCount, gameInfo.maximumNumOfMoves);
			printf("\n+---------------------------------------------------+\n");
		}
		if (bombFlag == 0 && treasureFlag == 1)
		{
			playerInfo.pastEnteredPositions[nextMove] = '$';
			printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
			gameInfo.maximumNumOfMoves -= 1;
			playerInfo.treasureCount += 1;
			if (gameInfo.maximumNumOfMoves == 0)
			{
				printf("No more MOVES remaining!\n\n");
			}
			for (j = 0; j < nextMove - 1; j++)
			{
				printf(" ");
			}
			printf("  ");
			printf("%c", playerInfo.symbolUser);
			for (j = nextMove; j < gameInfo.pathLength; j++)
			{
				printf(" ");
			}
			printf("\n");
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				printf("%c", playerInfo.pastEnteredPositions[i]);
			}
			printf("\n");
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				if (i % 10 != 0)
				{
					printf("%c", gamePlayVariables[i]);
				}
				else
				{
					printf("%d", i / 10);
				}
			}
			printf("\n");
			printf("  ");
			if (gameInfo.pathLength < 10)
			{
				for (i = 1; i < (gameInfo.pathLength + 1); i++)
				{
					printf("%d", i);
				}
			}
			gamePlayVariables1Workings = gameInfo.pathLength;
			while (gamePlayVariables1Workings >= 10)
			{
				for (i = 1; i < 10; i++)
				{
					printf("%d", i);
				}
				printf("%d", 0);
				gamePlayVariables1Workings -= 10;
			}
			if (gamePlayVariables1Workings != 0)
			{
				for (i = 1; i < (gamePlayVariables1Workings + 1); i++)
				{
					printf("%d", i);
				}
			}
			printf("\n+---------------------------------------------------+\n");
			printf("  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d", playerInfo.numberOfLives, playerInfo.treasureCount, gameInfo.maximumNumOfMoves);
			printf("\n+---------------------------------------------------+\n");
		}
		if (bombFlag == 1 && treasureFlag == 0)
		{
			playerInfo.pastEnteredPositions[nextMove] = '!';
			printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
			gameInfo.maximumNumOfMoves -= 1; playerInfo.numberOfLives -= 1;
			if (playerInfo.numberOfLives == 0)
			{
				printf("No more LIVES remaining!\n\n");
			}
			if (gameInfo.maximumNumOfMoves == 0)
			{
				printf("No more MOVES remaining!\n\n");
			}
			for (j = 0; j < nextMove - 1; j++)
			{
				printf(" ");
			}
			printf("  ");
			printf("%c", playerInfo.symbolUser);
			for (j = nextMove; j < gameInfo.pathLength; j++)
			{
				printf(" ");
			}
			printf("\n");
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				printf("%c", playerInfo.pastEnteredPositions[i]);
			}
			printf("\n");
			printf("  ");
			for (i = 1; i < (gameInfo.pathLength + 1); i++)
			{
				if (i % 10 != 0)
				{
					printf("%c", gamePlayVariables[i]);
				}
				else
				{
					printf("%d", i / 10);
				}
			}
			printf("\n");
			printf("  ");
			if (gameInfo.pathLength < 10)
			{
				for (i = 1; i < (gameInfo.pathLength + 1); i++)
				{
					printf("%d", i);
				}
			}
			gamePlayVariables1Workings = gameInfo.pathLength;
			while (gamePlayVariables1Workings >= 10)
			{
				for (i = 1; i < 10; i++)
				{
					printf("%d", i);
				}
				printf("%d", 0);
				gamePlayVariables1Workings -= 10;
			}
			if (gamePlayVariables1Workings != 0)
			{
				for (i = 1; i < (gamePlayVariables1Workings + 1); i++)
				{
					printf("%d", i);
				}
			}
			printf("\n+---------------------------------------------------+\n");
			printf("  Lives:%3d  | Treasures:%3d  |  Moves Remaining:%3d", playerInfo.numberOfLives, playerInfo.treasureCount, gameInfo.maximumNumOfMoves);
			printf("\n+---------------------------------------------------+\n");
		}
		i++;
	}
	printf("\n##################\n");
	printf("#   Game over!   #");
	printf("\n##################\n\n");
	printf("You should play again and try to beat your score!");
	return 0;
}