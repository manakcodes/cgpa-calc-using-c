// ============
// HEADER FILES
// ============
#include "utility_methods.h"
#include "get_result.h"
#pragma once

// =====================
// FUNCTION DECLARATIONS
// =====================

// =====================================================================
// PROMPTS the user to enter the number of subjects he / she wants to
// calculate CGPA for and RETURNS if the number of subjects is
// (1 <= Number OF Subjects <= 20) otherwise infinitely PROMPTS THE USER
// to enter a valid number
// =====================================================================
int InputNumberOfSubjects();

// ===================================================================
// INPUTS marks and credits from the user to store into the respective
// arrays, if user does not enter a valid entry then the fn will
// continuously prompts the user to enter a valid number
// ===================================================================
void InputMarksAndCredits(int *MarksArray, int *CreditsArray, int *GradePointArray, int size);

// =============
// METHOD BODIES
// =============

int InputNumberOfSubjects()
{
    int size = 0;
    while (1)
    {
        printf("\nENTER THE NUMBER OF SUBJECTS : ");
        scanf("%d", &size);
        printf("-------------------------------\n\n\n\n");
        loading(5);

        if ((size >= MIN_SUBJECTS_ALLOWED) && (size <= MAX_SUBJECTS_ALLOWED))
        {
            return size;
        }
        printf("\nINVALID NUMBER OF SUBJECTS !! \n(1 <= NUMBER OF SUBJECTS <= 20)\n");
        continue;
    }
}

void InputMarksAndCredits(int *MarksArray, int *CreditsArray, int *GradePointArray, int size)
{
    for (int i = 0; i < size; i++)
    {
        while (1)
        {
            printf("\nENTER THE MARKS OF SUBJECT %d : \n", i + 1);
            scanf("%d", &MarksArray[i]);

            printf("\nENTER THE CREDITS OF SUBJECT %d : \n", i + 1);
            scanf("%d", &CreditsArray[i]);

            if ((MarksArray[i] < MINIMUM_MARKS_ALLOWED || MarksArray[i] > MAXIMUM_MARKS_ALLOWED) || (CreditsArray[i] < MIN_CREDITS_ALLOWED || CreditsArray[i] > MAX_CREDITS_ALLOWED))
            {
                loading(1);
                printf("\n\nINVALID MARKS or INVALID CREDITS !!\n");
                printf("0 <= MARKS <= 100\n");
                printf("0 <= CREDITS <= 20\n\n");
                loading(1);
                continue;
            }
            break;
        }
        GradePointArray[i] = GetGradePoint(MarksArray[i]);
        printf("-------------------------------\n");
    }
}
