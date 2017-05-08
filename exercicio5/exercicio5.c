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
void ordenaHeapDown (HEAP* heap);

int main(void){
//	Local Definitions 
	HEAP* heap;
	bool result;
	srand(time(NULL));
	int i, *vet[i], *dataPtr;

//	Statements 
	heap = heapCreate (maxSize, compare);
	if (!heap)
	   printf("Can't create heap in main\n"), exit (100);

	for(i = 0; i<15; i++){
		vet[i]  = (int*)malloc(sizeof (int));
		*vet[i] = rand() % 999 + 1;
		heapInsert(heap, vet[i]);
	}

	printf("\nHEAP não ordenado:\n");
	printHeap(heap, 0, 0);

	ordenaHeapDown(heap);

}	// main 

void ordenaHeapDown(HEAP* heap){

	int meio = (maxSize/2-1), root, i;

	for(i=meio; i>=0; i--){
		_reheapDown (heap, 0);
	}

	printf("\n\nHEAP Ordenado:\n");
	printHeap(heap, 0, 0);

}

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
