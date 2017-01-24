
#include "BST.h"
int main(void){
  TreeNode* root;
  InitNode(root);
  root = NULL;
  InsertNode(root,MakeTreeNode(3));
  /*for(int i=0;i<10;i++){
    InsertNode(root,MakeTreeNode(i*7%10+1));
  }*/
 printNode(root);
 free(root);
}
