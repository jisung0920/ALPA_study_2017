#include <stdio.h>
#include <stdlib.h>

#define KEY int
#define DATA char
#define FRONT P->front
#define SIZE P->size
#define BACK P->back
#define MakeEntry(x) \
	entry* x = malloc(sizeof(entry));\
	x->key = k;\
	x->data = d;\
	x->next = NULL;\

#define MIN(x) \
	entry* x = malloc(sizeof(entry));\
	KEY k;\
	DATA d;\
	\
	if (isEmpty()) {\
		puts("empty");\
		exit(1);\
	}\
	x = FRONT;\
	k = x->key;\
	d = x->data;\


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
