#define _CRT_SECURE_NO_WARNINGS
#include "minheap_int.h"

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

void ElemSwap(ElemType *e1, ElemType *e2)
{
    ElemType tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
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

int LeftHeap(int i)
{
    return 2 * i + 1;
}

int RightHeap(int i)
{
    return 2 * i + 2;
}

int ParentHeap(int i)
{
    return (i - 1) / 2;
}

bool IsEmptyHeap(const Heap *h)
{
    return h->size == 0;
}

Heap* CreateEmptyHeap()
{
    Heap* h = malloc(1 * sizeof(Heap));
    h->size = 0;
    h->data = NULL;
    return h;
}

void InsertNodeMinHeap(Heap *h, const ElemType *e)
{
    h->size++;
    h->data = realloc(h->data, sizeof(ElemType)*h->size);

    h->data[h->size - 1] = ElemCopy(e);

    MoveUpMinHeap(h, h->size - 1);
}

ElemType* GetNodeValueHeap(const Heap *h, int i)
{
    if (!h || i >= (int)h->size) {
        printf("ERROR: 'GetNodeValueHeap()' si sta provando ad accedere ad un nodo che non fa parte dello heap.\n");
        exit(1);
    }
    else {
        return &h->data[i];
    }
}

void MoveUpMinHeap(Heap *h, int i)
{
    while (i != 0 && ElemCompare(GetNodeValueHeap(h,i), GetNodeValueHeap(h,ParentHeap(i))) < 0) {
        ElemSwap(GetNodeValueHeap(h,i), GetNodeValueHeap(h,ParentHeap(i)));
        i = ParentHeap(i);
    }
}

void MoveDownMinHeap(Heap *h, int i)
{
    int l, r, largest = i;
    bool done;
    do {
        done = true;
        l = LeftHeap(i);
        r = RightHeap(i);

        if ((l < (int)h->size) && ElemCompare(GetNodeValueHeap(h, l), GetNodeValueHeap(h, largest)) < 0) {
            largest = l;
        }

        if ((r < (int)h->size) && ElemCompare(GetNodeValueHeap(h, r), GetNodeValueHeap(h, largest)) < 0) {
            largest = r;
        }

        if (largest != i) {
            ElemSwap(GetNodeValueHeap(h, i), GetNodeValueHeap(h, largest));
            i = largest;
            done = false;
        }

    } while (!done);
}

void DeleteHeap(Heap *h)
{
    for (size_t i = 0; i < h->size; ++i) {
        ElemDelete(&h->data[i]);
    }
    free(h->data);
    free(h);
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

void WriteHeap(const Heap *h, FILE *f)
{
    fprintf(f, "[");
    for (size_t i = 0; i < h->size; ++i) {
        WriteElem(GetNodeValueHeap(h,i), f);
        if (i != h->size - 1) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}

void WriteStdoutHeap(const Heap *h)
{
    WriteHeap(h, stdout);
}