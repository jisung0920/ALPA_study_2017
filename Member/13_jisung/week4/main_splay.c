#include "Splay.h"

int main(void){
  Tree* tree;
  MakeTree(tree);
  InsertTree(tree,MakeNode(3));
  InsertTree(tree,MakeNode(1));
  InsertTree(tree,MakeNode(5));
  InsertTree(tree,MakeNode(8));
  PostorderTraverse(tree->root);
}
