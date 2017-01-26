#include "AVL.h"

int get_height(entry* e) {
	int h = 0;
	if(e != NULL) {
		h = 1 + max(get_height(R(e)), get_height(L(e)));
	}
	return h;
}

int get_balanced_num(entry* e) {
	if(e == NULL) {
		return 0;
	}
	else {
		return (get_height(L(e)) - get_height(R(e)));
