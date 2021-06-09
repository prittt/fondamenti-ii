/** @example show.c
* In questo esempio si mostra come creare una lista di `int vector` a partire da
* un vettore di `ElemType` e stamparla su `stdout`. Il modo in cui viene popolata
* la lista è puramente esemplificativo.
*/
#include "list.h"

#include <stdlib.h>

Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        ElemType tmp = { .size = v_size - i,.data = malloc(sizeof(int)*(v_size - i)) };
        for (size_t j = i; j < v_size; ++j) {
            tmp.data[j - i] = v[j];
        }
        list = ListInsertBack(list, &tmp);
        ElemDelete(&tmp);
    }
    return list;
}

int main(void) {
    int v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);

    ListWriteStdout(list);

    ListDelete(list);

    return EXIT_SUCCESS;
}