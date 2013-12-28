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

int insert(Tree tree,void* parent,void* data){
	TreeNode* node = malloc(sizeof(TreeNode));
	if(parent == NULL){
		node->data = data;
		node->children = NULL;
		node->parent = parent;
		tree.root = node;
		return 1;
	}
	return 0;
}