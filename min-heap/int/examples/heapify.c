#include <stdlib.h>
#include <string.h>

#include "minheap_int.h"

/** @brief Dato un vettore di ElemType, la funzione HeapifyMinHeap crea una 
           (min-)heap contenente tutti gli elementi del vettore. 

@param[in] v Vettore di ElemType.
@param[in] v_size Numero di elementi contenuti in v.

@return Puntatore alla coda (min-)heap appena creata.
*/
Heap* HeapifyMinHeap(ElemType *v, size_t v_size)
{
    // Costruisco la heap con gli elementi del vettore v
    Heap *h = CreateEmptyHeap();
    h->size = v_size;
    h->data = malloc(sizeof(ElemType)*(v_size));
    memcpy(h->data, v, v_size * sizeof(ElemType));

    // Chiamo la MoveDownMinHeap a partire dai nodi nel penultimo livello
    // dell'albero fino alla radice, per garantire che tutti i nodi rispettino 
    // le proprietà (min-)heap. Non serve chiamare la MoveDownMinHeap sulle
    // foglie perché non avrebbe alcun effetto.
    for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
        MoveDownMinHeap(h, i);
    }
    return h;
}

int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    
    Heap *h = HeapifyMinHeap(v, v_size);
    WriteStdoutHeap(h);

    DeleteHeap(h);

    return EXIT_SUCCESS;
}