#include "PQ.h"

void init_PQ(){
	P = malloc(sizeof(PQ));
	FRONT = NULL;
	SIZE = 0;
}

void insert(KEY k, DATA d) {
	MakeEntry(e);
	
	if(isEmpty()) {
		FRONT = e;
		BACK = e;
	}
	else {
		if (FRONT->key > k) {
			e->next = FRONT;
			FRONT = e;
		}
		else {
			BACK->next = e;
			BACK = e;
		}
	}
	SIZE++;
}

entry* min(){
	MIN(temp)
	printf("min : (%d, %c)\n", k, d);
	return temp;
}

entry* removeMin(){
	MIN(temp)
	printf("remove : (%d, %c)\n", k, d);
	FRONT = temp->next;
	free(temp);
	SIZE--;
	return temp;
}

int size() {
	int size;
	size = SIZE;
	return size;
}

boolean isEmpty(){
	if(SIZE==0) {
		return true;
	}
	else {
		return false;
	}
}

void print_PQ(){
	entry* temp = malloc(sizeof(entry));
	temp = FRONT;
	for(int i = 0; i < SIZE; i++){
		printf(" (%d, %c)",temp->key, temp->data);
		temp = temp->next;
	}
	puts("");
}
