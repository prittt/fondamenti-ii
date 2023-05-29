/** @example insert_ord.c
* In questo esempio si mostra come inserire un nuovo elemento in una lista esistente,
* rispettando l'ordinamento crescente.
*/
#include "doublelist.h"

#include <stdlib.h>

Item *DListInsOrd(const ElemType *e, Item *i) {
    if (DListIsEmpty(i) || ElemCompare(DListGetHeadValue(i), e) >= 0) {
        return DListInsertHead(e, i);
    }

    Item *head = i;
    Item *new_item = DListInsertHead(e, DListCreateEmpty());

    Item* prev = NULL;
    while (!DListIsEmpty(i) && ElemCompare(DListGetHeadValue(i), e) < 0) {
        prev = i;
        i = DListGetTail(i);
    }

    Item* next = i;
    new_item->next = next;
    new_item->prev = prev;

    prev->next = new_item;
    if (!DListIsEmpty(next)) {
        next->prev = new_item;
    }
    return head;
}

int main(void) {
    Item *i = DListCreateEmpty();
    ElemType e;
    // Acquisizione di elementi da stdin
    do {
        printf("Introdurre un valore intero: ");
        if (ElemReadStdin(&e) != 1) {
            break;
        }
        i = DListInsOrd(&e, i);
    } while (e != 0); // L'acquisizione termina quando viene inserito lo zero.
    
    DListWriteStdout(i);
    DListDelete(i);
    return EXIT_SUCCESS;
}