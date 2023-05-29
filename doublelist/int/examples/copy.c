/** @example copy.c
* In questo esempio si mostra come creare una lista a partire da un vettore di
* `ElemType` e successivamente crearne una copia.
*/
#include "doublelist.h"

#include <stdlib.h>

Item *DListCreateFromVector(const ElemType *v, size_t v_size) {
    Item *list = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = DListInsertBack(list, &v[i]);
    }
    return list;
}

Item *DListCopy(const Item *i) {
    Item *list_copy = DListCreateEmpty(); // Creo una lista vuota (NULL pointer)

    // Itero tutti gli elementi della lista da copiare
    for (; !DListIsEmpty(i); i = DListGetTail(i)) {
        // Aggiungo l'elemento corrente della lista di input alla nuova lista
        // usando la primitiva ListInsertBack(), la quale si occupa di allocare
        // opportunamente la memoria e aggiornare i puntatori!
        list_copy = DListInsertBack(list_copy, DListGetHeadValue(i));
    }

    return list_copy;
}

int main(void) {
    ElemType v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = DListCreateFromVector(v, v_size);


    Item *list_copy = DListCopy(list);

    printf("Input:\n  list: ");
    DListWriteStdout(list);
    printf("  head address: %p", list);
    printf("\n\nOutput (copy):\n  list: ");
    DListWriteStdout(list_copy);
    printf("  head address: %p", list_copy);

    DListDelete(list);
    DListDelete(list_copy);

    return EXIT_SUCCESS;
}
