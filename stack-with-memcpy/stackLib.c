#include "stackLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Stack* create(int typeSize,int noOfElements){
	Stack *stack = malloc(sizeof(Stack));
	stack->baseAddress = calloc(noOfElements,typeSize);
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
		return 0;
	stack->top += 1;	
	memcpy(stack->baseAddress+(stack->top*stack->elementSize),element,stack->elementSize);
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
	topElement = stack->baseAddress+(stack->top*stack->elementSize);
	return topElement;
}
void* pop(Stack *stack){
	void *popedElement = top(stack);
	stack->top -= 1;
	return popedElement;
}