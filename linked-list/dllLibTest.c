#include "testUtils.h"
#include "dllLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
List* list;
void freeNode(List *list){
	Node* cur = list->head,*prev;
	int i;
	for(i=0;i<list->length;i++){
		if(cur == NULL){
			free(list);
			break;
		}
		prev = cur;
		if(cur->next!=NULL)
			cur = cur->next;
		free(prev);
	}
}
void test_should_allocate_memory_for_linkedList_and_return_address_of_list(){
	list	= create();
	ASSERT(list->head==NULL);
	ASSERT(list->tail==NULL);
	ASSERT(list->length==0);
	freeNode(list);
}
void test_should_create_node_and_return_address_of_it(){
	int* element = malloc(sizeof(int));
	*element = 4;
	list->head = createNode(NULL,element,NULL);
	ASSERT(*(int*)list->head->data==4);
	ASSERT(list->head->next==NULL);
	ASSERT(list->head->prvious==NULL);
	freeNode(list);
	free(element);
}
void test_should_insert_node_into_zeroIndex_when_list_empty_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
	list = create();
	*element = 4;
	result = insertNode(list,0,element);
	ASSERT(result);
	ASSERT(*(int*)list->head->data==4);
	free(element);
	freeNode(list);
}
void test_should_insert_node_into_zeroIndex_when_list_not_empty_return_true(){
	int result;
	int *element = malloc(sizeof(int));
	list = create();
	*element = 4;
	insertNode(list,0,element);
	*element = 5;
	result = insertNode(list,0,element);
	ASSERT(*(int*)list->head->data==5);
	ASSERT(result);
	free(element);
	freeNode(list);
}
void test_should_insert_node_into_lastIndex_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
	list = create();
	*element = 4;
	insertNode(list,0,element);
	*element = 5;
	insertNode(list,0,element);
	*element = 6;
	result = insertNode(list,2,element);
	ASSERT(*(int*)list->tail->data==6);
	ASSERT(result);
	free(element);
	freeNode(list);
}
void test_should_not_insert_node_when_wrong_index_is_specified(){
	int result;
	int *element = malloc(sizeof(int));
	list = create();
	*element = 4;
	insertNode(list,0,element);
	*element = 7;
	result = insertNode(list,4,element);
	ASSERT(!result);
	free(element);
	freeNode(list);
}
void test_should_insert_node_into_middle_of_list_and_return_true(){
 	int result;
 	int *element = malloc(sizeof(int));
 	list = create();
	*element = 4;
	insertNode(list,0,element);
	*element = 5;
	insertNode(list,1,element);
	*element = 7;
	result = insertNode(list,1,element);
	ASSERT(result);
	free(element);
	freeNode(list);
}
void test_should_delete_node_from_zeroIndex_and_return_true(){
	int result;
 	int *element = malloc(sizeof(int));
 	list = create();
	*element = 4;
	insertNode(list,0,element);
	result = deleteNode(list,0);
	ASSERT(result);
	free(element);
	freeNode(list);
}
void test_should_delete_node_from_middle_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
 	list = create();
 	*element = 4;
	insertNode(list,0,element);
	*element = 5;
	insertNode(list,1,element);
	*element = 7;
	insertNode(list,1,element);
	result = deleteNode(list,1);
	ASSERT(result);	
	free(element);
	freeNode(list);
}
void test_should_delete_node_from_lastIndex_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
  	list = create();
  	*element = 4;
	insertNode(list,0,element);
	*element = 5;
	insertNode(list,1,element);
	result = deleteNode(list,1);
	ASSERT(result);
	free(element);
	freeNode(list);
}
void test_should_not_delete_node_when_wrong_index_provided_and_return_false(){
	int result;
	int *element = malloc(sizeof(int));
  	list = create();
  	*element = 4;
	insertNode(list,0,element);
	result = deleteNode(list,4);
	ASSERT(!result);
	free(element);
	freeNode(list);
}
void test_should_delete_node_when_list_has_only_one_node_and_return_true(){
	int result;
	int *element = malloc(sizeof(int));
  	list = create();
  	*element = 4;
	insertNode(list,0,element);
	result = deleteNode(list,0);
	ASSERT(result);
	free(element);
	freeNode(list);
}
void test_should_return_index_of_element_found(){
	int result;
	int *element1 = malloc(sizeof(int));
	int *element2 = malloc(sizeof(int));
  	list = create();
  	*element1 = 4;
	insertNode(list,0,element1);
	*element2 = 5;
	insertNode(list,1,element2);
	result = findIndex(list,element2);
	ASSERT(result==1);
	free(element1);
	free(element2);
	freeNode(list);
}
void test_should_return_minus_one_when_element_not_found(){
	int result;
	int *element1 = malloc(sizeof(int));
	int *element2 = malloc(sizeof(int));
  	list = create();
  	*element1 = 4;
	insertNode(list,0,element1);
	result = findIndex(list,element2);
	ASSERT(result==-1);
	free(element1);
	free(element2);
	freeNode(list);
}