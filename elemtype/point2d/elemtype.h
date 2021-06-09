/** @file
Questo file contiene la definizione di `ElemType` per il tipo `Point 2D` e la 
documentazione delle funzioni a esso associate.
*/

#ifndef ELEMTYPE_PUNTO_H_
#define ELEMTYPE_PUNTO_H_

#include <stdbool.h>
#include <stdio.h>

/** @brief Definizione di `struct ElemType`. */
typedef struct {
    int x;
    int y;
} Point2D;

typedef Point2D ElemType;

/** @brief La funzione `ElemCopy()` crea e ritorna una copia dell'elemento dato.

@param[in] e Puntatore all'elemento da copiare. Il valore contenuto in `e` non 
             viene modificato.

@return Copia dell'elemento `e`.
*/
ElemType ElemCopy(const ElemType *e);

/** @brief La funzione `ElemSwap()` scambia i due elementi specificati.

@param[in] e1 Puntatore al primo elemento da scambiare.
@param[in] e2 Puntatore al secondo elemento da scambiare.

@return Non ci sono valori di ritorno.
*/
void ElemSwap(ElemType *e1, ElemType *e2);

/** @brief La funzione `ElemDelete()` libera la memoria occupata dall'elemento
           specificato.

@param[in] e Puntatore all'elemento di cui liberare la memoria.

@return Non ci sono valori di ritorno.
*/
void ElemDelete(ElemType *e);

/** @brief La funzione `ElemWrite()` stampa un elemento su file.

@param[in] e Puntatore all'elemento da stampare su file. Il valore contenuto in
             e non viene modificato.
@param[in] f `FILE *` su cui stampare l'elemento.

@return Non ci sono valori di ritorno.
*/
void ElemWrite(const ElemType *e, FILE *f);

/** @brief La funzione `ElemWriteStdout()` stampa un elemento su `stdout`.

@param[in] e Puntatore all'elemento da stampare su `stdout`. Il valore
             contenuto in `e` non viene modificato.

@return Non ci sono valori di ritorno.
*/
void ElemWriteStdout(const ElemType *e);

#endif // ELEMTYPE_INT_H_

