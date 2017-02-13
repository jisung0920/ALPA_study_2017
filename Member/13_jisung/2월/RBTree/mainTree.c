#include "Tree.h"

int main(void){
  Tree* tree = MakeTree();
  nodeInsert(tree,5);
  nodeInsert(tree,1);
  nodeInsert(tree,2);
  nodeInsert(tree,6);
  nodeInsert(tree,8);
  InorderT(tree->root);
  return 0;
}
