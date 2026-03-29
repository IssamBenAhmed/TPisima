#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "codage.h"
#include "huffman.h"


// fonction qui permet de lire un fichier
// en temps qu'une chaine de caractères
char * lecture_fichier(char* nom) {
  FILE * f = fopen(nom, "rb");
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);

  char *string = malloc(fsize + 1);
  fread(string, fsize, 1, f);
  fclose(f);

  string[fsize] = 0;
  return string;
}
int main(int argc, char ** argv) {
   arbre * a=noeud('b',
                feuille('a'),
                noeud('d',
                      feuille('c'),
                      noeud('f', feuille('e'), feuille('g'))));
  infixe_inverse(stdout,a);
  libere_arbre(&a);
  return 0;
}