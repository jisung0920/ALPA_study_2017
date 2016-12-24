#include <stdio.h>
#include <stdlib.h>

#define KEY int
#define DATA char

#define ROOT H->root
#define SIZE H->sizei
#define LEFT(x) x->left
#define RIGHT(x) x->right
#define PARENT(x) x->parent

#define MakeEntry(x,y,z)\
	entry* x = malloc(sizeof(entry));\
	x->key = y;\
	x->data = z;\
	LEFT(x) = NULL;\
	RIGHT(x) = NULL;\
	PARENT(x) = NULL;\
	
typedef enum boolean {false, true} boolean;

typedef struct entry{
	KEY key;
	DATA data;
	struct entry* left;
	struct entry* right;
	struct entry* parent;
}entry;

typedef struct heap{
	entry* root;
	int size;
}Heap;

Heap* H;

void init_heap();
void insert(KEY, DATA);
entry* min();
entry* removeMin();
