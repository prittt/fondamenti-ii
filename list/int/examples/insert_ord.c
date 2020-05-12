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


Item* CreateListFromVector(const int *v, size_t v_size)
{
    Item *list = CreateEmptyList();
    for (size_t i = 0; i < v_size; ++i) {
        list = InsertBackList(list, &v[i]);
    }
    return list;
}

int main(void)
{

    int v[] = { 1,2,3,4,5,6,7,8,9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Item *list = CreateListFromVector(v, v_size);


    DeleteList(list);

    return EXIT_SUCCESS;
}