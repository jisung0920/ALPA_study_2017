#include "Splay.h"

void InitTree(Tree *tree){
  tree = NULL;
}

Tree* MakeTree(void){
  Tree* tree = malloc(sizeof(Tree));
  InitTree(tree);
  return tree;
}

Node* Zig_L(Node* bt){
  printf("Rotate L\n");
  Node* pnode = bt;
  Node* cnode = pnode->right;
  if(ChildNodeState(cnode) == Zero ||ChildNodeState(cnode) ==One_Right)
    pnode->right =NULL;
  else
    pnode->right = cnode->left;
  cnode->left = pnode;
  pnode->par = cnode;
  return cnode;
}

Node* Zig_R(Node* bt){
  printf("Rotate R\n");
  Node* pnode = bt;
  Node* cnode = pnode->left;
  if(ChildNodeState(cnode) == Zero ||ChildNodeState(cnode) ==One_Left)
    pnode->left =NULL;
  else
    pnode->left = cnode->right;
  cnode->right = pnode;
  pnode->par = cnode;
  return cnode;
}

Node* Zig_Zig_L(Node* z){
  printf("Rotate LL\n");
  Node* y = z->right;
  Node* x = y->right;
  z->right = y->left;
  y->left = z;
  y->right = x->left;
  x->left = y;
  z->par = y;
  y->par = x;

  return x;
}
Node* Zig_Zig_R( Node* z){
  printf("Rotate RR\n");
  Node* y = z->left;
  Node* x = y->left;
  z->left = y->right;
  y->right = z;
  y->left = x->right;
  x->right = y;
  z->par = y;
  y->par = x;
  return x;
}

Node* Zig_Zag_RL(Node* z){
  printf("Rotate RL\n");
  Node* y = z->right;
  Node* x = y->left;
  z->right = x->left;
  y->left = x->right;
  x->left = z;
  x->right = y;
  z->par = x;
  y->par = x;
  return x;
}

Node* Zig_Zag_LR(Node* z){
  printf("Rotate LR\n");
  Node* y = z->left;
  Node* x = y->right;
  z->left = x->right;
  y->right = x->left;
  x->right = z;
  x->left = y;
  z->par = x;
  y->par = x;
  return x;
}

void ZigZag(Tree* tree,Node* node){

  Node* Root = tree->root;
  while(1){
    if(Root == node)
      break;
    else if(Root->left == node){
      tree->root = Zig_R(node->par);
      break;
    }
    else if(Root->right == node){
      tree->root= Zig_L(node->par);
      break;
    }



    else{
      Node* Gnode = node->par->par;
      if(Gnode == tree->root){
        if(Gnode->left == node->par){
          if(node->par->left == node)
            Gnode = Zig_Zig_R(Gnode);
          else
            Gnode = Zig_Zag_LR(Gnode);
        }
        else{
          if(node->par->left == node)
            Gnode = Zig_Zag_RL(Gnode);
          else
            Gnode = Zig_Zig_L(Gnode);
        }
        tree->root = Gnode;
        break;
      }

      else{// 문제가 있다
        int i=0;
        Node* connect = Gnode->par;
        if(connect->left == Gnode)
          i=1;
        if(Gnode->left == node->par){
          if(node->par->left == node)
            Gnode = Zig_Zig_R(Gnode);
          else
            Gnode = Zig_Zag_LR(Gnode);
        }
        else{
          if(node->par->left == node)
            Gnode = Zig_Zag_RL(Gnode);
          else
            Gnode = Zig_Zig_L(Gnode);
        }

        if(i)
          connect->left = Gnode;
        else
          connect->right = Gnode;
        Gnode->par =connect;

        node =Gnode;
      }

    }
  }
}

Node* S_SearchNode(Tree* tree,Data data){
  Node* comNode = tree->root;
  Node* nearNode = comNode;
  while(comNode != NULL){
    nearNode = comNode;
    if(comNode->data == data)
      return comNode;
    else if(comNode->data>data)
      comNode = GetLeft(comNode);
    else
      comNode = GetRight(comNode);
  }
  return nearNode;

}

Node* SearchTree(Tree* tree,Data data){
  printf("Search : %d\n",data);
  Node* target = S_SearchNode(tree, data);
  if(target->data != data)
    printf("near Node :%d\n",target->data);
  ZigZag(tree,target);
  return target;
}

void InsertTree(Tree* tree,Node *node){
  printf("Insert : %d\n",node->data);
  InsertNode(tree->root,node);
  ZigZag(tree,node);
}
Data DeleteTree(Tree* tree,Data data){//error
  printf("Delete : %d\n",data);
  Data delData = DeleteNode(tree->root,data);
  SearchTree(tree,data);
  if(delData == NOTRETURN){
    printf("no data\n");
    return NOTRETURN;
  }
  return delData;
}
