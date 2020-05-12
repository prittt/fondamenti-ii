#include "list_int.h"

#include <stdlib.h>

Item* InsOrdRec(const ElemType *e, Item *i)
{
    if (IsEmptyList(i) || ElemCompare(GetHeadValueList(i), e) >= 0) {
        return InsertHeadList(e, i);
    }
    Item* tmp = InsertHeadList(GetHeadValueList(i), InsOrdRec(e, GetTailList(i)));
    free(i);
    return tmp;
}

Item* InsOrd(const ElemType *e, Item *i)
{
    if (IsEmptyList(i) || ElemCompare(GetHeadValueList(i), e) >= 0) {
        return InsertHeadList(e, i);
    }

    Item* root = i;
    Item* prev = CreateEmptyList();
    Item* new_item = InsertHeadList(e, CreateEmptyList());

    while (!IsEmptyList(i) && ElemCompare(GetHeadValueList(i), e) < 0) {
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
    // Acquisizione di elementi da stdin
    do {
        printf("Introdurre un valore intero: ");
        e = ReadStdinElem();
        i = InsOrd(&e, i);
        i_rec = InsOrdRec(&e, i_rec);
    } while (e != 0); // L'acquisizione termina quando viene inserito lo zero.
    WriteStdoutList(i);
    WriteStdoutList(i_rec);

    DeleteList(i);
    DeleteList(i_rec);

    return EXIT_SUCCESS;
}