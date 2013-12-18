#include "priorityQueueLib.h"
#include <stdio.h>
int enqueue(List *queue,void* data){
	int index=0;
	Node* temp = queue->head;
	while(temp!=NULL){
		if(((Data *)data)->priority >=  ((Data *)temp->data)->priority)
			break;
		index++;
		temp = temp->next;
	}
	insertNode(queue,index,data);
	return 1;
}
int dequeue(List *queue){
	if(queue->head==NULL)
		return 0;
	deleteNode(queue,0);
	return 1;
}