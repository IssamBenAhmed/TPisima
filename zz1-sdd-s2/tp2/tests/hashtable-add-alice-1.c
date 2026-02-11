#include <stdio.h>
#include <stdlib.h>
#include "hashtable.h"

int main(int argc, char ** argv) {
	hashtable * h = hashtableCreate(10);
	if (h->n!=0) {
		return 1;
	}
	hashtableAdd(h, "Alice", "Dupont");
	if (h->n!=1) {
		return 1;
	}
	return 0;
}
