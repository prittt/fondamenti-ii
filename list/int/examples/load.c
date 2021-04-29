/** @example load.c
* In questo esempio si mostra come creare una lista con elementi letti da file.
*/
#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

#include <stdlib.h>

Item *ListLoad(const char *filename) {
    FILE *f;
    f = fopen(filename, "r");

    if (!f) {
        return NULL;
    }

    Item *i = ListCreateEmpty();
    while (1) {
        ElemType tmp;
        if (1 != ElemRead(f, &tmp)) {
            break;
        }
        i = ListInsertHead(&tmp, i);
    }

    fclose(f);
    return i;
}

int main(void) {
    Item *list = ListLoad("load_example_01.txt");

    ListWriteStdout(list);

    ListDelete(list);

    return EXIT_SUCCESS;
}

