#include "Heap.h"

typedef struct PQ{
	int size;
	Heap que;
}PQ;

void PQInit(PQ* p){
  p->size =0;
  heapInit(p->que);
}

void insert(PQ* p,Key k ,Data d){
  Entry e = {k,d};
  heapInsert(p->que,e);
  p->size++;
}
Entry min(PQ *p){
  return p->que->con[0];
}
Entry removeMin(PQ *p){
  p->size--;
  return heapDelete(p->que);
}
int size(PQ *p){
  return p->size;
}
boolean isEmptry(PQ *p){
  return p->size == 0 ? true : false;
}

boolean isFULL(PQ *p){
  return p->size == MAX ? true : false;
}
