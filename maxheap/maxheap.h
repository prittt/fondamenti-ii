/** @file
Questo file contiene la definizione del tipo `Heap` e la documentazione delle
funzioni primitive (e non) relative alle code di priorità (heap). Si noti che il 
comportamento di queste funzioni è indipendente dalla definizione di `ElemType`.
*/

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include "elemtype.h"

#include <stdbool.h>
#include <stdio.h>

/*****************************************************************************/
/*                          Node & Primitives                                */
/*****************************************************************************/

/** @brief Definizione del tipo `struct Heap`. */
struct Heap {
    ElemType *data; /*!< Vettore dei dati. */
    size_t size; /*!< Dimensione del vettore dei dati, ovvero numero di `ElemType` che questo contiene. */
};
/** @brief Definizione di un nome alternativo per `struct Heap`. */
typedef struct Heap Heap;

/** @brief Dato l'indice di un nodo della coda di priorità, la funzione `HeapLeft()`
        ritorna l'indice del suo figlio sinistro.

@param[in] i Indice di un nodo della coda. 

@return Indice del figlio sinistro del nodo `i`. Non e' detto che il nodo avente
        l'indice ritornato sia effettivamente presente nella coda.
*/
int HeapLeft(int i);

/** @brief Dato l'indice di un nodo della coda di priorità, la funzione `HeapRight()`
        ritorna l'indice del suo figlio destro.

@param[in] i Indice di un nodo della coda.

@return Indice del figlio destro del nodo `i`. Non è detto che il nodo avente
        l'indice ritornato sia effettivamente presente nella coda.
*/
int HeapRight(int i);

/** @brief Dato l'indice di un nodo della coda di priorità, la funzione `HeapParent()`
        ritorna l'indice del nodo padre.

@param[in] i Indice di un nodo della coda.

@return Indice del padre del nodo `i`. Non è detto che il nodo avente l'indice 
        ritornato sia effettivamente presente nella coda.
*/
int HeapParent(int i);

/** @brief La funzione `HeapCreateEmpty()` crea e ritorna una coda di priorità 
           vuota implementata mediante array. 

@return Puntatore allo heap appena creato.
*/
Heap* HeapCreateEmpty();

/** @brief La funzione `HeapMaxInsertNode()` aggiunge un nodo a una coda di 
            priorità esistente, garantendo che le proprietà (max-)heap siano 
            rispettate.

@param[in] h (max-)heap.
@param[in] e Valore da utilizzare per la creazione del nuovo nodo.

@returns Non ci sono valori di ritorno.
*/
void HeapMaxInsertNode(Heap *h, const ElemType *e);

/** @brief La funzione `HeapIsEmpty()` verifica se una coda di priorità  esistente 
            è vuota.

@param[in] h Heap da testare.

@return `true` se lo heap è vuoto, ovvero contiene zero elementi (`h->size == 0`),
        `false` altrimenti.
*/
bool HeapIsEmpty(const Heap *h);

/** @brief La funzione `HeapGetNodeValue()` ritorna un puntatore all'elemento
           contenuto nel nodo di indice specificato.

@param[in] h (max-)heap.
@param[in] i Indice del nodo.

@returns Puntatore all'elemento contenuto nel nodo di indice `i`.
*/
ElemType* HeapGetNodeValue(const Heap *h, int i);

/** @brief Dato un heap e l'indice di un nodo, la funzione `HeapMaxMoveUp()` sposta
           il nodo verso l'alto, ovvero lo scambia con il nodo padre ricorsivamente
           fino a quando le condizione (max-)heap non sono rispettate.

@param[i] h (max-)heap. Tutti i nodi di `h`, ad eccezione di quello di indice `i`,
            devono rispettare le condizioni (max-)heap.
@param[i] i Indice del nodo su cui applicare la procedura.

@return Non ci sono valori di ritorno.
*/
void HeapMaxMoveUp(Heap *h, int i);

/** @brief Dato un heap e l'indice di un nodo, la funzione `HeapMaxMoveDown()`
           sposta il nodo verso il basso, ovvero lo scambia con il minore dei 
           figli ricorsivamente fino a quando le condizione (max-)heap non sono
           rispettate.

@param[i] h (max-)heap. Tutti i nodi di `h`, ad eccezione di quello di indice `i`,
            devono rispettare le condizioni (max-)heap.
@param[i] i Indice del nodo su cui applicare la procedura.

@return Non ci sono valori di ritorno.
*/
void HeapMaxMoveDown(Heap *h, int i);

/** @brief La funzione `HeapDelete()` libera la memoria occupata dall'heap.

@param[in] h Heap di cui liberare la memoria.

@return Non ci sono valori di ritorno.
*/
void HeapDelete(Heap *h);

/*****************************************************************************/
/*                             Non Primitives                                */
/*****************************************************************************/

/** @brief La funzione `HeapWrite()` stampa la coda di priorità su file. 
           Nello specifico, la funzione stampa il carattere "[" seguito dagli
           elementi del vettore che implementa la coda di priorità, separati 
           dai caratteri ", ". Infine viene stampato il carattere "]".
           La stampa degli elementi dipende dalla definizione di `ElemType`.

@param[in] h Heap da stampare su file. Lo heap non viene modificato.
@param[in] f `FILE *` su cui stampare lo heap.

@return Non ci sono valori di ritorno.
*/
void HeapWrite(const Heap *h, FILE *f);

/** @brief La funzione `HeapWriteStdout()` stampa lo heap specificato su `stdout`.
           Nello specifico, la funzione stampa il carattere "[" seguito dagli
           elementi del vettore che implementa la coda di priorità, separati 
           dai caratteri ", ". Infine viene stampato il carattere "]".
           La stampa degli elementi dipende dalla definizione di `ElemType`.

@param[in] h Heap da stampare su `stdout`. Lo heap non viene modificato.

@return Non ci sono valori di ritorno.
*/
void HeapWriteStdout(const Heap *i);

#endif // MAXHEAP_H_

