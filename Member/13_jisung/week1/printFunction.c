#include "Header.h"

void printEntry(Entry e){
  printf("[key : %d  - data : %c ]",e.key,e.data);
}

void printHeap(PQ *p){
  int i=1,j;

  if(isEmptry(p))
    return ;

  else{
    for(;i<p->size;i*=2){
      for(j=i;j<i*2;j++){
        if(p->size<j)
          break;
        printEntry(p->que->con[j-1]);
      }
      putchar('\n');
    }
  }
}
