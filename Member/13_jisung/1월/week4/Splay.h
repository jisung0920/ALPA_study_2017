#include "BST.h"
typedef struct Tree{
  Node* root;
  Node* recentNode;
}Tree;

void InitTree(Tree* tree);
Tree* MakeTree(void);

Node* Zig_L(Node* node);
Node* Zig_R(Node* node);
Node* Zig_Zig_L(Node* node);
Node* Zig_Zig_R(Node* node);
Node* Zig_Zag_RL(Node* node);
Node* Zig_Zag_LR(Node* node);

void ZigZag(Tree* tree,Node* node);

Node* S_SearchNode(Tree* bt,Data data);

Node* SearchTree(Tree* tree,Data data);
void InsertTree(Tree* bt,Node *node);
Data DeleteTree(Tree* bt,Data data);
