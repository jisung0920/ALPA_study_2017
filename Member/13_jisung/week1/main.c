#include "Header.h"

int main(void){

  PQ p;
  PQInit(&p);

  insert(&p,1,'A');
  insert(&p,11,'B');
  insert(&p,6,'C');
  insert(&p,2,'D');
  insert(&p,8,'E');
  insert(&p,4,'F');
  insert(&p,9,'G');
  insert(&p,12,'H');
  insert(&p,19,'I');
  insert(&p,0,'J');
  insert(&p,5,'K');
  insert(&p,3,'L');
  insert(&p,1,'M');
  printHeap(&p);

  putchar('\n');

  printf("Minum :");
  printEntry(min(&p));
  putchar('\n');
  printHeap(&p);
  for(int i=0;i<15;i++){
    printf("count:%d\n",i+1);
    printf("Remove Minum :");
    printEntry(removeMin(&p));
    putchar('\n');
    printHeap(&p);
}

  return 0;

}
