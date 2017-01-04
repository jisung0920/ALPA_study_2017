#include "PQ.h"

void main() {
	init_PQ();

	insert(4, 'a');
	min();
	print_PQ();

	insert(2, 'b');
	min();
	print_PQ();

	insert(7, 'c');
	min();
	print_PQ();

	removeMin();
	min();
	print_PQ();
}
