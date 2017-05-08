#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#include "P9-heap.h"
const int maxSize = 15;

//	Prototype Definitions 
int  compare    (void* arguPtr, void* heapPtr);
char getAction  ();
void printHeap (HEAP* heap, int idx, int recuo);

void main(int argc, char const *argv[]){

//	Local Definitions 
	

	
//	Statements 


}

char getAction(){ 
	char action;
	int  OK = 0;
//	Statements 
	do{
		printf("\nPlease enter action <P, I, D, U, Q>: ");
		scanf (" %c", &action);
		action = toupper(action);
		switch (action){
		    case 'P':
		    case 'I':
		    case 'D':
		   	case 'U':
		    case 'Q': OK = 1;
		    break;
		    default:  
			    printf("< %c> action invalid: ", action);
			    printf("Please re-enter\a\a\n"); 
			break;
		} // switch 
	} while (!OK);
	return action;
}	// getAction 

void printHeap (HEAP* heap, int idx, int recuo){
	int i;
	for (i=0; i<heap->size; i++){
		printf("%d\n",*(int*)(heap->heapAry[i]));
	}
}