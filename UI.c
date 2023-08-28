#include "UI.h"

extern void IntegerUserInput(uint32* Input, int8 Type)
{

    scanf(" %d", Input);

}

extern void PrintData(uint32 Data,int8 Type)
{
    if(Type == 'd')
    printf("%d", Data);

    if(Type == 'c')
    printf("%c", Data);

    printf("\n");

}

extern void PrintMessageOnScreen(int8* Message)
{
    while(*Message)
    {
        printf("%c", *Message);
        Message++;
    }

}

extern void NewLine(void)
{
    printf("\n");
}

extern void ErrorMessage(uint32 ErrorType)
{
    switch(ErrorType)
    {
        case WRONG_CHOICE:
        printf("--> Error type: Invalid choice entered, Please try again.\n\n");
        break;

        case WRONG_INPUTDATA:
        printf("--> Error type:  Wrong input data, Please Try again. \n\n");
        break;

        case NOT_FOUND:
        printf("--> Error type:  Data not found, Please try again.\n\n");
        break;

        case FULL_DATABASE:
        printf("--> Error Type:  Database is full; maximum size of %d has been reached. Free some splace and try again.\n\n", MAX_SIZE);
        break;

        case EMPTY_DATABASE:
        printf("--> Error type: Database is empty, Please add some entries. \n\n");
        break;

        case REPEATED_ID:
        printf("--> Error type: Student ID already exists, Please try gain. \n\n");
        break;

        case STUDENT_ID_OUT_OF_RANGE:
        printf("--> Error type: Student ID is out of range (%d - %d). \n\n",MIN_STUDENT_ID,MAX_STUDENT_ID);
        break;

        case STUDENT_YEAR_OUT_OF_RANGE:
        printf("--> Error type: Student year is out of range (%d - %d). \n\n",MIN_STUDENT_YEAR,MAX_STUDENT_YEAR);
        break;
        
        case COURSE_ID_OUT_OF_RANGE:
        printf("--> Error type: Course ID is out of range (%d - %d). \n\n",MIN_COURSE_ID,MAX_COURSE_ID);
        break;

        case COURSE_GRADE_OUT_OF_RANGE:
        printf("--> Error type: Course grade is out of range (%d - %d). \n\n",MIN_COURSE_GRADE,MAX_COURSE_GRADE);
        break;
       
    }

}

extern void PrintArray(uint32* IntegerArray, uint32 Size)
{
    for(uint32 i = 0; i< Size; i++)
    {
        printf("%d", IntegerArray[i]);
        
        if(i != Size)
        {
            printf(", ");
        }
    }
}

extern void PrintTable(void)
{
    printf("%s \n","******************************************");
    printf("                Options Table \n");
    printf("%s \n","******************************************");
    printf("#To add an entry                            1\n");
    printf("#To get the used Size in database           2\n");
    printf("#To read a student data,                    3\n");
    printf("#To get the list of all students IDs        4\n");
    printf("#To check if an ID exists                   5\n");
    printf("#To delete a student data                   6\n");
    printf("#To check if the database is full           7\n");
    printf("#To exit and delete the database            0\n");
    printf("%s \n","******************************************\n");
    printf("%s \n","******************************************");
    printf("Your Input: ");
}
