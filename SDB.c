#include "SDB.h"
#include "LinkedList.h"

//It is a static variable that can be only accessed inside the SDB module
static Node_t* DataBaseHead = 0;

extern Bool SDB_IsFull(void)
{
    uint32 Size = GetListSize(DataBaseHead);
    
    if(Size == MAX_SIZE)
    {
        return True;
    }
    return False;
}

extern uint8 SDB_GetUsedSize(void)
{
    return GetListSize(DataBaseHead);
}

extern Bool SDB_AddEntry(uint32 User_Student_ID, uint32 User_Student_Year, uint32 User_Course1_ID,uint32 User_Course1_Grade,uint32 User_Course2_ID, uint32 User_Course2_Grade,uint32 User_Course3_ID, uint32 User_Course3_Grade  )
{
    Student NewStudent;

    if( !(SDB_IsFull()) )
    {
    //Checks to be made
    if( (User_Student_ID < MIN_ID) || (User_Student_ID > Max_ID) )
    {

      return False;
    }
    NewStudent.Student_ID = User_Student_ID;

    if( (User_Student_Year < MIN_GRADE) || (User_Student_Year > MAX_GRADE) )
    {
        PrintMessageOnScreen("Invalid year");
        return False;
    }
    NewStudent.Student_Year = User_Student_Year;

    if( (User_Course1_ID < MIN_COURSE_ID) || (User_Course1_ID > MAX_COURSE_ID) )
    {
        PrintMessageOnScreen("Invalid Course ID");
        return False;
    }
    NewStudent.Course1_ID = User_Course1_ID;

    if( (User_Course1_Grade < MIN_COURSE_GRADE) || (User_Course1_Grade > MAX_COURSE_GRADE) )
    {
        PrintMessageOnScreen("Invalid Course grade");
        return False;
    }
    NewStudent.Course1_Grade = User_Course1_Grade;

    if( (User_Course2_ID < MIN_COURSE_ID) || (User_Course2_ID > MAX_COURSE_ID) )
    {
        PrintMessageOnScreen("Invalid Course ID");
        return False;
    }
    NewStudent.Course2_ID =User_Course2_ID;


    
    if( (User_Course2_Grade < MIN_COURSE_GRADE) || (User_Course2_Grade > MAX_COURSE_GRADE) )
    {
        PrintMessageOnScreen("Invalid Course grade");
        return False;
    }
    NewStudent.Course2_Grade = User_Course2_Grade;

    if( (User_Course3_ID < MIN_COURSE_ID) || (User_Course3_ID > MAX_COURSE_ID) )
    {
        PrintMessageOnScreen("Invalid Course ID");
        return False;
    }
    NewStudent.Course3_ID = User_Course3_ID;

    AddToEnd(&DataBaseHead,NewStudent);
    }
    else
    {
        ErrorMessage(FULL_DATABASE);
        return False;
    }

    return True;
}

extern void SDB_DeleteEntry(uint32 ID)
{
    if( SDB_IsIdExist(ID) )
    {
        DeleteFromMiddle(&DataBaseHead, ID);
    }

}


extern Bool SDB_ReadEntry(uint32 ID)
{
    uint32 Index = SearchList(&DataBaseHead, ID);
    if(Index)
    {
        PrintNodeData(DataBaseHead, Index);
    }
    return Index;
}

// extern void SDB_GetList(uint8* Count, uint32* List)
// {
//     *Count = GetListSize(DataBaseHead);
//     uint32* ArrPtr = List;
    
//     if(List)
//     {
//         for(uint32 i = 0; i < *Count; i++)
//         {
//             ArrPtr[i] = GetStudentID(DataBaseHead, i );
//             ArrPtr++;
//         }
//     }


// }


extern Bool SDB_IsIdExist(uint32 User_ID)
{
    
    if( SearchList(DataBaseHead,User_ID) )
    {
        return True;
    }
    return False;

}

extern void DeleteDatabase(void)
{
    DeleteList(&DataBaseHead);
}