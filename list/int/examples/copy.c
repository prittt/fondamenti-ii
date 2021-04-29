/** @example copy.c
* In questo esempio si mostra come creare una lista a partire da un vettore di
* `ElemType` e successivamente crearne una copia.
*/
#include "list.h"

#include <stdlib.h>

Item *ListCreateFromVector(const int *v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

Item *ListCopy(const Item *i) {
    Item *list_copy = ListCreateEmpty(); // Creo una lista vuota (NULL pointer)

    // Itero tutti gli elementi della lista da copiare
    for (; !ListIsEmpty(i); i = ListGetTail(i)) {
        // Aggiungo l'elemento corrente della lista di input alla nuova lista
        // usando la primitiva ListInsertBack(), la quale si occupa di allocare
        // opportunamente la memoria e aggiornare i puntatori!
        list_copy = ListInsertBack(list_copy, ListGetHeadValue(i));
    }

    return list_copy;
}

int main(void) {
    int v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);


    Item *list_copy = ListCopy(list);

    printf("Input:\n  list: ");
    ListWriteStdout(list);
    printf("  head address: %p", list);
    printf("\n\nOutput (copy):\n  list: ");
    ListWriteStdout(list_copy);
    printf("  head address: %p", list_copy);

    ListDelete(list);
    ListDelete(list_copy);

    return EXIT_SUCCESS;
}
