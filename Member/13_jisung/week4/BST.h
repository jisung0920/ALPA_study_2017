#include <stdio.h>
#include <stdlib.h>
#define GetLeft(x) (x->left)
#define GetRight(x) (x->right)

typedef int Data;
typedef enum{false,true} boolean;
typedef enum{firstD=-1,Left,Right} Dir;
typedef enum{Zero,One_Left,One_Right,Two} ChildState;


typedef struct Node{
  Data data;
  struct Node* par;
  struct Node* left;
  struct Node* right;
}Node;


void InitNode(Node *bt);
Node* MakeNode(Data data);
Data GetData(Node * bt);
void SetData(Node * bt, Data data);

ChildState ChildNodeState(Node* bt);

void MakeLeftSubTree(Node * main, Node * sub);
void MakeRightSubTree(Node * main, Node * sub);

void swapNodeData(Node* A, Node* B);

void printNode(Node* node);

Node* SearchNode(Node* bt,Data data,Dir *dir);
void InsertNode(Node* bt,Node *node);
Data DeleteNode(Node* bt,Data data);


void PreorderTraverse(Node * bt);
void InorderTraverse(Node * bt);
void PostorderTraverse(Node * bt);
