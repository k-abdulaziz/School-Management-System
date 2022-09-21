/**
 * @file stack.h
 * @author Khaled Abdulaziz
 * @date 29 August 2022
 * @brief File containing a c-program for School Management System using array.
 *
 * This project is focused on student record services in school, so it is named “School Management System using array”.
 * Here, you can create a new student, update information of an existing student, view and manage scores,
 * check the details of an existing student, remove existing student and view student’ list.
 *
 */

#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <string.h>

#define MAX_SIZE 10 /**< Maximum size of the stack */

/** @struct ST_Subjects
 *  @brief This structure represents the scores of subjects
 *  @var ST_Subjects::English
 *  Contains the score of English
 *  @var ST_Subjects::Chemistry
 *  Contains the score of Chemistry
 *  @var ST_Subjects::Maths
 *  Contains the score of Maths
 *  @var ST_Subjects::Physics
 *  Contains the score of Physics
 *  @var ST_Subjects::Computer_Science
 *  Contains the score of Computer Science subject
 *  @var ST_Subjects::History
 *  Contains the score of History
 */
typedef struct {
    int English;
    int Chemistry;
    int Maths;
    int Physics;
    int Computer_Science;
    int History;
}ST_Subjects;


/** @struct ST_Students
 *  @brief This structure represents the student information and scores
 *  @var ST_Students::Name
 *  Represents the student's name
 *  @var ST_Students::Date_of_Birth
 *  Represents the student's date of birth
 *  @var ST_Students::ID
 *  Represents the student's ID
 *  @var ST_Students::Address
 *  Represents the student's address
 *  @var ST_Students::Phone_Number
 *  Represents the student's phone number
 *  @var ST_Students::Subjects
 *  Represents the struct of subjects scores
 */
typedef struct {
    char Name[50];
    char Date_of_Birth[12];
    char ID[6];
    char Address[50];
    char Phone_Number[15];
    ST_Subjects Subjects;
}ST_Students;

/** @struct ST_Stack_Students
 *  @brief This structure represents the stack
 *  @var ST_Stack_Students::Top_Element
 *  Represents the top element of the stack
 *  @var ST_Stack_Students::Array_Students_DB
 *  Represents the data of the stack as an array structure
 */
typedef struct {
    int32_t Top_Element;
    ST_Students Array_Students_DB[MAX_SIZE];
}ST_Stack_Students;

/* functions prototypes */
void CreateStack(ST_Stack_Students *Ptr_Stack);
void DeleteStack(ST_Stack_Students *Ptr_Stack);
void NewStudent(ST_Stack_Students *Ptr_Stack);
void DeleteStudent(ST_Stack_Students *Ptr_Stack);
int IsFull(ST_Stack_Students *Ptr_Stack);
int IsEmpty(ST_Stack_Students *Ptr_Stack);
void StudentList(ST_Stack_Students *Ptr_Stack);
void getStudentData(ST_Stack_Students *Ptr_Stack, ST_Students *Ptr_Students);
void updateStudentData(ST_Stack_Students *Ptr_Stack, ST_Students *Ptr_Students, char x[]);
void sortAlphabetically(ST_Stack_Students *Ptr_Stack);
void searchIDDisplay(ST_Stack_Students *Ptr_Stack, char x[]);
void searchIDMakeTop(ST_Stack_Students *Ptr_Stack, char x[]);
void updateScores(ST_Stack_Students *Ptr_Stack, ST_Students *Ptr_Students, char x[]);
void RankingStudents(ST_Stack_Students *Ptr_Stack);

#endif //STACK_H
