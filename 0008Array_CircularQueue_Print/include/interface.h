#ifndef __INTERFACE_HEADER__
#define __INTERFACE_HEADER__

#include "mylib.h"
#include <stdlib.h>

//Function Declarations
void ShowMenu(void);
int SelectMenu(void);
void PrintQueue(QUEUE *);
QUEUE *UserEnqueue(QUEUE *);
QUEUE *UserDequeue(QUEUE *);
QUEUE *UserClean(QUEUE *);
#endif

