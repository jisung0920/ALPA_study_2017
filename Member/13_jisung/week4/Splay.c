#include "Splay.h"
void InitTree(Tree *tree){
  tree = NULL;
}
void MakeTree(Tree* tree){
  tree = malloc(sizeof(Tree));
  InitTree(tree);
}

void Zig_L(Node* x){
  Node* y = x->par;
  if(y->par != NULL){
    Node* z = y->par;
    x->par = z;
    if(GetLeft(z) == y)
      z->left = x;
    else
      z->right = x;
  }
  y->right = x->left;
  x->left = y;
  y->par = x;
}
void Zig_R(Node* x){
  Node* y = x->par;
  if(y->par != NULL){
    Node* z = y->par;
    x->par = z;
    if(GetLeft(z) == y)
      z->left = x;
    else
      z->right = x;
  }
  y->left = x->right;
  x->right = y;
  y->par = x;
}

void Zig_Zig_L(Node* node){
  Zig_L(node);
  Zig_L(node);
}

void Zig_Zig_R(Node* node){
  Zig_R(node);
  Zig_R(node);
}

void Zig_Zag_RL(Node* node){
  Zig_R(node);
  Zig_L(node);
}

void Zig_Zag_LR(Node* node){
  Zig_L(node);
  Zig_R(node);
}

void ZigZag(Tree* tree,Node* node){
  Node* root = tree->root;
  while(node != root){
    if(node == root)
      return ;
    else if(node == root->left)
      Zig_R(node);
    else if(node == root->right)
      Zig_L(node);
    else{
      Node* target = node->par->par;
      if(node == target->left->left)
        Zig_Zig_R(node);
      else if(node == target->right->right)
        Zig_Zig_L(node);
      else if(node == target->right->left)
        Zig_Zag_LR(node);
      else
        Zig_Zag_RL(node);
    }
  }
}

Node* S_SearchNode(Tree* tree,Data data,Dir *dir){
  Node* node = SearchNode(tree->root,data,dir);
  ZigZag(tree,node);
  return node;
}
void InsertTree(Tree* tree,Node *node){
  InsertNode(tree->root,node);
  //ZigZag(tree,node);
}
Data DeleteTree(Tree* bt,Data data){
  return data;
}
