#include "Heap.h"

void heapInit(Heap* heap){
  heap->con = NULL;
  heap->lastIDX= -1;
}

void heapInsert(Heap *heap,Entry e){
  heap->con[++lastIDX] = e;
  upheap(lastIDX);
}

Entry heapDelete(HEAP *heap){
  Entry tmp = heap->con[0];
  heap->con[0]=heap->con[lastIDX--];
  downheap(heap, 0);
  return tmp;
}

void swap(Entry *e1,Entry *e2){
  Entry tmp = *e1;
  *e1 = *e2;
  *e2 = tmp;
}

void upheap(Heap *heap,int idx){

  if(heap->con[parIDX]==NULL)
    return ;

  if((HEAP_key(idx))<(HEAP_key(parIDX(idx))){
    swap(HEAP(idx),HEAP(parIDX(idx)));
    upheap(heap,parIDX(idx));
  }
}

void downheap(Heap *heap,int idx){

  if(HEAP_key(L_IDX(idx))<HEAP_key(R_IDX(idx)) || HEAP(R_IDX)==NULL ){
    int sIDX = L_IDX(idx);
    Key sKey =HEAP_key(sIDX);
  }
  else{
    int sIDX = R_IDX(idx);
    Key sKey =HEAP_key(sIDX);
  }

  if(HEAP_key(idx)>skey)
    swap(HEAP(idx),HEAP(sIDX));
  else
    return ;
  downheap(heap,sIDX);
}
