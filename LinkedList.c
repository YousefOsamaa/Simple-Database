#include "LinkedList.h"

extern void LinkedListInit(Node_t** Head)
{
    *Head = 0;
    
}

extern void AddToEnd(Node_t** Head, Student Data)
{
     Node_t* NewNodePtr = (Node_t*)malloc(sizeof(Node_t));
     NewNodePtr ->Data = Data;


    if(*Head == 0)
    {
        *Head = NewNodePtr;
    }
    else
    {
        Node_t* SearchPtr = *Head;

        while(SearchPtr ->NextPtr)
        {
            SearchPtr= SearchPtr->NextPtr;
        }

        SearchPtr ->NextPtr = NewNodePtr;
        NewNodePtr ->NextPtr = 0;
    }

}

extern uint32 GetListSize(Node_t* Head)
{
    uint32 Count = 0;
    Node_t* CountPtr = Head; 
    while(CountPtr)
    {
        Count++;
        CountPtr = CountPtr->NextPtr;
    }
    return Count;
}

extern uint32 SearchList(Node_t* Head, uint32 ID)
{
    Node_t* SearchPtr = Head;
    uint32 Index = 0;
    uint32 Size = GetListSize(Head);

    while(SearchPtr)
    {
        Index++;
        if((SearchPtr->Data).Student_ID == ID)
        {
            return Index;
        }

        SearchPtr = SearchPtr->NextPtr;
    }

    return EMPTY;
}

extern void DeleteFromBegin(Node_t** Head)
{
    if(*Head)
    {
        Node_t* DeletePtr = *Head;
        *Head = (*Head)->NextPtr;
        free(DeletePtr);
    }
    
}

extern void DeleteFromEnd(Node_t** Head)
{
    if(*Head)
    {
        Node_t* SearchPtr =*Head;
        Node_t* DeletePtr = 0;

        while( (SearchPtr->NextPtr) ->NextPtr)
        {
            SearchPtr = SearchPtr -> NextPtr;

        }

        DeletePtr = SearchPtr->NextPtr;
        SearchPtr->NextPtr =0;

        free(DeletePtr);
    }

}

extern void DeleteFromMiddle(Node_t** Head, uint32 ID)
{
    uint32 Index = SearchList(*Head,ID);
    uint32 Size = GetListSize(*Head);
    
    if(Index == 1)
    {
        DeleteFromBegin(Head);

    }
    else if (Index == Size)
    {
        DeleteFromEnd(Head);

    }
    else if(Index != 0)
    {
        Node_t* TempPtr = *Head;
        Node_t* DeletePtr = 0;

        for(uint32 i =0; i< Index - 2; i++)
        {
            TempPtr = TempPtr->NextPtr;
        }

        DeletePtr = TempPtr->NextPtr;
        TempPtr->NextPtr = DeletePtr->NextPtr;
        free(DeletePtr);

    }
}

extern void DeleteList(Node_t** Head)
{
    Node_t* DeletePtr = *Head;

    if(DeletePtr)
    {
        *Head =(*Head)->NextPtr;
        free(DeletePtr);
        DeletePtr = *Head;
    }
}

extern void PrintNodeData(Node_t* Head, uint32 Index)
{
    Node_t* PrintPtr = Head;
    if(Index)
    {
        for(uint32 i = 1; i< Index; i++)
        {
            PrintPtr = PrintPtr->NextPtr;
        }

        PrintMessageOnScreen("Student ID:      ");
        PrintData( (PrintPtr->Data).Student_ID, 'd' );

        PrintMessageOnScreen("Student Year:    ");
        PrintData( (PrintPtr->Data).Student_Year, 'd' );

        PrintMessageOnScreen("Course 1 ID:     ");
        PrintData( (PrintPtr->Data).Course1_ID, 'd' );

        PrintMessageOnScreen("Course 1 Grade:  ");
        PrintData( (PrintPtr->Data).Course1_Grade, 'c' );

        PrintMessageOnScreen("Course 2 ID:     ");
        PrintData( (PrintPtr->Data).Course2_ID, 'd' );

        PrintMessageOnScreen("Course 2 Grade:  ");
        PrintData( (PrintPtr->Data).Course2_Grade, 'c' );

        PrintMessageOnScreen("Course 3 ID:     ");
        PrintData( (PrintPtr->Data).Course3_ID, 'd');

        PrintMessageOnScreen("Course 3 Grade:  ");
        PrintData( (PrintPtr->Data).Course3_Grade, 'c' );
        NewLine();

    }
}

extern uint32 GetStudentData(Node_t* Head, uint32 Index)
{
    uint32 Size = GetListSize(Head);
    Node_t* SearchPtr = Head;
    if(Index > 0 && Index <= Size)
    {
        for(uint32 i = 1; i< Size; i++)
        {
            SearchPtr = SearchPtr->NextPtr;
        }

        return ((SearchPtr->Data).Student_ID);

    }

}

