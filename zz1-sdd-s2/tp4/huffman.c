#include <stdlib.h>
#include <stdio.h>
#include "arbre.h"
#include "huffman.h"

arbrepoids * cree_arbrepoids(arbre * a, int poids) {
  arbrepoids * ap =  malloc(sizeof(struct arbrepoids));
  if (ap != NULL) {
    ap->element = a;
    ap->poids = poids;
  }
  return ap;
}

liste * cree_liste(arbre * a, int poids, liste * suivant) {
  liste * res = malloc(sizeof(struct liste));

  if (res != NULL) {
    arbrepoids * ap = cree_arbrepoids(a, poids);
    if (ap != NULL) {
      res->data = ap;
    }
    res->suivant = suivant;
  }

  return res;
}

liste * genere_liste(char * s) {
  int tab[256]={0};

  for(int i=0;s[i]!='\0';i++){
    tab[(unsigned char)s[i]]++;
  }

  liste * L = NULL;

  for(int k=0;k!=256;k++){

    if (tab[k]!=0){

      L->data->poids=tab[k];
      L->data->element->data=(char)k;
      L=L->suivant;
    }
  }
  return L;
}

arbrepoids * extrait_min(liste ** l) {
  if (*l!=NULL){
    int minpoids = (*l)->data->poids;
    arbrepoids * minarbre = (*l)->data;
     
    (*l)=(*l)->suivant;

    for(int i=0;(*l)!=NULL;i++){
      if((*l)->data->poids<minpoids){
        minpoids=(*l)->data->poids;
        minarbre=(*l)->data;
      }

      (*l)=(*l)->suivant;

    }
    
  }
  return NULL;
}

arbre * huffman(char * s) {
  return NULL;
}
