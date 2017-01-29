#include "Splay.h"

int main(void){
  Tree* tree=MakeTree();
  tree->root = MakeNode(4);

  InsertTree(tree,MakeNode(5));
  InsertTree(tree,MakeNode(6));
  InsertTree(tree,MakeNode(7));
  InsertTree(tree,MakeNode(8));//한방향만 가능
    //InsertTree(tree,MakeNode(1));
  PreorderTraverse(tree->root);
  putchar('\n');

}
