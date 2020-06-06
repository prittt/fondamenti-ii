#include <stdlib.h>

#include "minheap_int.h"

int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, -1 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    
    Heap* h = CreateEmptyHeap();
    for (unsigned i = 0; i < v_size; ++i) {
        InsertNodeMinHeap(h, &v[i]);
    }
    WriteStdoutHeap(h);

    DeleteHeap(h);

    return EXIT_SUCCESS;
}