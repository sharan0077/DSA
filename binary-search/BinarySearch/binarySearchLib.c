#include "binarySearchLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* bSearch(void *key,void *base,int length,int elementSize,compareFunc *compare){
	int result,reference = length/2;
	result = compare(base+reference*elementSize,key);
	if(!result)
		return (base+reference*elementSize);
	if(!reference )
		return NULL;
	if(result>0)
		return bSearch(key,base,length-reference,elementSize,compare);
	else
		return bSearch(key,base+(reference*elementSize),reference,elementSize,compare);
}






