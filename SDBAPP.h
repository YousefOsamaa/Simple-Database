#ifndef SDBAPP_FILE
#define SDBAPP_FILE

#include "SDB.h"
/*
  SDB_APP:

  This function contains a super loop that constantly takes the user input and passes it to SDB_Action to perform the User tasks.
 It contains a superloop performed by a do while() loop to enable it to run atleast 1 time. the fiunction constantly prints the
 options table for the user each iteration

*/
extern void SDB_APP(void);


/*
  SDB_Action:
  
  This function is passed the user input when he choses it from the options table printed on the screen and calls the appropriate action
function in SDB.h to perform the task.
It also prints indications and calls the UI to print anu error messages depending on the output of the action functions
*/
extern void SBD_Action(uint8);

#endif