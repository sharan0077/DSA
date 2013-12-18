#include "testUtils.h"
#include "priorityQueueLib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
List *queue;
void freeNode(List *actual){
	Node* cur = actual->head,*prev;
	int i;
	for(i=0;i<actual->length;i++){
		if(cur == NULL){
			free(actual);
			break;
		}
		prev = cur;
		if(cur->next!=NULL)
			cur = cur->next;
		free(prev);
	}
}
void test_should_insert_element_into_queue_and_return_true(){
	int result;
	Data* data = (Data *)malloc(sizeof(Data));
	int element = 4;
	queue = create();
	data->priority = 1;
	data->element = &element;
	result = enqueue(queue,data);
	ASSERT(result);
	freeNode(queue);
	free(data);
}
void test_should_delete_element_from_queue_and_return_true(){
	int result;
	Data* data = (Data *)malloc(sizeof(Data));
	int element = 4;
	queue = create();
	data->priority = 1;
	data->element = &element;
	enqueue(queue,data);
	result = dequeue(queue);
	ASSERT(result);
	freeNode(queue);
	free(data);
}