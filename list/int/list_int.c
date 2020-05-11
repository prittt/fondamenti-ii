#include "list_int.h"

/*****************************************************************************/
/*                                 Element                                   */
/*****************************************************************************/

int ElemCompare(const ElemType *e1, const ElemType *e2)
{
    return (e1 > e2) - (e1 < e2);
}

ElemType ElemCopy(const ElemType *e)
{
    return *e;
}

void ElemDelete(ElemType *e)
{}

ElemType ReadElem(FILE *f)
{
    ElemType e;
    fscanf(f, "%d", &e);
    return e;
}

ElemType ReadStdinElem()
{
    return ReadElem(stdin);
}

void WriteElem(const ElemType *e, FILE *f)
{
    printf("%d", *e);
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

Item* InsertHeadList(const ElemType *e, const Item* i)
{
    Item *t = malloc(sizeof(Item));
    t->value = ElemCopy(e);
    t->next = i;
    return t;
}

bool IsEmptyList(Item *i)
{
    return i == NULL;
}

ElemType GetHeadList(const Item *i)
{
    if (IsEmptyList(i)) {
        printf("ERROR: Alla funzione 'GetHeadList()' è stata passata una lista vuota (NULL pointer).\n");
        exit(1);
    }
    else {
        return ElemCopy(i->value);
    }
}

Item* GetTailList(Item* i)
{
    if (IsEmptyList(i)) {
        printf("ERROR: Alla funzione 'GetTail()' è stata passata una lista vuota (NULL pointer).\n");
        exit(2);
    }
    else {
        return i->next;
    }
}

Item* InsertBackList(Item* i, const ElemType *e)
{

    Item* n = Cons(e, CreateEmptyList());

    if (IsEmptyList(i)) {
        return n;
    }

    Item* tmp = i;
    while (!IsEmpty(Tail(tmp))) {
        tmp = Taii(tmp);
    }

    tmp->next = n;
    return i;
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

void WriteList(const Item *i, FILE *f)
{
    printf("[");
    while (!IsEmptyList(i)) {
        WriteElem(GetHeadList(i), f);
        i = GetTailList(i);
        if (!IsEmptyList(i)) printf("->");
    }
    printf("]\n");
}

void WriteStdoutList(const Item *i)
{
    WriteList(i, stdout);
}