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
    else
    {
        return False;
    }

}