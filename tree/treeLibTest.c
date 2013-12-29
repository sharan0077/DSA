#include "testUtils.h"
#include "treeLib.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
int areEqual(void* id,void* data){
	return (*(int*)id == *(int*)data);
}
void test_should_create_tree_and_insert_root_node_and_return_true(){
	int result , data = 4;
	Tree tree;
	tree = createTree(areEqual);
	result = insertNode(&tree,NULL,&data);
	ASSERT(result);
}
void test_should_insert_node_when_root_already_present(){
	int result , parentData = 4 , data = 5;
	Tree tree;

	Iterator it;
	tree = createTree(areEqual);
	insertNode(&tree,NULL,&data);
	result = insertNode(&tree,&parentData,&data);
	ASSERT(result);
	it = getChildren(&tree, &parentData);
	while(it.hasNext(&it)){
		ASSERT(data = *(int*)(it.next(&it)));
	}
}