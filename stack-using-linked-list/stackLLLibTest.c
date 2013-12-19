#include "testUtils.h"
#include "stackLLLib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
void freeNode(List *stack){
	Node* cur = stack->head,*prev;
	int i;
	for(i=0;i<stack->length;i++){
		if(cur == NULL){
			free(stack);
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
void test_should_return_true_after_pushing_multiple_elements_into_stack(){
	int result;
	int element = 4;
	List* stack = create();
	push(stack,&element);
	element = 5;
	push(stack,&element);
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
void test_should_pop_an_element_when_there_are_multiple_elements_in_the_queue(){
	int result;
	int element = 4;
	List* stack = create();
	push(stack,&element);
	element = 5;
	push(stack,&element);
	push(stack,&element);
	result = pop(stack);
	ASSERT(result);
	freeNode(stack);
}
void test_pop_should_return_false_when_que_is_empty(){
	int result;
	List* stack = create();
	result = pop(stack);
	ASSERT(!result);
}

