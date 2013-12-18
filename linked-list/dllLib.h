typedef struct{
	void* prvious;
	void* next;
	void* data;
}Node;
typedef struct{
	Node *head;
	Node *tail;
	int length;
}List;
typedef char String[256];
List* create();
Node* createNode(void* previous,void *element,void* next); 
int insertNode(List* list,int index,void* element);
int deleteNode(List* list,int index);
int findIndex(List* list,void* element);