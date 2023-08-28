#ifndef UI_FILE
#define UI_FILE

#include <stdio.h>
#include "SDB.h"

extern void IntegerUserInput(uint32*, int8);

extern void PrintData(uint32, int8);

extern void PrintMessageOnScreen(int8*);

extern void NewLine(void);

extern void ErrorMessage(uint32);

extern void PrintArray(uint32* IntegerArray, uint32 Size);

extern void PrintTable(void);
#endif
