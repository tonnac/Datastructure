#include "PriorityQueue.h"

void PQueueInit(PQueue * ph, PriorityComp pc)
{
	HeapInit(ph, pc);
}
int PQIsEmpty(PQueue * ph)
{
	return HIsEmpty(ph);
}
void PEnqueue(PQueue * ph, PQData data)
{
	HInsert(ph, data);
}
PQData PDequeue(PQueue * ph)
{
	return HDelete(ph);
}