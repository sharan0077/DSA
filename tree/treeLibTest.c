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
	result = insert(tree,NULL,&data);
	ASSERT(result);
}
