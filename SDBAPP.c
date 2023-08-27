#include "SDBAPP.h"
#include "UI.h"

extern void SDB_APP()
{
    PrintMessageOnScreen("Program has started");
    printf(" ");

    uint8 Input;
    SDB_INIT();

    do
    {
        //Options Table printed


        //UI takes input from user and places it in UserInput
        UserInput(&Input, 'd');

        //The appropriate action is implemented 
        SBD_Action(Input);
        
    } while ( UserInput != EXIT);
    
    

    

}

extern void SBD_Action(uint8 Choice)
{
    //typedef enum { EXIT, ADD_ENTRY, GET_USED_SIZE, READ_STUDENT_DATA , GET_STUDENTS_ID_LIST, CHECK_ID , DELETE_STUDENT_DATA , CHECK_DATABASE_FULL  } Option;
    switch(Choice)
    {
        case ADD_ENTRY:
        uint32 ID,Year, Course1ID, Course1Grade,Course2ID, Course2Grade, Course3ID, Course3Grade;
        PrintMessageOnScreen("Enter Student Id");
        UserInput(&ID, 'd');

        PrintMessageOnScreen("Enter Student Year");
        UserInput(&Year, 'd');
        
        PrintMessageOnScreen("Enter Course 1 ID");
        UserInput(&Course1ID, 'd');

        PrintMessageOnScreen("Enter Course 1 Grade");
        UserInput(&Course1Grade, 'c');

        PrintMessageOnScreen("Enter Course 2 ID");
        UserInput(&Course2ID, 'd');

        PrintMessageOnScreen("Enter Course 2 Grade");
        UserInput(&Course2Grade, 'c');

        PrintMessageOnScreen("Enter Course 3 ID");
        UserInput(&Course3ID, 'd');

        PrintMessageOnScreen("Enter Course 3 Grade");
        UserInput(&Course3Grade, 'c');

        if(SDB_AddEntry(ID,Year,Course1ID,Course1Grade,Course2ID,Course2Grade,Course3ID,Course3Grade))
        {
            PrintMessageOnScreen("Entry added successfulyy.");
        }
        else
        {
            ErrorMessage(WRONG_INPUTDATA);
        }
        break;

        case GET_USED_SIZE:
        PrintMessageOnScreen("Number of students: ");
        PrintData(SDB_GetUsedSize(),'d');
        break;

        case READ_STUDENT_DATA:
        uint32 ID;
        PrintMessageOnScreen("Enter Student ID: ");
        UserInput(&ID, 'd');

        if( !(SDB_ReadEntry(ID)) )
        {
            ErrorMessage(NOT_FOUND);
        }
        break;

        case GET_STUDENTS_ID_LIST:
        uint32* ListArray[MAX_SIZE];
        uint32 Count;

        SDB_GetList(&Count, ListArray);
        PrintArray(ListArray, SDB_GetUsedSize());

        break;

        case CHECK_ID:
        PrintMessageOnScreen("Enter Student ID: ");
        uint32 ID;
        UserInput(&ID,'d');

        if(SDB_IsIdExist(ID))
        {
            PrintMessageOnScreen("ID exists");
        }
        else
        {
            ErrorMessage(NOT_FOUND);
        }
        break;

        case DELETE_STUDENT_DATA:
        uint32 ID;
        UserInput(&ID,'d');

        if (SDB_IsIdExist(ID))
        {
            SDB_DeleteEntry(ID);
            PrintMessageOnScreen("Student data deleted successfully.");
        }
        else
        {
            ErrorMessage(NOT_FOUND);
        }
        

        break;

        case CHECK_DATABASE_FULL:
        if(SDB_IsFull())
        {
            PrintMessageOnScreen("Database is full.");
        }
        else
        {
            PrintMessageOnScreen("Database is not full.");
        }
        break;

        case EXIT:
        DeleteDatabase();
        PrintMessageOnScreen("Program has ended");
        break;

        default:
        //UI prints that the input is incorrect
        ErrorMessage(WRONG_CHOICE);
    }

}