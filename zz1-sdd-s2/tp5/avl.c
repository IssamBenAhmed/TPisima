#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int max(int a, int b) {
	if (a>b) {
		return a;
	}
	else {
		return b;
	}
}

struct avl * avlCreateNode(int key) {
    // TODO : question 8
    return NULL;
}

int avlHeight(struct avl * root) {
    // TODO : question 9
    return 0;
}

int avlGetBalance(struct avl * root) {
    // TODO : question 10
    return 0;
}

struct avl * avlRotateRight(struct avl * y) {
    // TODO : question 11
    return NULL;
}

struct avl * avlRotateLeft(struct avl * x) {
    // TODO : question 12
    return NULL;
}

struct avl * avlRotateLeftRight(struct avl * y) {
    return NULL;
}

struct avl * avlRotateRightLeft(struct avl * y) {
    return NULL;
}

struct avl * avlInsert(struct avl * root, int key) {
    // TODO : question 13
    return NULL;
}

struct avl * avlMinValue(struct avl * root) {
    // TODO : question 14
    return NULL;
}

struct avl * avlDelete(struct avl * root, int key) {
    // TODO : question 15
    return NULL;
}

void avlFree(struct avl * root) {
    // TODO : question 16
    return NULL;
}

void avlDisplay(struct avl * root) {
    // TODO : question 17
    return NULL;
}
