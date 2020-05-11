/** @file 
Dichiarazione del tipo ElemType e delle funzioni associate che dipendono dal
tipo scelto: ElemCompare, ElemCopy, ElemDelete, GetElem, GetStdinElem,
PrintElem, PrintStdoutElem. 

Dichiarazione del tipo Item e delle primitive delle liste:
*/
#ifndef LIST_INT_H_
#define LIST_INT_H_

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************************************/
/*                                 Element                                   */
/*****************************************************************************/    

typedef int ElemType;

/** @brief La funzione ElemCompare confronta due elementi.

@return La funzione ritorna un valore intero che indica la relazione tra i due 
        elementi, ovvero: 
         * -1 se il contenuto del primo è minore di quello del secondo;
         *  0 se i contenuti dei due elementi sono uguali
         *  1 se il contenuto del primo è maggiore di quello del secondo;
*/
int ElemCompare(const ElemType *e1, const ElemType *e2)
{
    return (e1 > e2) - (e1 < e2);
}

ElemType ElemCopy(const ElemType *e)
{
    return *e;
    //ElemType new_elem;
    //new_elem.data = malloc(sizeof(int)*e->size);
    //new_elem.size = e->size;
    //memcpy(new_elem.data, e->data, sizeof(int)*e->size);
    //return new_elem;
}

void ElemDelete(ElemType *e)
{
    //free(e->data);
}

ElemType GetElem(FILE *f)
{
    ElemType e;
    fscanf(f, "%d", &e);
    return e;
}

ElemType GetStdinElem()
{
    return 
}

void StdoutElem(const ElemType *e, )
{
    printf("%d", *e);
}


struct Item{
    ElemType value;
    struct Item *next;
};
typedef struct Item Item;

/** @brief La funzione EmptyList crea e ritorna una lista vuota (NULL pointer)

@return Lista vuota (NULL pointer)
*/
Item* CreateEmptyList(void)
{
    return NULL;
}

/** @brief La funzione Cons aggiunge un nuovo elemento in testa ad una lista data e ritorna il
            puntatore alla nuova testa della lista.

@param e Elemento da aggiugnere.
@param l Puntatore alla testa della lista a cui aggiungere il nuovo elemento. La
         lista puo' essere vuota (NULL pointer).

@return Puntatore nuova testa della lista.
*/
Item* InsertHeadList(const ElemType *e, Item* l)
{
    Item *t = malloc(sizeof(Item));
    t->value = ElemCopy(e);
    t->next = l;
    return t;
}

/** @brief La funzione IsEmpty verifica se una lista è vuota o meno.

@param l Puntatore alla testa della lista da verificare.

@return true se la lista e' vuota, false altrimenti.
*/
bool IsEmptyList(Item *l)
{
    return l == NULL;
}

/** @brief La funzione Head ritorna l'elemento in testa ad una lista senza
           rimuoverlo dalla lista.

@param l Puntatore alla testa della lista da cui estrarre l'elemento in testa.
         Nel caso in cui la lista specificata sia vuota la funzione termina il
         programma con codice di errore 1.

@returns Elemento in testa alla lista.
*/
ElemType GetHeadList(Item *i)
{
    if (IsEmptyList(i)) {
        printf("ERROR: Alla funzione 'GetHead()' è stata passata una lista vuota (NULL pointer).\n");
        exit(1);
    }
    else {
        return ElemCopy(i->value);
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
Item* GetTailList(Item* i)
{
    if (IsEmptyList(i)) {
        printf("ERROR: Alla funzione 'GetTail()' è stata passata una lista vuota (NULL pointer).\n");
        exit(1);
    }
    else {
        return i->next;
    }
}


/** @brief La funzione InsertBack aggiunge un elemento in coda ad una lista (anche vuota)
           e ritorna la lista risultante.

@param l Puntatore alla testa della lista a cui aggiungere l'elemento. La
         lista puo' essere vuota (NULL pointer).
@param e Elemento da aggiungere alla lista l.

@return Puntatore alla testa della lista ottenuta dopo l'aggiunta dell'elemento.
*/
Item* InsertBackList(Item* i, const ElemType *e)
{

    Item* n = Cons(e, CreateEmptyList());

    if (IsEmptyList(i)) {
        return n;
    }

    Item* tmp = i;
    while (!IsEmpty(Tail(tmp))) {
        tmp = Taii(tmp);
    }

    tmp->next = n;
    return i;
}

/** @brief Dato un puntatore alla testa di una lista, la funzrion FreeList libera la memoria
           occupata dai suoi elementi.

@param l Puntatore alla testa della lista di cui liberare la memoria.

@return Nothing
*/
void DeleteList(Item* item)
{
    while (!IsEmptyList(item)) {
        Item* tmp = item;
        item = item->next;
        free(tmp);
    }
}

#endif // LIST_INT_H_

