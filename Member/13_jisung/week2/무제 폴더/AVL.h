#include "BST.h"

void InitNode(TreeNode *bt);
TreeNode* MakeAVLNode(Data);

int GetHight(TreeNode *bt);
int CountingHight(TreeNode* bt);
boolean BalancedNode(TreeNode* bt);

void putNode(TreeNode *bt,TreeNode node);
TreeNode* removeNode(TreeNode *bt);

void ResettingHight(TreeNode *bt);

void Restruct(TreeNode *bt);
void Rebalancing(TreeNode *bt);
