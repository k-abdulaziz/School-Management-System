#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void CreateStack(ST_Stack_Students *Ptr_Stack)
{
    Ptr_Stack->Top_Element = -1;
}

void DeleteStack(ST_Stack_Students *Ptr_Stack)
{
    if (IsEmpty(Ptr_Stack))
    {
        printf("Stack Underflow");
    }
    else
    {
        Ptr_Stack->Top_Element = -1;
        printf("Stack was deleted successfully!");
    }
}

void NewStudent(ST_Stack_Students *Ptr_Stack)
{
    if (IsFull(Ptr_Stack))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        Ptr_Stack->Top_Element++;
    }
}

void DeleteStudent(ST_Stack_Students *Ptr_Stack)
{
    if (IsEmpty(Ptr_Stack))
    {
        printf("Stack Underflow");
    }
    else
    {
        Ptr_Stack->Top_Element--;
        printf("Student was deleted successfully!");
    }
}

int IsFull(ST_Stack_Students *Ptr_Stack)
{
    if (Ptr_Stack->Top_Element == MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int IsEmpty(ST_Stack_Students *Ptr_Stack)
{
    if (Ptr_Stack->Top_Element == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void StudentList(ST_Stack_Students *Ptr_Stack)
{
    int i;
    if (IsEmpty(Ptr_Stack))
    {
        printf("Stack Underflow");
    }
    else
    {
        for(i = 0;i <= Ptr_Stack->Top_Element; i++)
        {
            printf("STUDENT NO.%d\n", i+1);
            printf("Name: %s\n", Ptr_Stack->Array_Students_DB[i].Name);
            printf("Date of Birth: %s\n", Ptr_Stack->Array_Students_DB[i].Date_of_Birth);
            printf("ID: %s\n", Ptr_Stack->Array_Students_DB[i].ID);
            printf("Address: %s\n", Ptr_Stack->Array_Students_DB[i].Address);
            printf("Phone Number: %s\n", Ptr_Stack->Array_Students_DB[i].Phone_Number);
            printf("-----------------------------------------\n");
            printf("Grades:\n");
            printf("English: %d\n", Ptr_Stack->Array_Students_DB[i].Subjects.English);
            printf("Chemistry: %d\n", Ptr_Stack->Array_Students_DB[i].Subjects.Chemistry);
            printf("Maths: %d\n", Ptr_Stack->Array_Students_DB[i].Subjects.Maths);
            printf("Physics: %d\n", Ptr_Stack->Array_Students_DB[i].Subjects.Physics);
            printf("Computer Science: %d\n", Ptr_Stack->Array_Students_DB[i].Subjects.Computer_Science);
            printf("History: %d\n", Ptr_Stack->Array_Students_DB[i].Subjects.History);
            printf("-----------------------------------------\n");
            printf("=========================================\n");
        }
    }

}

void updateStudentData(ST_Stack_Students *Ptr_Stack, ST_Students *Ptr_Student, char x[])
{
    int i, num_of_choice;
    char str[5], *ptr;
    for (i = 0; i <= Ptr_Stack->Top_Element; i++) {
        if (!strcmp(Ptr_Stack->Array_Students_DB[i].ID, x)) {
            printf("=-----EDIT-MENU-----=\n");
            printf("Option 1: Edit Name\n");
            printf("Option 2: Edit Date of Birth\n");
            printf("Option 3: Edit ID\n");
            printf("Option 4: Edit Address\n");
            printf("Option 5: Edit Phone Number\n");
            printf("Option 6: Return\n");
            do {
                printf("\n[Edit_Menu] Enter the number of option:");
                fgets(str, sizeof(str), stdin);
                num_of_choice = strtol(str, &ptr, 10);
                switch (num_of_choice)
                {
                    case 1:
                    {
                        puts("Enter Student's Name:");
                        fgets(Ptr_Student->Name, sizeof(Ptr_Student->Name), stdin);
                        Ptr_Student->Name[strcspn(Ptr_Student->Name, "\n")] = 0;
                        strcpy(Ptr_Stack->Array_Students_DB[i].Name, Ptr_Student->Name);
                        break;
                    }
                    case 2:
                    {
                        puts("Enter Student's Birth Date:");
                        fgets(Ptr_Student->Date_of_Birth, sizeof(Ptr_Student->Date_of_Birth), stdin);
                        Ptr_Student->Date_of_Birth[strcspn(Ptr_Student->Date_of_Birth, "\n")] = 0;
                        strcpy(Ptr_Stack->Array_Students_DB[i].Date_of_Birth, Ptr_Student->Date_of_Birth);
                        break;
                    }
                    case 3:
                    {
                        puts("Enter Student's ID:");
                        fgets(Ptr_Student->ID, sizeof(Ptr_Student->ID), stdin);
                        Ptr_Student->ID[strcspn(Ptr_Student->ID, "\n")] = 0;
                        strcpy(Ptr_Stack->Array_Students_DB[Ptr_Stack->Top_Element].ID, Ptr_Student->ID);
                        break;
                    }
                    case 4:
                    {
                        puts("Enter Student's Address:");
                        fgets(Ptr_Student->Address, sizeof(Ptr_Student->Address), stdin);
                        Ptr_Student->Address[strcspn(Ptr_Student->Address, "\n")] = 0;
                        strcpy(Ptr_Stack->Array_Students_DB[i].Address, Ptr_Student->Address);
                        break;
                    }
                    case 5:
                    {
                        puts("Enter Student's Phone Number:");
                        fgets(Ptr_Student->Phone_Number, sizeof(Ptr_Student->Phone_Number), stdin);
                        Ptr_Student->Phone_Number[strcspn(Ptr_Student->Phone_Number, "\n")] = 0;
                        strcpy(Ptr_Stack->Array_Students_DB[i].Phone_Number, Ptr_Student->Phone_Number);
                        break;
                    }
                    case 6:
                    {
                        printf("Returning...");
                        break;
                    }
                    default:
                    {
                        printf("Invalid Input");
                    }
                }

            }while(num_of_choice != 6);
        }
    }
    if (i == Ptr_Stack->Top_Element)
    {
        printf("No student with this ID!");
    }
}

void getStudentData(ST_Stack_Students *Ptr_Stack, ST_Students *Ptr_Student)
{
    if (IsFull(Ptr_Stack))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        puts("Enter Student's Name:");
        fgets(Ptr_Student->Name, sizeof(Ptr_Student->Name), stdin);
        Ptr_Student->Name[strcspn(Ptr_Student->Name, "\n")] = 0;
        strcpy(Ptr_Stack->Array_Students_DB[Ptr_Stack->Top_Element].Name, Ptr_Student->Name);

        puts("Enter Student's Birth Date:");
        fgets(Ptr_Student->Date_of_Birth, sizeof(Ptr_Student->Date_of_Birth), stdin);
        Ptr_Student->Date_of_Birth[strcspn(Ptr_Student->Date_of_Birth, "\n")] = 0;
        strcpy(Ptr_Stack->Array_Students_DB[Ptr_Stack->Top_Element].Date_of_Birth, Ptr_Student->Date_of_Birth);

        puts("Enter Student's ID:");
        fgets(Ptr_Student->ID, sizeof(Ptr_Student->ID), stdin);
        Ptr_Student->ID[strcspn(Ptr_Student->ID, "\n")] = 0;
        strcpy(Ptr_Stack->Array_Students_DB[Ptr_Stack->Top_Element].ID, Ptr_Student->ID);

        puts("Enter Student's Address:");
        fgets(Ptr_Student->Address, sizeof(Ptr_Student->Address), stdin);
        Ptr_Student->Address[strcspn(Ptr_Student->Address, "\n")] = 0;
        strcpy(Ptr_Stack->Array_Students_DB[Ptr_Stack->Top_Element].Address, Ptr_Student->Address);

        puts("Enter Student's Phone Number:");
        fgets(Ptr_Student->Phone_Number, sizeof(Ptr_Student->Phone_Number), stdin);
        Ptr_Student->Phone_Number[strcspn(Ptr_Student->Phone_Number, "\n")] = 0;
        strcpy(Ptr_Stack->Array_Students_DB[Ptr_Stack->Top_Element].Phone_Number, Ptr_Student->Phone_Number);

        printf("Student was added successfully!");
    }
}

void searchIDMakeTop(ST_Stack_Students *Ptr_Stack, char x[])
{
    int i;
    ST_Students temp;
    for (i = 0; i <= Ptr_Stack->Top_Element; i++) {
        if (!strcmp(Ptr_Stack->Array_Students_DB[i].ID, x)) {
            temp = Ptr_Stack->Array_Students_DB[i];
            Ptr_Stack->Array_Students_DB[i] = Ptr_Stack->Array_Students_DB[Ptr_Stack->Top_Element];
            Ptr_Stack->Array_Students_DB[Ptr_Stack->Top_Element] = temp;
        }
    }
    if (i == Ptr_Stack->Top_Element)
    {
        printf("No student with this ID!");
    }
}

void searchIDDisplay(ST_Stack_Students *Ptr_Stack, char x[])
{
    int i;
    for (i = 0; i <= Ptr_Stack->Top_Element; i++) {
        if (!strcmp(Ptr_Stack->Array_Students_DB[i].ID, x)) {
            printf("Name: %s\n", Ptr_Stack->Array_Students_DB[i].Name);
            printf("Date of Birth: %s\n", Ptr_Stack->Array_Students_DB[i].Date_of_Birth);
            printf("ID: %s\n", Ptr_Stack->Array_Students_DB[i].ID);
            printf("Address: %s\n", Ptr_Stack->Array_Students_DB[i].Address);
            printf("Phone Number: %s\n", Ptr_Stack->Array_Students_DB[i].Phone_Number);
            printf("-----------------------------------------\n");
            printf("Grades:\nEnglish: %d\nChemistry: %d\nMaths: %d\nPhysics: %d\nComputer_Science: %d\nHistory: %d\n",
                   Ptr_Stack->Array_Students_DB[i].Subjects.English, Ptr_Stack->Array_Students_DB[i].Subjects.Chemistry, Ptr_Stack->Array_Students_DB[i].Subjects.Maths,
                   Ptr_Stack->Array_Students_DB[i].Subjects.Physics, Ptr_Stack->Array_Students_DB[i].Subjects.Computer_Science, Ptr_Stack->Array_Students_DB[i].Subjects.History);
            printf("-----------------------------------------\n");
            printf("=========================================\n");
        }
    }
    if (i == Ptr_Stack->Top_Element)
    {
        printf("No student with this ID!");
    }
}

void sortAlphabetically(ST_Stack_Students *Ptr_Stack)
{
    int i, j;
    ST_Students temp;
    for (i = 0; i <= Ptr_Stack->Top_Element - 1; i++) {
        for (j = i + 1; j <= Ptr_Stack->Top_Element; j++) {
            if (strcmp(Ptr_Stack->Array_Students_DB[i].Name, Ptr_Stack->Array_Students_DB[j].Name) > 0) {
                temp = Ptr_Stack->Array_Students_DB[i];
                Ptr_Stack->Array_Students_DB[i] = Ptr_Stack->Array_Students_DB[j];
                Ptr_Stack->Array_Students_DB[j] = temp;
            }
        }
    }
}

void updateScores(ST_Stack_Students *Ptr_Stack, ST_Students *Ptr_Student, char x[])
{
    int i;
    for (i = 0; i <= Ptr_Stack->Top_Element; i++) {
        if (!strcmp(Ptr_Stack->Array_Students_DB[i].ID, x)) {
            puts("Enter English score:");
            scanf_s("%d", &Ptr_Student->Subjects.English);
            Ptr_Stack->Array_Students_DB[i].Subjects.English = Ptr_Student->Subjects.English;

            puts("Enter Chemistry score:");
            scanf_s("%d", &Ptr_Student->Subjects.Chemistry);
            Ptr_Stack->Array_Students_DB[i].Subjects.Chemistry = Ptr_Student->Subjects.Chemistry;

            puts("Enter Maths score:");
            scanf_s("%d", &Ptr_Student->Subjects.Maths);
            Ptr_Stack->Array_Students_DB[i].Subjects.Maths = Ptr_Student->Subjects.Maths;

            puts("Enter Physics:");
            scanf_s("%d", &Ptr_Student->Subjects.Physics);
            Ptr_Stack->Array_Students_DB[i].Subjects.Physics = Ptr_Student->Subjects.Physics;

            puts("Enter Computer Science score:");
            scanf_s("%d", &Ptr_Student->Subjects.Computer_Science);
            Ptr_Stack->Array_Students_DB[i].Subjects.Computer_Science = Ptr_Student->Subjects.Computer_Science;

            puts("Enter History score:");
            scanf_s("%d", &Ptr_Student->Subjects.History);
            Ptr_Stack->Array_Students_DB[i].Subjects.History = Ptr_Student->Subjects.History;
            getchar();

            printf("Student scores was added successfully!");
        }
    }
    if (i == Ptr_Stack->Top_Element)
    {
        printf("No student with this ID!");
    }
}

void RankingStudents(ST_Stack_Students *Ptr_Stack)
{
    int i, j;
    ST_Students temp;
    for (i = 0; i <= Ptr_Stack->Top_Element - 1; i++) {
        for (j = i + 1; j <= Ptr_Stack->Top_Element; j++) {
            if (Ptr_Stack->Array_Students_DB[i].Subjects.Computer_Science < Ptr_Stack->Array_Students_DB[j].Subjects.Computer_Science) {
                temp = Ptr_Stack->Array_Students_DB[i];
                Ptr_Stack->Array_Students_DB[i] = Ptr_Stack->Array_Students_DB[j];
                Ptr_Stack->Array_Students_DB[j] = temp;
            }
        }
    }
}