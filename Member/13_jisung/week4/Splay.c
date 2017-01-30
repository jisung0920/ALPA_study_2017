#include "Splay.h"

void InitTree(Tree *tree){
  tree = NULL;
}

Tree* MakeTree(void){
  Tree* tree = malloc(sizeof(Tree));
  InitTree(tree);
  return tree;
}

void Zig_Par_Setting(Node* x,Node* y){
  Node* z = y->par;
  if(z->left==y)
    z->left = x;
  else
    z->right = y;
}

Node* Zig_L(Node* y){
  Node* x = y->right;
  if(y->par != NULL)
    Zig_Par_Setting(x,y);
  y->right = x->left;
  x->left = y;
  y->par = x;
  return x;
}

Node* Zig_R(Node* y){
  Node* x = y->left;
  if(y->par != NULL)
    Zig_Par_Setting(x,y);
  y->left = x->right;
  x->right = y;
  y->par = x;
  return x;
}

Node* Zig_Zig_L( Node* node){
  node = Zig_L(node);
  node = Zig_L(node);
  return node;
}
Node* Zig_Zig_R( Node* node){
  node = Zig_R(node);
  node = Zig_R(node);
  return node;
}

Node* Zig_Zag_RL(Node* node){
  node = Zig_R(node);
  node = Zig_L(node);
  return node;
}

Node* Zig_Zag_LR(Node* node){
  node = Zig_L(node);
  node = Zig_R(node);
  return node;
}

void ZigZag(Tree* tree,Node* node){
  Node* Root = tree->root;
  Node* Pnode = node->par;
  while(1){
      if(Root == node)
        break;
      else if(Root->left == node)
        Pnode = Zig_R(Pnode);
      else if(Root->right == node)
        Pnode = Zig_L(Pnode->par);
      else{
        /*Node* Gnode = node->par;
        if(Gnode->left == node)
          Zig_R(node->par);
        else if(Gnode->right == node)
          Zig_L(node->par);}*/
        //Node* Gnode = node->par->par;

        Node* Gnode = Pnode->par;
        if(Gnode->left == Pnode){
          if(Pnode->left == node)
            Pnode = Zig_Zig_R(Pnode);
          else
            Pnode = Zig_Zag_RL(Pnode);
          }
        else{
          if(Pnode->right == node)
            Zig_Zig_L(Pnode);
          else
            Zig_Zag_LR(Pnode);
        }

        /*else if(Gnode->right->right == node)
        else if(Gnode->left->right == node)
          Zig_Zag_RL(node->par);
        else
          Zig_Zag_LR(node->par);  */

      }
    }
    tree->root = node;
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
