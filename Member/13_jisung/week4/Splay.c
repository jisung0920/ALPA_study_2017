#include "Splay.h"
void InitTree(Tree *tree){
  tree = NULL;
}
Tree* MakeTree(void){
  Tree* tree = malloc(sizeof(Tree));
  InitTree(tree);
  return tree;
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
  if(node == root)
    ;
  else if(node == root->left)
    Zig_R(node);
  else if(node == root->right)
    Zig_L(node);
  else{
    while(node != root){
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
  tree->root = node;
  node->par = NULL;
}

Node* S_SearchNode(Tree* tree,Data data){
  Node* comNode = tree->root;
  Node* nearNode = comNode;
  while(comNode->data != data || comNode != NULL){
    nearNode = comNode;
    if(comNode->data>data)
      comNode = GetLeft(comNode);
    else
      comNode = GetRight(comNode);
  }
  if(comNode->data == data)
    return comNode;
  else
    return nearNode;
}

Node* SearchTree(Tree* tree,Data data){
  Node* target = S_SearchNode(tree, data);
  ZigZag(tree,target);
  return target;
}

void InsertTree(Tree* tree,Node *node){
  InsertNode(tree->root,node);
  ZigZag(tree,node);
}
Data DeleteTree(Tree* tree,Data data){
  Data delData = DeleteNode(tree->root,data);
  SearchTree(tree,data);
  return delData;
}
