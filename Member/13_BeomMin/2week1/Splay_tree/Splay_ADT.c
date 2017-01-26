#include "Splay.h"

void init_splay() {
	root = NULL;
}

boolean isEmpty() {
	return root == NULL ? true : false ;
}

void insert(int k) {
	MakeNode(k,newNode)
	
	if(isEmpty()) {
		root = newNode;
	}
	else {
		node* temp = root;
		while(1) {
			if(temp->key > k) {
				if(temp->left != NULL) {
					temp = temp->left;
				}
				else {
					temp->left = newNode;
					newNode->parent = temp;
//					splay(newNode);
					break;
				}
			}
			else if (temp->key < k) {
				if (temp->right != NULL) {
					temp = temp->right;
				}
				else {
					temp->right = newNode;
					newNode->parent = temp;
//				splay(newNode);
					break;
				}
			}
			else {
				puts("valid key");
			}
		}
		splay(newNode);
	}
	
}

void print_splay(node* n) {
	if(n->left != NULL) {
		print_splay(n->left);
	}
	printf("(%d)", n->key);
	if(n->right != NULL) {
		print_splay(n->right);
	}
}
		
