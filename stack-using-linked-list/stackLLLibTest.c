#include "testUtils.h"
#include "stackLLLib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
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
void test_should_create_and_push_an_element_into_stack(){
	int result;
	int element = 4;
	List* stack = create();
	result = push(stack,&element);
	ASSERT(result);
	freeNode(stack);
}
void test_should_pop_an_element_from_the_queue_and_return_true(){
int result;
	int element = 4;
	List* stack = create();
	push(stack,&element);
	result = pop(stack);
	ASSERT(result);
	freeNode(stack);
}
