#include <stdlib.h>
#include <stdio.h>
#include "codage.h"

static encodage * g_last_encodage = NULL;

encodage * cree_encodage(binaire data, encodage * suivant) {
  encodage * res = malloc(sizeof(struct listeBinaire));
  if (res != NULL) {
    res->data = data;
    res->suivant = suivant;
  }
  
  return res;
}

void imprime_encodage(FILE * f, encodage * e) {
  encodage * reste = (e != NULL) ? e : g_last_encodage;
  while(reste != NULL) {
    fprintf(f, "%i", reste->data);
    reste = reste->suivant;
  }
  fprintf(f, "\n");
}


void libere_encodage(encodage ** e) {
  if (e == NULL) {
    return;
  }
  if (*e != NULL) {
    libere_encodage(&(*e)->suivant);
    free(*e);
    *e = NULL;
    return;
  }
  if (g_last_encodage != NULL && e != &g_last_encodage) {
    libere_encodage(&g_last_encodage);
  }
}

int code_char(arbre * a, char c, encodage * e) {
  if (a == NULL) {
    return 0;
  }
  if (e == NULL) {
    encodage * head = cree_encodage(0, NULL);
    int ok = code_char(a, c, head);
    if (ok) {
      libere_encodage(&g_last_encodage);
      g_last_encodage = head->suivant;
      head->suivant = NULL;
    }
    free(head);
    return ok;
  }
  if (est_feuille(a)) {
    return a->data == c;
  }
  if (code_char(a->gauche, c, e)) {
    encodage * n = cree_encodage(0, e->suivant);
    e->suivant = n;
    return 1;
  }
  if (code_char(a->droite, c, e)) {
    encodage * n = cree_encodage(1, e->suivant);
    e->suivant = n;
    return 1;
  }
  return 0;
}

static encodage * avance_fin(encodage * e) {
  encodage * cur = e;
  while (cur != NULL && cur->suivant != NULL) {
    cur = cur->suivant;
  }
  return cur;
}

encodage * code_texte(arbre * a, char * s) {
  if (a == NULL || s == NULL) {
    return NULL;
  }

  encodage * head = cree_encodage(0, NULL);
  encodage * tail = head;

  for (int i = 0; s[i] != '\0'; i++) {
    encodage * temp = cree_encodage(0, NULL);
    if (!code_char(a, s[i], temp)) {
      libere_encodage(&temp);
      libere_encodage(&head);
      return NULL;
    }
    tail->suivant = temp->suivant;
    tail = avance_fin(tail);
    free(temp);
  }

  encodage * res = head->suivant;
  free(head);
  return res;
}

encodage * decode_suivant(FILE * f, arbre * a, encodage * e) {
  if (a == NULL || e == NULL) {
    return NULL;
  }

  arbre * cur = a;
  encodage * p = e;

  while (cur != NULL && p != NULL && !est_feuille(cur)) {
    if (p->data == 0) {
      cur = cur->gauche;
    } else {
      cur = cur->droite;
    }
    p = p->suivant;
  }

  if (cur != NULL && est_feuille(cur)) {
    fprintf(f, "%c", cur->data);
    return p;
  }
  return NULL;
}

void decode(FILE * f, arbre * a, encodage * e) {
  encodage * reste = e;
  while (reste != NULL) {
    encodage * suivant = decode_suivant(f, a, reste);
    if (suivant == NULL && reste != NULL) {
      break;
    }
    reste = suivant;
  }
}

