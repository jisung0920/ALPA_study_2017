#include "Splay.h"

int main(void){
  Tree* tree=MakeTree();
  tree->root = MakeNode(3);

  InsertTree(tree,MakeNode(4));
  PreorderTraverse(tree->root);
  putchar('\n');
  //InsertTree(tree,MakeNode(2));
    //InsertTree(tree,MakeNode(1));
  //tree->root = Zig_R(tree->root);

  InsertTree(tree,MakeNode(5));
    PreorderTraverse(tree->root);
      putchar('\n');
    InsertTree(tree,MakeNode(8));
        PreorderTraverse(tree->root);
          putchar('\n');
          putchar('\n');
  //  InsertTree(tree,MakeNode(2));
        PreorderTraverse(tree->root);
          putchar('\n');
          putchar('\n');
    InsertTree(tree,MakeNode(9));
    PreorderTraverse(tree->root);

          putchar('\n');
          putchar('\n');
    InsertTree(tree,MakeNode(6));
        InsertTree(tree,MakeNode(9));
//    tree->root = Zig_L(tree->root);
/*  InsertTree(tree,MakeNode(1));
  //InsertTree(tree,MakeNode(8));//한방향만 가능
  InsertTree(tree,MakeNode(1));*/
  PreorderTraverse(tree->root);
  putchar('\n');

}
