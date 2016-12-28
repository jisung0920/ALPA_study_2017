#include "heap.h"

void main(){
	
	init_heap();

	insert(4,'a');
	min();
	print_heap(ROOT);	

	insert(5,'b');
	min();
	print_heap(ROOT);

	insert(3,'c');
	min();

	insert(1,'d');
	min();
}
