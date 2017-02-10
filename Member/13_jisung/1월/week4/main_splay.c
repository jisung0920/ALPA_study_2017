#include "Splay.h"

int main(void){
  Tree* tree=MakeTree();
  tree->root = MakeNode(6);
  int n;

  InsertTree(tree,MakeNode(4));
  PreorderTraverse(tree->root);
  putchar('\n');

  InsertTree(tree,MakeNode(2));
  PreorderTraverse(tree->root);
  putchar('\n');

  InsertTree(tree,MakeNode(9));
  PreorderTraverse(tree->root);
  putchar('\n');

  InsertTree(tree,MakeNode(3));
  PreorderTraverse(tree->root);
  putchar('\n');

  SearchTree(tree,0);
  PreorderTraverse(tree->root);
  putchar('\n');

  SearchTree(tree,9);
  PreorderTraverse(tree->root);
  putchar('\n');

  InsertTree(tree,MakeNode(10));
  PreorderTraverse(tree->root);
  putchar('\n');


  DeleteTree(tree,0);
  PreorderTraverse(tree->root);
  putchar('\n');




  putchar('\n');
  PreorderTraverse(tree->root);
  putchar('\n');

}
