#define _CRT_SECURE_NO_WARNINGS
#include "doublelist.h"

#include <string.h>
#include <stdlib.h>

/*****************************************************************************/
/*                           Item & Primitives                               */
/*****************************************************************************/

Item *DListCreateEmpty(void) {
    return NULL;
}

Item *DListInsertHead(const ElemType *e, Item *i) {
    Item *n = malloc(sizeof(Item));
    n->value = ElemCopy(e);
    n->next = i;
    n->prev = NULL;
    if (!DListIsEmpty(i)) {
        i->prev = n;
    }
    return n;
}

bool DListIsEmpty(const Item *i) {
    return i == NULL;
}

const ElemType *DListGetHeadValue(const Item *i) {
    if (DListIsEmpty(i)) {
        printf("ERROR: Alla funzione 'DListGetHead()' e' stata passata una lista vuota (NULL).\n");
        exit(1);
    }
    else {
        return &i->value;
    }
}

Item *DListGetTail(const Item *i) {
    if (DListIsEmpty(i)) {
        printf("ERROR: Alla funzione 'ListGetTail()' e' stata passata una lista vuota (NULL).\n");
        exit(2);
    }
    else {
        return i->next;
    }
}

Item* DListGetPrev(const Item* i) {
    if (DListIsEmpty(i)) {
        printf("ERROR: Alla funzione 'DListGetHead()' e' stata passata una lista vuota (NULL).\n");
        exit(3);
    }
    else {
        return i->prev;
    }
}

Item *DListInsertBack(Item *i, const ElemType *e) {

    Item *n = DListInsertHead(e, DListCreateEmpty());

    if (DListIsEmpty(i)) {
        return n;
    }

    Item *tmp = i;
    while (!DListIsEmpty(DListGetTail(tmp))) {
        tmp = DListGetTail(tmp);
    }

    tmp->next = n;
    n->prev = tmp;
    return i;
}

static const Item* DListGetFirst(const Item* i) {
    if (DListIsEmpty(i)) {
        return NULL;
    }

    while (!DListIsEmpty(i->prev)) {
        i = i->prev;
    }

    return i;
}

void DListDelete(Item *i) {

    i = (Item*)DListGetFirst(i);

    while (!DListIsEmpty(i)) {
        Item *tmp = i;
        i = i->next;
        ElemDelete(&tmp->value);
        free(tmp);
    }
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

void DListWrite(const Item *i, FILE *f) {
    
    i = DListGetFirst(i);
    
    fprintf(f, "[");
    while (!DListIsEmpty(i)) {
        ElemWrite(&i->value, f);
        i = DListGetTail(i);
        if (!DListIsEmpty(i)) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}

void DListWriteStdout(const Item *i) {
    DListWrite(i, stdout);
}