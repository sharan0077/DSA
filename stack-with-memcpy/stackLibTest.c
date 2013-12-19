#include "testUtils.h"
#include "stackLib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack expected,*stack;
int areEqual(Stack a,Stack e){
	int result;
	result = a.length == e.length && a.elementSize == e.elementSize;
	if(!result) return 0;
	return 0 == memcmp(a.baseAddress,e.baseAddress,a.elementSize*a.length); 
}
void test_should_create_and_initialize_memory_to_zero_for_stack_of_typeInt(){	
	int arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(int);
	stack = create(sizeof(int),5);
	result = areEqual(*stack,expected);
	ASSERT(result);
	free(stack);
}
void test_should_create_and_initialize_memory_to_zero_for_stack_of_typeChar(){
	char arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(char);
	stack = create(sizeof(char),5);
	result = areEqual(*stack,expected);
	ASSERT(result);
	free(stack);
}
void test_should_create_and_initialize_memory_to_zero_for_stack_of_typeDouble(){	
	double arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(double);
	stack = create(sizeof(double),5);
	result = areEqual(*stack,expected);
	ASSERT(result);
	free(stack);
}
void test_should_create_stack_of_typeString(){
	String *ptr = calloc(5,sizeof(String));
	int result;
	expected.baseAddress = ptr;
	expected.length = 5;
	expected.elementSize = sizeof(String);
	stack = create(sizeof(String),5);
	result = areEqual(*stack,expected);
	ASSERT(result);
	free(stack);
}
void test_should_not_push_return_zero_as_stack_is_full(){
	int element = 5,result;
	stack = create(sizeof(int),3);
	push(stack,&element);
	push(stack,&element);
	push(stack,&element);
	result = push(stack,&element);
	ASSERT(result==0);
	free(stack);
}
void test_should_push_an_element_into_the_stack_for_intData(){
	int result,element=5;
	stack = create(sizeof(int),5);
	result = push(stack,&element);
	ASSERT(result);
	free(stack);
}
void test_should_pop_intElement_from_stack(){
	int *result;
	int element = 10;
	stack = create(sizeof(int),5);
	push(stack,&element);
	result = pop(stack);
	ASSERT(*result==element);
	free(stack);
}
void test_should_return_elment_pointed_by_top(){
	int *result;
	int value = 10;
	int element = 10;
	stack = create(sizeof(int),5);
	push(stack,&element);
	push(stack,&value);
	result = top(stack);
	ASSERT(*result==value);
	free(stack);
}
void test_should_push_an_element_into_the_stack_for_type_DoubleData(){
	int result;
	double element=5.00;
	stack = create(sizeof(double),5);
	result = push(stack,&element);
	ASSERT(result);
	free(stack);
}
void test_should_pop_doubleElement_from_stack(){
	double *result;
	double element = 10.00;
	stack = create(sizeof(double),5);
	push(stack,&element);
	result = pop(stack);
	ASSERT(*result==element);
	free(stack);
}
void test_should_return_zero_when_stack_isEmpty(){
	void* popedElement;
	stack = create(sizeof(int),5);
	popedElement = pop(stack);
	ASSERT(popedElement==NULL);
	free(stack);
}
void test_should_push_an_element_into_stack_for_stringData(){
	int result;
	String element = "hari";
	stack = create(sizeof(String),4);
	result = push(stack,&element);
	ASSERT(result);
	free(stack);
}
void test_should_pop_an_element_from_stack_of_stringData(){
	String* result;
	String element = "sri";
	stack = create(sizeof(String),4);
	push(stack,&element);
	result = pop(stack);
	ASSERT(0 == strcmp(*result,element));
	free(stack);
}
void test_should_return_double_type_element_pointed_by_top(){
	double *result;
	double value = 10.00;
	stack = create(sizeof(double),4);
	push(stack,&value);
	result = top(stack);
	ASSERT(*result==value);
	free(stack);
}
void test_should_return_string_type_element_pointed_by_top(){
	String *result;
	String value = "narayan";
	stack = create(sizeof(String),4);
	push(stack,&value);
	result = top(stack);
	ASSERT(0 == strcmp(*result,value));
	free(stack);
}