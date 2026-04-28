#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "hashtable.h"
#define N 10

static int hashtableSize(hashtable * h) {
	if (h == NULL || h->tab == NULL) {
		return 0;
	}
	return (int)(intptr_t)h->tab[-1];
}

list * listCreate() {
	return NULL;
}

hashtable * hashtableCreate(int n) {
	hashtable * H = (hashtable *)malloc(sizeof(hashtable));
	if (H == NULL) return NULL;

	int size = (n > 0) ? n : N;
	H->n = 0;
	list ** raw = (list **)malloc((size + 1) * sizeof(list *));
	if (raw == NULL) {
		free(H);
		return NULL;
	}
	raw[0] = (list *)(intptr_t)size;
	H->tab = raw + 1;
	if (H->tab == NULL) {
		free(raw);
		free(H);
		return NULL;
	}

	for (int i = 0; i < size; i++) {
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
	if (k == NULL) {
		return NULL;
	}
	for (list * cur = l; cur != NULL; cur = cur->next) {
		if (cur->key != NULL && strcmp(cur->key, k) == 0) {
			return cur->value;
		}
	}
	return NULL;
}

char * hashtableSearch(hashtable * h, char * key) {
	if (h == NULL || key == NULL) {
		return NULL;
	}
	int size = hashtableSize(h);
	int idx = hash(key, size);
	if (idx < 0 || idx >= size) {
		return NULL;
	}
	return listSearch(h->tab[idx], key);
}

void hashtableAdd(hashtable * h, char * key, char * value) {
	if (h == NULL || key == NULL) {
		return;
	}
	int size = hashtableSize(h);
	int idx = hash(key, size);
	if (idx < 0 || idx >= size) {
		return;
	}
	for (list * cur = h->tab[idx]; cur != NULL; cur = cur->next) {
		if (cur->key != NULL && strcmp(cur->key, key) == 0) {
			cur->value = value;
			return;
		}
	}
	h->tab[idx] = listAdd(h->tab[idx], key, value);
	h->n += 1;
}

void listFree(list * l) {
	list * cur = l;
	while (cur != NULL) {
		list * next = cur->next;
		free(cur);
		cur = next;
	}
}

void hashtableFree(hashtable * h) {
	if (h == NULL) {
		return;
	}
	int size = hashtableSize(h);
	for (int i = 0; i < size; i++) {
		listFree(h->tab[i]);
	}
	if (h->tab != NULL) {
		free(h->tab - 1);
	}
	free(h);
}

hashtable * hashtableRehash(hashtable * h, int newN) {
	if (h == NULL || newN <= 0) {
		return h;
	}
	hashtable * res = hashtableCreate(newN);
	if (res == NULL) {
		return h;
	}
	int size = hashtableSize(h);
	for (int i = 0; i < size; i++) {
		list * cur = h->tab[i];
		while (cur != NULL) {
			list * next = cur->next;
			hashtableAdd(res, cur->key, cur->value);
			free(cur);
			cur = next;
		}
	}
	if (h->tab != NULL) {
		free(h->tab - 1);
	}
	res->n = h->n;
	free(h);
	return res;
}
