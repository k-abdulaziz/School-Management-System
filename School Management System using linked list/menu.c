/** @file menu.c
 *  @brief The main menu.
 *
 *  This is the implementation of the linked list.
 *  Important details about its implementation should go in these comments.
 *
 *  @author Khaled I. Abdulaziz (khaled796)
 *  @bug No known bugs.
 */

#include "menu.h"

void main_menu(void)
{
    student_list list; /* create a list of type student_list */
    char str[10], *ptr; /* create a string and pointer to it */
    int num; /* create a variable to represent the user choice */
    printf("\t***********************************\n");
    printf("\n\tWELCOME TO SCHOOL MANAGEMENT SYSTEM\n");
    printf("\n\t***********************************\n");
    printf("\n=----------------------MAIN-MENU----------------------=\n");
    printf("Option 1: Add a New student\n");
    printf("Option 2: Delete a Student\n");
    printf("Option 3: Edit Student Data\n");
    printf("Option 4: Edit Student Score\n");
    printf("Option 5: Display Students List Sorted Alphabetically\n");
    printf("Option 6: Display Students Ranked According to CS Score\n");
    printf("Option 7: Exit\n");
    printf("=-----------------------------------------------------=\n");
    create_list(&list); /* create a list */
    do{
        printf("\nEnter the number of option:"); /* ask user to input the number of option */
        fgets(str, sizeof(str), stdin); /* get the input from the user with max of 10 chars */
        num = strtol(str, &ptr, 10); /* convert string to integer of base 10 */
        switch (num) {
            case 1: {
                add_new_student(&list); /* convert string to integer of base 10 */
                break;
            }
            case 2: {
                delete_student(&list); /* delete a certain student using by ID */
                break;
            }
            case 3: {
                edit_student_data(&list);  /* edit the data of a certain student by ID  */
                break;
            }
            case 4: {
                edit_student_score(&list); /* edit the score of a certain student by ID */
                break;
            }
            case 5: {
                sort_list_alpha(&list); /* sort the students in ascending alphabetical order */
                display_students_list(&list); /* display the student list after sorting */
                break;
            }
            case 6: {
                sort_list_ranked(&list); /* sort the students in descending based on CS score */
                display_students_list(&list); /* display the student list after sorting */
                break;
            }
            case 7: {
                printf("Exiting..."); /* exit the program */
                break;
            }
            default:
            {
                printf("Invalid Input"); /* display if user input is not listed in options */
            }
        }
    }while(num != 7); /* loop until user choose to exit the program */
}
