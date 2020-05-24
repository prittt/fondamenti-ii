#include <stdlib.h>

#include "tree_int.h"

// Per ogni nodo (elemento i-esimo del vettore) considero come figlio sinistro
// l'elemento del vettore di indice i * 2 + 1, e come figlio destro l'elemento
// di indice i * 2 + 2.
Node* CreateTreeFromVectorRec(const int *v, size_t v_size, int i)
{
    if (i >= (int)v_size) {
        return NULL;
    }

    Node *l = CreateTreeFromVectorRec(v, v_size, i * 2 + 1);
    Node *r = CreateTreeFromVectorRec(v, v_size, i * 2 + 2);

    return CreateRootTree(&v[i], l, r);
}

Node* CreateTreeFromVector(const int *v, size_t v_size)
{
    return CreateTreeFromVectorRec(v, v_size, 0);
}


int main(void)
{
    int v[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    size_t v_size = sizeof(v) / sizeof(int);
    Node *tree = CreateEmptyTree();
    
    WriteStdoutPreOrderTree(tree);
    WriteStdoutInOrderTree(tree);
    WriteStdoutPostOrderTree(tree);

    tree = CreateTreeFromVector(v, v_size);

    WriteStdoutPreOrderTree(tree);
    WriteStdoutInOrderTree(tree);
    WriteStdoutPostOrderTree(tree);
     
    DeleteTree(tree);

    return EXIT_SUCCESS;
}