/** @example insert_ord.c
* In questo esempio si mostra come inserire un nuovo elemento in una lista esistente,
* rispettando l'ordinamento crescente.
*/
#include "list.h"

#include <stdlib.h>

Item *ListInsOrdRec(const ElemType *e, Item *i) {
    if (ListIsEmpty(i) || ElemCompare(ListGetHeadValue(i), e) >= 0) {
        return ListInsertHead(e, i);
    }
    Item *tmp = ListInsertHead(ListGetHeadValue(i), ListInsOrdRec(e, ListGetTail(i)));
    free(i);
    return tmp;
}

Item *ListInsOrd(const ElemType *e, Item *i) {
    if (ListIsEmpty(i) || ElemCompare(ListGetHeadValue(i), e) >= 0) {
        return ListInsertHead(e, i);
    }

    Item *root = i;
    Item *prev = ListCreateEmpty();
    Item *new_item = ListInsertHead(e, ListCreateEmpty());

    while (!ListIsEmpty(i) && ElemCompare(ListGetHeadValue(i), e) < 0) {
        prev = i;
        i = ListGetTail(i);
    }
    prev->next = new_item;
    new_item->next = i;
    return root;
}

int main(void) {
    Item *i = ListCreateEmpty();
    Item *i_rec = ListCreateEmpty();
    ElemType e;
    // Acquisizione di elementi da stdin
    do {
        printf("Introdurre un valore intero: ");
        if (ElemReadStdin(&e) != 1) {
            break;
        }
        i = ListInsOrd(&e, i);
        i_rec = ListInsOrdRec(&e, i_rec);
    } while (e != 0); // L'acquisizione termina quando viene inserito lo zero.
    
    ListWriteStdout(i);
    ListWriteStdout(i_rec);

    ListDelete(i);
    ListDelete(i_rec);

    return EXIT_SUCCESS;
}