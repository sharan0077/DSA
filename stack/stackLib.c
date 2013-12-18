#include "stackLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Stack* create(int typeSize,int noOfElements){
	Stack *stack = malloc(sizeof(Stack));
	stack->baseAddress = calloc(noOfElements,sizeof(void**));
	stack->length = noOfElements;
	stack->elementSize = typeSize;
	stack->top = -1;
	return stack;
}
int isFull(Stack *stack){
	if(stack->top>=stack->length-1) return 1;
	return 0;
}
int push(Stack *stack,void *element){
	if(isFull(stack))
		stack->baseAddress=realloc(stack->baseAddress,(stack->length+1)*sizeof(void**));
	stack->top += 1;	
	stack->baseAddress[stack->top] = element;
	return 1;
}
int isEmpty(Stack *stack){
	if(stack->top<0) return 1;
	return 0;
}
void* top(Stack *stack){
	void *topElement = NULL;
	if(isEmpty(stack))
		return topElement;
	topElement = stack->baseAddress[stack->top];
	return topElement;
}
void* pop(Stack *stack){
	void *popedElement = top(stack);
	stack->top -= 1;
	return popedElement;
}
void dispose(Stack *stack){
	free(stack->baseAddress);
	free(stack);
}