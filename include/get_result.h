// ============
// HEADER FILES
// ============
#include "utility_methods.h"
#pragma once

// =====================
// FUNCTION DECLARATIONS
// =====================

// ==============================================================
// RETURNS a grade point for the corresponding marks passed to it
// otherwise aborts the program
// ==============================================================
int GetGradePoint(int marks);

// ======================================================================
// RETURNS a string for the corresponding marks passed to it otherwise it
// aborts the program
// ======================================================================
char *GetGradeChar(int marks);

// ========================================================
// DEALLOCATES the memory occupied by a 2D array of strings
// ========================================================
void FreeStringArray(char **arr, int rows);

// ====================================================================
// FILLS the GradeArray (2D array of str) with the corresponding grades
// calculated on the basis of marks from the MarksArray
// ====================================================================
void FillGradeArray(char **GradeArray, int ColsOfGradeArray, int *MarksArray, int size);

// ==========================================
// RETURNS the total marks scored by the user
// ==========================================
int GetTotalMarks(int *MarksArray, int size);

// ============================
// RETURNS the CGPA of the user
// ============================
double GetCGPA(int *CreditsArray, int *GradePointArray, int size);

// =============================================
// PRINTS the final result in a formatted manner
// =============================================
void PrintResultSet(int *MarksArray, int *CreditsArray, int *GradePointArray, char **GradeArray, int size);

// =============
// METHOD BODIES
// =============
int GetGradePoint(int marks)
{
    // if marks are not in a valid range abort() the program
    if (marks < MINIMUM_MARKS_ALLOWED || marks > MAXIMUM_MARKS_ALLOWED)
    {
        abort();
    }

    // else return a grade point corresponding to the range of the marks
    else
    {
        if (marks >= 90 && marks <= 100)
        {
            return 10;
        }
        if (marks >= 75 && marks <= 89)
        {
            return 9;
        }
        if (marks >= 65 && marks <= 74)
        {
            return 8;
        }
        if (marks >= 55 && marks <= 64)
        {
            return 7;
        }
        if (marks >= 50 && marks <= 54)
        {
            return 6;
        }
        if (marks >= 45 && marks <= 49)
        {
            return 5;
        }
        if (marks >= 40 && marks <= 44)
        {
            return 4;
        }
        if (marks < 40)
        {
            return 0;
        }
    }
    return -1;
}

char *GetGradeChar(int marks)
{
    // check marks are not i a valid range abort() the program
    if (marks < MINIMUM_MARKS_ALLOWED || marks > MAXIMUM_MARKS_ALLOWED)
    {
        abort();
    }

    // else return a grade point in the forms of a str which is
    // corresponding to the range of marks
    else
    {
        if (marks >= 90 && marks <= 100)
        {
            return "O";
        }
        if (marks >= 75 && marks <= 89)
        {
            return "A+";
        }
        if (marks >= 65 && marks <= 74)
        {
            return "A";
        }
        if (marks >= 55 && marks <= 64)
        {
            return "B+";
        }
        if (marks >= 50 && marks <= 54)
        {
            return "B";
        }
        if (marks >= 45 && marks <= 49)
        {
            return "C";
        }
        if (marks >= 40 && marks <= 44)
        {
            return "P";
        }
        if (marks < 40)
        {
            return "F";
        }
    }
    return "Z";
}

void FreeStringArray(char **arr, int rows)
{
    // if the memory location is valid
    if (arr)
    {
        // loop through the each row to free the allocated memory
        for (int i = 0; i < rows; i++)
        {
            // free the memory occupied by every row
            free(arr[i]);

            // set row the pointer to NULL
            arr[i] = NULL;
        }

        // free the memory allocated by the array of pointers
        free(arr);

        // set the array of pointer to NULL
        arr = NULL;
    }
}

void FillGradeArray(char **GradeArray, int ColsOfGradeArray, int *MarksArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        // writes the corresponding grade which maps to the marks
        // in the GradeArray (GradeArray is 1 2D array of str)
        strncpy(GradeArray[i], GetGradeChar(MarksArray[i]), ColsOfGradeArray);
    }
}

int GetTotalMarks(int *MarksArray, int size)
{
    // create a var to hold the sum of all the elements of MarksArray
    double MarksSum = 0.00;

    // loop to visit the every element
    for (int i = 0; i < size; i++)
    {
        // sum the element with all the elements of MarksArray
        MarksSum += MarksArray[i];
    }

    // return the sum
    return MarksSum;
}

double GetCGPA(int *CreditsArray, int *GradePointArray, int size)
{

    // cgpa = Σ(grade point scored * credit of subject) / Σ(total credits)

    // var to hold Σ total credits
    double CreditsSum = 0.0000;

    // var to hold Σ grade point
    double GradePointCreditSum = 0.00;

    for (int i = 0; i < size; i++)
    {
        CreditsSum += CreditsArray[i];
        GradePointCreditSum += (GradePointArray[i] * CreditsArray[i]);
    }

    // calculate CGPA
    double cgpa = (GradePointCreditSum / CreditsSum);

    // return CGPA
    return cgpa;
}