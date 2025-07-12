// ============
// HEADER FILES
// ============
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#pragma once

// ====================================================================
// DEFINE MACROS to enforce a maximum and a minimum limit on the number
// of subjects, to check if the marks and credits are in a valid range
// ====================================================================

#define MAX_SUBJECTS_ALLOWED 20
#define MIN_SUBJECTS_ALLOWED 1

#define MAXIMUM_MARKS_ALLOWED 100
#define MINIMUM_MARKS_ALLOWED 0

#define MAX_CREDITS_ALLOWED 20
#define MIN_CREDITS_ALLOWED 1

typedef enum
{
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} Weekday;

// =====================
// FUNCTION DECLARATIONS
// =====================

// ================================
// PRINTS the current date and time
// ================================
void GetDateAndTime();

// =======================================
// SIMULATES loading on the console window
// =======================================
void loading(int seconds);

// =============
// METHOD BODIES
// =============

void loading(int seconds)
{

    // simulates loading
    char spinner[] = "|/-\\ ";
    for (int i = 0; i < 10; i++)
    {
        printf("\r %c %c %c %c %c %c %c %c %c %c %c", spinner[i % 5], spinner[i % 5], spinner[i % 5], spinner[i % 5], spinner[i % 5], spinner[i % 5], spinner[i % 5], spinner[i % 5], spinner[i % 5], spinner[i % 5], spinner[i % 5]);
        fflush(stdout);
        usleep(seconds * 10000);
    }
}

void GetDateAndTime()
{
    printf("\n\n\n\n");
    time_t t = time(NULL);
    struct tm *CurrentTime = localtime(&t);

    int day = CurrentTime->tm_mday;
    int month = CurrentTime->tm_mon;
    int year = CurrentTime->tm_year + 1900;

    Weekday today = CurrentTime->tm_wday;

    char *MonthNames[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    char *DayNames[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int hours = CurrentTime->tm_hour;
    int minutes = CurrentTime->tm_min;
    int seconds = CurrentTime->tm_sec;

    printf("---------------------------------\n");
    printf("| %-5s | %s %d , %d \n", "DATE", MonthNames[month], day, year);
    printf("| %-5s | %s \n", "DAY", DayNames[today]);
    printf("| %-5s | %02d:%02d:%02d \n", "TIME", hours, minutes, seconds);
    printf("---------------------------------\n\n\n\n");
}
