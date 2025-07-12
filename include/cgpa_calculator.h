// ============
// HEADER FILES
// ============
#include "utility_methods.h"
#include "input_user.h"
#include "get_result.h"
#include "print_resultset.h"
#pragma once

// ================================
// MASTER METHOD TO RUN THE PROGRAM
// ================================
void run();

void run()
{
    // welcome message
    loading(2);
    printf("\n\n\n\n\n\n\n\n\n");
    loading(2);
    printf("WELCOME");
    printf("\n\n\n\n\n\n\n\n");
    GetDateAndTime();

    printf("\n-------------------------------\n");
    loading(2);

    // inputs the number of subjects from the user
    int NumberOfSubjects = InputNumberOfSubjects();

    // based on the number of subjects create array to hold the marks
    int *MarksArray = (int *)(calloc(NumberOfSubjects, sizeof(int)));

    // based on the number of subjects create array to hold the credits
    int *CreditsArray = (int *)(calloc(NumberOfSubjects, sizeof(int)));

    // based on the number of subjects create array to hold the grade point
    int *GradePointArray = (int *)(calloc(NumberOfSubjects, sizeof(int)));

    // based on the number of subjects create 2D array of str
    // to hold the grade

    // rows of the 2D array
    int RowsOfGradeArray = NumberOfSubjects;

    // columns of the 2D array
    int ColsOfGradeArray = 2;

    // create the 2D array of str
    // allocate an array of pointers of type (char) for each row
    char **GradeArray = (char **)(calloc(RowsOfGradeArray, sizeof(char *)));

    // loop through the array of pointers to create array of row pointers
    for (int i = 0; i < RowsOfGradeArray; i++)
    {
        // for each row allocate memory for 1 char extra to hold the
        // NULL terminator
        GradeArray[i] = (char *)(calloc(ColsOfGradeArray + 1, sizeof(char)));
    }

    // inputs the marks and credits from the user
    // prompts to enter marks and credits infinitely until user entered a
    // valid value
    InputMarksAndCredits(MarksArray, CreditsArray, GradePointArray, NumberOfSubjects);

    // fills the grade point array (2D array of strs) based on the
    // user marks and grade points
    FillGradeArray(GradeArray, ColsOfGradeArray, MarksArray, NumberOfSubjects);

    // print the result set
    PrintResultSet(MarksArray, CreditsArray, GradePointArray, GradeArray, NumberOfSubjects);

    // free the memory allocated by the MarksArray
    free(MarksArray);

    // free the memory allocated by the CreditsArray
    free(CreditsArray);

    // free the memory allocated by the GradePointArray
    free(GradePointArray);

    // free the memory allocated GradeArray which is a 2D array of str
    FreeStringArray(GradeArray, RowsOfGradeArray);
    printf("\n\n\n\n\n");
}
