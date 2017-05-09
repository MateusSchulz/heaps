#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#include "P9-heap.h"
const int maxSize = 15;
const int n = 15;

typedef struct{
	int sequencia;
	char nome[64];
	char sobrenome[64];
	double milhas;
	int anos;
	double prioridade;
} PASSAGEIRO;

//	Prototype Definitions 
int  compare    (void* arguPtr, void* heapPtr);
void printHeap (HEAP* heap, int idx, int recuo);
void preencherHeap(HEAP* heap, PASSAGEIRO* vet);

int main(void){
//	Local Definitions 
	HEAP* heap;
	PASSAGEIRO vet[15];
	PASSAGEIRO* dataPtr;
	FILE* file;
	char s, c;
	int i=0, j=0, k, d;
	double a, prioridade;

//	Statements 
	heap = heapCreate (maxSize, compare);
	if (!heap)
	   printf("Can't create heap in main\n"), exit (100);

    file = fopen("data.txt", "r");
    if(file==NULL){
        printf("Problemas para abir o arquivo!");
        exit(0);
    }

	// 32 espaço
	// 10 linha

    printf("\nLENDO OS ARQUIVOS: \n");

    while(fscanf(file, "%d", &	d)==1){

    	//SEQUENCIA
    	vet[i].sequencia = d;
    	printf("\nOrdem de chegada: %d", d);
		
    	//NOME
    	fscanf(file, "%c", &c); //pega espaço
		fscanf(file, "%c", &c); //pega primeira letra
		printf("\nNome: ");
		while(c != 32){
			vet[i].nome[j] = c;
			printf("%c", vet[i].nome[j]);
			fscanf(file, "%c", &c);
			j++;
		}
		vet[i].nome[j] = '\0';
		printf(" ");
		j=0;

		//SOBRENOME		
		fscanf(file, "%c", &c); //pega primeira letra
		while(c != 32){
			vet[i].sobrenome[j] = c;
			printf("%c", vet[i].sobrenome[j]);
			fscanf(file, "%c", &c);
			j++;
		}
		vet[i].sobrenome[j] = '\0';
		j=0;

		//MILHAS
		printf("\nMilhas: ");
		fscanf(file, "%lf", &a);
		vet[i].milhas = a;
		printf("%.2lf\n", vet[i].milhas);

		//ANOS
		printf("Anos: ");
		fscanf(file, "%d", &d);
		vet[i].anos = d;
		printf("%d\n", vet[i].anos);

		//PRIORIDADE
		vet[i].prioridade = (vet[i].milhas/1000)+vet[i].anos-vet[i].sequencia;
		printf("Prioridade: %.2lf\n", vet[i].prioridade);
		i++;

    }

    printf("\n\n");
    fclose(file);

	//PASSAR O VETOR COM AS PRIORIDADES PARA UM HEAP    
    for(i=0;i<12;i++){
    	PASSAGEIRO* data;
    	data = (PASSAGEIRO*)malloc(sizeof(PASSAGEIRO));
    	*data = vet[i];
    	heapInsert(heap, data);
    }

    printf("OS ARQUIVOS NO HEAP: \n\n");

    printHeap(heap, 0, 0);

    printf("\n\nOS ARQUIVOS NO NOVO VETOR: \n\n");

    i=0;
    while(!heapEmpty(heap)){

    	heapDelete(heap, (void*)&dataPtr);
    	vet[i] = *dataPtr;
    	printf("Nome: %s %s\nPrioridade: %lf\n\n", vet[i].nome, vet[i].sobrenome, vet[i].prioridade);
    	i++;

    }

    printf("\n\n");

    //novoVetor(heap, vet);

/*
	x- criar struct
	x- criar vetor de ponteiros
	x- ler do arquivo inserindo 
	x- inserir no heap
	- criar novo vetor deletando do heap
*/

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
	arguOne = ((PASSAGEIRO*)arg1)->prioridade;
	arguTwo = ((PASSAGEIRO*)arg2)->prioridade;

	if (arguOne < arguTwo)
	    return -1;
	else if (arguOne == arguTwo)
	    return  0;
	else
	    return +1;
}	// compare

void printHeap (HEAP* heap, int idx, int recuo){
	int i, j=0;
	for (i=0; i<heap->size; i++){
		printf("%s", ((PASSAGEIRO*)heap->heapAry[i])->nome);
		printf(" ");
		printf("%s", ((PASSAGEIRO*)heap->heapAry[i])->sobrenome);
		printf("\n%lf\n\n", ((PASSAGEIRO*)heap->heapAry[i])->prioridade);
	}
}