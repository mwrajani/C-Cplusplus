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


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include "function.h"
#include "functionHelpers.h"

int getParticipants(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1])
{
    int n_participants = readActivityFile(fp, participants, activNames);
    printf("Read %d participants\n\n", n_participants);
    return n_participants;
}
