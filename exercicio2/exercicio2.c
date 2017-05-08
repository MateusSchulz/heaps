#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#include "P9-heap.h"
const int maxSize = 15;

//	Prototype Definitions 
int  compare    (void* arguPtr, void* heapPtr);
char getAction  (void);
void printHeap (HEAP* heap, int idx, int recuo);

int main (void){
//	Local Definitions 

//	Statements 

}	// main 

/*	================== compare ================= 
	This function compares two integers identified
	by pointers to integers.
	   Pre    arguPtr and listPtr are pointers to DATA
	   Return -1: arg1 value <  arg2 
	          -0: arg1 value == arg2
	          +1: arg1 value >  arg2
*/
int compare (void* arg1, void* arg2)
{
//	Local Declarations 
	int arguOne;
	int arguTwo;
	
//	Statements 
	arguOne = *(int*)arg1;
	arguTwo = *(int*)arg2;

	if (arguOne < arguTwo)
	    return -1;
	else if (arguOne == arguTwo)
	    return  0;
	else
	    return +1;
}	// compare 
void printHeap (HEAP* heap, int idx, int recuo){
	int i;
	for (i=0; i<heap->size; i++){
		printf("%d\n",*(int*)(heap->heapAry[i]));
	}
}