#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"

#include <string.h>
#include <stdlib.h>

/*****************************************************************************/
/*                          Node & Primitives                                */
/*****************************************************************************/

Node *TreeCreateEmpty(void) {
    return NULL;
}

Node *TreeCreateRoot(const ElemType *e, Node *l, Node *r) {
    Node *t = malloc(sizeof(Node));
    t->value = ElemCopy(e);
    t->left = l;
    t->right = r;
    return t;
}

bool TreeIsEmpty(const Node *n) {
    return n == NULL;
}

const ElemType *TreeGetRootValue(const Node *n) {
    if (TreeIsEmpty(n)) {
        printf("ERROR: Alla funzione 'GetRootValueTree()' e' stato passato un albero vuoto (NULL).\n");
        exit(1);
    }
    else {
        return &n->value;
    }
}

Node *TreeLeft(const Node *n) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }
    else {
        return n->left;
    }
}

Node *TreeRight(const Node *n) {
    if (TreeIsEmpty(n)) {
        return NULL;
    }
    else {
        return n->right;
    }
}

bool TreeIsLeaf(const Node *n) {
    return TreeLeft(n) == NULL && TreeRight(n) == NULL;
}

void TreeDelete(Node *n) {
    if (TreeIsEmpty(n)) {
        return;
    }

    Node *l = TreeLeft(n);
    Node *r = TreeRight(n);

    ElemDelete(&n->value);

    free(n);

    TreeDelete(l);
    TreeDelete(r);
}

/*****************************************************************************/
/*                            Non Primitives                                 */
/*****************************************************************************/

static void TreeWritePreOrderRec(const Node *n, FILE *f) {
    if (TreeIsEmpty(n)) {
        return;
    }

    fprintf(f, "\t"); ElemWrite(TreeGetRootValue(n), f);
    TreeWritePreOrderRec(TreeLeft(n), f);
    TreeWritePreOrderRec(TreeRight(n), f);
}

void TreeWritePreOrder(const Node *n, FILE *f) {
    fprintf(f, "Albero in PreOrdine: ");
    if (TreeIsEmpty(n)) {
        fprintf(f, "vuoto!");
    }
    else {
        TreeWritePreOrderRec(n, f);
    }
    fprintf(f, "\n");
}

void TreeWriteStdoutPreOrder(const Node *n) {
    TreeWritePreOrder(n, stdout);
}

static void TreeWriteInOrderRec(const Node *n, FILE *f) {
    if (TreeIsEmpty(n)) {
        return;
    }

    TreeWriteInOrderRec(TreeLeft(n), f);

    fprintf(f, "\t"); ElemWrite(TreeGetRootValue(n), f);

    TreeWriteInOrderRec(TreeRight(n), f);

}

void TreeWriteInOrder(const Node *n, FILE *f) {
    fprintf(f, "Albero in Ordine: ");
    if (TreeIsEmpty(n)) {
        fprintf(f, "vuoto!");
    }
    else {
        TreeWriteInOrderRec(n, f);
    }
    fprintf(f, "\n");
}

void TreeWriteStdoutInOrder(const Node *n) {
    TreeWriteInOrder(n, stdout);
}

static void TreeWritePostOrderRec(const Node *n, FILE *f) {
    if (TreeIsEmpty(n)) {
        return;
    }

    TreeWritePostOrderRec(TreeLeft(n), f);
    TreeWritePostOrderRec(TreeRight(n), f);

    fprintf(f, "\t"); ElemWrite(TreeGetRootValue(n), f);
}

void TreeWritePostOrder(const Node *n, FILE *f) {
    fprintf(f, "Albero in PostOrdine: ");
    if (TreeIsEmpty(n)) {
        fprintf(f, "vuoto!");
    }
    else {
        TreeWritePostOrderRec(n, f);
    }
    fprintf(f, "\n");
}

void TreeWriteStdoutPostOrder(const Node *n) {
    TreeWritePostOrder(n, stdout);
}