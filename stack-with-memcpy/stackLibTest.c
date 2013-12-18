#include "testUtils.h"
#include "stackLib.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack expected,*actual;
int areEqual(Stack a,Stack e){
	int result;
	result = a.length == e.length && a.elementSize == e.elementSize;
	if(!result) return 0;
	return 0 == memcmp(a.baseAddress,e.baseAddress,a.elementSize*a.length); 
}
void test_should_should_allocate_and_initialize_memory_to_zero_for_stack_of_typeInt(){	
	int arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(int);
	actual = create(sizeof(int),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	free(actual);
}
void test_should_should_allocate_and_initialize_memory_to_zero_for_stack_of_typeChar(){
	char arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(char);
	actual = create(sizeof(char),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	free(actual);
}
void test_should_should_allocate_and_initialize_memory_to_zero_for_stack_of_typeDouble(){	
	double arr[] = {0,0,0,0,0};
	int result;
	expected.baseAddress = arr;
	expected.length = 5;
	expected.elementSize = sizeof(double);
	actual = create(sizeof(double),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	free(actual);
}
void test_should_allocate_and_initialize_memory_to_zero_for_stack_of_typeString(){
	String *ptr = calloc(5,sizeof(String));
	int result;
	expected.baseAddress = ptr;
	expected.length = 5;
	expected.elementSize = sizeof(String);
	actual = create(sizeof(String),5);
	result = areEqual(*actual,expected);
	ASSERT(result);
	free(actual);
}
void test_should_not_push_return_zero_as_stack_is_full(){
	int element = 5,result;
	actual = create(sizeof(int),3);
	push(actual,&element);
	push(actual,&element);
	push(actual,&element);
	result = push(actual,&element);
	ASSERT(result==0);
	free(actual);
}
void test_should_push_an_element_into_the_stack_for_intData(){
	int result,element=5;
	actual = create(sizeof(int),5);
	result = push(actual,&element);
	ASSERT(result);
}
void test_should_pop_intElement_from_stack(){
	int *result;
	int element = 10;
	push(actual,&element);
	result = pop(actual);
	ASSERT(*result==element);
}
void test_should_return_elment_pointed_by_top(){
	int *result;
	int value = 10;
	push(actual,&value);
	result = top(actual);
	ASSERT(*result==value);
	free(actual);
}
void test_should_push_an_element_into_the_stack_for_type_DoubleData(){
	int result;
	double element=5.00;
	actual = create(sizeof(double),5);
	result = push(actual,&element);
	ASSERT(result);
}
void test_should_pop_doubleElement_from_stack(){
	double *result;
	double element = 10.00;
	push(actual,&element);
	result = pop(actual);
	ASSERT(*result==element);
}
void test_should_return_zero_when_stack_isEmpty(){
	void* popedElement;
	actual = create(sizeof(int),5);
	popedElement = pop(actual);
	ASSERT(popedElement==NULL);
}
void test_should_push_an_element_into_stack_for_stringData(){
	int result;
	String element = "hari";
	actual = create(sizeof(String),4);
	result = push(actual,&element);
	ASSERT(result);
}
void test_should_pop_an_element_from_stack_of_stringData(){
	String* result;
	String element = "sri";
	push(actual,&element);
	result = pop(actual);
	ASSERT(0 == strcmp(*result,element));
	free(actual);
}
void test_should_return_double_type_element_pointed_by_top(){
	double *result;
	double value = 10.00;
	actual = create(sizeof(double),4);
	push(actual,&value);
	result = top(actual);
	ASSERT(*result==value);
	free(actual);
}
void test_should_return_string_type_element_pointed_by_top(){
	String *result;
	String value = "narayan";
	actual = create(sizeof(String),4);
	push(actual,&value);
	result = top(actual);
	ASSERT(0 == strcmp(*result,value));
	free(actual);
}