#include <stdlib.h>

#include "minheap_int.h"

void InsertNode(Heap *h, const ElemType *e) {
    h->size++;
    h->data = realloc(h->data, sizeof(ElemType)*h->size);
    
    h->data[h->size - 1] = ElemCopy(e);

    MoveUpMinHeap(h, h->size - 1);
}

int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    
    Heap* h = CreateEmptyHeap();
    for (unsigned i = 0; i < v_size; ++i) {
        InsertNode(h, &v[i]);
    }
    WriteStdoutHeap(h);

    h->data[0] = 99;
    WriteStdoutHeap(h);
    MoveDownMinHeap(h, 0);
    WriteStdoutHeap(h);

    h->data[2] = 24;
    WriteStdoutHeap(h);
    MoveDownMinHeap(h, 2);
    WriteStdoutHeap(h);


    DeleteHeap(h);

    return EXIT_SUCCESS;
}