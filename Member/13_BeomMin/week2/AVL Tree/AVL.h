#include <stdio.h>
#include <stdlib.h>

#define KEY int
#define DATA char

#define K(x) x->key
#define D(x) x->data
#define H(x) x->height
#define L(x) x->left
#define R(x) x->right
#define P(x) x->parent

#define MakeEntry(x, y, z) \
	entry* x = malloc(sizeof(entry)); \
	K(x) = y; \
	D(x) = z; \
	H(x) = 1; \
	L(x) = NULL; \
	R(x) = NULL; \
	P(x) = NULL; \

#define SetHeight \
	MakeEntry(SetEntry, 0, 0); \
	SetEntry = P(e); \
	while(P(SetEntry) != NULL) { \
		H(SetEntry)++; \
		SetEntry = P(SetEntry); \
	} \


typedef enum boolean {false, true} boolean;

typedef struct entry {
	int height;
	KEY key;
	DATA data;
	struct entry* left;
	struct entry* right;
	struct entry* parent;
}entry;

entry* root;

void init_AVL();
boolean isEmpty();
void insert(KEY, DATA);
void rebalance();
