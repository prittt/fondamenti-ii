#include "list_int.h"

#include <stdlib.h>

Item* CreateListFromVector(const int *v, size_t v_size) {
    Item *list = CreateEmptyList();
    for (size_t i = 0; i < v_size; ++i) {
        list = InsertBackList(list, &v[i]);
    }
    return list;
}

Item* CopyList(const Item* i) {
    Item *list_copy = CreateEmptyList(); // Creo una lista vuota (NULL pointer)

    // Itero tutti gli elementi della lista da copiare
    for (; !IsEmptyList(i); i = GetTailList(i)) {
        // Aggiungo l'elemento corrente della lista di input (i) alla nuova lista
        // usando la primitiva InsertBackList, la quale si occuperà di allocare
        // opportunamente la memoria e aggiornare i puntatori!
        list_copy = InsertBackList(list_copy, GetHeadValueList(i));
    }

    return list_copy;
}

int main(void) {
    
    int v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = CreateListFromVector(v, v_size);


    Item *list_copy = CopyList(list);

    printf("Input:\n  list: ");
    WriteStdoutList(list);
    printf("\n  head address: %p", list);
    printf("\n\nOutput (copy):\n  list: ");
    WriteStdoutList(list_copy);
    printf("\n  head address: %p", list_copy);

    DeleteList(list);
    DeleteList(list_copy);

    return EXIT_SUCCESS;
}