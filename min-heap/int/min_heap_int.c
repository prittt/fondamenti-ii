#define _CRT_SECURE_NO_WARNINGS
#include "tree_int.h"

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

const ElemType* GetRootValueTree(const Node *n)
{
    if (IsEmptyTree(n)) {
        printf("ERROR: Alla funzione 'GetRootValueTree()' e' stato passato un albero vuoto (NULL pointer).\n");
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

static void WritePreOrderTreeRec(const Node *n, FILE *f)
{
    if (IsEmptyTree(n)) {
        return;
    }

    printf("\t"); WriteElem(GetRootValueTree(n), f);
    WritePreOrderTreeRec(LeftTree(n), f);
    WritePreOrderTreeRec(RightTree(n), f);
}

void WritePreOrderTree(const Node *n, FILE *f)
{
    fprintf(f, "Albero in PreOrdine: ");
    if (IsEmptyTree(n)) {
        fprintf(f, "vuoto!");
    }
    else {
        WritePreOrderTreeRec(n, f);
    }
    fprintf(f, "\n");
}

void WriteStdoutPreOrderTree(const Node *n) 
{
    WritePreOrderTree(n, stdout);
}

static void WriteInOrderTreeRec(const Node *n, FILE *f)
{
    if (IsEmptyTree(n)) {
        return;
    }

    WriteInOrderTreeRec(LeftTree(n), f);

    printf("\t"); WriteElem(GetRootValueTree(n), f);

    WriteInOrderTreeRec(RightTree(n), f);
    
}

void WriteInOrderTree(const Node *n, FILE *f)
{
    fprintf(f, "Albero in Ordine: ");
    if (IsEmptyTree(n)) {
        fprintf(f, "vuoto!");
    }
    else {
        WriteInOrderTreeRec(n, f);
    }
    fprintf(f, "\n");
}

void WriteStdoutInOrderTree(const Node *n) 
{
    WriteInOrderTree(n, stdout);
}

static void WritePostOrderTreeRec(const Node *n, FILE *f)
{
    if (IsEmptyTree(n)) {
        return;
    }

    WritePostOrderTreeRec(LeftTree(n), f);
    WritePostOrderTreeRec(RightTree(n), f);

    printf("\t"); WriteElem(GetRootValueTree(n), f);
}

void WritePostOrderTree(const Node *n, FILE *f)
{
    fprintf(f, "Albero in PostOrdine: ");
    if (IsEmptyTree(n)) {
        fprintf(f, "vuoto!");
    }
    else {
        WritePostOrderTreeRec(n, f);
    }
    fprintf(f, "\n");
}

void WriteStdoutPostOrderTree(const Node *n)
{
    WritePostOrderTree(n, stdout);
}