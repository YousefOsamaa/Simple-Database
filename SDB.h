#ifndef SDB_FILE
#define SDB_FILE


/*
  This file contains any attributes or functions that operate on the database at the order of the user. They only can call the linked List 
 functions as the have the access to the database's head address through the DatabaseHead pointer 
*/

#include "STD.h"
#include "UI.h"

//List of program constraints regarding the data base:

#define MAX_SIZE 10 //Database maximum size
#define MIN_STUDENT_YEAR  1     //Max student year
#define MAX_STUDENT_YEAR 12     //Minimum student year
#define MIN_STUDENT_ID   1      //Maximum student Id
#define MAX_STUDENT_ID  1000    //Minimum student ID
#define MIN_COURSE_ID    1      //Minimum course ID
#define MAX_COURSE_ID   100     //Maximum course ID
#define MIN_COURSE_GRADE 0      //Minumum course grade
#define MAX_COURSE_GRADE 100    //Maximum course grade

//Student struct
typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_Year;
    uint32 Course1_ID;
    uint32 Course1_Grade;
    uint32 Course2_ID;
    uint32 Course2_Grade;
    uint32 Course3_ID;
    uint32 Course3_Grade;


}Student;


//Database Functions Prototypes :

/*
  SDB_INIT
  
  This function is called before the superloop begins to print that the program has started
 and to print the constraints defined above 

*/
extern void SDB_INIT(void);


/*
  SDB_IsFull

  This function checks if the size of the database has reached the maximum database size defined above or 
 not. It returns True = 1 or False = 1 
*/
extern Bool SDB_IsFull(void);

/*
  SDB_GetUsedSize

  This function returns the number of students in the database
*/
extern uint8 SDB_GetUsedSize(void);

/*
  SDB_AddEntry
  
  This function takes the inputed student data and performes validation on it then adds them to the data base. It returns
either True = 1 or False = 0
*/
extern Bool SDB_AddEntry(uint32 , uint32, uint32 ,uint32, uint32, uint32, uint32, uint32 );

/*
  SDB_DeleteEntry

  This function takes an ID and deletes the student from the database if the ID exists.
 It returns True = 1 or False = 0 
*/
extern void SDB_DeleteEntry(uint32);

/*
  SDB_ReadEntry

  This function takes an ID and prints the student data with such ID if he/her exists.
 It returns True = 1or False =0 
*/
extern Bool SDB_ReadEntry(uint32);

/*
 SDB_GetList

 This function takes both a character and an integer array variables by address. It places the
Size of the database in the character variable and places the IDs that exist in the database in the array 
*/
extern void SDB_GetList(uint8*, uint32*);

/*
    SDB_IsIDEXist

    This function takes an ID and searches for it in the database. It returns True = 1 or False = 0
*/
extern Bool SDB_IsIdExist(uint32);

/*
  SDB_DeleteDatabase

  This function is called when the program ends to delete all the data from the memory as it is allocated in the heap.
*/
extern void SDB_DeleteDatabase(void);

#endif



