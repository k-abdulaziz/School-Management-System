/** @file linked_list.c
 *  @brief The linked list.
 *
 *  This is the implementation of the linked list.
 *  Important details about its implementation should go in these comments.
 *
 *  @author Khaled I. Abdulaziz (khaled796)
 *  @bug No known bugs.
 */

#include "linked_list.h"

/* function to create the linked list */
void create_list(student_list *ptr_list)
{
    ptr_list->head_student = NULL; /* initialize the linked list head points to NULL */
    ptr_list->students_count = 0; /* initialize the student count with 0 */
}

/* function used to add new student to the list */
void add_new_student(student_list *ptr_list)
{
    /* create a new node which represents a student */
    student_node *new_student = (student_node *) malloc(sizeof(student_node));
    get_student_data(new_student); /* calling the function to get student data from user */
    get_student_scores(new_student); /* calling the function to get student scores from user */
    new_student->next_student = ptr_list->head_student; /* make the new node points to the head node */
    ptr_list->head_student = new_student; /* make the new node as the head node */
    ptr_list->students_count++; /* increment number of nodes */
    printf("Student added successfully!\n");
}

/* function used to delete a specific student */
void delete_student(student_list *ptr_list)
{
    int id; /* local variable to get the desired id to search for */
    student_node *release; /* create a pointer to node (used to free memory) */
    if (is_empty(ptr_list)) /* check for empty list */
    {
        printf("Hopeless try to delete from an Empty List!\n");
        return;
    }
    /* ask user to input the ID of the student */
    printf("Enter the student ID to update:");
    scanf_s("%d", &id); /* read input and store to variable */
    getchar(); /* used to catch \n */
    if (ptr_list->head_student->current_student.ID == id) /* if the head node has the x value */
    {
        release = ptr_list->head_student; /* assign head to release */
        ptr_list->head_student = ptr_list->head_student->next_student; /* move the head node to the next node */
        free(release); /* free the old head */
        printf("Student deleted successfully!\n");
    }
    else
    {
        student_node *temp = ptr_list->head_student; /* create a pointer to head node */
        while (temp->next_student != NULL)
        {
            /* check if the x is found in the next node */
            if (temp->next_student->current_student.ID == id)
            {
                release = temp->next_student; /* assign the next node to release */
                temp->next_student = temp->next_student->next_student; /* overtake the next node */
                free(release); /* free the node */
                printf("Student deleted successfully!\n");
                return;
            }
            else
            {
                /* move the node to the next */
                temp = temp->next_student;
            }
        }
        printf("No student have such an ID!"); /* not found the id */
    }
}

/* function used to edit data of a specific student */
void edit_student_data(student_list *ptr_list)
{
    if (is_empty(ptr_list)) /* check for empty list */
    {
        printf("No way to edit student data in an Empty List!\n");
        return;
    }
    /* get the return of the search function as a pointer to the node */
    student_node *temp = search_node(ptr_list);
    if(temp) /* if function return a pointer */
    {
        //puts("Insert New Information"), getchar();
        get_student_data(temp); /* get student info from user */
        printf("Student data updated successfully!\n");
    }
    else /* if function return NULL */
    {
        printf("No student have such an ID!"); /* not found the id */
    }
}

/* function used to edit scores of a specific student */
void edit_student_score(student_list *ptr_list)
{
    if (is_empty(ptr_list)) /* check for empty list */
    {
        printf("Can't edit student score in an Empty List\n");
        return;
    }
    student_node *temp = search_node(ptr_list);
    if(temp)
    {
        //puts("Insert New Scores\n"), getchar();
        get_student_scores(temp); /* getting student scores from user */
        printf("Student scores updated successfully!\n");
    }
    else
    {
        printf("No student have such an ID!"); /* not found the id */
    }
}

