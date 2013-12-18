typedef char String[256];
typedef int compareFunc(void* a,void* b);
void* bSearch(void *key,void *base,int length,int elementSize,compareFunc *compare);
