#include "Splay.h"

void main() {
	init_splay();
	
	insert(5);

	
	printf("%d", root->key);
	print_splay(root);
	puts("");
	insert(9);
	printf("%d", root->key);
	print_splay(root);
	puts("");
	insert(8);
	printf("%d",root->key);
	print_splay(root);
	puts("");
	insert(1);
	printf("%d",root->key);
	print_splay(root);
	puts("");
	insert(11);
	printf("%d",root->key);
	print_splay(root);

//	search(1);
//	sprint
//	search(7);
//	sprint

//	delete(100);
//	sprint;
	puts("///");		
	delete(11);
	sprint
}
