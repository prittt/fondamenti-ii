#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

#include <string.h>
#include <stdlib.h>

/*****************************************************************************/
/*                           Item & Primitives                               */
/*****************************************************************************/

Item *ListCreateEmpty(void) {
    return NULL;
}

Item *ListInsertHead(const ElemType *e, Item *i) {
    Item *n = malloc(sizeof(Item));
    n->value = ElemCopy(e);
    n->next = i;
    return n;
}

bool ListIsEmpty(const Item *i) {
    return i == NULL;
}

const ElemType *ListGetHeadValue(const Item *i) {
    if (ListIsEmpty(i)) {
        printf("ERROR: Alla funzione 'ListGetHead()' e' stata passata una lista vuota (NULL).\n");
        exit(1);
    }
    else {
        return &i->value;
    }
}

Item *ListGetTail(const Item *i) {
    if (ListIsEmpty(i)) {
        printf("ERROR: Alla funzione 'ListGetTail()' e' stata passata una lista vuota (NULL).\n");
        exit(2);
    }
    else {
        return i->next;
    }
}

Item *ListInsertBack(Item *i, const ElemType *e) {

    Item *n = ListInsertHead(e, ListCreateEmpty());

    if (ListIsEmpty(i)) {
        return n;
    }

    Item *tmp = i;
    while (!ListIsEmpty(ListGetTail(tmp))) {
        tmp = ListGetTail(tmp);
    }

    tmp->next = n;
    return i;
}

void ListDelete(Item *i) {
    while (!ListIsEmpty(i)) {
        Item *tmp = i;
        i = i->next;
        ElemDelete(&tmp->value);
        free(tmp);
    }
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

void ListWrite(const Item *i, FILE *f) {
    fprintf(f, "[");
    while (!ListIsEmpty(i)) {
        ElemWrite(&i->value, f);
        i = ListGetTail(i);
        if (!ListIsEmpty(i)) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}

void ListWriteStdout(const Item *i) {
    ListWrite(i, stdout);
}