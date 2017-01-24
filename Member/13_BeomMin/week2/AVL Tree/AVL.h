#include <stdio.h>
#include <stdlib.h>

#define KEY int
#define DATA char

#define K(x) x->key
#define D(x) x->data
#define L(x) x->left
#define R(x) x->right
#define P(x) x->parent

#define MakeEntry(x, y, z) \
	entry* x = malloc(sizeof(entry)); \
	K(x) = y; \
	D(x) = z; \
	L(x) = NULL; \
	R(x) = NULL; \
	P(x) = NULL; \

typedef enum boolean {false, true} boolean;

typedef struct entry {
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
int get_height(entry*);
int get_balanced_num(entry*);
