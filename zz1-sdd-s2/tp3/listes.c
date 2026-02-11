#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listes.h"

list * listCreate() {
    return NULL;
}

list * listAdd(list * l,int n){
    list * plist=(list *) malloc(sizeof(list));
    if (plist==NULL) return NULL;

    plist->value=n;
    plist->next=l;
    return plist;
}



void listDisplay(list * l){
      // TO DO question 2
}


void listInverseDisplay(list * l){
      // TO DO question 3

}

int listSearch(list * plist, int n){
      // TO DO question 4
      return 0;
}



list * listMap(list* l , int (*f)(int)){
      // TO DO question 5
      return NULL;

}

list * listFilter(list* l , int (*p)(int)){
    // TO DO question 6
    return NULL;

}

int listFold(list* l , int (*op)(int,int),int base){
    // TO DO question 7
      return 0;
}


// TO DO  question 7
// Fonction opSum
// .....

int listSum(list* l ){
    // TO DO question 7
      return 0;
}

// TO DO  question 7
// Fonction opProd
// .....

int listProd(list* l ){
    // TO DO question 7
      return 0;
}

// TO DO  question 7
// Fonction opLen
// .....

int listLen(list* l ){
    // TO DO question 7
      return 0;
}

// concatene à l1 l'inverse de l2
list * ajouteInverse(list * l1,list * l2){
    // TO DO question 8
      return NULL;
}

list* listInverse(list *l){
    // TO DO question 8
      return NULL;
}



void listFree(list * plist){
    // TO DO question 9
}