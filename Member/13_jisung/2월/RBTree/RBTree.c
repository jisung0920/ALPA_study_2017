#include "Tree.h"
void InitTree(Tree* tree){
  tree = NULL;
}
void InitNode(Node* node){
  node = NULL;
}
Node* MakeNode(Data data){
  Node* node = malloc(sizeof(Node));
  InitNode(node);
  node->data = data;
  color(node) = red;
  return node;
}
Tree* MakeTree(void){
  Tree* tree = malloc(sizeof(Tree));
  InitTree(tree);
  return tree;
}

void nodeInsert(Tree* tree,Data data){
  Node* curNode=tree->root;
  if(curNode==NULL){
    tree->root = MakeNode(data);
    color(tree->root) = black;
    return ;
  }

  Node* parNode=curNode;
  while(curNode != NULL){
    if(curNode->data > data)
      curNode = curNode->left;
    else
      curNode = curNode->right;
  }
  curNode = MakeNode(data);
}
Data nodeDelete(Tree* tree,Data data);
Data nodeSearch(Tree* tree,Data data);

void printNode(Node* node){
    printf("[%d]",node->data);
}

void PreorederT(Node* node){
  if(node == NULL)
  return ;
  printNode(node);
  PreorederT(node->left);
  PreorederT(node->right);
}
void InorderT(Node* node){
  if(node == NULL)
  return ;
  InorderT(node->left);
  printNode(node);
  InorderT(node->right);
}
void PostorderT(Node* node){
  if(node == NULL)
  return ;
  PostorderT(node->left);
  PostorderT(node->right);
}

void ChangeColor(Node* node){
  if(color(node)==red)
    color(node) = black;
  else
    color(node) = red;
}
void ResturctTree(Node* node);
void ReColoring(Node* node);
