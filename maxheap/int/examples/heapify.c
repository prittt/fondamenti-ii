/** @example heapify.c
* In questo esempio si mostra come convertire un vettore di `ElemType` in una 
* coda di priorità (max-)heap, mediante la funzione `HeapMaxMoveDown()`. Questo
* procedimento prende il nome di `HeapifyMaxHeap()`
*/
#include <stdlib.h>
#include <string.h>

#include "maxheap.h"

/** @brief Dato un vettore di `ElemType`, la funzione `HeapifyMaxHeap()` crea una 
           (max-)heap contenente tutti gli elementi del vettore. 

@param[in] v Vettore di `ElemType`.
@param[in] v_size Numero di elementi contenuti in `v`.

@return Puntatore alla coda (max-)heap appena creata.
*/
Heap *HeapifyMaxHeap(const ElemType *v, size_t v_size) {
    // Costruisco la heap con gli elementi del vettore v
    Heap *h = HeapCreateEmpty();
    h->size = v_size;
    h->data = malloc(sizeof(ElemType)*(v_size));
    memcpy(h->data, v, v_size * sizeof(ElemType));

    // Chiamo la HeapMaxMoveDown a partire dai nodi nel penultimo livello
    // dell'albero fino alla radice, per garantire che tutti i nodi rispettino 
    // le proprietà (max-)heap. Non serve chiamare la HeapMaxMoveDown sulle
    // foglie perché non avrebbe alcun effetto.
    for (int i = (int)h->size / 2 - 1; i >= 0; i--) {
        HeapMaxMoveDown(h, i);
    }
    return h;
}

int main(void) {
    ElemType v[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(ElemType);
    
    Heap *h = HeapifyMaxHeap(v, v_size);
    HeapWriteStdout(h);

    HeapDelete(h);

    return EXIT_SUCCESS;
}