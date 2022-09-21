#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void Main_Menu(void)
{
    static ST_Stack_Students stack;
    //static const Students_DB EmptyStruct;
    ST_Students student = {0};
    //memset(&student, 0, sizeof(student));
    char str[10], x[10], *ptr;
    int num_of_choice;
    printf("***********************************\n");
    printf("\nWELCOME TO SCHOOL MANAGEMENT SYSTEM\n");
    printf("\n***********************************\n");
    printf("\n=------------MAIN-MENU------------=\n");
    printf("Option 1: Add a New student\n");
    printf("Option 2: Delete a Student\n");
    printf("Option 3: Delete Recent Inserted Student\n");
    printf("Option 4: Display a Student\n");
    printf("Option 5: Display Students List Sorted Alphabetically\n");
    printf("Option 6: Update a Student Data\n");
    printf("Option 7: Edit a Student Score\n");
    printf("Option 8: Display Students CS Score Ranking\n");
    printf("Option 9: Delete the List\n");
    printf("Option 10: Exit\n");
    printf("=---------------------------------=\n");
    CreateStack(&stack);
    do{
        printf("\nEnter the number of option:");
        fgets(str, sizeof(str), stdin);
        num_of_choice = strtol(str, &ptr, 10);
        switch (num_of_choice)
        {
            case 1:
            {
                NewStudent(&stack);
                getStudentData(&stack, &student);
                break;
            }
            case 2:
            {
                if (IsEmpty(&stack))
                {
                    printf("Stack Underflow");
                    break;
                }
                else
                {
                    printf("Enter the ID of the student:");
                    gets(x);
                    searchIDMakeTop(&stack, x);
                    DeleteStudent(&stack);
                    break;
                }
            }
            case 3:
            {
                DeleteStudent(&stack);
                break;
            }
            case 4:
            {
                if (IsEmpty(&stack))
                {
                    printf("Stack Underflow");
                    break;
                }
                else
                {
                    printf("Enter the ID of the student:");
                    gets(x);
                    searchIDDisplay(&stack, x);
                    break;
                }
            }
            case 5:
            {
                sortAlphabetically(&stack);
                StudentList(&stack);
                break;
            }
            case 6:
            {
                if (IsEmpty(&stack))
                {
                    printf("Stack Underflow");
                    break;
                }
                else
                {
                    printf("Enter the ID of the student:");
                    gets(x);
                    updateStudentData(&stack, &student, x);
                    break;
                }
            }
            case 7:
            {
                if (IsEmpty(&stack))
                {
                    printf("Stack Underflow");
                    break;
                }
                printf("Enter the ID of the student:");
                gets(x);
                updateScores(&stack, &student,x);
                break;
            }
            case 8:
            {
                RankingStudents(&stack);
                StudentList(&stack);
                break;
            }
            case 9:
            {
                DeleteStack(&stack);
                break;
            }
            case 10:
            {
                printf("Exiting...");
                break;
            }
            default:
            {
                printf("Invalid Input");
            }
        }
    }while (num_of_choice != 10);
}
