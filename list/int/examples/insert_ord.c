#include "list_int.h"

#include <stdlib.h>

list insord(element e, list l)
{
    list t;
    if (empty(l) || !isLess(head(l), e)) {
        t = cons(e, l);
        //t->next = l;
        return t;
    }
    return cons(head(l), insord(e, tail(l)));
}

list insord2(element e, list l)
{
    list l1 = NULL, root = l;
    list t;
    if (empty(l) || !isLess(head(l), e)) {
        t = cons(e, l);
        return t;
    }
    t = cons(e, NULL);
    while (!empty(l) && isLess(head(l), e)) {
        l1 = l;
        l = tail(l);
    }
    l1->next = t;
    t->next = l;
    return root;
}
void main(void)
{
    list l1 = emptylist();
    int el;
    do {
        printf("\n Introdurre valore:\t");
        el = getElement();
        l1 = insord2(el, l1);
    } while (el != 0); /* condiz. arbitraria */
    showlist(l1);
}