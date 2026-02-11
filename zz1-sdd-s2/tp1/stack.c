#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

stack * stackCreate() {
	return NULL;
}

int stackIsEmpty(stack * s) {
	return (s==NULL);
}

stack * stackAdd(stack * s, int v) {
	stack * nouveau = malloc(sizeof(stack));
	nouveau->next=s;
	nouveau->value=v;
	return nouveau;
}

int stackTop(stack * s) {
	return s->value;
}

stack * stackRemove(stack * s) {
	stack * d = s->next;
	free(s);
	return d;
}

int stackSize(stack * s) {
    int i = 0;
    stack * actuel = s; 

    while (actuel != NULL) { 
        i++;
        actuel = actuel->next; 
	}
    return i; 
}

void stackDisplay(stack * s) {
	printf("[");
	stack * cur = s;
	while (cur != NULL) {
		printf(" %d", cur->value);
		if (cur->next != NULL) printf(",");
		cur = cur->next;
	}
	printf(" ]");
}

void stackFree(stack * s) {
	stack * tmp;
	while(s!=NULL){
		tmp=s->next;
		free(s);
		s=tmp;
	}
}
