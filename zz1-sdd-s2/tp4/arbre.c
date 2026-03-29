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
    if(a == NULL || *a == NULL) return;
    libere_arbre(&((*a)->droite));
    libere_arbre(&((*a)->gauche));
    free(*a);
    *a = NULL;
}

void infixe_inverse(FILE * f, arbre * a) {
  if (a!=NULL){
    infixe_inverse(f,a->droite);
    fprintf(f,"%c\n",a->data);
    infixe_inverse(f,a->gauche);

  }
}

void imprime_blancs(FILE * f, int niveau, int est_droit) {
 for (int i = 0; i < niveau; i++) {
    fprintf(f, "   "); // 3 espaces par niveau
  }

  if (est_droit){
    fprintf(f, "\\-");
  } else if (!est_droit){
    fprintf(f,"/-");
  }
}

void imprime_avec_blancs(FILE * f, arbre * a, int niveau, int est_droit) {
if (a){
  imprime_avec_blancs(f, a->droite, niveau + 3, 1);
  imprime_blancs(f,niveau,est_droit);
  fprintf(f,"%c\n",a->data);
  imprime_avec_blancs(f,a->gauche,niveau+3,0);
}
}

void imprime_arbre(FILE * f, arbre * a) {
    imprime_avec_blancs(f, a, 0, 0);
}


