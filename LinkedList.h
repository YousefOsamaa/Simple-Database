#ifndef LINKEDLIST_FILE
#define LINKEDLIST_FILE


#include "SDB.h"
#define EMPTY 0
typedef struct 
{
    Student Data ;
    Node_t* NextPtr;
}Node_t;

extern void LinkedListInit(Node_t**);

extern void AddToBegin(Node_t**, Student);

extern void AddToEnd(Node_t**, Student);

extern uint32 GetListSize(Node_t*);

extern uint32 SearchList(Node_t**, uint32);

extern void DeleteFromBegin(Node_t**);

extern void DeleteFromEnd(Node_t**);

extern void DeleteFromMiddle(Node_t**, uint32);

extern void DeleteList(Node_t**);

extern void PrintNodeData(Node_t*, uint32);

extern uint32 GetStudentData(Node_t*, uint32);

#endif