/* function used to get student data from the user */
void get_student_data(student_node *ptr_node)
{
    do {
        /* ask user to input the student name */
        puts("Enter Student's Name (20 to 30 chars):");
        fgets(ptr_node->current_student.Name,sizeof(ptr_node->current_student.Name),stdin);
        /* stop counting or storing \n in the string */
        ptr_node->current_student.Name[strcspn(ptr_node->current_student.Name, "\n")] = 0;
        /* loop until length is between 20 and 30 chars */
    }while(!(strlen(ptr_node->current_student.Name) >= 20 && strlen(ptr_node->current_student.Name) <= 30));

    do {
        /* ask user to input the student name */
        puts("Enter Student's Birth Date (dd/mm/yyyy):");
        fgets(ptr_node->current_student.Date_of_Birth,sizeof(ptr_node->current_student.Date_of_Birth),stdin);
        ptr_node->current_student.Date_of_Birth[strcspn(ptr_node->current_student.Date_of_Birth,"\n")] = 0;
    }while(strlen(ptr_node->current_student.Date_of_Birth) != 10); /* loop until correct length of 10 chars */

    do{
        /* ask user to input the student ID */
        puts("Enter Student's ID (greater than 0):");
        scanf_s("%d", &ptr_node->current_student.ID); /* read input and store */
        getchar(); /* consumes the \n by enter key */
    }while(ptr_node->current_student.ID <= 0); /* loop until ID greater than 0 */

    do{
        /* ask user to input the student address */
        puts("Enter Student's Address (20 to 30 chars):");
        fgets(ptr_node->current_student.Address,sizeof(ptr_node->current_student.Address), stdin);
        ptr_node->current_student.Address[strcspn(ptr_node->current_student.Address, "\n")] = 0;
        /* loop until length is between 20 and 30 chars */
    }while(!(strlen(ptr_node->current_student.Address) >= 20 && strlen(ptr_node->current_student.Address) <= 30));

    do{
        /* ask user to input the student phone number */
        puts("Enter Student's Phone Number (+20xxxXXXXxx):");
        fgets(ptr_node->current_student.Phone_Number,sizeof(ptr_node->current_student.Phone_Number),stdin);
        ptr_node->current_student.Phone_Number[strcspn(ptr_node->current_student.Phone_Number,"\n")] = 0;
        /* loop until starts with + and 12 chars after */
    }while(strlen(ptr_node->current_student.Phone_Number) != 13 && ptr_node->current_student.Phone_Number[0] != '+');
}

/* function used to get student scores from the user */
void get_student_scores(student_node *ptr_node)
{
    /* getting student scores from user */

    do {
        puts("Enter English score:");
        scanf_s("%d", &ptr_node->current_student.Subjects.English);
    }while(ptr_node->current_student.Subjects.English < 0 || ptr_node->current_student.Subjects.English > 100);

    do {
        puts("Enter Chemistry score:");
        scanf_s("%d", &ptr_node->current_student.Subjects.Chemistry);
    }while(ptr_node->current_student.Subjects.English < 0 || ptr_node->current_student.Subjects.Chemistry > 100);

    do {
        puts("Enter Maths score:");
        scanf_s("%d", &ptr_node->current_student.Subjects.Maths);
    }while(ptr_node->current_student.Subjects.Maths < 0 || ptr_node->current_student.Subjects.Maths > 100);

    do {
        puts("Enter Physics:");
        scanf_s("%d", &ptr_node->current_student.Subjects.Physics);
    }while(ptr_node->current_student.Subjects.Physics < 0 || ptr_node->current_student.Subjects.Physics > 100);

    do {
        puts("Enter Computer Science score:");
        scanf_s("%d", &ptr_node->current_student.Subjects.Computer_Science);
    }while(ptr_node->current_student.Subjects.Computer_Science < 0 || ptr_node->current_student.Subjects.Computer_Science > 100);

    do {
        puts("Enter History score:");
        scanf_s("%d", &ptr_node->current_student.Subjects.History); getchar();
    }while(ptr_node->current_student.Subjects.History < 0 || ptr_node->current_student.Subjects.History > 100);
}

student_node* search_node(student_list *ptr_list)
{
    int id; /* local variable to get the desired id to search for */
    student_node *temp = ptr_list->head_student; /* create a pointer to head node */
    printf("Enter the student ID to update:");
    scanf_s("%d", &id); getchar();
    while(temp != NULL)
    {
        if(temp->current_student.ID == id)
        {
            return temp;
        }
        temp = temp->next_student;
    }
    return NULL;
}

/* function to swap two nodes */
void swap_nodes(student_node *ptr_node1, student_node *ptr_node2)
{
    ST_Student temp; /* create temp struct to represent student */
    temp = ptr_node1->current_student; /* save front into temp */
    ptr_node1->current_student = ptr_node2->current_student; /* save rear into front */
    ptr_node2->current_student = temp; /* save temp into rear */
}

