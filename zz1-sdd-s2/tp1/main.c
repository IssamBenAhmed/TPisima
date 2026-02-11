#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

int main() {
    //stack
   /* stack * A = stackAdd(stackAdd(stackCreate(),7),6);
    int i=stackIsEmpty(stackCreate());
    int j=stackIsEmpty(A);
    int o=stackSize(A);
    stackDisplay(A);
    int k=stackTop(A);
    int l=stackTop(stackRemove(A));
    printf("\n      i=%d   j=%d   k=%d  l=%d  o=%d ", i , j , k ,l ,o); */
   


    //queue
    
    queue * Q = queueCreate();
    for (int i=0;i<10;i++){
    queueAdd(Q,i);
    }
    queueDisplay(Q);
    








    return 0;
}
