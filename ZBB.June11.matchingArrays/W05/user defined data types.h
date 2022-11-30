#pragma once
#define maximumPathLength 70
struct PlayerInfo
{
	int numberOfLives;
	char symbolUser;
	int treasureCount;
	char pastEnteredPositions[maximumPathLength];
};
struct GameInfo
{
	char symbolUser;
	int pathLength;
	int bombLocations[maximumPathLength];
	int treasureLocations[maximumPathLength];
	int maximumNumOfMoves;
};

