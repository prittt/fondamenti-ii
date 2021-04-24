#define _CRT_SECURE_NO_WARNINGS
#include "minheap.h"

#include <string.h>
#include <stdlib.h>

/*****************************************************************************/
/*                          Node & Primitives                                */
/*****************************************************************************/

int HeapLeft(int i) {
    return 2 * i + 1;
}

int HeapRight(int i) {
    return 2 * i + 2;
}

int HeapParent(int i) {
    return (i - 1) / 2;
}

bool HeapIsEmpty(const Heap *h) {
    return h->size == 0;
}

Heap *HeapCreateEmpty() {
    Heap *h = malloc(1 * sizeof(Heap));
    h->size = 0;
    h->data = NULL;
    return h;
}

void HeapMinInsertNode(Heap *h, const ElemType *e) {
    h->size++;
    h->data = realloc(h->data, sizeof(ElemType)*h->size);

    h->data[h->size - 1] = ElemCopy(e);

    HeapMinMoveUp(h, h->size - 1);
}

ElemType *HeapGetNodeValue(const Heap *h, int i) {
    if (!h || i >= (int)h->size) {
        printf("ERROR: 'HeapGetNodeValue()' si sta provando ad accedere ad un nodo che non fa parte dello heap.\n");
        exit(1);
    }
    else {
        return &h->data[i];
    }
}

void HeapMinMoveUp(Heap *h, int i) {
    while (i != 0 && ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i))) < 0) {
        ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i)));
        i = HeapParent(i);
    }
}

void HeapMinMoveDown(Heap *h, int i) {
    int l, r, smallest = i;
    bool done;
    do {
        done = true;
        l = HeapLeft(i);
        r = HeapRight(i);

        if ((l < (int)h->size) && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, smallest)) < 0) {
            smallest = l;
        }

        if ((r < (int)h->size) && ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, smallest)) < 0) {
            smallest = r;
        }

        if (smallest != i) {
            ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, smallest));
            i = smallest;
            done = false;
        }

    } while (!done);
}

void HeapDelete(Heap *h) {
    for (size_t i = 0; i < h->size; ++i) {
        ElemDelete(&h->data[i]);
    }
    free(h->data);
    free(h);
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

void HeapWrite(const Heap *h, FILE *f) {
    fprintf(f, "[");
    for (size_t i = 0; i < h->size; ++i) {
        ElemWrite(HeapGetNodeValue(h, i), f);
        if (i != h->size - 1) {
            fprintf(f, ", ");
        }
    }
    fprintf(f, "]\n");
}

void HeapWriteStdout(const Heap *h) {
    HeapWrite(h, stdout);
}