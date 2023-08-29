#include "SDBAPP.h"
#include "UI.h"

extern void SDB_APP(void)
{
    PrintMessageOnScreen("\n--> Program has started");
    NewLine();

    SDB_INIT();

    uint32 Input;
    do
    {
        //Options Table printed
        PrintTable();

        //UI takes input from user and places it in IntegerUserInput
        IntegerUserInput(&Input);

        //The appropriate action is implemented 
        SBD_Action(Input);
        
    } while ( Input != EXIT);
    
    

    

}

extern void SBD_Action(uint8 Choice)
{
    //typedef enum { EXIT, ADD_ENTRY, GET_USED_SIZE, READ_STUDENT_DATA , GET_STUDENTS_ID_LIST, CHECK_ID , DELETE_STUDENT_DATA , CHECK_DATABASE_FULL  } Option;
    switch(Choice)
    {
        case ADD_ENTRY:  
         {
            uint32 ID,Year, Course1ID, Course1Grade,Course2ID, Course2Grade, Course3ID, Course3Grade;
            NewLine();
            PrintMessageOnScreen("Enter Student Id:  ");
            IntegerUserInput(&ID);

            PrintMessageOnScreen("Enter Student Year:  ");
            IntegerUserInput(&Year);
            
            PrintMessageOnScreen("Enter Course 1 ID:  ");
            IntegerUserInput(&Course1ID);

            PrintMessageOnScreen("Enter Course 1 Grade (%):  "); 
            IntegerUserInput(&Course1Grade);

            PrintMessageOnScreen("Enter Course 2 ID: ");
            IntegerUserInput(&Course2ID);
            
            PrintMessageOnScreen("Enter Course 2 Grade (%):  ");
            IntegerUserInput(&Course2Grade);

            PrintMessageOnScreen("Enter Course 3 ID:  ");
            IntegerUserInput(&Course3ID);
            
            PrintMessageOnScreen("Enter Course 3 Grade (%):  ");
            IntegerUserInput(&Course3Grade);
            
            NewLine();

            if(SDB_AddEntry(ID, Year, Course1ID, Course1Grade, Course2ID, Course2Grade, Course3ID, Course3Grade))
            {
                PrintMessageOnScreen("--> Entry added successfulyy.");
                NewLine();
                NewLine();
            }
            break;
        }    


        case GET_USED_SIZE:
        NewLine();
        PrintMessageOnScreen("--> Number of students:  ");
        PrintData(SDB_GetUsedSize(),'d');
        NewLine();
        NewLine();
        break;


        case READ_STUDENT_DATA:
        {
            uint32 ID;
            NewLine();
            PrintMessageOnScreen("Enter Student ID:  ");
            IntegerUserInput(&ID);
            NewLine();

            if( !(SDB_ReadEntry(ID)) )
            {
                ErrorMessage(NOT_FOUND);
            }
            break;
        }

        case GET_STUDENTS_ID_LIST:
        {
            uint8 Count;
            uint32 IDArray [MAX_SIZE] = {0};
            SDB_GetList(&Count, IDArray);
            
            if(Count)
            {
             NewLine();
             PrintMessageOnScreen("--> Count =  ");
             PrintData(Count,'d');
             NewLine();

             PrintMessageOnScreen("--> ID List: ");
             PrintArray(IDArray,Count);
             
             NewLine();
             NewLine();
            }
            else
            {
                ErrorMessage(EMPTY_DATABASE);
            }                            
            break;
            NewLine();

        }


        case CHECK_ID:
        NewLine();
        PrintMessageOnScreen("Enter Student ID:  ");
        uint32 ID;
        IntegerUserInput(&ID);

        if(SDB_IsIdExist(ID))
        {
            PrintMessageOnScreen("--> ID exists");
            NewLine();
            NewLine();
        }
        else
        {
            ErrorMessage(NOT_FOUND);
        }
        break;


        case DELETE_STUDENT_DATA:
        {
            uint32 ID;

            if(!SDB_GetUsedSize())
            {
                ErrorMessage(EMPTY_DATABASE);
                break;
            }

            PrintMessageOnScreen("Enter Student ID:  ");
            IntegerUserInput(&ID);

            if (SDB_IsIdExist(ID))
            {
                SDB_DeleteEntry(ID);
                NewLine();
                PrintMessageOnScreen("--> Student data deleted successfully.");
                NewLine();
                NewLine();
            }
            else
            {
                ErrorMessage(NOT_FOUND);
            }
        }     break;


        case CHECK_DATABASE_FULL:
        if(SDB_IsFull())
        {
            ErrorMessage(FULL_DATABASE);
        }
        else
        {
            NewLine();
            PrintMessageOnScreen("--> Database is not full.");
            NewLine();
            NewLine();
        }
        break;


        case EXIT:
        DeleteDatabase();
        //printf("%d \n",SDB_GetUsedSize() );
        NewLine();
        PrintMessageOnScreen("--> Program has ended and database has been deleted");
        NewLine();
        break;


        default:
        //UI prints that the choice is incorrect
        ErrorMessage(WRONG_CHOICE);
    }

}