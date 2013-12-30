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
void test_should_insert_child_for_the_root_node(){
	int result , parentData = 4 , data = 5;
	Tree tree;
	Iterator it;
	tree = createTree(areEqual);
	insertNode(&tree,NULL,&parentData);
	result = insertNode(&tree,&parentData,&data);
	ASSERT(result);
	it = getChildren(&tree, &parentData);
	while(it.hasNext(&it)){
		ASSERT(data = *(int*)(it.next(&it)));
	}
}

void test_getChildren_should_return_false_root__has_no_child(){
	int result , parentData = 4 , data = 5;
	Tree tree;
	Iterator it;
	tree = createTree(areEqual);
	insertNode(&tree,NULL,&parentData);
	it = getChildren(&tree, &parentData);
	ASSERT(0== it.hasNext(&it));
}

void test_search_should_return_true_when_data_found_in_tree(){
	int result , parentData = 4 , data = 5;
	Tree tree;
	Iterator it;
	tree = createTree(areEqual);
	insertNode(&tree,NULL,&parentData);
	insertNode(&tree, &parentData, &data);
	ASSERT(1 == search(&tree,&data));
}

void test_search_should_return_false_when_data_not_in_tree(){
	int result , parentData = 4 , data = 5, data2 = 6;
	Tree tree;
	Iterator it;
	tree = createTree(areEqual);
	insertNode(&tree,NULL,&parentData);
	insertNode(&tree, &parentData, &data);
	ASSERT(0 == search(&tree,&data2));
}

void test_to_insert_multiple_nodes_at_root_node(){
	int arr[] = {1,2,3,4};
	int result ;
	Tree tree;
	int count = 3;
	Iterator it;
	tree = createTree(areEqual);
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	insertNode(&tree, &arr[0], &arr[3]);
	it = getChildren(&tree, &arr[0]);
	while(it.hasNext(&it)){
		ASSERT(arr[count] == *(int*)(it.next(&it)));
		count--;
	}
}

void test_to_insert_child_of_child_of_root(){
	int arr[] = {1,2,3,4,5};
	int result ;
	int count = 3;
	Tree tree;
	Iterator it;
	tree = createTree(areEqual);
	result = insertNode(&tree, NULL, &arr[0]);
	ASSERT(result);
	insertNode(&tree, &arr[0], &arr[1]);
	insertNode(&tree, &arr[0], &arr[2]);
	insertNode(&tree, &arr[0], &arr[3]);
	result = insertNode(&tree, &arr[1], &arr[4]);	
	ASSERT(result);
	it = getChildren(&tree, &arr[1]);
	while(it.hasNext(&it)){
		ASSERT(5 == *(int*)(it.next(&it)));
		count++;
	}
}