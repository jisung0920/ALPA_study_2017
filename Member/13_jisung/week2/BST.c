#include "BST.h"

void InitNode(TreeNode *bt){
  bt->par = NULL;
  bt->left = NULL;
  bt->right = NULL;
  bt->height = 0;
}

TreeNode * MakeTreeNode(Data data){
  TreeNode* node = malloc(sizeof(TreeNode));
  InitNode(node);
  node->data = data;
  return node;
}
Data GetData(TreeNode * bt){
  return bt->data;
}
void SetData(TreeNode * bt, Data data){
  bt->data = data;
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
  Dir tmp;
  if(bt==NULL)
    return NULL;
  if(data < GetData(bt)){
    tmp = Left;
    dir = &tmp;
    return SearchNode(GetLeft(bt),data,dir);
  }
  else if(data == GetData(bt))
    return bt;
  else{
    tmp = Right;
    dir = &tmp;
    return SearchNode(GetRight(bt),data,dir);
  }
}

void InsertNode(TreeNode* bt,TreeNode* node){//overload
  TreeNode* tmpNode;
  if(bt==NULL){
    bt = node;
    return ;
  }
  /*
  tmpNode = bt;
  TreeNode* parNode;
  Dir dir;
  while(tmpNode != NULL){
    parNode = tmpNode;
    while(tmpNode->data>node->data){
      tmpNode= GetLeft(tmpNode);
      dir =Left;
    }
    while(tmpNode->data<node->data){
      tmpNode = GetRight(tmpNode);
      dir = Right;
    }
  }
  tmpNode = node;
  tmpNode->par = parNode;
  if(dir==Left)
    GetLeft(parNode) = tmpNode;
  else
    GetRight(parNode) = tmpNode;
    */
}


Data DeleteNode(TreeNode* bt,Data data){

  return data;
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
