#include "STD.h"



#define MAX_SIZE 10
#define MIN_SIZE 3 //?

typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_Year;
    uint32 Course1_ID;
    uint32 Course1_Grade;
    uint32 Course2_ID;
    uint32 Course2_Grade;
    uint32 Course3_ID;
    uint32 Course3_Grade;


}Student;


//Database Functions Prototypes :


extern Bool SDB_IsFull(void);

extern uint8 SDB_GetUsedSize(void);

extern Bool SDB_AddEntry(uint32 , uint32, uint32 ,uint32, uint32, uint32, uint32, uint32 );

extern void SDB_DeleteEntry(uint32);

extern Bool SDB_ReadEntry(uint32);

extern void SDB_GetList(uint8*, uint32);

extern Bool SDB_IsIdExist(uint32);

extern void DeleteDatabase(void);




