#ifndef C_VECTOR_INT_H
#define C_VECTOR_INT_H

#include <stdlib.h>

// vector's struct
struct c_vector_int {
  int size;
  int capacity;
  int *data;
};

// default constructor
struct c_vector_int /* */ *ctor_vector_default(struct c_vector_int *v);

// constructor with parameters
struct c_vector_int /*  */ *ctor_vector_with_param(struct c_vector_int *v,
                                                   int size, int value);

// destructor
void dtor_vector_int(struct c_vector_int *v);

// vector "methods"
int GetSize(struct c_vector_int *v);

struct c_vector_int /* */ *PushBack(struct c_vector_int *v, int value);

int PopBack(struct c_vector_int *v);

void Clear(struct c_vector_int *v);

int Resize(struct c_vector_int *v, int new_size);

int Reserve(struct c_vector_int *v, int new_capacity);

int IsEmpty(struct c_vector_int *v);

int GetFront(struct c_vector_int *v);

int GetBack(struct c_vector_int *v);

int Swap(struct c_vector_int *lhs, struct c_vector_int *rhs);

int Erase(struct c_vector_int *v, int index);

#endif // C_VECTOR_INT_H
