/** @file
Questo file contiene la definizione del tipo `Node` e la documentazione delle
funzioni primitive (e non) relative agli alberi binari. Si noti che il 
comportamento di queste funzioni è indipendente dalla definizione di `ElemType`.
*/

#ifndef TREE_H_
#define TREE_H_

#include "elemtype.h"

#include <stdbool.h>
#include <stdio.h>

/*****************************************************************************/
/*                          Node & Primitives                                */
/*****************************************************************************/

/** @brief Definizione del tipo `struct Node`. */
struct Node {
    ElemType value; /*!< Valore associato al `Node`. */
    struct Node *left; /*!< Puntatore al figlio sinistro. */
    struct Node *right; /*!< Puntatore al figlio destro. */
};
/** @brief Definizione di un nome alternativo per `struct Node`. */
typedef struct Node Node;

/** @brief La funzione `TreeCreateEmpty()` crea e ritorna un albero vuoto, 
        ovvero `NULL`.

@return Albero vuoto (`NULL`).
*/
Node* TreeCreateEmpty(void);

/** @brief La funzione `TreeCreateRoot()` crea un nuovo albero avente come radice 
           il valore specificato e come figli sinistro e destro i sottoalberi
           specificati. La funzione ritorna quindi il puntatore al nodo radice
           dell'albero appena creato.

@param[in] e Puntatore all'elemento il cui valore sarà copiato nel nodo radice del
           nuovo albero.
@param[in] l Figlio sinistro del nuovo albero. Il valore contenuto in `l` non 
            viene modificato dalla funzion. `l` può anche essere un albero
            vuoto (`NULL`).
@param[in] r Figlio destro del nuovo albero. Il valore contenuto in `r` non viene
            modificato dalla funzione. `r` anche essere un albero vuoto (`NULL`).

@return Puntatore al nodo radice dell'albero appena creato.
*/
Node* TreeCreateRoot(const ElemType *e, Node* l, Node* r);

/** @brief La funzione `TreeIsEmpty()` verifica se un albero è vuoto o meno.

@param[in] n Albero su cui eseguire il test.

@return `true` se l'albero è vuoto, `false` altrimenti.
*/
bool TreeIsEmpty(const Node *n);

/** @brief La funzione `TreeGetRootValue()` ritorna un puntatore all'elemento 
        contentuto nel nodo radice dell'albero specificato.

@param[in] n Albero da cui estratte il valore. L'albero NON può essere vuoto,
           nel caso in cui lo sia la funzione termina il programma con codice di
           errore `1`.

@returns Puntatore all'elemento (costante) contenuto nel nodo radice dell'albero.
*/
const ElemType *TreeGetRootValue(const Node *n);

/** @brief La funzione `TreeLeft()` ritorna un puntatore al nodo figlio sinistro
           dell'albero specificato.

@param[in] n Albero da cui ottenere il figlio sinistro che può eventualmente essere
            vuoto (`NULL`). Il nodo `n` non viene modificato.

@returns Puntatore al nodo figlio sinistro dell'albero specificato. Se l'albero
         specificato è vuoto o non ha un figlio sinistro la funzione ritorna 
         un albero vuoto (`NULL`).
*/
Node *TreeLeft(const Node *n);

/** @brief La funzione `TreeRight()` ritorna un puntatore al nodo figlio destro
           dell'albero specificato.

@param[in] n Albero da cui ottenere il figlio destro che può eventualmente essere
            vuoto (`NULL`). Il nodo `n` non viene modificato.

@returns Puntatore al nodo figlio destro dell'albero specificato. Se l'albero
         specificato è vuoto o non ha un figlio destro la funzione ritorna 
         un albero vuoto (`NULL`).
*/
Node *TreeRight(const Node *n);

/** @brief La funzione `TreeIsLeaf()` verifica se il nodo specificato è una foglia.

@param[in] n Puntatore al nodo/albero da verificareche può eventualmente essere
            vuoto (`NULL`). Il nodo `n` non viene modificato.

@returns `true` se il nodo è una foglia, ovvero se è un nodo vuoto (`NULL`)
         o se entrambi i suoi figli (sinistro e destro) sono nodi vuoti (`NULL`), 
         `false` altrimenti.
*/
bool TreeIsLeaf(const Node *n);

/** @brief La funzione `TreeDelete()` libera la memoria occupata dai nodi di un 
           albero.

@param[in] n Albero di cui liberare la memoria. Può essere un albero vuoto (`NULL`).

@return Non ci sono valori di ritorno.
*/
void TreeDelete(Node *n);

