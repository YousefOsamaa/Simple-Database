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


        
    }

}

extern PrintArray(uint32* IntegerArray, uint32 Size)
{
    for(uint32 i = 0; i< Size; i++)
    {
        printf("%d", IntegerArray + i);
    }
}