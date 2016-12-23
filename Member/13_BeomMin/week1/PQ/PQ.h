#include <stdio.h>
#include <stdlib.h>

#define KEY int
#define DATA char
#define FRONT P->front
#define SIZE P->size
#define BACK P->back

typedef enum boolean {false, true} boolean;

typedef struct entry{
	KEY key;
	DATA data;
	struct entry* next;
}entry;

typedef struct PQ{
	entry* front;
	entry* back;
	int size;
}PQ;
	
PQ* P;

void init_PQ();
void insert(KEY, DATA);	
entry* min();
entry* removeMin();
int size();
boolean isEmpty();
void print_PQ();
