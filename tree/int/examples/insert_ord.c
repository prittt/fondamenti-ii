#include <stdlib.h>

#include "tree_int.h"

Node* InsertBinOrd(const ElemType *e, Node* n)
{
    if (IsEmptyTree(n)) {
        return CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
    }
    Node *root = n;

    while (true) {
        if (ElemCompare(e, GetRootTree(n)) < 0) {
            if (IsEmptyTree(LeftTree(n))) {
                n->left = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
                break;
            }
            else {
                n = LeftTree(n);
            }
        }
        else {
            if (IsEmptyTree(RightTree(n))) {
                n->right = CreateRootTree(e, CreateEmptyTree(), CreateEmptyTree());
                break;
            }
            else {
                n = RightTree(n);
            }
        }
    }

    return root;
}

int main(void) {
    int v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(int);

    Node *tree = CreateEmptyTree();
    for (unsigned i = 0; i < v_size; ++i) {
        tree = InsertBinOrd(&v[i], tree);
    }

    return EXIT_SUCCESS;
}