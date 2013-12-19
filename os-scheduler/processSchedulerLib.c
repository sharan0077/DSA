#include "processSchedulerLib.h"
#include <stdlib.h>
int processScheduler(List *queue){
	int index=0;
	Node* currentProcess=queue->head,*prev;
	if(queue->head==NULL)
		return 0;
	while(currentProcess!=NULL){
		((Data*)currentProcess->data)->element -= 5;
		prev = currentProcess->next;
	 	if((int*)((Data*)currentProcess->data)->element<=0)
	 		deleteNode(queue,index);
		index++;
		currentProcess = prev;
		if(currentProcess!=NULL && currentProcess->next==NULL)
		  	index = 0;
		if(currentProcess==NULL && queue->head!=NULL)
		  	currentProcess = queue->head;
	}
	return 1;
}

