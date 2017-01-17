#include "BST.h"

TreeNode * MakeTreeNode(void){
  TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
  return node;
}
Data GetData(TreeNode * bt){
  return bt->data;
}
void SetData(TreeNode * bt, Data data);{
  bt->data = data;
}


TreeNode * GetLeft(TreeNode * bt){
  return bt->left;
}
TreeNode * GetRight(TreeNode * bt){
  return bt->right;
}


ChildState ChildNodeState(TreeNode* bt){
  if(GetLeft(bt)==NULL && GetRight(bt)==NULL)
    return Zero;
  else if(GetLeft(bt)!=NULL && GetRight(bt)!=NULL)
    return Two;
  else if(GetLeft(bt)!=NULL)
    return One_Left;
  else
    return One_Right;

}
void MakeLeftSubTree(TreeNode * main, TreeNode * sub){
  main->left = sub;
}
void MakeRightSubTree(TreeNode * main, TreeNode * sub){
  main->right = sub;
}


TreeNode* SearchNode(TreeNode* bt,Data data,Dir *dir){
  if(bt=NULL)
    return NULL;
  if(data < GetData(bt)){
    dir = &Left;
    SearchNode(GetLeft(bt),data,dir);
  }
  else if(data == GetData(bt))
    return bt;
  else{
    dir = &Right;
    SearchNode(GetRight(bt,data,dir));
  }
}

void InsertNode(TreeNode* bt,TreeNode* node,Dir dir){
  if(bt==NULL){
    bt = node;
    if(dir==-1)
      return ;//root node
    if(dir==Left)//set left
      GetLeft(bt->par)=node;
    else//set right
      GetRight(bt->par)=node;
  }//setting node

  if(GetData(bt)>GetData(node))
    InsertNode(GetLeft(bt),node,Left);
  else
    InsertNode(GetRight(bt),node,Right);
}


Data DeleteNode(TreeNode* bt,Data data){

  Dir* dir;
  Data res;
  TreeNode* node = SearchNode(bt,data,dir);
  res = GetData(node);
  if(node ==NULL)
    return NULL;
  if(node == bt)
    return GetData(bt);

  ChlidState n = ChildNodeState(bt);

  if(n == Zero){
    if(!(*dir))//par - left
      bt->par->left=NULL;
    else
      bt->par->right=NULL;
  }
  else if(n == One_Left){
    if(!(*dir))//par - left
      GetLeft(bt->par)=GetLeft(bt);
    else
      GetRight(bt->par)=GetLeft(bt);
  }
  else if(n == One_Right){
    if(!(*dir))//par - left
      GetLeft(bt->par)=GetRight(bt);
    else
      GetRight(bt->par)=GetRight(bt);
  }
  else{
    TreeNode* cur = GetRight(bt);
    int count=0;
    while(cur!=NULL){
      cur = GetLeft(cur);
      count=1;
    }
    if(count){

    }
    else{//cur == bt->right
      ////////////////////////////////
    }
  }
  free(bt);
  return res;
}

void printNode(TreeNode* node){
  printf("[%d]",node->data);
}

void PreorderTraverse(TreeNode * bt){
  printNode(bt);
  PreorderTraverse(GetLeft(bt));
  PreorderTraverse(GetRight(bt));
}
void InorderTraverse(TreeNode * bt){
  InorderTraverse(GetLeft(bt));
  printNode(bt);
  InorderTraverse(GetRight(bt));
}
void PostorderTraverse(TreeNode * bt){
  PostorderTraverse(GetLeft(bt));
  PostorderTraverse(GetRight(bt));
  printNode(bt);
}
