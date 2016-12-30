#include "header.h"

int main(void){
  PQ *p;
  PQInit(p);
  insert(p,1,'A');
  insert(p,4,'B');
  insert(p,2,'C');
  insert(p,5,'D');
  insert(p,3,'E');
  insert(p,7,'F');
  insert(p,0,'G');
  printHeap(p);
  return 0;

}
