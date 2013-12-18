#include "stackLLLib.h"
#include <stdlib.h>
int push(List* stack,void* element){
	insertNode(stack,0,element);
	return 1;
}
int getIndex(List* stack){
	int index = 0;
	Node* current=stack->head;
	while(current!=NULL){
		if(current==stack->tail)
			return index;
		index++;
		current = current->next;
	}
	return index;
}
int pop(List* stack){
	int index;
	if(stack->head==NULL)
		return 0;
	index = getIndex(stack);
	deleteNode(stack,index);
	return 1;
}
