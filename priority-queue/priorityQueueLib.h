#include "../linkedlist/dllLib.h"
typedef struct{
	int priority;
	void* element;
}Data;
int enqueue(List *queue,void* data);
int dequeue(List *queue);