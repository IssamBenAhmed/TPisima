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
	int k = 0;
	if (key==NULL || n<=0){
		return -1;
	}
	for (int i=0;key[i]!='\0';i++){
		//k=k+octect du caractère key[i]
		k=k+(unsigned char)key[i];
	}
	k=k%n;
	return k;
}

void listDisplay(list * l) {
	list * cur = l;

	printf("[");
	while ( cur != NULL ) {
		printf(" { %s, %s} ",cur->key,cur->value);
		if (cur->next!=NULL)
			printf(",");
		cur=cur->next;
	}
	printf("]\n");
	

}

void hashtableDisplay(hashtable * h) {
    for(int i = 0; i < h->n; i++) {
        printf("%d : ", i);
        listDisplay(h->tab[i]);
    }
}

list * listAdd(list * l, char * newK, char * newV) {
	list * newz = malloc(sizeof(list));
	newz->key=newK;
	newz->value=newV;
	newz->next=l;
	return newz;
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
