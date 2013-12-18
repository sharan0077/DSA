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

	testStarted("test_should_allocate_memory_for_linkedList_and_return_address_of_list");
	setup();
		test_should_allocate_memory_for_linkedList_and_return_address_of_list();
	tearDown();
	testEnded();
	testStarted("test_should_create_node_and_return_address_of_it");
	setup();
		test_should_create_node_and_return_address_of_it();
	tearDown();
	testEnded();
	testStarted("test_should_insert_node_into_zeroIndex_when_list_empty_and_return_true");
	setup();
		test_should_insert_node_into_zeroIndex_when_list_empty_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_insert_node_into_zeroIndex_when_list_not_empty_return_true");
	setup();
		test_should_insert_node_into_zeroIndex_when_list_not_empty_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_insert_node_into_lastIndex_and_return_true");
	setup();
		test_should_insert_node_into_lastIndex_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_node_when_wrong_index_is_specified");
	setup();
		test_should_not_insert_node_when_wrong_index_is_specified();
	tearDown();
	testEnded();
	testStarted("test_should_insert_node_into_middle_of_list_and_return_true");
	setup();
		test_should_insert_node_into_middle_of_list_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_delete_node_from_zeroIndex_and_return_true");
	setup();
		test_should_delete_node_from_zeroIndex_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_delete_node_from_middle_and_return_true");
	setup();
		test_should_delete_node_from_middle_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_delete_node_from_lastIndex_and_return_true");
	setup();
		test_should_delete_node_from_lastIndex_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_not_delete_node_when_wrong_index_provided_and_return_false");
	setup();
		test_should_not_delete_node_when_wrong_index_provided_and_return_false();
	tearDown();
	testEnded();
	testStarted("test_should_delete_node_when_list_has_only_one_node_and_return_true");
	setup();
		test_should_delete_node_when_list_has_only_one_node_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_return_index_of_element_found");
	setup();
		test_should_return_index_of_element_found();
	tearDown();
	testEnded();
	testStarted("test_should_return_minus_one_when_element_not_found");
	setup();
		test_should_return_minus_one_when_element_not_found();
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
