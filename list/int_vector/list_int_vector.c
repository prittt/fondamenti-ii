#define _CRT_SECURE_NO_WARNINGS
#include "list_int_vector.h"

#include <string.h>
#include <stdlib.h>

/*****************************************************************************/
/*                                 Element                                   */
/*****************************************************************************/

// Definiziamo l'ordinameto per i vettori di interi in maniera analoga a quello
// definito tra stringe.
int ElemCompare(const ElemType *e1, const ElemType *e2)
{
    for (size_t i = 0; i < e1->size && i < e2->size; ++i) {
        if (e1->data[i] != e2->data[i]) {
            return (e1->data[i] > e2->data[i]) - (e1->data[i] < e2->data[i]);
        }
    } 

    return e1->size - e2->size;
}

ElemType ElemCopy(const ElemType *e)
{
    ElemType copy = { .size = e->size,.data = malloc(sizeof(int) * e->size) };
    memcpy(copy.data, e->data, sizeof(int)*e->size);
    return copy;
}

void ElemDelete(ElemType *e)
{
    free(e->data);
}

int ReadElem(FILE *f, ElemType *e)
{
    int ret = fscanf(f, "%u", &e->size);
    e->data = NULL;
    if (ret){
        e->data = malloc(sizeof(int)*e->size);
        for (size_t i = 0; i < e->size; ++i) {
            if (!fscanf(f, "%i", &e->data[i])) { 
                return 0;
            }
        }
    }
    return ret;
}

int ReadStdinElem(ElemType *e)
{
    return ReadElem(stdin, e);
}

void WriteElem(const ElemType *e, FILE *f)
{
    fprintf(f, "[");
    for (size_t i = 0; i < e->size; ++i) {
        fprintf(f, "%i", e->data[i]);
        if (i != e->size - 1) {
            printf(", ");
        }
    }
    fprintf(f, "]");
}

void WriteStdoutElem(const ElemType *e)
{
    WriteElem(e, stdout);
}

/*****************************************************************************/
/*                          Item & Primitives                                */
/*****************************************************************************/

Item* CreateEmptyList(void)
{
    return NULL;
}

Item* InsertHeadList(const ElemType *e, Item* i)
{
    Item *t = malloc(sizeof(Item));
    t->value = ElemCopy(e);
    t->next = i;
    return t;
}

bool IsEmptyList(const Item *i)
{
    return i == NULL;
}

const ElemType* GetHeadList(const Item *i)
{
    if (IsEmptyList(i)) {
        printf("ERROR: Alla funzione 'GetHeadList()' e' stata passata una lista vuota (NULL pointer).\n");
        exit(1);
    }
    else {
        return &i->value;
    }
}

Item* GetTailList(const Item* i)
{
    if (IsEmptyList(i)) {
        printf("ERROR: Alla funzione 'GetTail()' e' stata passata una lista vuota (NULL pointer).\n");
        exit(2);
    }
    else {
        return i->next;
    }
}

Item* InsertBackList(Item* i, const ElemType *e)
{

    Item* n = InsertHeadList(e, CreateEmptyList());

    if (IsEmptyList(i)) {
        return n;
    }

    Item* tmp = i;
    while (!IsEmptyList(GetTailList(tmp))) {
        tmp = GetTailList(tmp);
    }

    tmp->next = n;
    return i;
}

void DeleteList(Item* i)
{
    while (!IsEmptyList(i)) {
        Item* tmp = i;
        i = i->next;
        ElemDelete(&tmp->value);
        free(tmp);
    }
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

void WriteList(const Item *i, FILE *f)
{
    printf("[");
    while (!IsEmptyList(i)) {
        WriteElem(&i->value, f);
        i = GetTailList(i);
        if (!IsEmptyList(i)) printf(", ");
    }
    printf("]\n");
}

void WriteStdoutList(const Item *i)
{
    WriteList(i, stdout);
}