/*****************************************************************************/
/*                             Non Primitives                                */
/*****************************************************************************/

/** @brief La funzione `TreeWritePreOrder()` stampa l'albero specificato su file,
           visitandolo in pre-ordine. Nello specifico, la funzione stampa la
           sequenza di caratteri "Albero in PreOrdine: " seguita dagli elementi
           in ordine di visita e separati dal carattere <tab>. La stampa degli 
           elementi dipende dalla definizione di `ElemType`. Se l'albero è
           vuoto i caratteri sopra elencati saranno seguiti da "vuoto!".
           
@param[in] n Albero da stampare su file. L'albero non viene modificato e può 
            essere vuoto.
@param[in] f `FILE *` su cui stampare l'albero.

@return Non ci sono valori di ritorno.
*/
void TreeWritePreOrder(const Node *n, FILE *f);

/** @brief La funzione `TreeWriteStdoutPreOrder()` stampa l'albero specificato su 
           `stdout`, visitandolo in pre-ordine. Nello specifico, la funzione stampa la
           sequenza di caratteri "Albero in PreOrdine: " seguita dagli elementi
           in ordine di visita e separati dal carattere <tab>. La stampa degli 
           elementi dipende dalla definizione di `ElemType`. Se l'albero è vuoto
           i caratteri sopra elencati saranno seguiti da "vuoto!".

@param[in] n Albero da stampare su `stdout`. L'albero non viene modificato e 
            può essere vuoto.

@return Non ci sono valori di ritorno.
*/
void TreeWriteStdoutPreOrder(const Node *n);

/** @brief La funzione `TreeWriteInOrder()` stampa l'albero specificato su file,
           visitandolo in ordine. Nello specifico, la funzione stampa la
           sequenza di caratteri "Albero in Ordine: " seguita dagli elementi
           in ordine di visita e separati dal carattere <tab>. La stampa degli 
           elementi dipende dalla definizione di `ElemType`. Se l'albero è vuoto
           i caratteri sopra elencati saranno seguiti da "vuoto!".

@param[in] n Albero da stampare su file. L'albero non viene modificato e può
            essere vuoto.
@param[in] f `FILE *` su cui stampare l'albero.

@return Non ci sono valori di ritorno.
*/
void TreeWriteInOrder(const Node *n, FILE *f);

/** @brief La funzione `TreeWriteStdoutInOrder()` stampa l'albero specificato su
           `stdout`, visitandolo in ordine. Nello specifico, la funzione stampa la
           sequenza di caratteri "Albero in Ordine: " seguita dagli elementi
           in ordine di visita e separati dal carattere <tab>. La stampa degli 
           elementi dipende dalla definizione di `ElemType`. Se l'albero è vuoto
           i caratteri sopra elencati saranno seguiti da "vuoto!".

@param[in] n Albero da stampare su `stdout`. L'albero non viene modificato e può
            essere vuoto.

@return Non ci sono valori di ritorno.
*/
void TreeWriteStdoutInOrder(const Node *n);

/** @brief La funzione `TreeWritePostOrder()` stampa l'albero specificato su file,
           visitandolo in post-ordine. Nello specifico, la funzione stampa la
           sequenza di caratteri "Albero in PostOrdine: " seguita dagli elementi
           in ordine di visita e separati dal carattere <tab>. La stampa degli 
           elementi dipende dalla definizione di `ElemType`. Se l'albero è vuoto
           i caratteri sopra elencati saranno seguiti da "vuoto!".

@param[in] n Albero da stampare su file. L'albero non viene modificato e può
            essere vuoto.
@param[in] f `FILE *` su cui stampare l'albero.

@return Non ci sono valori di ritorno.
*/
void TreeWritePostOrder(const Node *n, FILE *f);

/** @brief La funzione `TreeWriteStdoutPostOrder()` stampa l'albero specificato su
           `stdout`, visitandolo in post-ordine. Nello specifico, la funzione stampa la
           sequenza di caratteri "Albero in PostOrdine: " seguita dagli elementi
           in ordine di visita e separati dal carattere <tab>. La stampa degli 
           elementi dipende dalla definizione di `ElemType`. Se l'albero è vuoto
           i caratteri sopra elencati saranno seguiti da "vuoto!".

@param[in] n Albero da stampare su `stdout`. L'albero non viene modificato e può
            essere vuoto.

@return Non ci sono valori di ritorno.
*/
void TreeWriteStdoutPostOrder(const Node *n);

#endif // TREE_H_

