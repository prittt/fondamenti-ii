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

Definizione del tipo Item e delle funzioni primitive (e non) delle liste:
    - CreateEmptyList()
    - InsertHeadList()
    - IsEmptyList()
    - GetHeadValueList()
    - GetTailList()
    - InsertBackList()
    - DeleteList()

    - WriteList()
    - WriteStdoutList()

La dichiarazione e la definizione delle suddette funzioni NON devono essere
modificate al variare della definizione di ElemType.
*/

#ifndef LIST_INT_H_
#define LIST_INT_H_

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
/*                          Item & Primitives                                */
/*****************************************************************************/

/** @brief Definizione del tipo Item. */
struct Item
{
    ElemType value; /*!< Valore associato all'item */
    struct Item *next; /*!< Puntatore all'item successivo */
};
typedef struct Item Item;

/** @brief La funzione CreateEmptyList crea e ritorna una lista vuota, ovvero
           NULL pointer.

@return Lista vuota appena creata (NULL pointer).
*/
Item* CreateEmptyList(void);

/** @brief La funzione InsertHeadList aggiunge un nuovo elemento in testa ad 
           una lista data e ritorna il puntatore alla nuova testa della lista.

@param[in] e Puntatore all'elemento da aggiugnere in testa alla lista.
@param[in] i Puntatore all'item in testa alla lista a cui aggiungere il nuovo 
         elemento. Il valore contenuto in i non viene modificato. i puo'
         puntare ad una lista vuota (NULL pointer).

@return Puntatore all'item in testa alla lista ottenuta dopo l'aggiunta.
*/
Item* InsertHeadList(const ElemType *e, Item* i);

/** @brief La funzione IsEmptyList verifica se una lista data e' vuota o meno.

@param[in] i Puntatore all'item in testa alla lista da verificare.

@return true se la lista e' vuota, false altrimenti.
*/
bool IsEmptyList(const Item *i);

/** @brief La funzione GetHeadList ritorna un puntatore all'elemento in testa 
            ad una lista data senza rimuoverlo dalla lista.

@param[in] i Puntatore all'item in testa alla lista. La lista non puo' essere vuota,
         nel caso in cui lo sia la funzione termina il programma con codice di 
         errore 1.

@returns Puntatore costante all'elemento in testa alla lista.
*/
const ElemType* GetHeadValueList(const Item *i);

/** @brief La funzione GetTailList ritorna la lista privata dell'elemento in 
           testa. La funzione NON dealloca la memoria occupata dall'elemento.

@param[in] i Puntatore all'item in testa alla lista da cui eliminare la testa. La 
         lista non puo' essere vuota, nel caso in cui lo sia la funzione termina
         il programma con codice di errore 2. 

@return Puntatore all'item in testa alla lista ottenuta dopo l'eliminazione.
        Il valore di ritorno potrebbe essere una lista vuota (NULL pointer).
*/
Item* GetTailList(const Item* i);


/** @brief La funzione InsertBackList aggiunge un elemento in coda ad una lista 
           (anche vuota) e ritorna la lista risultante.

@param[in] i Puntatore all'item in testa alla lista a cui aggiungere l'elemento 
         specifciato. La lista puo' essere vuota (NULL pointer).
@param[in] e Puntatore all'elemento da aggiugnere in testa alla lista. Il valore 
         contenuto in e non viene modificato.

@return  Puntatore all'item in testa alla lista ottenuta dopo l'aggiunta 
         dell'elemento.
*/
Item* InsertBackList(Item* i, const ElemType *e);

/** @brief La funzione DeleteList libera la memoria occupata dagli elementi di 
           una lista.

@param[in] i Puntatore all'item in testa alla lista di cui liberare la memoria. 
         Puo' essere una lista vuota (NULL pointer).

@return Non ci sono valori di ritorno.
*/
void DeleteList(Item* i);

/*****************************************************************************/
/*                             Non Primitives                                */
/*****************************************************************************/

/** @brief La funzione WriteList stampa la lista specificata su file.

@param[in] i Puntatore all'item in testa alla lista da stampare su file. La lista
         non viene modificata. La lista puo' essere vuota.
@param[in] f FILE * su cui stampare la lista.

@return Non ci sono valori di ritorno.
*/
void WriteList(const Item *i, FILE *f);

/** @brief La funzione WriteStdoutList stampa la lista specificata su standard
           output.

@param[in] i Puntatore all'item in testa alla lista da stampare su standard output.
         La lista non viene modificata. La lista puo' essere vuota.

@return Non ci sono valori di ritorno.
*/
void WriteStdoutList(const Item *i);

#endif // LIST_INT_H_

