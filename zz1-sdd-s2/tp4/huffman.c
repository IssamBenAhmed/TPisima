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

static liste * cree_cellule(arbrepoids * ap, liste * suivant) {
  liste * res = malloc(sizeof(struct liste));
  if (res != NULL) {
    res->data = ap;
    res->suivant = suivant;
  }
  return res;
}

liste * genere_liste(char * s) {
  if (s == NULL) {
    return NULL;
  }

  int tab[256] = {0};
  for (int i = 0; s[i] != '\0'; i++) {
    tab[(unsigned char)s[i]]++;
  }

  liste * L = NULL;
  for (int k = 0; k < 256; k++) {
    if (tab[k] != 0) {
      arbre * f = feuille((char)k);
      arbrepoids * ap = cree_arbrepoids(f, tab[k]);
      if (ap != NULL) {
        L = cree_cellule(ap, L);
      }
    }
  }

  return L;
}

arbrepoids * extrait_min(liste ** l) {
  if (l == NULL || *l == NULL) {
    return NULL;
  }

  liste * min_prev = NULL;
  liste * min_node = *l;
  int min_poids = min_node->data->poids;

  liste * prev = NULL;
  for (liste * cur = *l; cur != NULL; cur = cur->suivant) {
    if (cur->data->poids < min_poids) {
      min_poids = cur->data->poids;
      min_node = cur;
      min_prev = prev;
    }
    prev = cur;
  }

  if (min_prev == NULL) {
    *l = min_node->suivant;
  } else {
    min_prev->suivant = min_node->suivant;
  }

  arbrepoids * res = min_node->data;
  free(min_node);
  return res;
}

arbre * huffman(char * s) {
  if (s == NULL) {
    return NULL;
  }

  liste * L = genere_liste(s);
  if (L == NULL) {
    return NULL;
  }

  while (L != NULL && L->suivant != NULL) {
    arbrepoids * ap1 = extrait_min(&L);
    arbrepoids * ap2 = extrait_min(&L);
    if (ap1 == NULL || ap2 == NULL) {
      if (ap1 != NULL) {
        arbre * res = ap1->element;
        free(ap1);
        return res;
      }
      return NULL;
    }

    arbre * n = noeud('*', ap1->element, ap2->element);
    arbrepoids * ap = cree_arbrepoids(n, ap1->poids + ap2->poids);
    free(ap1);
    free(ap2);

    if (ap != NULL) {
      L = cree_cellule(ap, L);
    }
  }

  arbre * res = L->data->element;
  free(L->data);
  free(L);
  return res;
}
