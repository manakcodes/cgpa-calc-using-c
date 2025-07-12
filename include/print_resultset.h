// ============
// HEADER FILES
// ============
#include "utility_methods.h"
#include "get_result.h"

// =====================
// FUNCTION DECLARATIONS
// =====================

void PrintResultSet(int *MarksArray, int *CreditsArray, int *GradePointArray, char **GradeArray, int size);

// =============
// METHOD BODIES
// =============

void PrintResultSet(int *MarksArray, int *CreditsArray, int *GradePointArray, char **GradeArray, int size)
{
    printf("\n-------------------------------\n");
    loading(10);
    printf("\n\n\n");
    printf("\n+--------------+--------------+--------------+--------------+\n");

    printf("| %-12s | %-12s | %-12s | %-12s |\n", "MARKS", "CREDITS", "GRADEPOINT", "GRADE");
    printf("|--------------+--------------+--------------+--------------+\n");

    for (int i = 0; i < size; i++)
    {
        printf("| %-12d | %-12d | %-12d | %-12s |\n", MarksArray[i], CreditsArray[i], GradePointArray[i], GradeArray[i]);
        printf("+--------------+--------------+--------------+--------------+\n");
    }

    printf("\n");
    loading(2);

    double cgpa = GetCGPA(CreditsArray, GradePointArray, size);
    double percentage = 10.00 * cgpa;

    int MarksSum = GetTotalMarks(MarksArray, size);

    printf("\n+---------------+----+---------------+\n");
    printf("|%-15s|----|%15.2f|\n", "CGPA", cgpa);
    printf("|---------------|----|---------------|\n");
    printf("|%-15s|----|%15.2f|\n", "PERCENTAGE", percentage);
    printf("|---------------|----|---------------|\n");
    printf("|%-15s|----|%15d|\n", "SCORED MARKS", MarksSum);
    printf("|---------------|----|---------------|\n");
    printf("|%-15s|----|%15d|\n", "TOTAL MARKS", MAXIMUM_MARKS_ALLOWED * size);
    printf("+---------------+----+---------------+\n");

    printf("\n\nCONGRATULATIONS !! YOU SCORED %.2f CGPA\n\n\n\n", cgpa);

    if (cgpa >= 6.00)
    {
        printf("\nPASSED WITH I DIVISION !!\n");
    }
    else if (cgpa >= 5.00 && cgpa >= 5.99)
    {
        printf("\nPASSED WITH II DIVISION !!\n");
    }
    else
    {
        bool HasFailed = false;
        for (int i = 0; i < size; i++)
        {
            if (MarksArray[i] < 40)
            {
                HasFailed = true;
                break;
            }
        }

        if (!HasFailed)
        {
            printf("\n\nCONGRATULATIONS YOU PASSED\n\n");
        }
        else
        {
            printf("\n\nSORRY !! YOU FAILED\n\n");
        }
    }
}
