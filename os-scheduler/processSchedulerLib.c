#include "processSchedulerLib.h"
#include <stdlib.h>
int processScheduler(List *queue){
	int index=0;
	Node* currentProcess=queue->head,*prev;
	if(queue->head==NULL)
	return 0;
	while(currentProcess!=NULL){
		((Process*)currentProcess->data)->Time -= 5;
		prev = currentProcess->next;
	 	if(((Process*)currentProcess->data)->Time<=0)
	 		deleteNode(queue,index);
	index++;
	currentProcess = prev;
	if(currentProcess!=NULL && currentProcess->next==NULL)
	  	index = 0;
	}
	return 1;
}

