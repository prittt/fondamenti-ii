/** @example load.c
* In questo esempio si mostra come creare una lista con elementi letti da file.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "doublelist.h"

#include <stdlib.h>

Item *DListLoad(const char *filename) {
    FILE *f;
    f = fopen(filename, "r");

    if (!f) {
        return NULL;
    }

    Item *i = DListCreateEmpty();
    while (1) {
        ElemType tmp;
        if (1 != ElemRead(f, &tmp)) {
            break;
        }
        i = DListInsertHead(&tmp, i);
    }

    fclose(f);
    return i;
}

int main(void) {
    Item *list = DListLoad("load_example_01.txt");

    DListWriteStdout(list);

    DListDelete(list);

    return EXIT_SUCCESS;
}

