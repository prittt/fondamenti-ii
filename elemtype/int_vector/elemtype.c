#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

#include <string.h>
#include <stdlib.h>

int ElemCompare(const ElemType *e1, const ElemType *e2) {
    for (size_t i = 0; i < e1->size && i < e2->size; ++i) {
        if (e1->data[i] != e2->data[i]) {
            return (e1->data[i] > e2->data[i]) - (e1->data[i] < e2->data[i]);
        }
    } 

    return (int)(e1->size - e2->size);
}

ElemType ElemCopy(const ElemType *e) {
    ElemType copy = { .size = e->size,.data = malloc(sizeof(int) * e->size) };
    memcpy(copy.data, e->data, sizeof(int)*e->size);
    return copy;
}

void ElemSwap(ElemType *e1, ElemType *e2) {
    ElemType tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}

void ElemDelete(ElemType *e) {
    free(e->data);
}

int ElemRead(FILE *f, ElemType *e) {
    int ret = fscanf(f, "%zu", &e->size);
    e->data = NULL;
    if (ret == 1){
        e->data = malloc(sizeof(int)*e->size);
        for (size_t i = 0; i < e->size; ++i) {
            if (!fscanf(f, "%i", &e->data[i])) { 
                return 0;
            }
        }
    }
    return ret;
}

int ElemReadStdin(ElemType *e) {
    return ElemRead(stdin, e);
}

void ElemWrite(const ElemType *e, FILE *f) {
    fprintf(f, "[");
    for (size_t i = 0; i < e->size; ++i) {
        fprintf(f, "%i", e->data[i]);
        if (i != e->size - 1) {
            printf(", ");
        }
    }
    fprintf(f, "]");
}

void ElemWriteStdout(const ElemType *e) {
    ElemWrite(e, stdout);
}
