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
		test_should_should_allocate_and_initialize_memory_to_zero_for_stack_of_typeInt();
	tearDown();

	setup();
		test_should_should_allocate_and_initialize_memory_to_zero_for_stack_of_typeChar();
	tearDown();

	setup();
		test_should_should_allocate_and_initialize_memory_to_zero_for_stack_of_typeDouble();
	tearDown();

	setup();
		test_should_allocate_and_initialize_memory_to_zero_for_stack_of_typeString();
	tearDown();

	setup();
		test_should_not_push_return_zero_as_stack_is_full();
	tearDown();

	setup();
		test_should_push_an_element_into_the_stack_for_intData();
	tearDown();

	setup();
		test_should_pop_intElement_from_stack();
	tearDown();

	setup();
		test_should_return_elment_pointed_by_top();
	tearDown();

	setup();
		test_should_push_an_element_into_the_stack_for_type_DoubleData();
	tearDown();

	setup();
		test_should_pop_doubleElement_from_stack();
	tearDown();

	setup();
		test_should_return_zero_when_stack_isEmpty();
	tearDown();

	setup();
		test_should_push_an_element_into_stack_for_stringData();
	tearDown();

	setup();
		test_should_pop_an_element_from_stack_of_stringData();
	tearDown();

	setup();
		test_should_return_double_type_element_pointed_by_top();
	tearDown();

	setup();
		test_should_return_string_type_element_pointed_by_top();
	tearDown();


	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
