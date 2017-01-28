#include "BST.h"
typedef struct Tree{
  Node* root;
  Node* recentNode;
}Tree;

void InitTree(Tree* tree);
void MakeTree(Tree* tree);

void Zig_L(Node* node);
void Zig_R(Node* node);
void Zig_Zig_L(Node* node);
void Zig_Zig_R(Node* node);
void Zig_Zag_RL(Node* node);
void Zig_Zag_LR(Node* node);

Node* S_SearchNode(Tree* bt,Data data,Dir *dir);
void InsertTree(Tree* bt,Node *node);
Data DeleteTree(Tree* bt,Data data);
