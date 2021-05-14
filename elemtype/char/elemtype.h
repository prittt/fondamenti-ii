/** @file
Questo file contiene la definizione di `ElemType` per il tipo `char` e la 
documentazione delle funzioni a esso associate.
*/

#ifndef ELEMTYPE_CHAR_H_
#define ELEMTYPE_CHAR_H_

#include <stdbool.h>
#include <stdio.h>

/** @brief Definizione di `struct ElemType`. */
typedef char ElemType;

/** @brief La funzione `ElemCompare()` confronta due elementi.

@param[in] e1 Puntatore al primo elemento di cui eseguire il confronto. Il 
              valore contenuto in `e1` non viene modificato.
@param[in] e2 Puntatore al secondo elemento di cui eseguire il confronto. Il
              valore contenuto in `e2` non viene modificato.

@return La funzione ritorna un valore intero che indica la relazione tra i due
        elementi, ovvero:
         - `< 0` (ad esempio `-1`) se il contenuto del primo è minore di quello del secondo;
         - `0` se i contenuti dei due elementi sono uguali;
         - `> 0` (ad esempio `1`) se il contenuto del primo è maggiore di quello del secondo.
*/
int ElemCompare(const ElemType *e1, const ElemType *e2);

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

/** @brief La funzione `ElemRead()` legge un elemento da file.

@param[in] f `FILE *` da cui leggere un elemento.
@param[out] e Elemento letto da file.

@return Se la lettura va a buon fine la funzione ritorna `1`, altrimenti ritorna `0`
        in caso di errore di corrispondenza, errore di lettura o fine del file. Se 
        si verifica un errore di lettura o si raggiunge la fine del file prima che 
        qualunque dato possa essere letto correttamente la funzione ritorna EOF, 
        ovvero un numero negativo.
*/
int ElemRead(FILE *f, ElemType *e);

/** @brief La funzione `ElemReadStdin()` legge un elemento da `stdin`.

@param[out] e Elemento letto da `stdin`.

@return Se la lettura va a buon fine la funzione ritorna `1`, altrimenti ritorna `0`
        in caso di errore di corrispondenza, errore di lettura o fine del file. Se 
        si verifica un errore di lettura o si raggiunge la fine del file prima che 
        qualunque dato possa essere letto correttamente la funzione ritorna EOF, 
        ovvero un numero negativo.
*/
int ElemReadStdin(ElemType *e);

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

#endif // ELEMTYPE_CHAR_H_

