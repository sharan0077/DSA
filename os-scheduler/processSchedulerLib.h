#include "../priorityQueue/priorityQueueLib.h"
typedef struct{
	int priority;
	int Time;
	int data;
}Process;
int processScheduler(List *queue);