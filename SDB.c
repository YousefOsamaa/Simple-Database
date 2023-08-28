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
    if( (User_Student_ID < MIN_STUDENT_ID) || (User_Student_ID > MAX_STUDENT_ID))
    {
        PrintMessageOnScreen("--> Error in student ID");
        NewLine();
        ErrorMessage(STUDENT_ID_OUT_OF_RANGE);
        return False;
    }
    if(SDB_IsIdExist(User_Student_ID) )
    {
        PrintMessageOnScreen("--> Error in student ID");
        NewLine();
        ErrorMessage(REPEATED_ID);
        return False;
    }
    NewStudent.Student_ID = User_Student_ID;

    if( (User_Student_Year < MIN_STUDENT_YEAR) || (User_Student_Year > MAX_STUDENT_YEAR) )
    {
        PrintMessageOnScreen("--> Error in Student year");
        NewLine();
        ErrorMessage(STUDENT_YEAR_OUT_OF_RANGE);
        return False;
    }
    NewStudent.Student_Year = User_Student_Year;

    if( (User_Course1_ID < MIN_COURSE_ID) || (User_Course1_ID > MAX_COURSE_ID) )
    {
        PrintMessageOnScreen("--> Error in Course 1");
        NewLine();
        ErrorMessage(COURSE_ID_OUT_OF_RANGE);
        return False;
    }
    NewStudent.Course1_ID = User_Course1_ID;

    if( (User_Course1_Grade < MIN_COURSE_GRADE) || (User_Course1_Grade > MAX_COURSE_GRADE) )
    {
        PrintMessageOnScreen("--> Error in Course 1");
        NewLine();
        ErrorMessage(COURSE_GRADE_OUT_OF_RANGE);
        return False;
    }
    NewStudent.Course1_Grade = User_Course1_Grade;

    if( (User_Course2_ID < MIN_COURSE_ID) || (User_Course2_ID > MAX_COURSE_ID) )
    {
        PrintMessageOnScreen("--> Error in Course 2");
        NewLine();
        ErrorMessage(COURSE_ID_OUT_OF_RANGE);
        return False;
    }
    NewStudent.Course2_ID = User_Course2_ID;

    if( (User_Course2_Grade < MIN_COURSE_GRADE) || (User_Course2_Grade > MAX_COURSE_GRADE) )
    {
        PrintMessageOnScreen("--> Error in Course 2");
        NewLine();
        ErrorMessage(COURSE_GRADE_OUT_OF_RANGE);
        return False;
    }
    NewStudent.Course2_Grade = User_Course2_Grade;

    if( (User_Course3_ID < MIN_COURSE_ID) || (User_Course3_ID > MAX_COURSE_ID) )
    {
        PrintMessageOnScreen("--> Error in Course 3");
        NewLine();
        ErrorMessage(COURSE_ID_OUT_OF_RANGE);
        return False;
    }
    NewStudent.Course3_ID = User_Course3_ID;

    if( (User_Course3_ID < MIN_COURSE_GRADE) || (User_Course3_ID > MAX_COURSE_GRADE) )
    {
        PrintMessageOnScreen("--> Error in Course 3");
        NewLine();
        ErrorMessage(COURSE_GRADE_OUT_OF_RANGE);
        return False;
    }
    NewStudent.Course3_Grade = User_Course3_Grade;

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
    uint32 Index = SearchList(DataBaseHead, ID);
    if(Index)
    {
        NewLine();
        PrintMessageOnScreen("--> Student Data:");
        NewLine();
        PrintNodeData(DataBaseHead, Index);
        return True;
    }
    return False;
}

extern void SDB_GetList(uint8* Count, uint32* List)
{
    *Count = SDB_GetUsedSize();
    uint32* Ptr = List;

    for(uint32 i = 0; i< *Count; i++)
    {
        Ptr[i] = GetStudentData(DataBaseHead,i);
        Ptr++;
    }

}

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

