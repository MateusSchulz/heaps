#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#include "P9-heap.h"
const int maxSize = 15;

//	Prototype Definitions 
int  compare    (void* arguPtr, void* heapPtr);
void printHeap (HEAP* heap, int idx, int recuo);
HEAP* preencherHeap ();
HEAP* concatenaHeap(HEAP* heap1, HEAP* heap2);

int main(void){
//	Local Definitions 
	HEAP *heap1, *heap2, *heap3;
	bool result;
	srand(time(NULL));	

//	Statements
	heap1 = heapCreate (maxSize, compare);
	if (!heap1)
	   printf("Can't create heap in main\n"), exit (100);
	heap2 = heapCreate (maxSize, compare);
	if (!heap2)
	   printf("Can't create heap in main\n"), exit (100);
	heap3 = heapCreate (maxSize, compare);
	if (!heap3)
	   printf("Can't create heap in main\n"), exit (100);

	heap1 = preencherHeap();
	printf("\nPrimeiro HEAP: \n");
	printHeap(heap1, 0, 0);
	heap2 = preencherHeap();
	printf("\nSegundo HEAP: \n");
	printHeap(heap2, 0, 0);
	heap3 = concatenaHeap(heap1, heap2);
	printf("\nTerceiro HEAP: \n");
	printHeap(heap3, 0, 0);

	printf("\n");

}	// main 

HEAP* concatenaHeap(HEAP* heap1, HEAP* heap2){
//	Local Definitions
	int *dataPtr;
	int bldLooper;

//	Statements
	HEAP* heap;
	heap = heapCreate(maxSize*2, compare);
	if(!heap)
	   printf("Can't create heap in main\n"), exit (100);
	
	for(bldLooper = 0; bldLooper <= maxSize / 2 - 1; bldLooper++){
	    
	    heapDelete(heap1, (void*)&dataPtr);
	    heapInsert(heap, dataPtr);
	    
	    heapDelete(heap2, (void*)&dataPtr);
	    heapInsert(heap, dataPtr);

	} // for 

	return heap;
}

HEAP* preencherHeap (int n){
//	Local Definitions
	int  *dataPtr;
	int bldLooper;

//	Statements
	HEAP* heap;
	heap = heapCreate(maxSize, compare);
	if(!heap)
	   printf("Can't create heap in main\n"), exit (100);
	
	for(bldLooper = 0; bldLooper <= maxSize / 2 - 1; bldLooper++){
	    dataPtr = (int*)malloc(sizeof (int));
	    if(!dataPtr)
	        printf("Overflow in main\n"), exit (101);
	    *dataPtr = rand() % 999 + 1;
	    heapInsert (heap, dataPtr);
	} // for 

	return heap;

}

/*	================== compare ================= 
	This function compares two integers identified
	by pointers to integers.
	   Pre    arguPtr and listPtr are pointers to DATA
	   Return -1: arg1 value <  arg2 
	          -0: arg1 value == arg2
	          +1: arg1 value >  arg2
*/
int compare(void* arg1, void* arg2){
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