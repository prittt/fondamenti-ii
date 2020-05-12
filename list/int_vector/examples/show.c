// Per controllare eventuali memory leaks
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include "list_int_vector.h"

#include <stdlib.h>

Item* CreateListFromVector(const int *v, size_t v_size)
{
    Item *list = CreateEmptyList();
    for (size_t i = 0; i < v_size; ++i) {
        ElemType tmp = { .size = v_size - i,.data = malloc(sizeof(int)*(v_size - i)) };
        for (size_t j = i; j < v_size; ++j) {
            tmp.data[j - i] = v[j];
        }
        list = InsertBackList(list, &tmp);
        ElemDelete(&tmp);
    }
    return list;
}

int main(void) {

    int v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = CreateListFromVector(v, v_size);

    WriteStdoutList(list);

    DeleteList(list);

    // Per controllare eventuali memory leaks
    //_CrtDumpMemoryLeaks();

    return EXIT_SUCCESS;
}