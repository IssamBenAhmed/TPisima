#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char ** argv) {
	int i;
	queue * q = queueCreate();
	for (i=0; i<10; i++) {
		queueAdd(q, i+1);
	}
	if (queueSize(q)==10) {
		return 0;
	}
	else {
		return 1;
	}
}
