#include "treeLib.h"
#include <stdlib.h>
typedef struct{
	void* parent;
	void* data;
	List* children;
}TreeNode;

Tree createTree(compare cmp){
	Tree tree;
	tree.root = NULL;
	tree.compareFunc = cmp;
	return tree; 
}
int insertAsRoot(Tree* tree,TreeNode* node,void* data){
	node->data = data;
	node->children = create();
 	node->parent = NULL;
	tree->root = create();
	insert((List*)tree->root, 0,node);	
	return 1;
}
TreeNode* traverse(List* list,void* data,compare cmp){
	TreeNode* temp;
	Iterator it = getIterator(list);
	while(it.hasNext(&it)){
		temp = it.next(&it);
		if(cmp(temp->data,data))
			return temp;
		if(temp->children->head != NULL)
			return traverse(temp->children, data, cmp);
	}
	return NULL;
}
int insertChild(TreeNode* node,TreeNode* treenode,void* data){
	node->data = data;
	node->children = create();
	node->parent = treenode;
	insert(treenode->children, 0, node);
	return 1;
}
int insertNode(Tree* tree,void* parentData,void* data){
	TreeNode* treenode;
	TreeNode* node = malloc(sizeof(TreeNode));
	if(parentData == NULL)
		return insertAsRoot(tree,node,data);
	treenode = traverse((List*)tree->root, parentData,tree->compareFunc);
	return insertChild(node,treenode,data);
	return 0;
}
void* getChildrenData(Iterator* it){
	TreeNode* node;
	Iterator treeIterator = getIterator(it->list);
	treeIterator.position = it->position;
	node = treeIterator.next(&treeIterator);
	it->position++;
	return node->data;
}
Iterator getChildren(Tree* tree, void* data){
	Iterator it;
	TreeNode* treenode ;
	treenode = traverse((List*)tree->root, data, tree->compareFunc);
	it = getIterator(treenode->children);
	it.next = getChildrenData;
	return  it;
}
int search(Tree* tree, void* data){
	TreeNode* treenode;
	treenode = traverse((List*)tree->root, data, tree->compareFunc);
	if(!treenode) return 0;
	return 1;
}
int getIndex(Tree* tree,TreeNode* treenode,void* data){
	int index = 0;
	Iterator it = getIterator(treenode->children);
	void* dataInNode;
	while(it.hasNext(&it)){
		dataInNode = ((TreeNode*)it.next(&it))->data;
		if(tree->compareFunc(dataInNode,data))
			return index;
		index++;
	}
	return -1;
}

int deleteNode(Tree* tree,void* data){
	TreeNode* treenode;
	int index;
	treenode = traverse((List*)tree->root, data,tree->compareFunc);
	if(treenode == NULL || treenode->children->head != NULL)
		return 0;
	index = getIndex(tree,treenode->parent,data);
	remove(((TreeNode*)(treenode->parent))->children,index);
	return 1;
}
