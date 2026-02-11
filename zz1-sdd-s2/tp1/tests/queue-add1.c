#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char ** argv) {
	queue * q = queueCreate();
	if (!queueIsEmpty(q)) {
		return 1;
	}
	queueAdd(q, 21);
	if (queueIsEmpty(q)) {
		return 1;
	}
	return 0;
}
