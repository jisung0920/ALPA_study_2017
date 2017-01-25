
#include "BST.h"
int main(void){
  TreeNode* root = MakeTreeNode(10);
//  InitNode(root);

  InsertNode(root,MakeTreeNode(5));
  InsertNode(root,MakeTreeNode(16));
  InsertNode(root,MakeTreeNode(2));
  InsertNode(root,MakeTreeNode(6));
  InsertNode(root,MakeTreeNode(1));
  InsertNode(root,MakeTreeNode(8));
  InsertNode(root,MakeTreeNode(14));
  InsertNode(root,MakeTreeNode(11));
  InsertNode(root,MakeTreeNode(19));
  InsertNode(root,MakeTreeNode(12));


 InorderTraverse(root);
 printf("\n" );
 //printNode(SearchNode(root,3,Left));
 printf("delete : %d\n",DeleteNode(root,10));
 InorderTraverse(root);
 printf("delete : %d\n",DeleteNode(root,1));
 InorderTraverse(root);
 printf("delete : %d\n",DeleteNode(root,5));
 InorderTraverse(root);
 //free(root);
}
