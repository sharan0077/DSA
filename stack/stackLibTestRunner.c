#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
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

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_should_push_elemntsAddress_into_stack_and_return_true");
	setup();
		test_should_push_elemntsAddress_into_stack_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_push_an_element_into_the_stack_by_reallocating_the_memory");
	setup();
		test_should_push_an_element_into_the_stack_by_reallocating_the_memory();
	tearDown();
	testEnded();
	testStarted("test_should_pop_intElement_from_stack");
	setup();
		test_should_pop_intElement_from_stack();
	tearDown();
	testEnded();
	testStarted("test_should_return_elment_pointed_by_top");
	setup();
		test_should_return_elment_pointed_by_top();
	tearDown();
	testEnded();
	testStarted("test_should_push_an_element_into_the_stack_for_type_DoubleData");
	setup();
		test_should_push_an_element_into_the_stack_for_type_DoubleData();
	tearDown();
	testEnded();
	testStarted("test_should_pop_doubleElement_from_stack");
	setup();
		test_should_pop_doubleElement_from_stack();
	tearDown();
	testEnded();
	testStarted("test_should_return_zero_when_stack_isEmpty");
	setup();
		test_should_return_zero_when_stack_isEmpty();
	tearDown();
	testEnded();
	testStarted("test_should_push_an_element_into_stack_for_stringData");
	setup();
		test_should_push_an_element_into_stack_for_stringData();
	tearDown();
	testEnded();
	testStarted("test_should_pop_an_element_from_stack_of_stringData");
	setup();
		test_should_pop_an_element_from_stack_of_stringData();
	tearDown();
	testEnded();
	testStarted("test_should_return_double_type_element_pointed_by_top");
	setup();
		test_should_return_double_type_element_pointed_by_top();
	tearDown();
	testEnded();
	testStarted("test_should_return_string_type_element_pointed_by_top");
	setup();
		test_should_return_string_type_element_pointed_by_top();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
