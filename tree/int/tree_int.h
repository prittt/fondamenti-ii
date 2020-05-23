/** @file
Definizione del tipo ElemType e dichiarazione delle funzioni ad esso associate: 
    - ElemCompare()
    - ElemCopy()
    - ElemDelete()
    - ReadElem()
    - ReadStdinElem()
    - WriteElem()
    - WriteStdoutElem()

Le suddette funzioni dipendono da come ElemType viene definito: al variare
della definizione di ElemType la dichiarazione delle funzioni non cambia, ma 
la loro definizione deve essere modificata opportunamente.

Definizione del tipo Node e delle funzioni primitive (e non) degli alberi:
    - CreateEmptyTree()
    - CreateRootTree()
    - IsEmptyTree()
    - GetRootTree()
    - LeftTree()
    - RightTree()
    - IsLeafTree()
    - DeleteTree()

    - 
    - 

La dichiarazioni e la definizione delle suddette funzioni NON deve essere
modificate al variare della definizione di ElemType.
*/

#ifndef TREE_INT_H_
#define TREE_INT_H_

#include <stdbool.h>
#include <stdio.h>

/*****************************************************************************/
/*                                 Element                                   */
/*****************************************************************************/

/** @brief Definizione del tipo ElemType. */
typedef int ElemType;

/** @brief La funzione ElemCompare confronta due elementi.

@param[in] e1 Puntatore al primo elemento di cui eseguire il confronto. Il 
              valore contenuto in e1 non viene modificato.
@param[in] e2 Puntatore al secondo elemento di cui eseguire il confronto. Il
              valore contenuto in e2 non viene modificato.

@return La funzione ritorna un valore intero che indica la relazione tra i due
        elementi, ovvero:
         - -1 se il contenuto del primo e' minore di quello del secondo;
         -  0 se i contenuti dei due elementi sono uguali
         -  1 se il contenuto del primo e' maggiore di quello del secondo;
*/
int ElemCompare(const ElemType *e1, const ElemType *e2);

/** @brief La funzione ElemCopy crea e ritorna una copia dell'elemento dato.

@param[in] e Puntatore all'elemento da copiare. Il valore contenuto in e non 
             viene modificato.

@return Copia dell'elemento e.
*/
ElemType ElemCopy(const ElemType *e);

/** @brief La funzione ElemDelete libera la memoria occupata dall'elemento
           specificato.

@param[in] e Puntatore all'elemento di cui liberare la memoria.

@return Non ci sono valori di ritorno.
*/
void ElemDelete(ElemType *e);

/** @brief La funzione ReadElem legge un elemento da file.

@param[in] f FILE * da cui leggere un elemento.
@param[out] e Elemento letto da file.

@return Numero di elementi effettivamente letti (0 o 1).
*/
int ReadElem(FILE *f, ElemType *e);

/** @brief La funzione ReadStdinElem legge un elemento da standard input.

@param[out] e Elemento letto da standard input.

@return Numero di elementi effettivamente letti (0 o 1).
*/
int ReadStdinElem(ElemType *e);

/** @brief La funzione WriteElem stampa un elemento su file.

@param[in] e Puntatore all'elemento da stampare su file. Il valore contenuto in
             e non viene modificato.
@param[in] f FILE * su cui stampare l'elemento.

@return Non ci sono valori di ritorno.
*/
void WriteElem(const ElemType *e, FILE *f);

/** @brief La funzione PrintStdoutElem stampa un elemento su standard output.

@param[in] e Puntatore all'elemento da stampare su standard output. Il valore
             contenuto in e non viene modificato.

@return Non ci sono valori di ritorno.
*/
void WriteStdoutElem(const ElemType *e);

/*****************************************************************************/
/*                          Node & Primitives                                */
/*****************************************************************************/

/** @brief Definizione del tipo Node. */
struct Node
{
    ElemType value; /*!< Valore associato al nodo */
    struct Node *left; /*!< Puntatore al figlio sinistro del nodo */
    struct Node *right; /*!< Puntatore al figlio destro del nodo */
};
typedef struct Node Node;

/** @brief La funzione CreateEmptyTree crea e ritorna un albero vuoto, ovvero
           NULL pointer.

@return Albero vuoto appena creato (NULL pointer).
*/
Node* CreateEmptyTree(void);

