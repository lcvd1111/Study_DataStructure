#ifndef __INTERFACE_HEADER__
#define __INTERFACE_HEADER__

#include "mylib.h"

//Function Declarations
void ShowMenu(void);
int SelectMenu(void);
void PrintQueue(void);
QUEUE *UserEnqueue(QUEUE *);
QUEUE *UserDequeue(QUEUE *);

#endif

