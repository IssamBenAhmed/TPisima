#include <stdio.h>
#include <stdlib.h>
#include "record.h"

int main(int argc, char ** argv) {
	list * l = listCreate();
    addRecord(l, 4, 10);
    addRecord(l, 5, 9);
    addRecord(l, 6, 8);
    listDisplay(l);
    if (l->length!=3) {
	    return 1;
    }
    listDestroy(l);
    return 0;
}
