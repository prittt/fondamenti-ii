/** @example show.c
* In questo esempio si mostra come creare una lista di `point 2D` a partire da
* un vettore di `ElemType` e stamparla su `stdout`. Il modo in cui viene popolata
* la lista è puramente esemplificativo.
*/
#include "list.h"

#include <stdlib.h>

Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; i += 2) {
        list = ListInsertBack(list, &(ElemType){v[i], v[i + 1]});
    }
    return list;
}

int main(void) {
    //          x1 y1 x2 y2 x3 y3 x4 y4 x5 y5
    int v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);

    ListWriteStdout(list);

    ListDelete(list);

    return EXIT_SUCCESS;
}