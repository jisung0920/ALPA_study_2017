#include <stdio.h>
#include <stdlib.h>

#define MakeNode(x, y) \
	node* y = malloc(sizeof(node)); \
	y->key = x; \
	y->parent = NULL; \
	y->left = NULL; \
	y->right = NULL; \

#define sprint \
	printf("%d",root->key); \
	 print_splay(root); \
	puts(""); \



typedef enum boolean {false, true} boolean;

typedef struct node {
	int key;
	struct node *parent;
	struct node *left;
	struct node *right;
}node;

node* root;

void init_splay();
void search(int);
void insert(int);
int delete(int);
boolean isEmpty();
void print_splay();

void splay(node*);
void zig_R(node*);
void zig_L(node*);
void zigzig_RR(node*);
void zigzig_LL(node*);
void zigzag_RL(node*);
void zigzag_LR(node*);
