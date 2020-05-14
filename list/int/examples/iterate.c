#include "list_int.h"

#include <stdlib.h>

Item* CreateListFromVector(const int *v, size_t v_size) {
    Item *list = CreateEmptyList();
    for (size_t i = 0; i < v_size; ++i) {
        list = InsertBackList(list, &v[i]);
    }
    return list;
}

int main(void) {
    
    int v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = CreateListFromVector(v, v_size);

    // Iterazione con il for usando le primitive:
    for (Item* tmp = list; !IsEmptyList(tmp); tmp = GetTailList(tmp)) {
        // Prendo il valore dell'elemento corrente della lista.
        const ElemType *e = GetHeadValueList(tmp); 
        // Se volessi un elemento modificabile potrei fare:
        // ElemType e = ElemCopy(GetHeadList(tmp));

        // E lo uso 
        // ...    
    }

    // Iterazione con il for senza la primitive:
    for (Item* tmp = list; tmp; tmp = tmp->next) {
        ElemType e = tmp->value;
        // Cose ...
    }

    // Iterazione con il while usando le primitive:
    Item* tmp = list;
    while (!IsEmptyList(tmp)) {
        const ElemType *e = GetHeadValueList(tmp);
        // Cose ...

        tmp = GetTailList(tmp);
    }

    // Iterazione con il while senza le primitive:
    /*Item**/ tmp = list;
    while (tmp) {
        ElemType e = tmp->value;
        // Cose ...
        tmp = tmp->next;
    }

    DeleteList(list);

    return EXIT_SUCCESS;
}