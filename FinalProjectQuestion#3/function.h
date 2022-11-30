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

#ifndef _FUNCTION_H
#define _FUNCTION_H

#include <stdio.h>

#define MAX_ACTIVITY_NAME_LEN 4
#define MAX_NAME_LEN 40
#define MAX_PARTICIPANTS 10
#define MAX_ACTIVITIES 10
#define NUM_ACTIVITY_NAMES 3



struct Date
{
    int year;
    int month;
    int day;
};

struct Activity
{
    struct Date date;
    int activityType;
    double distance;
};

struct Participant
{
    char name[MAX_NAME_LEN];
    int numActivities;
    struct Activity activities[MAX_ACTIVITIES];
};

int getParticipants(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1]);


#endif