#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"

#include <string.h>
#include <stdlib.h>

#define _unused(x) ((void)(x))

/*****************************************************************************/
/*                                 Element                                   */
/*****************************************************************************/

int ElemCompare(const ElemType *e1, const ElemType *e2)
{
    return (*e1 > *e2) - (*e1 < *e2);
}

ElemType ElemCopy(const ElemType *e)
{
    return *e;
}

void ElemDelete(ElemType *e)
{
    // In questo caso la funzione ElemDelete non deve fare nulla, ma il 
    // compilatore potrebbe segnalare il mancato utilizzo di e come warning
    // o come errore. Utilizzando la macro _unused sopra definita eliminiamo
    // questo il problema.
    _unused(e);
}

int ReadElem(FILE *f, ElemType *e)
{
    return fscanf(f, "%d", e);
}

int ReadStdinElem(ElemType *e)
{
    return ReadElem(stdin, e);
}

void WriteElem(const ElemType *e, FILE *f)
{
    fprintf(f, "%d", *e);
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

const ElemType* GetHeadValueList(const Item *i)
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
    fprintf(f, "[");
    while (!IsEmptyList(i)) {
        WriteElem(&i->value, f);
        i = GetTailList(i);
        if (!IsEmptyList(i)) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}

void WriteStdoutList(const Item *i)
{
    WriteList(i, stdout);
}