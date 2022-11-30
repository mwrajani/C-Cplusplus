// This project has been done by:

// Student Name: Sara Dehghaniyan
// Student Number: 118383207
// Email Address: Sdehghaniyan@myseneca.ca

// Student Name: Muhammad Wajih Rajani
// Student Number: 142199207
// Email Address: mwrajani@myseneca.ca

// Student Name: Mori Maskoot
// Student Number: 144084209
// Email Address: mmaskoot1@myseneca.ca

// Section: NAA

#ifndef _HELPERS_H
#define _HELPERS_H

#include "function.h"


int Zeller(const struct Date* date);

int findParticipant(struct Participant participants[], int size, const char name[]);

int findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int n_activities, char activity[]);

int readActivityFile(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1]);

void clearKeyboard();

int getInt();

int getIntInRange(int min, int max);

int menu();

void manager();

void displayParticipant(struct Participant participants[], int size);

double getTotalActivityDist(struct Participant* participant, char activity[]);

double getMaxActivityDist(struct Participant* participant, char activity[]);

void sortParticipantsByTotalActivityDist(struct Participant participants[], int size, char activity[]);

void listTotalActivityDistances(struct Participant participants[], int size, char activity[]);

void listBestActivityDistances(struct Participant participants[], int size, char activity[]);

void displayParticipantActivity(struct Participant* participant, double value);

#endif