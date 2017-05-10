#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

int contador = 0;
#include "P9-heap.h"
const int maxSize = 100000000;

//	Prototype Definitions 
int  compare    (void* arguPtr, void* heapPtr);
void printHeap (HEAP* heap, int idx, int recuo);
HEAP* preencherHeap ();

int main(void){
//	Local Definitions 
	HEAP *heap;
	srand(time(NULL));

//	Statements
	heap = heapCreate (maxSize, compare);
	if (!heap)
	   printf("Can't create heap in main\n"), exit (100);

	heap = preencherHeap();
	printf("\nHEAP:\n");
	//printHeap(heap, 0, 0);

	printf("\n\nContador: %d, para n=%d\n", contador, heap->size);


}	// main 

HEAP* preencherHeap (){
//	Local Definitions
	int *dataPtr;
	int bldLooper;

//	Statements
	HEAP* heap;
	heap = heapCreate(maxSize, compare);
	if(!heap)
	   printf("Can't create heap in main\n"), exit (100);
	printf("\nVETOR:\n");

	for(bldLooper = 0; bldLooper < maxSize; bldLooper++){
	    dataPtr = (int*)malloc(sizeof (int));
	    if(!dataPtr)
	        printf("Overflow in main\n"), exit (101);
	    *dataPtr = rand() % 999 + 1;
	    //printf("%d ", *dataPtr);
	    heapInsert (heap, dataPtr);
	    //printf("\n");
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