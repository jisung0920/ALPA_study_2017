#include <stdio.h>
#include <stdlib.h>
#define GetLeft(x) (x->left)
#define GetRight(x) (x->right)

typedef int Data;
typedef enum{false,true} boolean;
typedef enum{firstD=-1,Left,Right} Dir;
typedef enum{Zero,One_Left,One_Right,Two} ChildState;


typedef struct TreeNode{
  Data data;
  struct TreeNode* par;
  struct TreeNode* left;
  struct TreeNode* right;
  int hight;
}TreeNode;

TreeNode * MakeTreeNode(void);
Data GetData(TreeNode * bt);
void SetData(TreeNode * bt, Data data);
TreeNode* SettingNode(Data data);

ChildState ChildNodeState(TreeNode* bt);

void MakeLeftSubTree(TreeNode * main, TreeNode * sub);
void MakeRightSubTree(TreeNode * main, TreeNode * sub);

void printNode(TreeNode* node);

TreeNode* SearchNode(TreeNode* bt,Data data,Dir *dir);
void InsertNode(TreeNode* bt,TreeNode *node,Dir dir);
Data DeleteNode(TreeNode* bt,Data data);


void PreorderTraverse(TreeNode * bt);
void InorderTraverse(TreeNode * bt);
void PostorderTraverse(TreeNode * bt);
