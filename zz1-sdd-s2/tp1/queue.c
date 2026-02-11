#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

queue * queueCreate() {
	queue * q = malloc(sizeof(queue));
	q->head=NULL;
	q->tail=NULL;
	q->size=0;
	return q;
}

int queueIsEmpty(queue * q) {
	return(q->head==NULL && q->tail==NULL && q->size==0);
	
}

void queueAdd(queue * q, int v) {
	queue_element * nouveau=malloc(sizeof(queue_element));
	nouveau->value=v;
	
	if (q->size==0){
		q->tail=nouveau;
		q->head=nouveau;
		q->size++;
		nouveau->next=NULL;
		nouveau->previous=NULL;
	}

	else{
	nouveau->next=q->head;
	nouveau->previous=NULL;
	q->head->previous=nouveau;
	q->head=nouveau;
	q->size++;

	}	
}


int queueGet(queue * q) {
	if(q->size!=0){
		return q->tail->value;
	}
	return -1;
}

void queueRemove(queue * q) {
	queue_element * tmp = q->tail;
	if (q->size == 1) {
		q->head = NULL;
		q->tail = NULL;
	} else {
		q->tail = tmp->previous;
		q->tail->next = NULL;
	}
	free(tmp);
	q->size--;
	
}

void queueDestroy(queue * q) {
	queue_element * cur = q->head;
	while(cur!=NULL){
		queue_element * suivant = cur->next;
		free(cur);
		cur=suivant;
	}
	q->head=NULL;
	q->tail=NULL;
	q->size=0;


}

int queueSize(queue * q) {
	return q->size;
}

void queueDisplay(queue * q) {
	queue_element * cur = q->tail;
	printf("[");
	while(cur!=NULL){
		printf(" %d ",cur->value);
		if(cur->previous!=NULL)
			printf(",");
		cur=cur->previous;

	}
	printf("]");
}
