typedef struct{
	void *baseAddress;
	int elementSize;
	int length;
	int top;
}Stack;
typedef char String[256];
Stack* create(int typeSize,int noOfelements);
int push(Stack *stack,void *element);
void* pop(Stack *stack);
void* top(Stack *stack);
int isFull(Stack *stack);
int isEmpty(Stack *stack);