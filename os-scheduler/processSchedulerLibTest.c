#include "testUtils.h"
#include "processSchedulerLib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
List *queue;
void test_should_accept_procees_and_give_it_scheduler_and_return_true_once_proceesed(){
	int result;
	Process* process1 = (Process*) malloc(sizeof(Process));
	Process* process2 = (Process*) malloc(sizeof(Process));
	queue = create();
	process1->Time = 20;
	process1->priority = 5;
	process2->Time = 25;
	process2->priority = 10;
	enqueue(queue,process1);
	enqueue(queue,process2);
	result = processScheduler(queue);
	ASSERT(result);
}