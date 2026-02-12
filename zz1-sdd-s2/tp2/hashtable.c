#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#define N 10

list * listCreate() {
	return NULL;
}

hashtable * hashtableCreate(int n) {
	hashtable * H = (hashtable *)malloc(sizeof(hashtable));
	if (H == NULL) return NULL;
	
	H->n = n;
	H->tab = (list **)malloc(n * sizeof(list *));
	if (H->tab == NULL) {
		free(H);
		return NULL;
	}
	
	
	for (int i = 0; i < n; i++) {
		H->tab[i] = NULL;
	}
	
	return H;
}

int hash(char * key, int n) {
	
	return 0;
}

void listDisplay(list * l) {
	// TODO : question 4
}

void hashtableDisplay(hashtable * h) {
	// TODO : question 5
}

list * listAdd(list * l, char * newK, char * newV) {
	// TODO : question 6
	return NULL;
}

char * listSearch(list * l, char * k) {
	// TODO : question 7
	return NULL;
}

char * hashtableSearch(hashtable * h, char * key) {
	// TODO : question 8
	return NULL;
}

void hashtableAdd(hashtable * h, char * key, char * value) {
	// TODO : question 9
}

void listFree(list * l) {
	// TODO : question 10
}

void hashtableFree(hashtable * h) {
	// TODO : question 10
}

hashtable * hashtableRehash(hashtable * h, int newN) {
	// TODO : question 11
	return NULL;
}
