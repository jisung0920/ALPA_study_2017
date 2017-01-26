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

void search(int k) {
	node* temp = root;
	while(1) {
		if(root->key == k) {	
			break;
		}
		else if(temp->key == k) {
			splay(temp);
			break;
		}
		else if(temp->key < k) {
			if (temp->right == NULL) {
				splay(temp);
				break;
			}
			else {
			temp = temp->right;
			}
		}
		else if(temp->key > k) {
			if (temp->left == NULL) {
				splay(temp);
				break;
			}
			else {
			temp = temp->left;
			}
		}
		
	}
}

int delete(int k) {
	node* removeNode = root;
	while(1) {
		if (removeNode->key == k) {
			break;
		}
		else if(removeNode->key > k) {
			if(removeNode->left == NULL) {
				removeNode = NULL;
				break;
			}
			else {
			removeNode = removeNode->left;
			}
		}
		else if(removeNode->key < k) {
			if(removeNode->right == NULL) {
				removeNode = NULL;
				break;
			}
			else {
				
			removeNode = removeNode->right;
			}
		}
	}
	if (removeNode == NULL) {
		puts("not exist");
		exit(1);
	}
	else {
		if(removeNode != root) {
		splay(removeNode);
		}
		node* replaceNode = root->left;
		while(replaceNode->right != NULL) {
			replaceNode = replaceNode->right;
		}
		node* splayNode = replaceNode->parent;
		int temp = removeNode->key;
		
		if(replaceNode->left == NULL) {
		splayNode->right = NULL;
		}
		else {
			splayNode->right = replaceNode->left;
			replaceNode->left->parent = splayNode;
		}
		
		replaceNode->parent = NULL;
		if(removeNode->left == NULL) {
			replaceNode->left = NULL;
		}
		else {
			replaceNode->left = removeNode->left;
			removeNode->left->parent = replaceNode;
		}
		if(removeNode->right == NULL) {
			replaceNode->right = NULL;
		}
		else {
			replaceNode->right = removeNode->right;
			removeNode->right->parent = replaceNode;
		}
		
		root = replaceNode;	
		
		splay(splayNode);
		
		free(removeNode);
		return temp;
		
	}
}	
