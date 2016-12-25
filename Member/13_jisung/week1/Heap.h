#include <stdio.h>
#define MAX  100
#define parIDX(x) ((x-1)/2)
#define L_IDX(x) (x*2+1)
#define R_IDX(x) (x*2+2)

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
}heap;
void heapInit(heap*);
void swap(Entry*,Entry*);
void upheap(Entry*);
void downheap(Entry*);
