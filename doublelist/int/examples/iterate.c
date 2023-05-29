/** @example iterate.c
* In questo esempio si mostra come creare una lista a partire da un vettore di 
* `ElemType` e come iterare gli elementi di una lista esistente utilizzando i 
* ciclo `for` e `while` facendo o meno uso delle funzioni primitive.
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

int main(void) {
    ElemType v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = DListCreateFromVector(v, v_size);

    // Iterazione con il for usando le primitive:
    for (Item *tmp = list; !DListIsEmpty(tmp); tmp = DListGetTail(tmp)) {
        // Prendo il valore dell'elemento corrente della lista.
        const ElemType *e = DListGetHeadValue(tmp);
        // Se volessi un elemento modificabile potrei fare:
        // ElemType e = ElemCopy(DListGetHeadValue(tmp));

        // E lo uso 
        // ...    
    }

    // Iterazione con il for senza la primitive:
    for (Item *tmp = list; tmp; tmp = tmp->next) {
        ElemType e = tmp->value;
        // Cose ...
    }

    // Iterazione con il while usando le primitive:
    Item *tmp = list;
    while (!DListIsEmpty(tmp)) {
        const ElemType *e = DListGetHeadValue(tmp);
        // Cose ...

        tmp = DListGetTail(tmp);
    }

    // Iterazione con il while senza le primitive:
    /*Item**/ tmp = list;
    while (tmp) {
        ElemType e = tmp->value;
        // Cose ...
        tmp = tmp->next;
    }

    DListDelete(list);

    return EXIT_SUCCESS;
}