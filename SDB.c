#include "SDB.h"
#include "LinkedList.h"

//  It is the base address of the database linked list, it's a static variable to prevent it from
//beingexterned and accessed in external files. It is initialized with Null 
static Node_t* DataBaseHead = 0;

extern void SDB_INIT(void)
{
    //Printing database size constraints
    PrintMessageOnScreen("--> Database is initialized with a current size of: ");
    PrintData(SDB_GetUsedSize(), 'd');
    PrintMessageOnScreen(" and a Mamimum Size of: ");
    PrintData(MAX_SIZE,'d');
    NewLine();
    NewLine();
    
    PrintMessageOnScreen("--> Constraints: ");
    NewLine();

    //Printing student ID range constraint
    PrintMessageOnScreen("--> Students ID has a range of: ");
    PrintData(MIN_STUDENT_ID, 'd');
    PrintMessageOnScreen(" - ");
    PrintData(MAX_STUDENT_ID,'d');
    NewLine();
    
    //Printing student year range constraint
    PrintMessageOnScreen("--> Students year has a range of: ");
    PrintData(MIN_STUDENT_YEAR, 'd');
    PrintMessageOnScreen(" - ");
    PrintData(MAX_STUDENT_YEAR,'d');
    NewLine();
    
    //Printing course ID range constraint
    PrintMessageOnScreen("--> Courses ID has a range of: ");
    PrintData(MIN_COURSE_ID, 'd');
    PrintMessageOnScreen(" - ");
    PrintData(MAX_COURSE_ID,'d');
    NewLine();
    
    //Printing course grade range Constraint
    PrintMessageOnScreen("--> Courses grade has a range of: ");
    PrintData(MIN_COURSE_GRADE, 'd');
    PrintMessageOnScreen(" - ");
    PrintData(MAX_COURSE_GRADE,'d');
    NewLine();

    //Printing some general constarints for the user
    PrintMessageOnScreen("--> For the same student, No 2 courses can have the same ID.");
    NewLine();

    PrintMessageOnScreen("--> No 2 students can have the same ID.");
    NewLine();

    PrintMessageOnScreen("--> Constraints' ranges  can be changed from the SDB file. ");
    NewLine();
    NewLine();
    
}

extern Bool SDB_IsFull(void)
{
    //geting the linked List size in the 'Size' variable
    uint32 Size = GetListSize(DataBaseHead);
    
    //Checking if the database has reached the mas size
    if(Size == MAX_SIZE)
    {
        return True;
    }
    return False;
}

extern uint8 SDB_GetUsedSize(void)
{
    //Returning the length of the linked list
    return GetListSize(DataBaseHead);
}

