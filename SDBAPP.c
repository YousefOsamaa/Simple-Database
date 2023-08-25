#include "SDBAPP.h"

extern void SDB_APP()
{
    uint8 UserInput;
    SDB_INIT();

    do
    {
       
        //UI takes input from user and places it in UserInput
        
        SBD_Action(UserInput);
        
    } while ( UserInput != EXIT);
    
    

    

}

extern void SBD_Action(uint8 Choice)
{
    //typedef enum { EXIT, ADD_ENTRY, GET_USED_SIZE, READ_STUDENT_DATA , GET_STUDENTS_ID_LIST, CHECK_ID , DELETE_STUDENT_DATA , CHECK_DATABASE_FULL  } Option;
    Option UserChoice = Choice;
    switch(Choice)
    {
        case ADD_ENTRY:
        break;

        case GET_USED_SIZE:
        break;

        case READ_STUDENT_DATA:
        break;

        case GET_STUDENTS_ID_LIST:
        break;

        case CHECK_ID:
        break;

        case DELETE_STUDENT_DATA:
        break;

        case CHECK_DATABASE_FULL:
        break;

        case EXIT:
        //UI prints that the program is terminated
        //calls delete function which delete all database elements
        break;

        default:
        //UI prints that the input is incorrect
    }

}