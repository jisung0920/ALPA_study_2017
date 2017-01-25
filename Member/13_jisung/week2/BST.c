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
void swapNodeData(TreeNode* A, TreeNode* B){
  Data data;
  data = A->data;
  A->data = B->data;
  B->data = data;

}

TreeNode* SearchNode(TreeNode* bt,Data data,Dir *dir){
  Dir tmp;
  if(bt==NULL)
    return NULL;
  if(data < GetData(bt)){
    *dir = Left;

    return SearchNode(GetLeft(bt),data,dir);
  }
  else if(data == GetData(bt))
    return bt;
  else{
    *dir = Right;

    return SearchNode(GetRight(bt),data,dir);
  }
}

void InsertNode(TreeNode* bt,TreeNode* node){//overload
  TreeNode* curNode=bt;
  if(curNode==NULL){
    bt = node;
    return ;
  }
  TreeNode* parNode=curNode;

  Dir dir;
  while(curNode != NULL){
    parNode = curNode;
    if(curNode->data > node->data){
      curNode = GetLeft(curNode);
      dir =Left;
    }
    else{
      curNode = GetRight(curNode);
      dir =Right;
    }
  }
  curNode = node;
  curNode->par = parNode;
  if(dir==Left)
    GetLeft(parNode) = node;
  else
    GetRight(parNode) = node;

}


Data DeleteNode(TreeNode* bt,Data data){

  Dir dir =Left;
  Data delData;
  TreeNode* delNode = SearchNode(bt,data,&dir);

  if(delNode==NULL)
    exit(1);

  delData = delNode->data;
  TreeNode* parNode = delNode->par;
  TreeNode* repNode;

  switch (ChildNodeState(delNode)) {

    case Zero:
      if(dir==Left)
        GetLeft(parNode) = NULL;
      else
        GetRight(parNode) = NULL;
      break;

    case One_Left:
      if(dir==Left)
        GetLeft(parNode) = GetLeft(delNode);
      else
        GetRight(parNode) = GetLeft(delNode);
      break;

    case One_Right:
      if(dir==Left)
        GetLeft(parNode) = GetRight(delNode);
      else
        GetRight(parNode) = GetRight(delNode);
      break;

    case Two:
      printf("case Two\n");
      repNode = GetRight(delNode);
      Dir rep_dir = Right;
      while(GetLeft(repNode)!=NULL){
        repNode = GetLeft(repNode);
        rep_dir =Left;
      }
      if(rep_dir == Right){
        delNode->right = repNode->right;
        if(ChildNodeState(repNode)==One_Right)
          repNode->right->par =delNode;
      }
      else{
        printf("rep R -L node \n");
        if(ChildNodeState(repNode)==One_Right){
          repNode->par->left = repNode->right;
          repNode->right->par = repNode->par;
        }
      }

      swapNodeData(repNode,delNode);
      if(bt==delNode)
        bt = repNode;
      else if(dir==Left)
        GetLeft(delNode->par) = repNode;
      else
        GetRight(delNode->par) = repNode;

      free(repNode);
      return delData;
      break;
  }
/*  if(dir==Left)
    printf("DIR LEFT");
  if(dir==Right)
    printf("DIR RIGHT");*/
  free(delNode);

  return delData;
}

void printNode(TreeNode* node){
  printf("[%d]",node->data);
}

void PreorderTraverse(TreeNode * bt){
  if(bt == NULL)
    return ;
  printNode(bt);
  PreorderTraverse(GetLeft(bt));
  PreorderTraverse(GetRight(bt));
}

void InorderTraverse(TreeNode * bt){
  if(bt == NULL)
    return ;
  InorderTraverse(GetLeft(bt));
  printNode(bt);
  InorderTraverse(GetRight(bt));
}

void PostorderTraverse(TreeNode * bt){
  if(bt == NULL)
    return ;
  PostorderTraverse(GetLeft(bt));
  PostorderTraverse(GetRight(bt));
  printNode(bt);
}
