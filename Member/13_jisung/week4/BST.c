#include "BST.h"

void InitNode(Node *bt){
  bt->par = NULL;
  bt->left = NULL;
  bt->right = NULL;
}

Node * MakeNode(Data data){
  Node* node = malloc(sizeof(Node));
  InitNode(node);
  node->data = data;
  return node;
}


Data GetData(Node * bt){
  return bt->data;
}
void SetData(Node * bt, Data data){
  bt->data = data;
}

ChildState ChildNodeState(Node* bt){
  if(GetLeft(bt)==NULL && GetRight(bt)==NULL)
    return Zero;
  else if(GetLeft(bt)!=NULL && GetRight(bt)!=NULL)
    return Two;
  else if(GetLeft(bt)!=NULL)
    return One_Left;
  else
    return One_Right;
}


void MakeLeftSubTree(Node * main, Node * sub){
  main->left = sub;
}
void MakeRightSubTree(Node * main, Node * sub){
  main->right = sub;
}
void swapNodeData(Node* A, Node* B){
  Data data;
  data = A->data;
  A->data = B->data;
  B->data = data;

}

Node* SearchNode(Node* bt,Data data,Dir *dir){
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

void InsertNode(Node* bt,Node* node){//overload
  Node* curNode=bt;
  if(curNode==NULL){
    bt = node;
    return ;
  }
  Node* parNode=curNode;

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


Data DeleteNode(Node* bt,Data data){

  Dir dir =Left;
  Data delData;
  Node* delNode = SearchNode(bt,data,&dir);

  if(delNode==NULL)
    return NOTRETURN;

  delData = delNode->data;
  Node* parNode = delNode->par;
  Node* repNode;

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
        if(ChildNodeState(repNode)==One_Right){
          repNode->par->left = repNode->right;
          repNode->right->par = repNode->par;
        }
        repNode->par->left = NULL;
      }
      swapNodeData(repNode,delNode);
      free(repNode);
      return delData;
      break;
  }
  free(delNode);
  return delData;
}

void printNode(Node* node){
  printf("[%d]",node->data);
}

void PreorderTraverse(Node * bt){
  if(bt == NULL)
    return ;
  printNode(bt);
  PreorderTraverse(GetLeft(bt));
  PreorderTraverse(GetRight(bt));
}

void InorderTraverse(Node * bt){
  if(bt == NULL)
    return ;
  InorderTraverse(GetLeft(bt));
  printNode(bt);
  InorderTraverse(GetRight(bt));
}

void PostorderTraverse(Node * bt){
  if(bt == NULL)
    return ;
  PostorderTraverse(GetLeft(bt));
  PostorderTraverse(GetRight(bt));
  printNode(bt);
}
