#include "heap.h"

void main(){
	
	init_heap();

	insert(4,'a');
	min();
	print_heap(ROOT);	
	puts("");
	insert(5,'b');
	min();
	print_heap(ROOT);
	puts("");
	insert(3,'c');
//	print_heap(ROOT);
	puts("");
	min();
//	puts("??");
	print_heap(ROOT);
//	puts("!!");	
	insert(1,'d');
	min();
	print_heap(ROOT);
	puts("");
	insert(7,'a');
	print_heap(ROOT);
	puts("");
	insert(6,'e');
	print_heap(ROOT);
	puts("");
	insert(10,'f');
	print_heap(ROOT);
}