/** @brief La funzione CreateRootTree crea un nuovo albero avente come radice 
           il valore specificato e come figli sinistro e destro i sottoalberi
           dati. La funzione ritorna quindi il puntatore al nodo radice
           dell'albero appena creato.

@param[in] e Puntatore all'elemento il cui valore sara' copiato nel nodo radice del
           nuovo albero.
@param[in] l Puntatore al nodo che diventera' il figlio sinistro del nuovo albero. 
           Il valore contenuto in l non viene modificato. l puo'
           puntare ad un albero vuoto (NULL pointer).
@param[in] r Puntatore al nodo che diventera' il figlio destro del nuovo albero.
           Il valore contenuto in r non viene modificato. r puo'
           puntare ad un albero vuoto (NULL pointer).

@return Puntatore al nodo radice dell'albero appena creato.
*/
Node* CreateRootTree(const ElemType *e, Node* l, Node* r);

/** @brief La funzione IsEmptyTree verifica se un albero e' vuoto o meno.

@param[in] n Puntatore al nodo radice dell'albero da verificare.

@return true se l'albero e' vuoto, false altrimenti.
*/
bool IsEmptyTree(const Node *n);

/** @brief La funzione GetRootTree ritorna un puntatore all'elemento contentuto
           nel nodo radice dell'albero specificato.

@param[in] n Puntatore al nodo radice dell'albero. L'albero non puo' essere vuoto,
           nel caso in cui lo sia la funzione termina il programma con codice di
           errore 1.

@returns Puntatore costante all'elemento contenuto nel nodo radice dell'albero.
*/
const ElemType* GetRootTree(const Node *n);

/** @brief La funzione LeftTree ritorna un puntatore al nodo figlio (sinistro)
           dell'albero specificato.

@param[in] n Puntatore al nodo radice dell'albero da cui ottenere il figlio sinistro.
          Puo' essere un nodo vuoto (NULL pointer). Il nodo n non viene modificato.

@returns Puntatore al nodo figlio (sinistro) dell'albero specificato. Se l'albero
         specificato e' vuoto o non ha un figlio sinistro la funzione ritorna NULL;
*/
Node* LeftTree(const Node *n);

/** @brief La funzione RightTree ritorna un puntatore al nodo figlio (destro)
           dell'albero specificato.

@param[in] n Puntatore al nodo radice dell'albero da cui ottenere il figlio destro.
           Puo' essere un nodo vuoto (NULL pointer). Il nodo n non viene modificato.

@returns Puntatore al nodo figlio (destro) dell'albero specificato. Se l'albero
         specificato e' vuoto o non ha un figlio destro la funzione ritorna NULL;
*/
Node* RightTree(const Node *n);

/** @brief La funzione IsLeafTree verifica se il nodo specificato e' una foglia
           oppure no.

@param[in] n Puntatore al nodo da verificare. Puo' essere un nodo vuoto (NULL pointer). 
           Il nodo n non viene modificato.

@returns true se il nodo e' una foglia, ovvero se e' un nodo vuoto (NULL pointer)
         o se entrambi i suoi figli (sinistro e destro) sono nodi vuoti (NULL 
         pointer).
*/
bool IsLeafTree(const Node *n);

/** @brief La funzione DeleteTree libera la memoria occupata dai nodi di un 
           albero.

@param[in] n Puntatore al nodo radice dell'albero di cui liberare la memoria. 
           Puo' essere un albero vuoto (NULL pointer).

@return Non ci sono valori di ritorno.
*/
void DeleteTree(Node *n);

/*****************************************************************************/
/*                             Non Primitive                                 */
/*****************************************************************************/

/** @brief La funzione WriteList stampa la lista specificata su file.

@param i Puntatore all'item in testa alla lista da stampare su file. La lista
         non viene modificata. La lista puo' essere vuota.
@param f FILE * su cui stampare la lista.

@return Non ci sono valori di ritorno.
*/
//void WriteList(const Item *i, FILE *f);

/** @brief La funzione WriteStdoutList stampa la lista specificata su standard
           output.

@param i Puntatore all'item in testa alla lista da stampare su standard output.
         La lista non viene modificata. La lista puo' essere vuota.

@return Non ci sono valori di ritorno.
*/
//void WriteStdoutList(const Item *i);

#endif // TREE_INT_H_

