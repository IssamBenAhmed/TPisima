#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(int argc, char ** argv) {
	hashtable * h = hashtableCreate(10);
	printf("Hashtable vide :\n");
	hashtableDisplay(h);
	if (h->n!=0) {
		return 1;
	}
	printf("Hashtable sans collision :\n");
	hashtableAdd(h, "Alice", "Dupont");
	hashtableAdd(h, "Bob", "Dupond");
	hashtableAdd(h, "Charles", "Dupon");
	hashtableDisplay(h);
	if (h->n!=3) {
		return 1;
	}
	printf("Hashtable avec collision :\n");
	hashtableAdd(h, "David", "Duppont");
	hashtableDisplay(h);
	printf("Rehash à 5 :\n");
	h = hashtableRehash(h, 5);
	hashtableDisplay(h);
	printf("Rehash à 20 :\n");
	h = hashtableRehash(h, 20);
	hashtableDisplay(h);
	if (h->n==0) {
		return 1;
	}
	hashtableFree(h);
	return 0;
}
