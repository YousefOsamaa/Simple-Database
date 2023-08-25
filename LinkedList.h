#include "SDB.h"

typedef struct 
{
    Student Data ;
    Node_t* NextPtr;
}Node_t;

extern void LinkedListInit(Node_t** Head);

extern void AddToBegin(Node_t** Head, Student Data);

extern void AddToEnd(Node_t** Head, Student Data);

extern uint32 GetListSize(Node_t* Head);

extern uint32 SearchList(Node_t** Head, uint32 ID);

extern void DeleteFromBegin(Node_t** Head);

extern void DeleteFromEnd(Node_t** Head);

extern void DeleteFromMiddle(Node_t** Head, uint32 ID);