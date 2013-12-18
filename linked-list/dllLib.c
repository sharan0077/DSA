#include "dllLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
List* create(){
	List* list = malloc(sizeof(List));
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return list;
}
Node* getCurrent(List* list,int index){
	int i;
	Node* current = list->head;
	for(i=0;i<index;i++){
		if(current->next!=NULL)
			current = current->next; 
	}
	return current;
}
Node* createNode(void* previous,void *element,void* next){
	Node* node = malloc(sizeof(Node));
	node->data = element;
	node->next = next;
	node->prvious = previous;
	return node;
}
int insertFront(List* list,Node* current,void* element){
	current->prvious = createNode(NULL,element,current);
	list->head = current->prvious;
	list->length += 1;
	return 1;
}
int insertRear(List* list,Node* current,void* element){
	current->next = createNode(current,element,NULL);
	list->tail = current->next;
	list->length += 1;
	return 1;
}
int insertMiddle(List* list,Node* current,void* element){
	Node* temp = current->prvious;
	current->prvious = createNode(temp,element,current);
	temp->next = current->prvious;
	list->length += 1;
	return 1;
}
int insertNode(List* list,int index,void* element){

	Node* current = list->head; 
	int i;
	if(index>list->length)
		return 0;
	if(list->head == NULL && list->tail == NULL){
		list->head = createNode(NULL,element,NULL);
		list->tail = list->head;
		list->length += 1;
		return 1;
	}

	current = getCurrent(list,index);
	if(index==0)
		return insertFront(list,current,element);
	if(index==list->length)
		return insertRear(list,current,element);
	return insertMiddle(list,current,element);
}
int deleteFront(List* list,Node* current){
	list->head=current->next;
	free(current);
	list->head->prvious=NULL;
	list->length--;
	return 1;
}
int deleteRear(List* list,Node* current){
	list->tail=current->prvious;
	list->tail->next=NULL;
	free(current);
	list->length--;
	return 1;
}
int deleteMiddle(List* list,Node* current){
	Node* temp = current->prvious;
	temp->next = current->next;
	temp = temp->next;
	temp->prvious = current->prvious;
	free(current);
	list->length--;
	return 1;
}
int deleteNode(List* list,int index){
	int i;
	Node* current;
	if(index>=list->length)
		return 0;
	current = getCurrent(list,index);
	if(index==0 && current->next==NULL){
		free(current);
		list->head=NULL;
		list->tail=NULL;	
		return 1;
	}
	if(index==0)
		return deleteFront(list,current);
	if(index==(list->length-1))
		return deleteRear(list,current);
	return deleteMiddle(list,current);	
}
int findIndex(List* list,void* element){
	int i=0;
	Node* current = list->head;
	for(i=0;i<list->length;i++){
		if(current->data==element)
			return i;
		current = current->next;
	}
	return -1;
}