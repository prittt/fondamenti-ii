#define _CRT_SECURE_NO_WARNINGS
#include "list_int.h"

Item* LoadList(const char *filename)
{
    FILE *f;
    f = fopen(filename, "r");

    if (!f) {
        return NULL;
    }

    Item* i = CreateEmptyList();
    while (1) {
        ElemType tmp;
        if (1 != ReadElem(f, &tmp)) {
            break;
        }
        i = InsertHeadList(&tmp, i);
    }

    fclose(f);
    return i;
}

int main(void) {
    Item* list = LoadList("load_example_01.txt");

    WriteStdoutList(list);

    DeleteList(list);
}

