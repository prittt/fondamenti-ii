#include <stdlib.h>
#include <string.h>

#include "minheap_int.h"

/** @brief Dato un Heap, la funzione Heapsort ordina il vettore dei dati
           sfruttando le proprieta' (min-)heap. Si noti che al termine 
           dell'operazione il vetttore dei dati sara' ordinato, e NON 
           rispettera' piu' le proprietà (min-)heap.
           

@param[in] h Heap da ordinare.

@return Non ci sono valori di ritorno.
*/
void HeapsortMinHeap(Heap *h)
{
    size_t origin_size = h->size; // Ci salviamo la dimensione originaria per
                                  // ripristinarla al termine. 

    while(h->size >= 2) {
        ElemSwap(GetNodeValueHeap(h, 0), GetNodeValueHeap(h, h->size - 1));
        h->size--;
        MoveDownMinHeap(h, 0);
    }
    h->size = origin_size; // Ripristiniamo la dimensione originaria altrimenti
                           // il distruttore della heap (DeleteHeap) non può
                           // fare il suo dovere. 
}

Heap* HeapifyMinHeap(ElemType *v, size_t v_size)
{
    Heap *h = CreateEmptyHeap();
    h->size = v_size;
    h->data = malloc(sizeof(ElemType)*(v_size));
    memcpy(h->data, v, v_size * sizeof(ElemType));

    for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
        MoveDownMinHeap(h, i);
    }
    return h;
}

int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    
    Heap* h = HeapifyMinHeap(v, v_size);
    WriteStdoutHeap(h);

    HeapsortMinHeap(h);
    WriteStdoutHeap(h);

    DeleteHeap(h);

    return EXIT_SUCCESS;
}