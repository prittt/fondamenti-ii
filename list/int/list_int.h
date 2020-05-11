#ifndef LIST_INT_H_
#define LIST_INT_H_

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definizione del tipo di dato da usare nella lista e funzioni annesse
typedef struct {
    int* data;
    size_t size; 
} ElemType;

// Confronta due elementi e ritorna -1 se a < b, 0 se a = b e 1 se a > b
int ElemCompare(const ElemType *e1, const ElemType *e2)
{
    return (e1 > e2) - (e1 < e2);
}

ElemType* ElemCopy(const ElemType *e)
{
    ElemType *new_elem = malloc(sizeof(ElemType));
    *new_elem = *e;
    //memcpy(new_elem.data, e->data, sizeof(int)*e->size);
    return *new_elem;
}

void ElemDelete(ElemType *a)
{
    free(a.)
    return *a;
}

typedef struct Item {
    ElemType value;
    struct Item *next;
}Item;



/** @brief La funzione EmptyList crea e ritorna una lista vuota (NULL pointer)

@return Lista vuota (NULL pointer) 
*/
Item* EmptyList(void) {
    return NULL;
}

/** @brief La funzione Cons aggiunge un nuovo elemento in testa ad una lista data e ritorna il 
            puntatore alla nuova testa della lista.

@param e Elemento da aggiugnere.
@param l Puntatore alla testa della lista a cui aggiungere il nuovo elemento. La
         lista puo' essere vuota (NULL pointer).

@return Puntatore nuova testa della lista.
*/
Item* Cons(ElemType e, Item* l) {
    Item *t = malloc(sizeof(Item));
    t->value = Copy(e);
    t->next = l;
    return t;
}

/** @brief La funzione IsEmpty verifica se una lista è vuota o meno.

@param l Puntatore alla testa della lista da verificare.

@return true se la lista e' vuota, false altrimenti.
*/
bool IsEmpty(Item *l) {
    return (l == NULL);
}

/** @brief La funzione Head ritorna l'elemento in testa ad una lista senza 
           rimuoverlo dalla lista.

@param l Puntatore alla testa della lista da cui estrarre l'elemento in testa.
         Nel caso in cui la lista specificata sia vuota la funzione termina il 
         programma con codice di errore 1.

@returns Elemento in testa alla lista.
*/
ElemType Head(Item *l) {
    if (IsEmpty(l)) {
        printf("ERROR: Alla funzione 'Head()' è stata passata una lista vuota (NULL pointer).\n");
        exit(1);
    }
    else {
        return l->value;
    }
}

/** @brief La funzione Tail ritorna una lista privata dell'elemento in testa. La funzione NON dealloca 
           la memoria occupata dall'elemento in testa alla lista data.

@param l Puntatore alla testa della lista da cui eliminare l'elemento in testa.
         Nel caso in cui la lista specificata sia vuota la funzione termina il
         programma con codice di errore 2.

@return Puntatore alla testa della lista ottenuta dopo l'eliminazione dell'elemento in testa. 
        Il valore di ritorno potrebbe essere una lista vuota.
*/
Item* Tail(Item* l) {
    if (IsEmpty(l)) {
        printf("ERROR: Alla funzione 'Tail()' è stata passata una lista vuota (NULL pointer).\n");
        exit(2);
    }
    else {
        return l->next;
    }
}


/** @brief La funzione InsertBack aggiunge un elemento in coda ad una lista (anche vuota) 
           e ritorna la lista risultante.

@param l Puntatore alla testa della lista a cui aggiungere l'elemento. La 
         lista puo' essere vuota (NULL pointer).
@param e Elemento da aggiungere alla lista l.

@return Puntatore alla testa della lista ottenuta dopo l'aggiunta dell'elemento.
*/
Item* InsertBack(Item* l, const ElemType *e) {
    
    Item* n = Cons(e, EmptyList());

    if (IsEmpty(l)) {
        return n;
    }

    Item* tmp = l;
    while (!IsEmpty(Tail(tmp))) {
        tmp = Tail(tmp);
    }

    tmp->next = n;
    return l;
}

/** @brief Dato un puntatore alla testa di una lista, la funzrion FreeList libera la memoria 
           occupata dai suoi elementi.

@param l Puntatore alla testa della lista di cui liberare la memoria.

@return Nothing
*/
void FreeList(Item* l) {
    while (!IsEmpty(l)) {
        Item* tmp = l;
        l = l->next;
        free(tmp);
    }
}

#endif // !LIST_COORDS_H_

