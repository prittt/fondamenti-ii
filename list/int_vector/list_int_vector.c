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

#endif // LIST_INT_H_

