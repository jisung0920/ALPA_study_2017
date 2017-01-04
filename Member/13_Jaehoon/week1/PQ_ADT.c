#include "PQ.h"

typedef struct entry{
	KEY key;
	DATA data;
	struct entry* next;
}entry;

typedef struct PQ{
	entry front;
	entry back;
	int size;
}PQ;

PQ* P;

void init_PQ(){
	P = malloc(sizeof(PQ));
	p->front = NULL;
	size = 0;
}

void insert(KEY k, DATA d){
	entry* x = malloc(sizeof(entry));
	x->KEY = k;
	x->DATA = d;
	x->next = NULL;

	if(isEmpty()){
		P->front = x;
		P->back = x;
	}else{
		if(x->front->key > k){
			x->next = P->front;
			P->front = x;
		}else{
			P->back->next = x;
			P->back = x;
		}
	}
	P->size++;
}

entry* min(){
	entry* x = malloc(sizeof(entry));
	KEY k;
	DATA d;
	if(isEmpty()){
		puts("Empty");
		exit(1);
	}
	x = P->front;
	k = x->key;
	d= x->data;
	printf("min : (%d, %c)\n", k, d);
	return x;
}

entry* removeMin(){
	entry* x = malloc(sizeof(entry));
	KEY k;
	DATA d;
	if(isEmpty()){
		puts("empty");
		exit(1);
	}
	x = P->front;
	k = x->key;
	d = x->data;
	printf("remove : (%d, %c)\n", k, d);
	P->front = x->next;
	free(x);
	P->size--;
	return x;
}

int size(){
	int size;
	size = p->size;
	return size;
}

boolean isEmpty(){
	if(P->size == 0){
		return true;
	}else
		return false;
}

void print_PQ(){
	entry* temp = malloc(sizeof(entry));
	temp = P->front;
	for(int i = 0; i<P->size; i++){
		printf(" (%d, %c) ", temp->key, temp->data);
		temp = temp->next;
	}
	putchar('\n');
}
