#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(int argc, char ** argv) {
	hashtable * h = hashtableCreate(10);
	printf("Hashtable vide :\n");
	hashtableDisplay(h);
	printf("Hashtable sans collision :\n");
	hashtableAdd(h, "Alice", "Dupont");
	hashtableAdd(h, "Bob", "Dupond");
	hashtableAdd(h, "Charles", "Dupon");
	hashtableDisplay(h);
	printf("Hashtaqble avec collision :\n");
	hashtableAdd(h, "David", "Duppont");
	hashtableDisplay(h);
	printf("Rehash à 5 :\n");
	h = hashtableRehash(h, 5);
	hashtableDisplay(h);
	printf("Rehash à 20 :\n");
	h = hashtableRehash(h, 20);
	hashtableDisplay(h);
	hashtableFree(h);
	return 0;
}

// Test hash:
// printf("hash(\"Alice\", 10) = %d\n", hash("Alice", 10));
// printf("hash(\"Bob\", 10) = %d\n", hash("Bob", 10));
// printf("hash(\"\", 10) = %d\n", hash("", 10));
// printf("hash(NULL, 10) = %d\n", hash(NULL, 10));

// Test listDisplay:
// list * l = NULL;
// l = listAdd(l, "Alice", "Dupont");
// l = listAdd(l, "Bob", "Dupond");
// l = listAdd(l, "Charles", "Dupon");
// listDisplay(l);
