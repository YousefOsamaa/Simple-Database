#ifndef UI_FILE
#define UI_FILE
/*
  This file controls the input and output proccess as it interfases with the userr. It only has the right to use printf() or scanf()
 functions.
 It is also responsibile for the printing of error messages 
*/
#include <stdio.h>
#include "SDB.h"

/*
  IntegerUserInput
  
  This function takes an integer imnput from the user and places it into a variable passed by address 
*/
extern void IntegerUserInput(uint32*);

/*
  PrintData 

  This function takes a variable and prints it on the output. Must specify the type format of variable 'd' for decimal or 'c' for character. 
*/
extern void PrintData(uint32, int8);

/*
  PrintMessageOnScreen 

  This function takes an array of characters and prints it to the user 
*/
extern void PrintMessageOnScreen(int8*);

/*
  NewLine

  This function prints a new line on the screen 
*/
extern void NewLine(void);

/*
  ErrorMessage

  This function takes an integer that represents an error type and prints the appropriate error message
*/
extern void ErrorMessage(uint32);

/*
  PrintArray

  This function takes an integer array and its size and prints the array on the screen
*/
extern void PrintArray(uint32* IntegerArray, uint32 Size);

/*
  Print Table

  Ghis function prints the options table for the user
*/
extern void PrintTable(void);
#endif
