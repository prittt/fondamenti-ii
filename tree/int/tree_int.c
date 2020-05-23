#define _CRT_SECURE_NO_WARNINGS
#include "tree_int.h"

#include <string.h>
#include <stdlib.h>

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
{}

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
    printf("%d", *e);
}

void WriteStdoutElem(const ElemType *e)
{
    WriteElem(e, stdout);
}

/*****************************************************************************/
/*                          Node & Primitives                                */
/*****************************************************************************/

Node* CreateEmptyTree(void)
{
    return NULL;
}

Node* CreateRootTree(const ElemType *e, Node *l, Node *r)
{
    Node* t = malloc(sizeof(Node));
    t->value = ElemCopy(e);
    t->left = l;
    t->right = r;
    return t;
}

bool IsEmptyTree(const Node *n)
{
    return n == NULL;
}

const ElemType* GetRootTree(const Node *n)
{
    if (IsEmptyTree(n)) {
        printf("ERROR: Alla funzione 'GetRootTree()' e' stato passato un albero vuoto (NULL pointer).\n");
        exit(1);
    }
    else {
        return &n->value;
    }
}

Node* LeftTree(const Node *n)
{
    if (IsEmptyTree(n)) {
        return NULL;
    }
    else {
        return n->left;
    }
}

Node* RightTree(const Node *n)
{
    if (IsEmptyTree(n)) {
        return NULL;
    }
    else {
        return n->right;
    }
}

bool IsLeafTree(const Node *n)
{
    return LeftTree(n) == NULL && RightTree(n) == NULL;
}

void DeleteTree(Node *n)
{
    if (IsEmptyTree(n)) {
        return;
    }

    Node *l = LeftTree(n);
    Node *r = RightTree(n);

    ElemDelete(&n->value);
    
    free(n);

    DeleteTree(l);
    DeleteTree(r);
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

//void WriteList(const Item *i, FILE *f)
//{
//    printf("[");
//    while (!IsEmptyList(i)) {
//        WriteElem(&i->value, f);
//        i = GetTailList(i);
//        if (!IsEmptyList(i)) printf(", ");
//    }
//    printf("]\n");
//}
//
//void WriteStdoutList(const Item *i)
//{
//    WriteList(i, stdout);
//}