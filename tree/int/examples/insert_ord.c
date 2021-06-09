/** @example insert_ord.c
* In questo esempio si mostra come inserire elementi in maniera ordinata
* in un albero binario. L'albero risultante sarà un BST.
*/

#include <stdlib.h>

#include "tree.h"

Node *TreeInsertBinOrd(const ElemType *e, Node* n) {
    if (TreeIsEmpty(n)) {
        return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
    }
    Node *root = n;

    while (true) {
        if (ElemCompare(e, TreeGetRootValue(n)) < 0) {
            if (TreeIsEmpty(TreeLeft(n))) {
                n->left = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
                break;
            }
            else {
                n = TreeLeft(n);
            }
        }
        else {
            if (TreeIsEmpty(TreeRight(n))) {
                n->right = TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
                break;
            }
            else {
                n = TreeRight(n);
            }
        }
    }

    return root;
}

int main(void) {
    int v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(int);

    Node *tree = TreeCreateEmpty();
    for (unsigned i = 0; i < v_size; ++i) {
        tree = TreeInsertBinOrd(&v[i], tree);
    }

    TreeWriteStdoutPreOrder(tree);
    TreeWriteStdoutInOrder(tree);
    TreeWriteStdoutPostOrder(tree);
    TreeDelete(tree);

    return EXIT_SUCCESS;
}