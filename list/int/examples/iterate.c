/** @example iterate.c
* In questo esempio si mostra come creare una lista a partire da un vettore di 
* `ElemType` e come iterare gli elementi di una lista esistente utilizzando i 
* ciclo `for` e `while` facendo o meno uso delle funzioni primitive.
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

int main(void) {
    int v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = ListCreateFromVector(v, v_size);

    // Iterazione con il for usando le primitive:
    for (Item *tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
        // Prendo il valore dell'elemento corrente della lista.
        const ElemType *e = ListGetHeadValue(tmp);
        // Se volessi un elemento modificabile potrei fare:
        // ElemType e = ElemCopy(ListGetHeadValue(tmp));

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
    while (!ListIsEmpty(tmp)) {
        const ElemType *e = ListGetHeadValue(tmp);
        // Cose ...

        tmp = ListGetTail(tmp);
    }

    // Iterazione con il while senza le primitive:
    /*Item**/ tmp = list;
    while (tmp) {
        ElemType e = tmp->value;
        // Cose ...
        tmp = tmp->next;
    }

    ListDelete(list);

    return EXIT_SUCCESS;
}