#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "list_int.h"

#include <stdlib.h>

Item* InsOrdRec(const ElemType *e, Item *i)
{
    if (IsEmptyList(i) || ElemCompare(GetHeadList(i), e) >= 0) {
        return InsertHeadList(e, i);
    }
    Item* tmp = InsertHeadList(GetHeadList(i), InsOrdRec(e, GetTailList(i)));
    free(i);
    return tmp;
}

Item* InsOrd(const ElemType *e, Item *i)
{

    if (IsEmptyList(i) || ElemCompare(GetHeadList(i), e) >= 0) {
        return InsertHeadList(e, i);
    }

    Item* root = i;
    Item* prev = CreateEmptyList();
    Item* new_item = InsertHeadList(e, CreateEmptyList());

    while (!IsEmptyList(i) && ElemCompare(GetHeadList(i), e) < 0) {
        prev = i;
        i = GetTailList(i);
    }
    prev->next = new_item;
    new_item->next = i;
    return root;
}

int main(void)
{
    Item* i = CreateEmptyList();
    Item* i_rec = CreateEmptyList();
    ElemType e;
    do {
        printf("Introdurre valore:\t");
        e = ReadStdinElem();
        i = InsOrd(&e, i);
        i_rec = InsOrdRec(&e, i_rec);
    } while (e != 0); // Condizione di uscita arbitraria
    WriteStdoutList(i);
    WriteStdoutList(i_rec);

    DeleteList(i);
    DeleteList(i_rec);

    _CrtDumpMemoryLeaks();

    return EXIT_SUCCESS;
}