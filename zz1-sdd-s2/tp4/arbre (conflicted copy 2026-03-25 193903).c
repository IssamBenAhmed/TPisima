#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arbre.h"

arbre * feuille(char c){
  arbre * f = malloc(sizeof(arbre));
  f->data=c;
  f->droite=NULL;
  f->gauche=NULL;
  return f;
}

arbre * noeud(char c, arbre * g, arbre * d){
  arbre * n = malloc(sizeof(arbre));
  n->data=c;
  n->droite=d;
  n->gauche=g;
  return n;
}

int est_feuille(arbre * a) {
  return (a->droite==NULL && a->gauche==NULL);
}

void libere_arbre(arbre ** a){
  libere_arbre((*a)->droite);
  libere_arbre((*a)->gauche);
  free((*a));
  (*a)=NULL;
}

void infixe_inverse(FILE * f, arbre * a) {
}

void imprime_blancs(FILE * f, int niveau, int est_droit) {
}

void imprime_avec_blancs(FILE * f, arbre * a, int niveau, int est_droit) {
}

void imprime_arbre(FILE * f, arbre * a){
}


