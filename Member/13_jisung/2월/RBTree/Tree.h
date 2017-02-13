#include <stdio.h>
#include <stdlib.h>
#define color(x) (x->color)

typedef int Data;
typedef enum {red, black} Color;

typedef struct Node{
  Data data;
  struct Node* left;
  struct Node* right;
  Color color;
}Node;
typedef struct Tree{
  Node* root;
}Tree;

Node* MakeNode(Data data);
Tree* MakeTree(void);
void InitTree(Tree* tree);
void InitNode(Node* node);

void nodeInsert(Tree* tree,Data data);
Data nodeDelete(Tree* tree,Data data);
Data nodeSearch(Tree* tree,Data data);

void PreorederT(Node* node);
void InorderT(Node* node);
void PostorderT(Node* node);
