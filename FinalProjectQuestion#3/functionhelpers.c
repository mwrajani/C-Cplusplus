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
#include "functionHelpers.h"
#include <string.h>

const char WEEK[7][4] = { "Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri" };
const char MONTH[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
const char ACTIVITY_NAMES[NUM_ACTIVITY_NAMES][MAX_ACTIVITY_NAME_LEN + 1] = { "run", "bike", "swim" };

int Zeller(const struct Date* date)
{
    int month = date->month;
    int year = date->year;
    if (date->month < 3)
    {
        year--;
        month += 12;
    }
    int yr = year % 100;
    int century = year / 100;
    int result = date->day;
    result += 13 * (month + 1) / 5;
    result += yr;
    result += yr / 4;
    result += century / 4;
    result -= 2 * century;
    result = result % 7;
    return result;
}

int readActivityFile(FILE* fp, struct Participant participants[], const char activNames[][MAX_ACTIVITY_NAME_LEN + 1])
{
    int count = 0, ch, addPosn, actPosn;
    char activity[16];
    char name[MAX_NAME_LEN + 1];
    int year = 0, month = 0, day = 0;
    double dist = 0.0;
    //FILE* fp = NULL;
    fp = fopen("activitiesInfo.txt", "r");

    while (!feof(fp))
    {
        fscanf(fp, "%[^~]s%*c", name);
        ch = fgetc(fp);
        fscanf(fp, "%[^~]s%*c", activity);
        ch = fgetc(fp);
        fscanf(fp, "%d", &year);
        ch = fgetc(fp);
        fscanf(fp, "%d", &month);
        ch = fgetc(fp);
        fscanf(fp, "%d", &day);
        ch = fgetc(fp);
        fscanf(fp, "%lf", &dist);
        ch = fgetc(fp);
        addPosn = findParticipant(participants, count, name);
        if (addPosn < 0)
        {
            addPosn = count;
            count++;
            participants[addPosn].numActivities = 0;
            strcpy(participants[addPosn].name, name);
        }
        actPosn = participants[addPosn].numActivities;
        participants[addPosn].activities[actPosn].activityType = findString(activNames, NUM_ACTIVITY_NAMES, activity);
        participants[addPosn].activities[actPosn].date.year = year;
        participants[addPosn].activities[actPosn].date.month = month;
        participants[addPosn].activities[actPosn].date.day = day;
        participants[addPosn].activities[actPosn].distance = dist;
        participants[addPosn].numActivities++;
        ch = fgetc(fp);
        if (!feof(fp))
            ungetc(ch, fp);
    }
    fclose(fp);
    return count;
}

int findParticipant(struct Participant participants[], int size, const char name[])
{
    for (int i = 0; i < size; i++)
        if (strcmp(participants[i].name, name) == 0)
            return i;
    return -1;
}

int findString(const char activNames[][MAX_ACTIVITY_NAME_LEN + 1], int n_activities, char activity[])
{
    for (int i = 0; i < n_activities; i++)
        if (strcmp(activNames[i], activity) == 0)
            return i;
    return -1;
}

void clearKeyboard()
{
    while (getchar() != '\n');
}

int getInt()
{
    char NL = 'x';
    int value;
    while (NL != '\n')
    {
        scanf("%d%c", &value, &NL);
        if (NL != '\n')
        {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return value;
}

int getIntInRange(int min, int max)
{
    while (1)
    {
        int value = getInt();
        if (value >= min && value <= max)
            return value;
        else
            printf("Enter a number between %d and %d: ", min, max);
    }
}

int menu()
{
    printf("Select one of the following options:\n");
    printf("0 - Exit\n");
    printf("1 - list all participants and events\n");
    printf("2 - list total run distances\n");
    printf("3 - list total swim distances\n");
    printf("4 - list total bike distances\n");
    printf("5 - list best run distances\n");
    printf("6 - list best swim distances\n");
    printf("7 - list best bike distances\n");
    return getIntInRange(0, 7);
}

void manager()
{
    struct Participant participants[MAX_PARTICIPANTS];
    FILE* fp = fopen("activitiesInfo.txt", "r");
    int n_participants = getParticipants(fp, participants, ACTIVITY_NAMES);
    while (1)
    {
        int selection = menu();
        if (selection == 1)
            displayParticipant(participants, n_participants);
        else if (selection == 2)
            listTotalActivityDistances(participants, n_participants, "run");
        else if (selection == 3)
            listTotalActivityDistances(participants, n_participants, "swim");
        else if (selection == 4)
            listTotalActivityDistances(participants, n_participants, "bike");
        else if (selection == 5)
            listBestActivityDistances(participants, n_participants, "run");
        else if (selection == 6)
            listBestActivityDistances(participants, n_participants, "swim");
        else if (selection == 7)
            listBestActivityDistances(participants, n_participants, "bike");
        else
        {
            printf("Goodbye\n");
            fclose(fp);
            return;  
        }
    }
}

void displayParticipant(struct Participant participants[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", participants[i].name);
        printf("----------------------------------------------\n");
        for (int j = 0; j < participants[i].numActivities; j++)
        {
            printf("%5s  %s  %s  %d  %5.1lf\n", ACTIVITY_NAMES[participants[i].activities[j].activityType],
                WEEK[Zeller(&participants[i].activities[j].date)],
                MONTH[participants[i].activities[j].date.month - 1],
                participants[i].activities[j].date.day,
                participants[i].activities[j].distance + 0.005);
        }
        printf("\n");
    }
}

void displayParticipantActivity(struct Participant* participant, double value)
{
    printf("           %s    %5.1lf\n", participant->name, value + 0.005);
}


double getTotalActivityDist(struct Participant* participant, char activity[])
{
    double res = 0.0;
    for (int i = 0; i < participant->numActivities; i++)
    {
        int type = findString(ACTIVITY_NAMES, NUM_ACTIVITY_NAMES, activity);
        if (participant->activities[i].activityType == type)
            res += participant->activities[i].distance;
    }
    return res;
}

void sortParticipantsByTotalActivityDist(struct Participant participants[], int size, char activity[])
{
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (getTotalActivityDist(&participants[j], activity) < getTotalActivityDist(&participants[j + 1], activity))
            {
                struct Participant temp = participants[j];
                participants[j] = participants[j + 1];
                participants[j + 1] = temp;
            }
}

void sortParticipantsByMaxActivityDist(struct Participant participants[], int size, char activity[])
{
    int i, j;
    for (i = 0; i < size - 1; i++)
        for (j = 0; j < size - i - 1; j++)
            if (getMaxActivityDist(&participants[j], activity) < getMaxActivityDist(&participants[j + 1], activity))
            {
                struct Participant temp = participants[j];
                participants[j] = participants[j + 1];
                participants[j + 1] = temp;
            }
}

void listTotalActivityDistances(struct Participant participants[], int size, char activity[])
{
    sortParticipantsByTotalActivityDist(participants, size, activity);
    char title[11];
    (strcmp(activity, "run") == 0) ? strcpy(title, "RUNS") :
        (strcmp(activity, "swim") == 0) ? strcpy(title, "SWIMS") :
        (strcmp(activity, "bike") == 0) ? strcpy(title, "BIKES") : strcpy(title, "");
    printf("       *** TOTAL %s ***\n", title);
    for (int i = 0; i < size; i++)
        displayParticipantActivity(&participants[i], getTotalActivityDist(&participants[i], activity));
    printf("\n");
}

double getMaxActivityDist(struct Participant* participant, char activity[])
{
    double max = 0.0;
    for (int i = 0; i < participant->numActivities; i++)
    {
        int type = findString(ACTIVITY_NAMES, NUM_ACTIVITY_NAMES, activity);
        if (participant->activities[i].activityType == type && max < participant->activities[i].distance)
            max = participant->activities[i].distance;
    }
    return max;
}


void listBestActivityDistances(struct Participant participants[], int size, char activity[])
{
    sortParticipantsByMaxActivityDist(participants, size, activity);
    char title[11];
    (strcmp(activity, "run") == 0) ? strcpy(title, "RUNS") :
        (strcmp(activity, "swim") == 0) ? strcpy(title, "SWIMS") :
        (strcmp(activity, "bike") == 0) ? strcpy(title, "BIKES") : strcpy(title, "");
    printf("       *** TOP %s ***\n", title);
    for (int i = 0; i < size; i++)
        displayParticipantActivity(&participants[i], getMaxActivityDist(&participants[i], activity));
    printf("\n");
}

