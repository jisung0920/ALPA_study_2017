#include "AVL.h"

TreeNode* MakeAVLNode(Data data){
  TreeNode* node = MakeTreeNode();
  InitNode(node);
  SetData(node,data);
  return node;
}


void InitNode(TreeNode *bt){
  bt->par = NULL;
  bt->left = NULL;
  bt->right = NULL;
  bt->hight = 0;
}
int GetHight(TreeNode *bt){
  bt->hight;
}
int CountingHight(TreeNode* bt){
  if(bt==NULL)
    return 0;
  int L=0;
  int R=0;
  L = CountingHight(bt->left);
  R = CountingHight(bt->right);
  return L>R?L+1:R+1;
}

boolean BalancedNode(TreeNode* bt){
  int B =GetHight(bt);
  if(B<2 && B>-2)
    return true;
  else
    return false;
}


void putNode(TreeNode *bt,TreeNode node){
  insertNode(bt,node,-1);
  ResettingHight(bt);
  if(!BalancedNode(bt))
    Restruct(bt);
}

TreeNode* removeNode(TreeNode *bt){
  TreeNode node;
  node = DeleteNode(bt);
  ResettingHight(bt);
  if(!BalancedNode(bt))
    Rebalancing(bt);
  return node;
}

void ResettingHight(TreeNode *bt){
  if(bt==NULL)
    return ;
  bt->hight = CountingHight(bt);
  ResettingHight(bt->left);
  ResettingHight(bt->right);
}

void Reconstruct(TreeNode *bt){
  TreeNode* x,y,z;
  TreeNode* a,b,c;
  z = bt;
  if(GetHight(bt->left)>GetHight(bt->right))
    y = bt->left;
  else
    y = bt->right;
  if(GetHight(y->left)>GetHight(y->right))
    z = y->left;
  else
    z = y->right;

  }
void Rebalancing(TreeNode *bt);
