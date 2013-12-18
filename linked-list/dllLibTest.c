#include "testUtils.h"
#include "dllLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
List* actual;
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
void test_should_allocate_memory_for_linkedList_and_return_address_of_list(){
	actual	= create();
	ASSERT(actual->head==NULL);
	ASSERT(actual->tail==NULL);
	ASSERT(actual->length==0);
	freeNode(actual);
}
void test_should_create_node_and_return_address_of_it(){
	int* element = malloc(sizeof(int));
	*element = 4;
	actual->head = createNode(NULL,element,NULL);
	ASSERT(*(int*)actual->head->data==4);
	ASSERT(actual->head->next==NULL);
	ASSERT(actual->head->prvious==NULL);
	freeNode(actual);
	free(element);
}
void test_should_insert_node_into_zeroIndex_when_list_empty_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
	actual = create();
	*element = 4;
	result = insertNode(actual,0,element);
	ASSERT(result);
	ASSERT(*(int*)actual->head->data==4);
	free(element);
	freeNode(actual);
}
void test_should_insert_node_into_zeroIndex_when_list_not_empty_return_true(){
	int result;
	int *element = malloc(sizeof(int));
	actual = create();
	*element = 4;
	insertNode(actual,0,element);
	*element = 5;
	result = insertNode(actual,0,element);
	ASSERT(*(int*)actual->head->data==5);
	ASSERT(result);
	free(element);
	freeNode(actual);
}
void test_should_insert_node_into_lastIndex_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
	actual = create();
	*element = 4;
	insertNode(actual,0,element);
	*element = 5;
	insertNode(actual,0,element);
	*element = 6;
	result = insertNode(actual,2,element);
	ASSERT(*(int*)actual->tail->data==6);
	ASSERT(result);
	free(element);
	freeNode(actual);
}
void test_should_not_insert_node_when_wrong_index_is_specified(){
	int result;
	int *element = malloc(sizeof(int));
	actual = create();
	*element = 4;
	insertNode(actual,0,element);
	*element = 7;
	result = insertNode(actual,4,element);
	ASSERT(!result);
	free(element);
	freeNode(actual);
}
void test_should_insert_node_into_middle_of_list_and_return_true(){
 	int result;
 	int *element = malloc(sizeof(int));
 	actual = create();
	*element = 4;
	insertNode(actual,0,element);
	*element = 5;
	insertNode(actual,1,element);
	*element = 7;
	result = insertNode(actual,1,element);
	ASSERT(result);
	free(element);
	freeNode(actual);
}
void test_should_delete_node_from_zeroIndex_and_return_true(){
	int result;
 	int *element = malloc(sizeof(int));
 	actual = create();
	*element = 4;
	insertNode(actual,0,element);
	result = deleteNode(actual,0);
	ASSERT(result);
	free(element);
	freeNode(actual);
}
void test_should_delete_node_from_middle_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
 	actual = create();
 	*element = 4;
	insertNode(actual,0,element);
	*element = 5;
	insertNode(actual,1,element);
	*element = 7;
	insertNode(actual,1,element);
	result = deleteNode(actual,1);
	ASSERT(result);	
	free(element);
	freeNode(actual);
}
void test_should_delete_node_from_lastIndex_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
  	actual = create();
  	*element = 4;
	insertNode(actual,0,element);
	*element = 5;
	insertNode(actual,1,element);
	result = deleteNode(actual,1);
	ASSERT(result);
	free(element);
	freeNode(actual);
}
void test_should_not_delete_node_when_wrong_index_provided_and_return_false(){
	int result;
	int *element = malloc(sizeof(int));
  	actual = create();
  	*element = 4;
	insertNode(actual,0,element);
	result = deleteNode(actual,4);
	ASSERT(!result);
	free(element);
	freeNode(actual);
}
void test_should_delete_node_when_list_has_only_one_node_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
  	actual = create();
  	*element = 4;
	insertNode(actual,0,element);
	result = deleteNode(actual,0);
	ASSERT(result);
	free(element);
	freeNode(actual);
}
void test_should_return_index_of_element_found(){
	int result;
	int *element1 = malloc(sizeof(int));
	int *element2 = malloc(sizeof(int));
  	actual = create();
  	*element1 = 4;
	insertNode(actual,0,element1);
	*element2 = 5;
	insertNode(actual,1,element2);
	result = findIndex(actual,element2);
	ASSERT(result==1);
	free(element1);
	free(element2);
	freeNode(actual);
}
void test_should_return_minus_one_when_element_not_found(){
	int result;
	int *element1 = malloc(sizeof(int));
	int *element2 = malloc(sizeof(int));
  	actual = create();
  	*element1 = 4;
	insertNode(actual,0,element1);
	result = findIndex(actual,element2);
	ASSERT(result==-1);
	free(element1);
	free(element2);
	freeNode(actual);
}