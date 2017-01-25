
#include "AVL.h"
int main(void){
  TreeNode* root;
  root = SettingNode(1);
  TreeNode* a[10];
  for(int i=0;i<10;i++){
    a[i]=SettingNode((7*i)%10);
    InsertNode(root,a[i],-1);
  }
  PreorderTraverse(root);
}
