
#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector {
    void **items;
    unsigned int nbEl;
    unsigned int maxEl;
} Vector;

Vector *newVector();

typedef void deleteFunction(void *item);

int vector_size(Vector *vec);

void *vector_get(Vector *vec, int pos);

void vector_push(Vector *vec, void *item);

void vector_slowPushAt(Vector *vec, int pos, void *item);

void vector_pushAt(Vector *vec, int pos, void *item);

void vector_pop(Vector *vec, deleteFunction *deleteFun);

void vector_slowPopAt(Vector *vec, int pos, deleteFunction *deleteFun);

void vector_popAt(Vector *vec, int pos, deleteFunction *deleteFun);

void vector_free(Vector *vec, deleteFunction *deleteFun);

#endif /* VECTOR_H */