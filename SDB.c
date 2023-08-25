#include "LinkedList.h"

//It is a static variable that can be only accessed inside the SDB module
static Node_t* DataBaseHead = 0;

extern Bool SDB_IsFull(void)
{
    uint32 Size = GetListSize(DataBaseHead);
    Bool B1;
    
    if(Size == MAX_SIZE)
    {
        B1 = True;
    }
    else
    {
        B1 = False;
    }
    return B1;
}

extern uint8 SDB_GetUsedSize(void)
{
    return GetListSize(DataBaseHead);
}

extern Bool SDB_AddEntry(uint32 User_Student_ID, uint32 User_Student_Year, uint32 User_Course1_ID,uint32 User_Course1_Grade,uint32 User_Course2_ID, uint32 User_Course2_Grade,uint32 User_Course3_ID, uint32 User_Course3_Grade  )
{
    Student NewStudent;
    Bool CorrectDataFlag = False;

    if( !(SDB_IsFull()) )
    {
    //Checks to be made
    NewStudent.Student_ID = User_Student_Year;

    NewStudent.Student_Year = User_Student_Year;

    NewStudent.Course1_ID = User_Course1_ID;

    NewStudent.Course1_Grade = User_Course1_Grade;

    NewStudent.Course2_ID =User_Course2_ID;

    NewStudent.Course2_Grade = User_Course2_Grade;

    NewStudent.Course3_ID = User_Course3_ID;

    }

    return CorrectDataFlag;
}

extern void SDB_DeleteEntry(uint32 User_ID)
{
    if( SDB_IsIdExist(User_ID) )
    {
        DeleteFromMiddle(&DataBaseHead, User_ID);
    }

}



extern Bool SDB_IsIdExist(uint32 User_ID)
{
    Bool FoundFLag;
    if( SearchList(DataBaseHead,User_ID) )
    {
        FoundFLag = True;
    }
    else
    {
        FoundFLag = False;
    }
    return FoundFLag;

}

extern void DeleteDatabase(void)
{
    DeleteList(&DataBaseHead);
}