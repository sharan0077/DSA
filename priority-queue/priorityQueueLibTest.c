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
void test_should_insert_element_into_queue_based_on_priority_and_return_true(){
	int result;
	Data* data1 = (Data *)malloc(sizeof(Data));
	Data* data2 = (Data *)malloc(sizeof(Data));
	int element1 = 4,element2 = 5;
	queue = create();
	data1->priority = 1;
	data2->priority = 2;
	data1->element = &element1;
	data2->element = &element2;
	enqueue(queue,data1);
	result = enqueue(queue,data2);
	ASSERT(result);
	ASSERT(*(int*)((Data*)queue->head->data)->element==5);
	freeNode(queue);
	free(data1);
	free(data2);
}
void test_should_insert_element_based_on_priority_and_return_true(){
	int result;
	Data* data1 = (Data *)malloc(sizeof(Data));
	Data* data2 = (Data *)malloc(sizeof(Data));
	Data* data3 = (Data *)malloc(sizeof(Data));
	int element1 = 4,element2 = 5,element3 = 6;
	queue = create();
	data1->priority = 2;
	data2->priority = 3;
	data3->priority = 1;
	data1->element = &element1;
	data2->element = &element2;
	data3->element = &element3;
	enqueue(queue,data1);
	enqueue(queue,data2);
	result = enqueue(queue,data3);
	ASSERT(result);
	ASSERT(*(int*)((Data*)queue->head->data)->element==5);
	freeNode(queue);
	free(data1);
	free(data2);
	free(data3);
}
void test_should_delete_element_from_queue_and_return_true_when_que_has_one_element(){
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
void test_should_delete_element_with_heighest_priority_when_que_has_multiple_elements(){
	int result;
	Data* data1 = (Data *)malloc(sizeof(Data));
	Data* data2 = (Data *)malloc(sizeof(Data));
	int element1 = 4,element2 = 5;
	queue = create();
	data1->priority = 1;
	data2->priority = 2;
	data1->element = &element1;
	data2->element = &element2;
	enqueue(queue,data1);
	enqueue(queue,data2);
	result = dequeue(queue);
	ASSERT(result);
	ASSERT(*(int*)((Data*)queue->head->data)->element==4);
	freeNode(queue);
	free(data1);
	free(data2);
}
void test_dequeue_should_return_false_when_queue_is_empty(){
	int result;
	queue = create();
	result = dequeue(queue);
	ASSERT(!result);
	freeNode(queue);
}