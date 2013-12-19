#include "testUtils.h"
#include "processSchedulerLib.h"
#include <stdlib.h>
#include <string.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
List *queue;
void test_should_accept_procees_and_give_it_scheduler_and_return_true_once_proceesed(){
	int result;
	int time = 10;
	Data* element1 = (Data*) malloc(sizeof(Data));
	Data* element2 = (Data*) malloc(sizeof(Data));
	Process* process1 = (Process*) malloc(sizeof(Process));
	Process* process2 = (Process*) malloc(sizeof(Process));
	process1->Time = 10;
	strcpy(process1->processName,"tskMgr");
	process2->Time = 20;
	strcpy(process1->processName,"browser");
	element1->priority = 10;
	element1->element = process1;
	element2->priority = 5;
	element2->element = process2;
	queue = create();
	enqueue(queue,element1);
	enqueue(queue,element2);
	result = processScheduler(queue);
	ASSERT(result);
}
