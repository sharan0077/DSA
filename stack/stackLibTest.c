#include "testUtils.h"
#include "stackLib.h"
#include <string.h>
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack expected,*actual;
void test_should_push_elemntsAddress_into_stack_and_return_true(){
	int element = 5,result;
	actual = create(sizeof(int),3);
	push(actual,&element);
	push(actual,&element);
	result = push(actual,&element);
	ASSERT(result);
	dispose(actual);
}
void test_should_push_an_element_into_the_stack_by_reallocating_the_memory(){
	int result,element=5;
	actual = create(sizeof(int),3);
	push(actual,&element);
	push(actual,&element);
	push(actual,&element);
	result = push(actual,&element);
	ASSERT(result);
	dispose(actual);
}
void test_should_pop_intElement_from_stack(){
	int *result;
	int element = 10;
	actual = create(sizeof(int),3);
	push(actual,&element);
	result = pop(actual);
	ASSERT(*result==element);
	dispose(actual);
}
void test_should_return_elment_pointed_by_top(){
	int *result;
	int value = 10;
	actual = create(sizeof(int),3);
	push(actual,&value);
	result = top(actual);
	ASSERT(*result==value);
	dispose(actual);
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
	actual = create(sizeof(double),3);
	push(actual,&element);
	result = pop(actual);
	ASSERT(*result==element);
	dispose(actual);
}
void test_should_return_zero_when_stack_isEmpty(){
	void* popedElement;
	actual = create(sizeof(int),5);
	popedElement = pop(actual);
	ASSERT(popedElement==NULL);
	dispose(actual);
}
void test_should_push_an_element_into_stack_for_stringData(){
	int result;
	String element = "hari";
	actual = create(sizeof(String),4);
	result = push(actual,&element);
	ASSERT(result);
	dispose(actual);
}
void test_should_pop_an_element_from_stack_of_stringData(){
	String* result;
	String element = "sri";
	actual = create(sizeof(String),4);
	push(actual,&element);
	result = pop(actual);
	ASSERT(0 == strcmp(*result,element));
	dispose(actual);
}
void test_should_return_double_type_element_pointed_by_top(){
	double *result;
	double value = 10.00;
	actual = create(sizeof(double),4);
	push(actual,&value);
	result = top(actual);
	ASSERT(*result==value);
	dispose(actual);
}
void test_should_return_string_type_element_pointed_by_top(){
	String *result;
	String value = "narayan";
	actual = create(sizeof(String),4);
	push(actual,&value);
	result = top(actual);
	ASSERT(0 == strcmp(*result,value));
	dispose(actual);
}