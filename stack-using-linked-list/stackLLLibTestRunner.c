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

	testStarted("test_should_create_and_push_an_element_into_stack");
	setup();
		test_should_create_and_push_an_element_into_stack();
	tearDown();
	testEnded();
	testStarted("test_should_return_true_after_pushing_multiple_elements_into_stack");
	setup();
		test_should_return_true_after_pushing_multiple_elements_into_stack();
	tearDown();
	testEnded();
	testStarted("test_should_pop_an_element_from_the_queue_and_return_true");
	setup();
		test_should_pop_an_element_from_the_queue_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_pop_an_element_when_there_are_multiple_elements_in_the_queue");
	setup();
		test_should_pop_an_element_when_there_are_multiple_elements_in_the_queue();
	tearDown();
	testEnded();
	testStarted("test_pop_should_return_false_when_que_is_empty");
	setup();
		test_pop_should_return_false_when_que_is_empty();
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
