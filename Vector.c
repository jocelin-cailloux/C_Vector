#include <assert.h>
#include <stdlib.h>

#include "Vector.h"

Vector *newVector() {
    Vector *vec = malloc(sizeof(Vector));
    vec->maxEl = 2;
    vec->nbEl = 0;
    vec->items = malloc(vec->maxEl*sizeof(void *));
}

int vector_length(Vector *vec) {
    return vec->nbEl;
}

void *vector_get(Vector *vec, int pos) {
    return vec->items[pos];
}

void *vector_set(Vector *vec, int pos, void *item) {
    vec->items[pos] = item;
}

void vector_push(Vector *vec, void *item) {
    if (vec->nbEl == vec->maxEl) {
        vec->maxEl *= 2;
        vec->items = (void *) realloc(vec->items, vec->maxEl*sizeof(void *));
        assert(vec->items != NULL);
    }
    vec->items[vec->nbEl] = item;
    vec->nbEl += 1;
}

void vector_slowPushAt(Vector *vec, int pos, void *item) {
    if (vec->nbEl == vec->maxEl) {
        vec->maxEl *= 2;
        vec->items = (void *) realloc(vec->items, vec->maxEl*sizeof(void *));
        //assert(vec->items != NULL);
    }
    for (int i = vec->nbEl; i > pos ; i -= 1) {
        vec->items[i] = vec->items[i-1];
    }
    vec->nbEl += 1;
    vec->items[pos] = item;
}

void vector_pushAt(Vector *vec, int pos, void *item) {
    if (vec->nbEl == vec->maxEl) {
        vec->maxEl *= 2;
        vec->items = (void *) realloc(vec->items, vec->maxEl*sizeof(void *));
        //assert(vec->items != NULL);
    }
    vec->items[vec->nbEl] = vec->items[pos];
    vec->nbEl += 1;
    vec->items[pos] = item;
}

void vector_pop(Vector *vec, deleteFunction *deleteFun) {
    vec->nbEl -= 1;
    if (deleteFun != NULL) {
        deleteFun(vec->items[vec->nbEl]);
    }
}

void vector_slowPopAt(Vector *vec, int pos, deleteFunction *deleteFun) {
    vec->nbEl -= 1;
    if (deleteFun != NULL) {
        deleteFun(vec->items[pos]);
    }
    for (int i = pos; i < vec->nbEl; i += 1) {
        vec->items[i] = vec->items[i+1];
    }
}

void vector_popAt(Vector *vec, int pos, deleteFunction *deleteFun) {
    vec->nbEl -= 1;
    if (deleteFun != NULL) {
        deleteFun(vec->items[pos]);
    }
    vec->items[pos] = vec->items[vec->nbEl];
}

void vector_free(Vector *vec, deleteFunction *deleteFun) {
    if (deleteFun != NULL) {
        for (int i = 0; i < vec->nbEl; i += 1) {
            deleteFun(vec->items[i]);
        }
    }
    free(vec->items);
}