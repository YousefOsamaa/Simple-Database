#ifndef LINKEDLIST_FILE
#define LINKEDLIST_FILE

/*
  This file contains the linked list implementation. I chose the single linked list data structure as it provides an easy
 approach when deleting data and also as it uses the heap and can have undeetermined size precompiling   
*/
#include <stdlib.h>
#include "SDB.h"
#define EMPTY 0

typedef struct Node 
{
    Student Data ;
    struct Node* NextPtr;
}Node_t;

/*
Initializes the head pointer to make sure it points yo NULL
*/
extern void LinkedListInit(Node_t**);

/*
  Takes the student object and list head and inserts the Node in the end
*/
extern void AddToEnd(Node_t**, Student);

/*
  Returns the number of nodes in the linked list
*/
extern uint32 GetListSize(Node_t*);

/*
Searches the List for a specific ID passed
*/
extern uint32 SearchList(Node_t*, uint32);

/*
  Deletes the first node
*/
extern void DeleteFromBegin(Node_t**);

/*
  Deletes the last node
*/
extern void DeleteFromEnd(Node_t**);

/*
  Deletes a node acording to its index 
*/
extern void DeleteFromMiddle(Node_t**, uint32);

/*
 Delete all Nodes
*/
extern void DeleteList(Node_t**);

/*
 Prints Node data
*/
extern void PrintNodeData(Node_t*, uint32);

/*
 Returns student ID
*/
extern uint32 GetStudentData(Node_t*, uint32);

#endif