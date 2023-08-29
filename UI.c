#include "UI.h"

extern void IntegerUserInput(uint32* Input)
{

    scanf(" %d", Input);

}

extern void PrintData(uint32 Data,int8 Type)
{
    //Checking if the variable is a decimal or character

    if(Type == 'd')
    printf("%d", Data);

    if(Type == 'c')
    printf("%c", Data);


}

extern void PrintMessageOnScreen(int8* Message)
{
    //Checing if the pointer points to the null terminator or not
    while(*Message)
    {
        //Printing the element pointed to by the pointer
        printf("%c", *Message);

        //Incrementing the ponter
        Message++;
    }

}

extern void NewLine(void)
{
    printf("\n");
}

extern void ErrorMessage(uint32 ErrorType)
{
    //Checing what type of error does the variable hold 
    //All the error types are described in the STD.h file
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

        case REPEATED_COURSE_ID:
        printf("--> Error type: Course ID aleady exists, Please try again. \n\n");
        break;

        default:
        printf("--> Error type: no such error type exists, revise the error passed and try agin. \n\n");
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
    printf("#To add an entry                            %d\n",ADD_ENTRY);
    printf("#To get the used Size in database           %d\n",GET_USED_SIZE);
    printf("#To read a student data,                    %d\n",READ_STUDENT_DATA);
    printf("#To get the list of all students IDs        %d\n",GET_STUDENTS_ID_LIST);
    printf("#To check if an ID exists                   %d\n",CHECK_ID);
    printf("#To delete a student data                   %d\n",DELETE_STUDENT_DATA);
    printf("#To check if the database is full           %d\n",CHECK_DATABASE_FULL);
    printf("#To exit and delete the database            %d\n",EXIT);
    printf("%s \n","******************************************\n");
    printf("%s \n","******************************************");
    printf("Your Input: ");
}
