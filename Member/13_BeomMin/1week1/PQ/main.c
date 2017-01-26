#include "PQ.h"

void main() {
	init_PQ();
	
	insert(2,'a');
	min();
	print_PQ();

	insert(1,'b');
	min();
	print_PQ();

	insert(5,'c');
	min();
	print_PQ();

	insert(5, 'd');
	removeMin();
	min();
	print_PQ();
}
