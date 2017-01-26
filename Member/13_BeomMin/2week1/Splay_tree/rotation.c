#include "Splay.h"


void splay(node* newNode) {
	

	while (1) {
		node* parent = newNode->parent;
		if(parent == root) {
			if(root->right == newNode) {
				zig_R(newNode);
				break;
			}
			else {
				zig_L(newNode);
				break;
			}
		}
		else if(parent->parent == root) {
			if(root->right == parent && parent->right == newNode) {
				zigzig_RR(newNode);
				root = newNode;
				break;
			}
			else if (root->left == parent && parent->left == newNode ) {
				zigzig_LL(newNode);
				root = newNode;
				break;
			}
			else if (root->right == parent && parent->left == newNode) {
				zigzag_RL(newNode);
				root = newNode;
				break;
			}
			else if (root->left == parent && parent->right == newNode) {
				zigzag_LR(newNode);
				root = newNode;
				break;
			}
		}
		else {
			if(parent->parent->right == parent && parent->right == newNode) {
				zigzig_RR(newNode);
			}
			else if (parent->parent->left == parent && parent->left == newNode ) {
				zigzig_LL(newNode);
			}
			else if (parent->parent->right == parent && parent->left == newNode) {
				zigzag_RL(newNode);
			}
			else if (parent->parent->left == parent && parent->right == newNode) {
				zigzag_LR(newNode);
			}
		}	
	}
}		

void zig_R(node* n) {
	node* temp = n->left;

	n->left = root;
	n->parent = NULL;
	
	root->parent = n;
	if (temp == NULL) {
		root->right = NULL;
	}	
	else {
		root->left = temp;
		temp->parent = root;
	}
	root = n;
}

void zig_L(node* n) {
	node* temp = n->right;

	n->right = root;
	n->parent = NULL;

	root->parent = n;
	if (temp== NULL) {
		root->left = NULL;
	}
	else if (temp!= NULL){
		root->left = temp;
		temp->parent = root;
	}

	root = n;
}

void zigzig_RR(node* n) {
	node* p = n->parent;
	node* pp = p->parent;
	node* temp = n->left;
	node* temp2 = p->left;

	if(pp != root) {
	if(pp->parent->left == pp) {
		pp->parent->left = n;
	}
	else {
		pp->parent->right = n;
	}

	n->parent = pp->parent;
	}
	else {
		n->parent = NULL;
	}
	n->left = p;
	
	p->parent = n;
	if (temp == NULL) {
	p->right = NULL;
	}
	else {
		p->right = temp;
		temp->parent = p;
	}
	p->left = pp;

	pp->parent = p;
	if(temp2 == NULL) {
	pp->right = NULL;
	}
	else {
		pp->right = temp2;
		temp2->parent = pp;
	}

}

void zigzig_LL(node* n) {
	node* p = n->parent;
	node* pp = p->parent;
	node* temp = n->right;
	node* temp2 = p->right;

	if(pp != root) {
	if(pp->parent->left == pp) {
		pp->parent->left = n;
	}
	else {
		pp->parent->right = n;
	}

	n->parent = pp->parent;
	}
	else {
		n->parent = NULL;
	}
	n->right = p;

	p->parent = n;
	if(temp == NULL) {
		p->left = NULL;
	}
	else {
		p->left = temp;
		temp->parent = p;
	}
	p->right = pp;

	pp->parent = p;
	if(temp2 == NULL) {
	pp->left = NULL;
	}
	else {
		pp->left = temp2;
		temp2->parent = pp;
	}
}

void zigzag_RL(node* n) {
	node* p = n->parent;
	node* pp = p->parent;
	node* temp_l = n->left;
	node* temp_r = n->right;
	
	if(pp != root) {
	if(pp->parent->left == pp) {
		pp->parent->left = n;
	}
	else {
		pp->parent->right = n;
	}

	n->parent = pp->parent;
	}
	else {
		n->parent = NULL;
	}
	n->left = pp;
	n->right = p;

	p->parent = n;
	if(temp_r == NULL) {
		p->left = NULL;
	}
	else {
		p->left = temp_r;
		temp_r->parent = p;
	}
	
	pp->parent = n;
	if(temp_l == NULL) {
	pp->right = NULL;
	}
	else {
		pp->right = temp_l;
		temp_l->parent = pp;
	}
}

void zigzag_LR(node* n) {
	node* p = n->parent;
	node* pp = p->parent;
	node* temp_l = n->left;
	node* temp_r = n->right;
	
	if(pp != root) {
	if(pp->parent->left == pp) {
		pp->parent->left = n;
	}
	else {
		pp->parent->right = n;
	}

	n->parent = pp->parent;
	}
	else {
		n->parent = NULL;
	}
	n->left = p;
	n->right = pp;

	p->parent = n;
	if(temp_l == NULL) {
		p->right = NULL;
	}
	else {
		p->right = temp_l;
		temp_l->parent = p;
	}

	pp->parent = n;
	if (temp_r == NULL) {
		pp->left = NULL;
	}
	else {
		pp->left = temp_r;
		temp_r->parent = pp;
	}
}
