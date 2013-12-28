#include "../linked-list/dllLib.h"
typedef int(*compare)(void* dataToBeCompared, void* parentData);
typedef struct{
	void* root;
	compare compareFunc; 
}Tree;
Tree createTree(compare cmp);
int insert(Tree tree,void* parent,void* data);