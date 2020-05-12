// Per controllare eventuali memory leak
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include "list_int.h"

#include <stdlib.h>

/*****************************************************************************/
/*                               IS MEMBER                                   */
/*****************************************************************************/

bool IsMember(const ElemType *e, Item* i)
{
    while (!IsEmptyList(i)) {
        if (ElemCompare(e, GetHeadValueList(i)) == 0) {
            return true;
        }

        i = GetTailList(i);
    }
    return false;
}

bool IsMemberRec(const ElemType *e, Item* i)
{
    if (IsEmptyList(i)) {
        return false;
    }

    if (ElemCompare(e, GetHeadValueList(i)) == 0) {
        return true;
    }

    return IsMemberRec(e, GetTailList(i));
}

/*****************************************************************************/
/*                                 LENGHT                                    */
/*****************************************************************************/
int Length(Item* i)
{
    int n = 0;
    while (!IsEmptyList(i)) {
        n++;
        i = GetTailList(i);
    }
    return n;
}

int LengthRec(Item* i)
{
    if (IsEmptyList(i)) {
        return 0;
    }

    return 1 + LengthRec(GetTailList(i));
}

/*****************************************************************************/
/*                                 APPEND                                    */
/*****************************************************************************/
Item* AppendRec(Item* i1, Item* i2)
{
    if (IsEmptyList(i1)) {
        return i2;
    }

    Item* tmp = InsertHeadList(GetHeadValueList(i1), AppendRec(GetTailList(i1), i2));
    free(i1);
    return tmp;
}

/*****************************************************************************/
/*                                  COPY                                     */
/*****************************************************************************/
Item* CopyRec(Item* i)
{
    if (IsEmptyList(i)) {
        return i;
    }
    return InsertHeadList(GetHeadValueList(i), CopyRec(GetTailList(i)));
}

/*****************************************************************************/
/*                                 REMOVE                                    */
/*****************************************************************************/
Item* RemoveRec(const ElemType* e, Item* i)
{
    if (IsEmptyList(i)) {
        return i;
    }

    if (ElemCompare(e, GetHeadValueList(i)) == 0) {
        Item* tmp = GetTailList(i);
        free(i);
        return tmp;
    }
    
    Item* tmp = InsertHeadList(GetHeadValueList(i), RemoveRec(e, GetTailList(i)));
    free(i);
    return tmp;
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
    Item *other_list = CreateListFromVector(v, v_size - 5);

    ElemType e;
    bool ret;

    e = 5;
    ret = IsMember(&e, list);
    ret = IsMemberRec(&e, list);
    e = 11;
    ret = IsMember(&e, list);
    ret = IsMemberRec(&e, list);

    int len;
    len = Length(list);
    len = LengthRec(list);

    WriteStdoutList(list);
    WriteStdoutList(other_list);
    list = AppendRec(list, other_list);
    WriteStdoutList(list);

    other_list = CopyRec(list);
    WriteStdoutList(other_list);

    e = 1;
    list = RemoveRec(&e, list);
    WriteStdoutList(list);

    e = 5;
    list = RemoveRec(&e, list);
    WriteStdoutList(list);

    DeleteList(list);
    DeleteList(other_list);

    // Per controllare eventuali memory leak
    //_CrtDumpMemoryLeaks();

    return EXIT_SUCCESS;
}