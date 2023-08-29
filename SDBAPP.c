#include "SDBAPP.h"
#include "UI.h"

extern void SDB_APP(void)
{
    //Printing indication that the program has started 
    PrintMessageOnScreen("\n--> Program has started");
    NewLine(); 

    //Calls initialzation function that prints the constraints before the superloop is entered
    SDB_INIT();

    uint32 Input;
    do
    {
        //Options Table printed every time for user
        PrintTable();

        //UI takes input from user and places it in the variable 'Input'
        IntegerUserInput(&Input);

        //The appropriate action is implemented according to the value in 'Input'
        SBD_Action(Input);
        
    } while ( Input != EXIT); 
    //As long as the user doesnt press exit loop continue
    
    

    

}

extern void SBD_Action(uint8 Choice)
{
    //this function chooses the appropriate action by switching on 'Choice' that contains
    //an integer value that the user has entered according to the Options table 

    switch(Choice)
    {
        //Actions:

        //Action 1: To enter a new student into the database  ADD_ENRTY = 1
        case ADD_ENTRY:  
         {
            uint32 ID,Year, Course1ID, Course1Grade,Course2ID, Course2Grade, Course3ID, Course3Grade;
            
            //User inputs all the student data in these variables

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

            //The variables are passed to the SDB_AddEntry function which processes the data to see if it's correct or not
            if(SDB_AddEntry(ID, Year, Course1ID, Course1Grade, Course2ID, Course2Grade, Course3ID, Course3Grade))
            {
                //If the function return True = 1, The entry has been added successfully
                PrintMessageOnScreen("--> Entry added successfulyy.");
                NewLine();
                NewLine();
            }

            break;
        }    

        //Action 2: Get the number of students in the database GET_USED_SIZE = 2
        case GET_USED_SIZE:
        NewLine();
        PrintMessageOnScreen("--> Number of students:  ");
        
        //The function SDb_GetUeedSize returns an integer value and passes it to the PrintData function which prints it to the user  
        PrintData(SDB_GetUsedSize(),'d');
        NewLine();
        NewLine();

        break;

        //Action 3: Print a specific student's data   READ_STUDENT_DATA = 3
        case READ_STUDENT_DATA:
        {
            uint32 ID;
            NewLine();
            PrintMessageOnScreen("Enter Student ID:  ");

            //The user enters the student's ID through the IntegerUserInput function found in UI
            IntegerUserInput(&ID);
            NewLine();

            //The ID is passed to the function SDB_ReadEntry which prints the data of the student if the id exists and returns True or False 
            //if it doesn't exist
            if( !(SDB_ReadEntry(ID)) )
            {
                //If the function returns False then there is an error an UI rints the error type and message.
                ErrorMessage(NOT_FOUND);
            }
            break;
        }

        //Action 4: To acquire an ID list 
        //GET_STUDENTS_LIST = 4
        case GET_STUDENTS_ID_LIST:
        {
            uint8 Count = 0;

            //An int array initialized with 0s
            uint32 IDArray [MAX_SIZE] = {0};

            //The variable and array are passed to SDB_GetList which places the Number of students in Count and fills the array with IDS
            SDB_GetList(&Count, IDArray);
            
            //Count is checked to see if it contains a value such that the database is not empty
            if(Count)
            {
            //If it contains a number then the UI prints it and Prints the array

            //Printing Count
             NewLine();
             PrintMessageOnScreen("--> Count =  ");
             PrintData(Count,'d');
             NewLine();

             //Printing the array
             PrintMessageOnScreen("--> ID List: ");
             PrintArray(IDArray,Count);
             
             NewLine();
             NewLine();
            }
            else
            {
                //If it contains zero then the database is empty and an error message is printed
                ErrorMessage(EMPTY_DATABASE);
            }                            
            break;

            NewLine();

        }

        //Action 5: To check if an ID exists 
        //CHECK_ID = 5
        case CHECK_ID:
        //The USer is asked to input the ID he wants
        NewLine();
        PrintMessageOnScreen("Enter Student ID:  ");
        uint32 ID;
        IntegerUserInput(&ID);

        //The ID is passed to SDB_IsIDExist which searches for it and reurns either EMPTY = 0 or it's index
        if(SDB_IsIdExist(ID))
        {
            //If the ID exists the user in notified with the following message
            PrintMessageOnScreen("--> ID exists");
            NewLine();
            NewLine();
        }
        else
        {
            //If it doesn't te UI prints the errpr type and message
            ErrorMessage(NOT_FOUND);
        }
        break;

        //Action 6: To delete a specific student from database 
        //DELETE_STUDENT_DATA = 6
        case DELETE_STUDENT_DATA:
        {
            uint32 ID;

            //Checking if the database is empty or not
            if(!SDB_GetUsedSize())
            {
                //if the database is empty an error message and type is printed
                ErrorMessage(EMPTY_DATABASE);
                break;
            }

            //If the database is not empty the user inputs the ID of the student
            PrintMessageOnScreen("Enter Student ID:  ");
            IntegerUserInput(&ID);

            //checking if the ID exists or not
            if (SDB_IsIdExist(ID))
            {
                //If it exists a specific function deletes it from the database 
                SDB_DeleteEntry(ID);
                
                //A message is printed for the user to notify him/her that the process is a success
                NewLine();
                PrintMessageOnScreen("--> Student data deleted successfully.");
                NewLine();
                NewLine();
            }
            else
            {
                //If te ID does't exist an error message and type is printed 
                ErrorMessage(NOT_FOUND);
            }
        }     break;

        //Action 7: To check if the database is FUll  
        //CHECK_DATABASE_FULL = 7
        case CHECK_DATABASE_FULL:
        
        //A function is called that returns True or False
        if(SDB_IsFull())
        {
            //If it's True an error type and message is printed
            ErrorMessage(FULL_DATABASE);
        }
        else
        {
            //If it's not the user is notified
            NewLine();
            PrintMessageOnScreen("--> Database is not full.");
            NewLine();
            NewLine();
        }
        break;

        //Action 8: To delete the database and exist the program
        //EXIT = 0
        case EXIT:
        //A function is called to delete the database
        SDB_DeleteDatabase();
        
        //User is notified that the program will end
        NewLine();
        PrintMessageOnScreen("--> Program has ended and database has been deleted");
        NewLine();

        break;


        default:
        //UI prints an eror messsage that the choice is incorrect entered by the user is incorrect
        ErrorMessage(WRONG_CHOICE);
    }

}