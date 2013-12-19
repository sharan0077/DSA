#include "../priorityQueue/priorityQueueLib.h"
typedef struct{
	int Time;
	String processName;
}Process;

int processScheduler(List *queue);