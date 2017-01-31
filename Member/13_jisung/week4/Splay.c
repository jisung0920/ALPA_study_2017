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
  printf("Rotate Left %d\n",bt->right->data);
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
    printf("Rotate Right %d\n",bt->left->data);
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

Node* Zig_Zig_L( Node* node){
  printf("LL\n");
  node->right = Zig_L(node->right);
  node = Zig_L(node);
  return node;
}
Node* Zig_Zig_R( Node* node){
  printf("RR\n");
  node->left = Zig_R(node->left);
  node = Zig_R(node);
  return node;
}

Node* Zig_Zag_RL(Node* node){
  printf("RL\n");
  node->right->left = Zig_R(node->right->left);
  node = Zig_L(node);
  return node;
}

Node* Zig_Zag_LR(Node* node){
  printf("LR\n");
  node->left = Zig_L(node->left);
  printf("LR - 2nd\n");
  node = Zig_R(node);
  return node;
}

void ZigZag(Tree* tree,Node* node){
  printf("Zig Zag Function :%d\n",node->data);
  Node* Root = tree->root;
  while(1){
    if(tree->root == node)
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
      printf("else Case\n");
      Node* Gnode = node->par->par;

      printf("Gnode data : %d\n",Gnode->data);
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
      else{
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

      }

    }
  }
}

Node* S_SearchNode(Tree* tree,Data data){
  Node* comNode = tree->root;
  Node* nearNode = comNode;
  while(comNode->data != data || comNode != NULL){
    nearNode = comNode;
    if(comNode->data>data)
      comNode = GetLeft(comNode);
    else
      comNode = GetRight(comNode);
  }
  if(comNode->data == data)
    return comNode;
  else
    return nearNode;
}

Node* SearchTree(Tree* tree,Data data){
  Node* target = S_SearchNode(tree, data);
  ZigZag(tree,target);
  return target;
}

void InsertTree(Tree* tree,Node *node){
  InsertNode(tree->root,node);
  ZigZag(tree,node);
}
Data DeleteTree(Tree* tree,Data data){
  Data delData = DeleteNode(tree->root,data);
  SearchTree(tree,data);
  return delData;
}
