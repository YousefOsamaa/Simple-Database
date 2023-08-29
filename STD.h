
#ifndef STD_FILE
#define STD_FILE

//Data types declaration
typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;

//Boolean enum definition:
typedef enum {False, True} Bool;

//Database Options enum definition:
typedef enum { EXIT , ADD_ENTRY, GET_USED_SIZE, READ_STUDENT_DATA , GET_STUDENTS_ID_LIST, CHECK_ID , DELETE_STUDENT_DATA , CHECK_DATABASE_FULL  } Option;

//Error List enum definition: 
typedef enum { WRONG_CHOICE, WRONG_INPUTDATA, FULL_DATABASE, NOT_FOUND, REPEATED_ID,REPEATED_COURSE_ID, EMPTY_DATABASE, STUDENT_YEAR_OUT_OF_RANGE, STUDENT_ID_OUT_OF_RANGE, COURSE_GRADE_OUT_OF_RANGE, COURSE_ID_OUT_OF_RANGE  }Error;
/*
 WRONG_CHOICE: When the user chooses a wrong option
 FULL_DATABASE: When the database is full
 NOT_FOUND: When a specific data is not founded after the database has been searched 
 REPEATED_ID: When two students have the same ID
 REPEATED_COURSE_ID: When two courses have the same ID for the same student
 EMPTY_DATABASE: When an action is performed on the database and it's empty
 STUDENT_YEAR_OUT_OF_RANGE: When the sudent year range constraint is broken
 STUDENT_ID_OUT_OF_RANGE: When the student ID range constraint is broken
 COURSE_GRADE_OUT_OF_RANGE: When the course grade range constraint is broken
 COURSE_ID_OUT_OF_RANGE: When the course ID range constraint is broken 
*/
#endif