#include "UI.h"

extern void UserInput(uint32* Input, int8 Type)
{
    if(Type == 'd')
    scanf("%d", UserInput);

    if(Type == 'c')
    scanf("%c", UserInput);

}

extern void PrintData(uint32 Data,int8 Type)
{
    if(Type == 'd')
    printf("%d", Data);

    if(Type == 'c')
    printf("%c", Data);

    printf("\n");

}

extern void PrintMessageOnScreen(int8* Message)
{
    while(*Message)
    {
        printf("%c", *Message);
    }
    printf("\n");

}

extern void ErrorMessage(uint32 ErrorType)
{
    switch(ErrorType)
    {
        case WRONG_CHOICE:
        PrintMessageOnScreen("Invalid choice entered, Please try again.");
        break;

        case WRONG_INPUTDATA:
        PrintMessageOnScreen("Wrong input data, Please Try again.");
        break;

        case NOT_FOUND:
        PrintMessageOnScreen("Data not found, Please try again.");
        break;

        case FULL_DATABASE:
        printf("Database is full; maximum size of %d has been reached. Free some splace and try again.", MAX_SIZE);
        break;

        case EMPTY_DATABASE:
        PrintMessageOnScreen("Database is empty, Please add some entries.");
        break;

        case REPEATED_ID:
        PrintMessageOnScreen("Invalid Input ID already exists, Please try gain.");
        break;

        case OUT_OF_RANGE:
        PrintMessageOnScreen("Input data is out of range, Please try again.");
        break;


        
    }

}

extern void PrintArray(uint32* IntegerArray, uint32 Size)
{
    for(uint32 i = 0; i< Size; i++)
    {
        printf("%d", IntegerArray[i]);
    }
}

extern void PrintTable(void)
{
    printf("To add entry, Enter 1\n");
    printf("To get Used Size in database, Enter 2\n");
    printf("To read student data, Enter 3\n");
    printf("To get the List of all students IDs, Enter 4\n");
    printf("To check if an ID exists, Enter 5\n");
    printf("To delete student data, Enter 6\n");
    printf("To check is database is full, Enter 7\n");
    printf("To exit, Enter 0\n");
    printf("%15s \n","***************");
}
