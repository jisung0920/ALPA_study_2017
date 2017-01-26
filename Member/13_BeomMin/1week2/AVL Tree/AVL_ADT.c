#include "AVL.h"

void init_AVL() {
	root = malloc(sizeof(entry));
	root = NULL;
}

boolean isEmpty() {
	return root == NULL ? true : false ;
}

void insert(KEY k, DATA d) {
	MakeEntry(e, k, d)
	if(isEmpty()) {
		root = e;
	}
	else {
		MakeEntry(temp, 0, 0)
		temp = root;
		while(1) {
			if (K(temp) > K(e)) {
				if (L(temp) == NULL) {
					L(temp) = e;
		//			P(e) = temp;
					break;
				}
				else {
					temp = L(temp);
				}
			}
			else {
				if (R(temp) == NULL) {
					R(temp) = e;
				//	P(e) = temp;
				
					break;
				}
				else {
					temp = R(temp);
				}
			}
		}
	}
}
