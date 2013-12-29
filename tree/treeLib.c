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
	node->children = NULL;
	node->parent = NULL;
	tree->root = create();
	insert((List*)tree->root, 0,node);	
	return 1;
}
TreeNode* traverse(Tree* tree,void* data){
	void* temp = ((TreeNode*)(((List*)tree->root)->head->data))->data;
	if(tree->compareFunc(temp, data))
		return ((List*)(tree->root))->head->data;
	return NULL;
}
int insertChild(TreeNode* node,TreeNode* treenode,void* data){
	node->data = data;
	node->children = NULL;
	node->parent = treenode;
	treenode->children = create();
	insert(treenode->children, 0, node);
	return 1;
}
int insertNode(Tree* tree,void* parent,void* data){
	TreeNode* treenode;
	TreeNode* node = malloc(sizeof(TreeNode));
	if(parent == NULL)
		return insertAsRoot(tree,node,data);
	treenode = traverse(tree, data);
	return insertChild(node,treenode,data);
	return 0;
}
