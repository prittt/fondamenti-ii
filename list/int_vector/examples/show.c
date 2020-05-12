#include "list_int_vector.h"

#include <stdlib.h>

Item* CreateListFromVector(const int *v, size_t v_size)
{
    Item *list = CreateEmptyList();
    for (size_t i = 0; i < v_size; ++i) {
        ElemType tmp = { .size = v_size - i,.data = malloc(sizeof(int)*(v_size - i)) };
        for (size_t j = i; j < tmp.size; ++j) {
            tmp.data[j] = v[i];
        }
        list = InsertBackList(list, &v[i]);
    }
    return list;
}

int main(void) {

    int v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = CreateListFromVector(v, v_size);

    WriteStdoutList(list);

    DeleteList(list);

    return EXIT_SUCCESS;
}