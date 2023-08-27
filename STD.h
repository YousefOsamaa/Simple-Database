
#ifndef STD_FILE
#define STD_FILE

// Data types declaration
typedef unsigned char uint8;
typedef char int8;
typedef unsigned short uint16;
typedef short int16;
typedef unsigned int uint32;

//Boolean enum definition:
typedef enum {False, True} Bool;

//Database Options enum definition:
typedef enum { EXIT, ADD_ENTRY, GET_USED_SIZE, READ_STUDENT_DATA , GET_STUDENTS_ID_LIST, CHECK_ID , DELETE_STUDENT_DATA , CHECK_DATABASE_FULL  } Option;

//Error List 
typedef enum { WRONG_CHOICE, WRONG_INPUTDATA, FULL_DATABASE, NOT_FOUND, REPEATED_ID }ErrorList;

#endif