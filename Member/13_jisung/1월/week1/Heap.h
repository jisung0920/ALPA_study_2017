#include <stdio.h>
#define MAX  100
#define parIDX(x) ((x-1)/2)
#define L_IDX(x) (x*2+1)
#define R_IDX(x) (x*2+2)
#define HEAP(x) heap->con[x]
#define H_key(x) heap->con[x].key //부적절함

typedef enum{false,true} boolean;
typedef int Key;
typedef char Data;

typedef struct entry{
  Key key;
  Data data;
}Entry;

typedef struct heap{
  Entry con[MAX];
  int lastIDX;
}Heap;
void heapInit(Heap*);
void heapInsert(Heap *heap,Entry e);
Entry heapDelete(Heap*);
void swap(Entry*,Entry*);
void upheap(Heap*,int);
void downheap(Heap*,int);
