#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "base.h"

static int base=2;


//  IMPORTANT :  les nombres en binaires sont par exemple modélisés de la façon suivante :
//  Le nombre binaire 1101101
//  NULL <- 1 <- 1 <- 0 <- 1 <- 1 <- 0 <- 1 
//  C'est à dire que la tête de la liste est le bit de poids faible et la queue le bit de poids fort.

// 
void setBase(int b)
{
    base=b;
}

void printBaseB(list * l){
    char symboles[] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','g','h','i','j','k'};
    if (l == NULL) {
        printf("NULL");
    }
    else {
        printf(" <- %c", symboles[l->value]);
        printBaseB(l->next);
    }
}

int baseToDec(list* l){
    if (l == NULL) {
        return 0;
    } else {
        return l->value + base * baseToDec(l->next);
    }
}

int opBase(int acc, int x) {
    return acc * base + x;
}

int baseToDec2(list* l){
    list* liv = listInverse(l);
    return listFold(liv, opBase, 0);
}


list* decToBase(int n){
    if (n < base) {
        return listAdd(NULL, n);
    } else {
        return listAdd(decToBase(n / base), n % base);
    }
}