/* pointer to swap function */
void (*swap_ptr)(student_node*, student_node*) = &swap_nodes;

/* function used to sort students in ascending alphabetical order */
void sort_list_alpha(student_list *ptr_list)
{
    student_node *front = ptr_list->head_student; /* definition of pointer to struct_node points to head_student */
    student_node *rear  = NULL; /* definition of pointer to struct_node points to NULL */
    if (is_empty(ptr_list)) /* check for empty list */
    {
        printf("Impossible to sort an Empty List\n");
        return;
    }
    while (front != NULL) /* iterates until reach null */
    {
        rear = front->next_student; /* make rear point to next of front */
        while (rear != NULL) /* iterates until reach null */
        {
            /* compare between the front and the rear name and swap if front has greater ASCII value */
            if (strcmp(strupr(front->current_student.Name), strupr(rear->current_student.Name)) > 0)
            {
                swap_ptr(front, rear); /* swap front and rear */
            }
            rear = rear->next_student; /* if rear ASCII is greater, go to the next student */
        }
        front = front->next_student; /* move front to next to compare */
    }
}

/* function used to sort students in descending order according to CS score */
void sort_list_ranked(student_list *ptr_list)
{
    student_node *front = ptr_list->head_student; /* definition of pointer to struct_node points to head_student */
    student_node *rear  = NULL; /* definition of pointer to struct_node points to NULL */
    if (is_empty(ptr_list)) /* check for empty list */
    {
        printf("Impossible to sort an Empty List\n");
        return;
    }
    while (front != NULL) /* iterates until reach null */
    {
        rear = front->next_student; /* make rear point to next of front */
        while (rear != NULL)  /* iterates until reach null */
        {
            if ((front->current_student.Subjects.Computer_Science) < (rear->current_student.Subjects.Computer_Science))
            {
                swap_ptr(front, rear); /* swap front and rear */
            }
            rear = rear->next_student; /* if rear ASCII is greater, go to the next student */
        }
        front = front->next_student; /* move front to next to compare */
    }
}

/* display the list of students including data and scores of each one */
void display_students_list(student_list *ptr_list)
{
    uint16_t i = 1; /* create a counter */
    student_node *temp = ptr_list->head_student; /* create a pointer to the head node */
    if (is_empty(ptr_list)) /* check for empty list */
    {
        printf("Illogical to display an Empty List\n");
        return;
    }
    else
        /* display the number of students showing on the list */
        printf("\n***********LIST of %d STUDENTS************\n", ptr_list->students_count);
    {
        printf("=========================================\n");
        printf("-----------------------------------------\n");
        while (temp != NULL) /* loop until reach the end of the list */
        {
            /* display student's rank */
            printf("STUDENT NO.%d\n", i);
            /* display student's name */
            printf("Name: %s\n", temp->current_student.Name);
            /* display student's date of birth */
            printf("Date of Birth: %s\n", temp->current_student.Date_of_Birth);
            /* display student ID */
            printf("ID: %d\n", temp->current_student.ID);
            /* display student's address */
            printf("Address: %s\n", temp->current_student.Address);
            /* display student's phone number */
            printf("Phone Number: %s\n", temp->current_student.Phone_Number);
            printf("-----------------------------------------\n");
            printf("Scores:\n");
            /* display student's score in English */
            printf("English: %d\n", temp->current_student.Subjects.English);
            /* display student's score in Chemistry */
            printf("Chemistry: %d\n", temp->current_student.Subjects.Chemistry);
            /* display student's score in Maths */
            printf("Maths: %d\n", temp->current_student.Subjects.Maths);
            /* display student's score in Physics */
            printf("Physics: %d\n", temp->current_student.Subjects.Physics);
            /* display student's score in Computer Science */
            printf("Computer Science: %d\n", temp->current_student.Subjects.Computer_Science);
            /* display student's score in History */
            printf("History: %d\n", temp->current_student.Subjects.History);
            printf("-----------------------------------------\n");
            printf("=========================================\n");
            temp = temp->next_student; /* move to the next student node */
            i++; /* increment counter */
        }
    }
}
