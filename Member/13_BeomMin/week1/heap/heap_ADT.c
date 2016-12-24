#include "heap.h"

void init_heap() {
	H = malloc(sizeof(Heap));
	ROOT = NULL;
	SIZE = 0;
}

void insert(KEY k, DATA d) {
	MakeEntry(e,k,d)
	if(isEmpty()) {
		ROOT = e;
	}
	else {
		MakeEntry(temp,NULL,NULL)
		temp = ROOT;
		while(1){
			if(LEFT(temp) == NULL) {
				PARENT(e) = temp;
				LEFT(temp) = e;
				break;
			}
			else if(RIGHT(temp == NULL)) {
				PARENT(e) = temp;
				RIGHT(temp) = e;
				break;
			}
			else {
				temp = LEFT(temp);
			}
		}
		MakeEntry(p,NULL,NULL)
		p = PARENT(e);
		while(p->key > e->key) {
			PARENT(e) = PARENT(p);
			if(p == LEFT(PARENT(p))){
				LEFT(PARENT(p)) = e;
			}
			else {
				RIGHT(PARENT(p)) = e;
			}
			if(e == LEFT(p)) {
				LEFT(e) = p;
			else {
				RIGHT(e) = p;
			}
			PARENT(p) = e;
		}			
	}
	SIZE++;
}

entry* min(){
	if(isEmpty()){
		puts("empty");
		exit(1);
	}
	MakeEntry(temp,NULL,NULL)
	temp = ROOT;
	printf("min : (%d, %c)\n", temp->key, temp->data);
	return temp;
}

entry* removeMin() {
	if(isEmpty()) {
		puts("empty");
		exit(1);
	}
	MakeEntry(temp,NULL,NULL)
	MakeEntry(rep,NULL,NULL)
	temp = ROOT;
	rep = ROOT;
	printf("remove : (%d, %c)\n", temp->key, temp->data);
	
	while(1) {
		if(LEFT(rep) == NULL) {
			break;
		}
		else if(RIGHT(rep) == NULL) {
			rep = LEFT(rep);
			break;
		}
		else if(RIGTH(rep) != NULL && LEFT(LEFT(rep)) == NULL) {
			rep = RIGHT(rep);
			break;
		}
		else {
			rep = LEFT(rep);
			if (RIGHT(rep) != NULL) {
				rep = RIGHT(PARENT(rep));
			}
		}
	}
	if (rep == LEFT(PARENT(rep))) {
		LEFT(PARENT(rep)) = NULL;
	}
	else { 
		RIGHT(PARENT(rep)) = NULL:
	}
	LEFT(rep) = LEFT(ROOT);
	RIGHT(rep) = RIGHT(ROOT);
	PARENT(rep) = NULL;
	ROOT = rep;
	
	MakeEntry(bub,NULL,NULL)
	bub = ROOT;
	while(bub->key > LEFT(bub) || bub->key > RIGHT(bub)) {
		if(bub->key > LEFT(bub)->key) {
			
		

