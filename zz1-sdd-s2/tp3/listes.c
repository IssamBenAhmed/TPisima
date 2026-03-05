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
    if(l==NULL){
        printf("NULL ");
    }
    else{
        listDisplay(l->next);
        printf("%d ",l->value);
    }
    

}


void listInverseDisplay(list * l){
       if(l==NULL) {
        printf("NULL");
    }
    else {
        printf("%d ",l->value);
        listInverseDisplay(l->next);
    }

}

int listSearch(list * plist, int n){
    if(plist!=NULL)
        if(plist->value==n)
            return 1;
        else{
            listSearch(plist->next,n);}
    else{
        return 0;
    }

}



list * listMap(list* l , int (*f)(int)){
      if(l == NULL){
        return NULL;
      }
      else{
        return listAdd(listMap(l->next,f),f(l->value));
      }

}

list * listFilter(list* l , int (*p)(int)){
    if(l == NULL){
        return NULL;
    }

    if(p(l->value)){
        return listAdd(listFilter(l->next, p), l->value);
    }
    else{
        return listFilter(l->next, p);
    }
}

int listFold(list* l , int (*op)(int,int),int base){
    if(!l){
        return base;
    }
    else return op(l->value,listFold(l->next,op,base));

      return 0;
}


// TO DO  question 7
// Fonction opSum
// .....

int opSum(int i, int j){
    return i+j;
}








int listSum(list* l ){
    return listFold(l,opSum,0);
}

// TO DO  question 7
// Fonction opProd
int opProd(int i,int j){
    return i*j;
}

int listProd(list* l ){
    return listFold(l,opProd,0);
    
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