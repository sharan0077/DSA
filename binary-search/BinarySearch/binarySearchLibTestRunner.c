#include <stdio.h>

int testCount=0;
int passCount=0;

void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();

void testStarted(char* name){
	printf("\t%s\n",name);
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber){
	printf("\t\t*** failed at %s:%d\n",fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	setup();
		test_should_accept_intArray_and_return_address_of_found_element();
	tearDown();

	setup();
		test_should_accept_intArray_and_return_NULL_when_element_not_found();
	tearDown();

	setup();
		test_should_accept_doubleArray_and_return_address_of_found_elements();
	tearDown();

	setup();
		test_should_accept_charArray_and_return_address_of_found_elements();
	tearDown();

	setup();
		test_should_accept_oneElement_and_return_address_of_found_element();
	tearDown();

	setup();
		test_should_accept_StringArray_andreturn_address_of_found_element();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
