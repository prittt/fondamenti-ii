/** @example load.c
* In questo esempio si illustrano implementazioni di diverse operazioni su liste, 
* come ad esempio il calcolo della sua lunghezza, la rimozione di un elemento, ecc.
*/
// Per controllare eventuali memory leak
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
#include "list.h"

#include <stdlib.h>

/*****************************************************************************/
/*                               IS MEMBER                                   */
/*****************************************************************************/

bool ListIsMember(const ElemType *e, Item* i) {
    while (!ListIsEmpty(i)) {
        if (ElemCompare(e, ListGetHeadValue(i)) == 0) {
            return true;
        }

        i = ListGetTail(i);
    }
    return false;
}

bool ListIsMemberRec(const ElemType *e, Item* i) {
    if (ListIsEmpty(i)) {
        return false;
    }

    if (ElemCompare(e, ListGetHeadValue(i)) == 0) {
        return true;
    }

    return ListIsMemberRec(e, ListGetTail(i));
}

/*****************************************************************************/
/*                                 LENGHT                                    */
/*****************************************************************************/
int ListLength(Item *i) {
    int n = 0;
    while (!ListIsEmpty(i)) {
        n++;
        i = ListGetTail(i);
    }
    return n;
}

int ListLengthRec(Item *i) {
    if (ListIsEmpty(i)) {
        return 0;
    }

    return 1 + ListLengthRec(ListGetTail(i));
}

/*****************************************************************************/
/*                                 APPEND                                    */
/*****************************************************************************/
Item *ListAppendRec(Item *i1, Item *i2) {
    if (ListIsEmpty(i1)) {
        return i2;
    }

    Item* tmp = ListInsertHead(ListGetHeadValue(i1), ListAppendRec(ListGetTail(i1), i2));
    free(i1);
    return tmp;
}

/*****************************************************************************/
/*                                  COPY                                     */
/*****************************************************************************/
Item *ListCopyRec(Item *i) {
    if (ListIsEmpty(i)) {
        return i;
    }
    return ListInsertHead(ListGetHeadValue(i), ListCopyRec(ListGetTail(i)));
}

/*****************************************************************************/
/*                                 REMOVE                                    */
/*****************************************************************************/
Item *ListRemoveRec(const ElemType *e, Item *i) {
    if (ListIsEmpty(i)) {
        return i;
    }

    if (ElemCompare(e, ListGetHeadValue(i)) == 0) {
        Item *tmp = ListGetTail(i);
        free(i);
        return tmp;
    }
    
    Item *tmp = ListInsertHead(ListGetHeadValue(i), ListRemoveRec(e, ListGetTail(i)));
    free(i);
    return tmp;
}

Item *ListCreateFromVector(const ElemType*v, size_t v_size) {
    Item *list = ListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = ListInsertBack(list, &v[i]);
    }
    return list;
}

int main(void) {
    ElemType v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    Item *list = ListCreateFromVector(v, v_size);
    Item *other_list = ListCreateFromVector(v, v_size - 5);

    ElemType e;
    bool ret;

    e = 5;
    ret = ListIsMember(&e, list);
    ret = ListIsMemberRec(&e, list);
    e = 11;
    ret = ListIsMember(&e, list);
    ret = ListIsMemberRec(&e, list);

    int len;
    len = ListLength(list);
    len = ListLengthRec(list);

    ListWriteStdout(list);
    ListWriteStdout(other_list);
    list = ListAppendRec(list, other_list);
    ListWriteStdout(list);

    other_list = ListCopyRec(list);
    ListWriteStdout(other_list);

    e = 1;
    list = ListRemoveRec(&e, list);
    ListWriteStdout(list);

    e = 5;
    list = ListRemoveRec(&e, list);
    ListWriteStdout(list);

    ListDelete(list);
    ListDelete(other_list);

    // Per controllare eventuali memory leak
    //_CrtDumpMemoryLeaks();

    return EXIT_SUCCESS;
}