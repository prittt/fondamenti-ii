/** @file
Questo file contiene la definizione del tipo `Item` e la documentazione delle
funzioni primitive (e non) relative alle liste doppiamente concatenate. Si noti
che il comportamento di queste funzioni è indipendente dalla definizione di `ElemType`.
*/

#ifndef DOUBLELIST_H_
#define DOUBLELIST_H_

#include "elemtype.h"

#include <stdbool.h>
#include <stdio.h>

/*****************************************************************************/
/*                           Item & Primitive                                */
/*****************************************************************************/

/** @brief Definizione del tipo `struct Item`. */
struct Item {
    ElemType value; /*!< Valore associato all'`Item`. */
    struct Item *next; /*!< Puntatore all'`Item` successivo. */
    struct Item *prev; /*!< Puntatore all'`Item` precedente. */
};
/** @brief Definizione di un nome alternativo per `struct Item`. */
typedef struct Item Item;

/** @brief La funzione `DListCreateEmpty()` crea e ritorna una lista vuota, ovvero
           `NULL`.

@return Lista vuota (`NULL`).
*/
Item *DListCreateEmpty(void);

/** @brief La funzione `DListInsertHead()` aggiunge un nuovo elemento in testa ad 
           una lista e ritorna il puntatore alla nuova lista.

@param[in] e Puntatore all'elemento da aggiugnere in testa alla lista.
@param[in] i Lista a cui aggiungere il nuovo elemento. `i` può essere una lista
            vuota (NULL).

@return Lista risultante.
*/
Item *DListInsertHead(const ElemType *e, Item *i);

/** @brief La funzione `DListIsEmpty(`) verifica se una lista è vuota.

@param[in] i Lista su cui eseguire la verifica.

@return `true` se la lista è vuota, `false` altrimenti.
*/
bool DListIsEmpty(const Item *i);

/** @brief La funzione `DListGetHead()` ritorna un puntatore all'elemento in testa 
            alla lista, senza rimuoverlo.

@param[in] i Lista da cui estrarre il valore in testa. Questa lista non può 
         essere vuota, nel caso in cui lo sia la funzione termina il programma 
         con codice di errore `1`.

@returns Puntatore all'elemento (costante) in testa alla lista.
*/
const ElemType *DListGetHeadValue(const Item *i);

/** @brief La funzione `DListGetTail()` ritorna la lista privata dell'elemento in 
           testa. La funzione NON dealloca la memoria occupata dalla testa
           della lista.

@param[in] i Lista da cui ottenere la coda. La lista non può essere vuota, 
         nel caso in cui lo sia la funzione termina il programma con codice di 
         errore `2`. 

@return Lista ottenuta dopo l'eliminazione della testa. Il valore di ritorno 
        potrebbe essere una lista vuota (`NULL`).
*/
Item *DListGetTail(const Item *i);

/** @brief La funzione `DListGetPrev()` ritorna il puntatore all'elemento precedente.

@param[in] i Lista da cui ottenere l'`Item` precedente. La lista non può essere vuota,
         nel caso in cui lo sia la funzione termina il programma con codice di
         errore `3`.

@return Puntatore alla nuova testa della lista. Il valore di ritorno potrebbe essere 
        una lista vuota (`NULL`).
*/
Item* DListGetPrev(const Item* i);

/** @brief La funzione `DListInsertBack()` aggiunge un elemento in coda ad una
            lista (anche vuota) e ritorna la lista risultante.

@param[in] i Lista a cui aggiungere l'elemento specifciato. Questa lista può
            essere vuota (`NULL`).
@param[in] e Puntatore all'elemento da aggiugnere in coda alla lista. Il valore 
         contenuto in e non viene modificato.

@return  Lista ottenuta dopo l'aggiunta dell'elemento.
*/
Item *DListInsertBack(Item *i, const ElemType *e);

/** @brief La funzione `ListDelete()` libera la memoria occupata da tutti gli elementi 
           di una lista, indipendentemente dalla posizione dell'`Item` specificato.

La funzione `ListDelete()` prende in input un puntatore ad un elemento di una lista e 
libera la memoria occupata da tutti i suoi `Item`, quelli precedenti, quelli successivi 
e quello passato come input alla funzione.

@param[in] i `Item` della lista di cui liberare la memoria, può essere `NULL`.

@return Non ci sono valori di ritorno.
*/
void DListDelete(Item *i);

/*****************************************************************************/
/*                             Non Primitive                                 */
/*****************************************************************************/

/** @brief La funzione `DListWrite()` stampa la lista specificata su file. 
           Nello specifico, la funzione stampa il carattere "[" seguito dagli 
           elementi della lista, separati dai caratter ", ", e dal carattere "]". 
           La stampa degli elementi dipende dalla definizione di `ElemType`. 

@param[in] i `Item` della lista da stampare su file: può essere NULL e non è necessario 
           che sia l'`Item` in testa alla lista, la lista non viene modificata.
@param[in] f `FILE *` su cui stampare la lista.

@return Non ci sono valori di ritorno.
*/
void DListWrite(const Item *i, FILE *f);

/** @brief La funzione `DListWriteStdout()` stampa la lista specificata su `stdout`.
           Nello specifico, la funzione stampa il carattere "[" seguito dagli
           elementi della lista, separati dai caratter ", ", e dal carattere "]".
           La stampa degli elementi dipende dalla definizione di `ElemType`.

@param[in] i `Item` della lista da stampare su file: può essere NULL e non è necessario
           che sia l'`Item` in testa alla lista, la lista non viene modificata.

@return Non ci sono valori di ritorno.
*/
void DListWriteStdout(const Item *i);

#endif // DOUBLELIST_H_

