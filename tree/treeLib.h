#include "dll.h"
typedef int(*compare)(void* dataToBeCompared, void* parentData);
typedef struct{
	void* root;
	compare compareFunc; 
}Tree;
Tree createTree(compare cmp);
int insertNode(Tree* tree,void* parent,void* data);
Iterator getChildren(Tree* tree, void* data);
int search(Tree* tree,void* data);
int deleteNode(Tree* tree,void* data);