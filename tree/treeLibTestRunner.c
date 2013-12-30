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

	testStarted("test_should_create_tree_and_insert_root_node_and_return_true");
	setup();
		test_should_create_tree_and_insert_root_node_and_return_true();
	tearDown();
	testEnded();
	testStarted("test_should_insert_child_for_the_root_node");
	setup();
		test_should_insert_child_for_the_root_node();
	tearDown();
	testEnded();
	testStarted("test_getChildren_should_return_false_root__has_no_child");
	setup();
		test_getChildren_should_return_false_root__has_no_child();
	tearDown();
	testEnded();
	testStarted("test_search_should_return_true_when_data_found_in_tree");
	setup();
		test_search_should_return_true_when_data_found_in_tree();
	tearDown();
	testEnded();
	testStarted("test_search_should_return_false_when_data_not_in_tree");
	setup();
		test_search_should_return_false_when_data_not_in_tree();
	tearDown();
	testEnded();
	testStarted("test_to_insert_multiple_nodes_at_root_node");
	setup();
		test_to_insert_multiple_nodes_at_root_node();
	tearDown();
	testEnded();
	testStarted("test_to_insert_child_of_child_of_root");
	setup();
		test_to_insert_child_of_child_of_root();
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
