#include "testUtils.h"
#include "binarySearchLib.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int intCompare(void *a,void *b){
	return *(int*)a - *(int*)b;
}
int compareStrings(void *a,void *b){
        return strcmp((char*)a, (char*)b);
}
int compareChar(void *a,void *b){
	return *(char*)a - *(char*)b;
}
int compareDouble(void *a,void *b){
	return *(double*)a - *(double*)b;
}
void test_should_accept_intArray_and_return_address_of_found_element(){
	int a[] = {1,2,3,4,5};
	int key = 1;
	ASSERT(*(int*)(bSearch(&key,a,5,sizeof(int),intCompare))==key);
}
void test_should_accept_intArray_and_return_NULL_when_element_not_found(){
	int a[] = {1,2,3,4,5};
	int key = 9;
	ASSERT((int*)(bSearch(&key,a,5,sizeof(int),intCompare))==NULL);
}
void test_should_accept_doubleArray_and_return_address_of_found_elements(){
	double a[] = {1.5,2.5,3.5,4.5};
	double key = 1.5;
	ASSERT(*(double*)(bSearch(&key,a,4,sizeof(double),compareDouble))==key);
}
void test_should_accept_charArray_and_return_address_of_found_elements(){
	char a[] = {'a','b','c','d','e'};
	char key = 'd';
	ASSERT(*(char*)(bSearch(&key,a,5,sizeof(char),compareChar))==key);
}
void test_should_accept_oneElement_and_return_address_of_found_element(){
	int a[] = {1};
	int key = 1;
	ASSERT(*(int*)(bSearch(&key,a,1,sizeof(int),intCompare))==key);
}
void test_should_accept_StringArray_andreturn_address_of_found_element(){
    String names[5] = {"abc","def","hij","klm","nop"};
    char* key = "klm";
    char* result = bSearch(key, names, 5, sizeof(String), compareStrings);
    ASSERT(0 == strcmp(key, result));
};