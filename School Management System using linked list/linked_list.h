/** @file linked_list.h
 *  @brief Data structure and function prototypes for the linked list.
 *
 *  This file contains the prototypes for the linked
 *  list and data structures, directives, macros and
 *  global variables you will need.
 *
 *  @author Khaled I. Abdulaziz (khaled796)
 *  @bug No known bugs.
 */

/*file guard for LINKED_LIST_H*/
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* -- Includes -- */

#include <stdio.h> /* included to use functions like printf() and fgets() */
#include <string.h> /* included to use functions like puts() and strcmp() */
#include <stdlib.h> /* included to use functions like malloc() and free() */
#include <stdint.h> /* included to use declare integer types uint16_t and uint32_t */
#include <stdbool.h> /* included to use declare integer types uint16_t and uint32_t */

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
typedef struct ST_Subjects{
    uint16_t English;
    uint16_t Chemistry;
    uint16_t Maths;
    uint16_t Physics;
    uint16_t Computer_Science;
    uint16_t History;
}ST_Subjects;

/** @struct ST_Student
 *  @brief This structure represents the student information and scores
 *  @var ST_Student::Name
 *  Represents the student's name
 *  @var ST_Student::Date_of_Birth
 *  Represents the student's date of birth
 *  @var ST_Student::ID
 *  Represents the student's ID
 *  @var ST_Student::Address
 *  Represents the student's address
 *  @var ST_Student::Phone_Number
 *  Represents the student's phone number
 *  @var ST_Student::Subjects
 *  Represents the struct of subjects scores
 */
typedef struct ST_Student{
    char Name[40];
    char Date_of_Birth[15];
    uint32_t ID;
    char Address[40];
    char Phone_Number[20];
    ST_Subjects Subjects;
}ST_Student;

/** @struct student_node
 *  @brief This structure represents the node containing the current student and the address of the next one
 *  @var student_node::current_student
 *  Represents the struct of current student data
 *  @var student_node::next_student
 *  Represents the pointer of the next student node
 */
typedef struct student_node{
    ST_Student current_student;
    struct student_node *next_student;
}student_node;

/** @struct student_list
 *  @brief This structure represents the pointer to the student node and the number of nodes
 *  @var student_list::head_student
 *  Represents the pointer to the student node
 *  @var student_list::students_count
 *  Represents the number of students
 */
typedef struct student_list{
    student_node *head_student;
    uint16_t students_count;
}student_list;

/** @brief Creating a new linked list
 *  @param ptr_list a pointer to struct of type student_list
 *  @return void
 */
void create_list(student_list *ptr_list);

/** @brief Checking whether the list is empty or not
 *  @param ptr_list a pointer to struct of type student_list
 *  @return true or false
 */
static inline bool is_empty(student_list *ptr_list)
{
    if (ptr_list->head_student == NULL) /* check if head points to NULL */
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** @brief Adding new student node to the linked list
 *  @param ptr_list a pointer to struct of type student_list
 *  @return void
 */
void add_new_student(student_list *ptr_list);

/** @brief Deleting a student from the list using his ID
 *  @param ptr_list a pointer to struct of type student_list
 *  @return void
 */
void delete_student(student_list *ptr_list);

/** @brief Editing student data using his ID
 *  @param ptr_list a pointer to struct of type student_list
 *  @return void
 */
void edit_student_data(student_list *ptr_list);

/** @brief Editing student scores using his ID
 *  @param ptr_list a pointer to struct of type student_list
 *  @return void
 */
void edit_student_score(student_list *ptr_list);

/** @brief Getting student data from the user
 *  @param ptr_node a pointer to struct of type student_node
 *  @return void
 */
void get_student_data(student_node *ptr_node);

/** @brief Getting student scores from the user
 *  @param ptr_node a pointer to struct of type student_node
 *  @return void
 */
void get_student_scores(student_node *ptr_node);

/** @brief Searching for certain student node using ID
 *  @param ptr_list a pointer to struct of type student_list
 *  @return pointer to student_node
 */
student_node* search_node(student_list *ptr_list);

/** @brief Swapping two student nodes
 *  @param ptr_node1 a pointer to the first student_node
 *  @param ptr_node1 a pointer to the second student_node
 *  @return void
 */
void swap_nodes(student_node *ptr_node1, student_node *ptr_node2);

/** @brief swap_ptr is a function pointer to function swap_nodes()
 */
extern void (*swap_ptr)(student_node*, student_node*);

/** @brief Sorting students in ascending alphabetical order
 *  @param ptr_list a pointer to struct of type student_list
 *  @return void
 */
void sort_list_alpha(student_list *ptr_list);

/** @brief Sorting students in descending order according to CS score
 *  @param ptr_list a pointer to struct of type student_list
 *  @return void
 */
void sort_list_ranked(student_list *ptr_list);

/** @brief Displaying the list of the students data and scores
 *  @param ptr_list a pointer to struct of type student_list
 *  @return void
 */
void display_students_list(student_list *ptr_list);

#endif /* end of LINKED_LIST_H */