extern Bool SDB_AddEntry(uint32 User_Student_ID, uint32 User_Student_Year, uint32 User_Course1_ID,uint32 User_Course1_Grade,uint32 User_Course2_ID, uint32 User_Course2_Grade,uint32 User_Course3_ID, uint32 User_Course3_Grade  )
{
    //Creating a new instance of a student
    Student NewStudent;

    //Making sure the database in not full
    if( !(SDB_IsFull()) )
    {
      //Data validations is performed to make sure no constraints are broken by the user. If one constraint is broken the function is exited and
      //returns False 

        //Checikng if the ID is in range
        if( (User_Student_ID < MIN_STUDENT_ID) || (User_Student_ID > MAX_STUDENT_ID))
        {
            //Printing and error message and exiting the functiom
            PrintMessageOnScreen("--> Error in student ID");
            NewLine();
            ErrorMessage(STUDENT_ID_OUT_OF_RANGE);
            return False;
        }
        //Checking if anothe student has the same ID
        if(SDB_IsIdExist(User_Student_ID) )
        {
            //Printing an error message and existing the function 
            PrintMessageOnScreen("--> Error in student ID");
            NewLine();
            ErrorMessage(REPEATED_ID);
            return False;
        }
        //If not constraints are broken the parameter is saved in NewStudent object
        NewStudent.Student_ID = User_Student_ID;

        //Checing it the year is in range
        if( (User_Student_Year < MIN_STUDENT_YEAR) || (User_Student_Year > MAX_STUDENT_YEAR) )
        {
            //Printing an error message and exiting the function
            PrintMessageOnScreen("--> Error in Student year");
            NewLine();
            ErrorMessage(STUDENT_YEAR_OUT_OF_RANGE);
            return False;
        }
        //If no constraints are broken the parameter is saved in NewStudent object
        NewStudent.Student_Year = User_Student_Year;

        //Checking if the course ID is in range
        if( (User_Course1_ID < MIN_COURSE_ID) || (User_Course1_ID > MAX_COURSE_ID) )
        {
            //Printing an error message and exiting the function
            PrintMessageOnScreen("--> Error in Course 1");
            NewLine();
            ErrorMessage(COURSE_ID_OUT_OF_RANGE);
            return False;
        }
        //If no constraints are broken the parameter is saved in NewStudent object
        NewStudent.Course1_ID = User_Course1_ID;

        //Checking if the course grade is in range
        if( (User_Course1_Grade < MIN_COURSE_GRADE) || (User_Course1_Grade > MAX_COURSE_GRADE) )
        {
            //Printing an error message and exiting the function
            PrintMessageOnScreen("--> Error in Course 1");
            NewLine();
            ErrorMessage(COURSE_GRADE_OUT_OF_RANGE);
            return False;
        }
        //If no constraints are broken the parameter is saved in NewStudent object
        NewStudent.Course1_Grade = User_Course1_Grade;

        //Checking if the 2 courses have the same ID
        if ( ( User_Course1_ID == User_Course2_ID))
        {
            //Printing an error message and exiting the function
            PrintMessageOnScreen("--> Error in Course 2");
            NewLine();
            ErrorMessage(REPEATED_COURSE_ID);
            return False;
        }
        //Checking if the course ID is in range
        if( (User_Course2_ID < MIN_COURSE_ID) || (User_Course2_ID > MAX_COURSE_ID) )
        {
            //Printing an error message and exiting the function
            PrintMessageOnScreen("--> Error in Course 2");
            NewLine();
            ErrorMessage(COURSE_ID_OUT_OF_RANGE);
            return False;
        }
        //If no constraints are broken the parameter is saved in NewStudent object
        NewStudent.Course2_ID = User_Course2_ID;

        //Checking if the course grade is in range
        if( (User_Course2_Grade < MIN_COURSE_GRADE) || (User_Course2_Grade > MAX_COURSE_GRADE) )
        {
            //Printing an error message and exiting the function
            PrintMessageOnScreen("--> Error in Course 2");
            NewLine();
            ErrorMessage(COURSE_GRADE_OUT_OF_RANGE);
            return False;
        }
        //If no constraints are broken the parameter is saved in NewStudent object
        NewStudent.Course2_Grade = User_Course2_Grade;

        //Checking if the 2 courses have the same ID
         if ( ( User_Course3_ID == User_Course2_ID))
        {
            //Printing an error message and exiting the function
            PrintMessageOnScreen("--> Error in Course 3");
            NewLine();
            ErrorMessage(REPEATED_COURSE_ID);
            return False;
        }
        //Checking if the 2 courses have the same ID
        if ( ( User_Course3_ID == User_Course1_ID))
        {
            PrintMessageOnScreen("--> Error in Course 3");
            NewLine();
            ErrorMessage(REPEATED_COURSE_ID);
            return False;
        }
        //Checking if the course ID is in range
        if( (User_Course3_ID < MIN_COURSE_ID) || (User_Course3_ID > MAX_COURSE_ID) )
        {
            //Printing an error message and exiting the function
            PrintMessageOnScreen("--> Error in Course 3");
            NewLine();
            ErrorMessage(COURSE_ID_OUT_OF_RANGE);
            return False;
        }
        //If no constraints are broken the parameter is saved in NewStudent object
        NewStudent.Course3_ID = User_Course3_ID;

        //Checking if the course grade is in range
        if( (User_Course3_ID < MIN_COURSE_GRADE) || (User_Course3_ID > MAX_COURSE_GRADE) )
        {
            //Printing an error message and exiting the function
            PrintMessageOnScreen("--> Error in Course 3");
            NewLine();
            ErrorMessage(COURSE_GRADE_OUT_OF_RANGE);
            return False;
        }
        //If no constraints are broken the parameter is saved in NewStudent object
        NewStudent.Course3_Grade = User_Course3_Grade;
        
        //The NewStudent object is Passed to the AddToEnd function to place it in the linked list data structure
        AddToEnd(&DataBaseHead,NewStudent);
    }
    else
    {
        //If the database is empty prints an error message and returns false
        ErrorMessage(FULL_DATABASE);
        return False;
    }

    //If all the validations are correct the function returns True
    return True;
}

extern void SDB_DeleteEntry(uint32 ID)
{
    //Checks if the ID exists in the database
    if( SDB_IsIdExist(ID) )
    {
        //If it exists in passes it to the DeleteFromMiddleFunction that deletes it from the Linked List
        DeleteFromMiddle(&DataBaseHead, ID);
    }

}

extern Bool SDB_ReadEntry(uint32 ID)
{
    //Searches the Linked list for the a node containing a student with the ID and store its index in the variable 'Index'
    uint32 Index = SearchList(DataBaseHead, ID);

    //If 'Index' contains a number other than zero then the ID exists
    if(Index)
    {
        //Prints the student data to the user
        NewLine();
        PrintMessageOnScreen("--> Student Data:");
        NewLine();
        PrintNodeData(DataBaseHead, Index);
        return True;
    }
    //returns false if the ID doesnt exist
    return False;
}

extern void SDB_GetList(uint8* Count, uint32* List)
{
    //Places the linked list size in the variable passed by address
    *Count = SDB_GetUsedSize();
    
    //Points a pointer to the first element in the array
    uint32* Ptr = List;
    
    for(uint32 i = 1; i<= *Count; i++)
    {   
        //Placing each student id that exist in the database into the array passed address
        Ptr[i-1] = GetStudentData(DataBaseHead,i);
    }

}

extern Bool SDB_IsIdExist(uint32 User_ID)
{
    //Searches the linked list for the ID
    if( SearchList(DataBaseHead,User_ID) )
    {
        //If it exists then it returns True
        return True;
    }
    //If the ID doesnt exist returns False
    return False;

}

extern void SDB_DeleteDatabase(void)
{
    //Calls the DeleteList function to delete all the Linked List nodes from the .Heap
    DeleteList(&DataBaseHead);
}

