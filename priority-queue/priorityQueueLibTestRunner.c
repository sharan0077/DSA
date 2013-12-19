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

	testStarted("test_should_insert_element_into_queue_and_return_true");
	setup();
		test_should_insert_element_into_queue_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_insert_element_into_queue_based_on_priority_and_return_true");
	setup();
		test_should_insert_element_into_queue_based_on_priority_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_insert_element_based_on_priority_and_return_true");
	setup();
		test_should_insert_element_based_on_priority_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_delete_element_from_queue_and_return_true_when_que_has_one_element");
	setup();
		test_should_delete_element_from_queue_and_return_true_when_que_has_one_element();
	tearDown();
	testEnded();
	testStarted("test_should_delete_element_with_heighest_priority_when_que_has_multiple_elements");
	setup();
		test_should_delete_element_with_heighest_priority_when_que_has_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_dequeue_should_return_false_when_queue_is_empty");
	setup();
		test_dequeue_should_return_false_when_queue_is_empty();
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
