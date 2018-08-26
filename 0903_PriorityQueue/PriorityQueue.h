#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "UsefulHeap.h"

typedef Heap PQueue;
typedef HData PQData;


void PQueueInit(PQueue * ph, PriorityComp pc);
int PQIsEmpty(PQueue * ph);

void PEnqueue(PQueue * ph, PQData data);
PQData PDequeue(PQueue * ph);

#endif
