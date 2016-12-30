#include "Heap.h"

void heapInit(Heap* heap){
  //heap->con = (Entry*)malloc(MAX*sizeof(Entry));
  //heap->con = NULL;
  heap->lastIDX= -1;
}

void heapInsert(Heap *heap,Entry e){
  heap->con[++(heap->lastIDX)] = e;
  upheap(heap,heap->lastIDX);
}

Entry heapDelete(Heap *heap){
  Entry tmp = heap->con[0];
  heap->con[0]=heap->con[(heap->lastIDX)--];
  downheap(heap, 0);
  return tmp;
}

void swap(Entry *e1,Entry *e2){
  Entry tmp = *e1;
  *e1 = *e2;
  *e2 = tmp;
}

void upheap(Heap *heap,int idx){

  if(heap->con[parIDX(idx)]==NULL)//
    return ;

  if( H_key(idx) < H_key(parIDX(idx)) ){
    swap(&HEAP(idx),&HEAP(parIDX(idx)));
    upheap(heap,parIDX(idx));
  }
}

void downheap(Heap *heap,int idx){
  int sIDX;
  Key sKey;
  if(H_key(L_IDX(idx))<H_key(R_IDX(idx)) || HEAP(R_IDX(idx))==NULL ){
    sIDX = L_IDX(idx);
    sKey =H_key(sIDX);
  }
  else{
    sIDX = R_IDX(idx);
    sKey =H_key(sIDX);
  }

  if(H_key(idx)>sKey)
    swap(&HEAP(idx),&HEAP(sIDX));
  else
    return ;
  downheap(heap,sIDX);
}
