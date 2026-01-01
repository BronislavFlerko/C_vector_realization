#include "c_vector.h"

/*
struct c_vector_int {

  int size;
  int capacity;
  int *data;
};
*/

// default constructor
struct c_vector_int /* */ *ctor_vector_default(struct c_vector_int *v) {

  if (!v) {
    return NULL;
  }

  v->size = 0;
  v->capacity = 16;

  v->data = malloc(v->capacity * sizeof(int));
  if (!v->data) {
    return NULL;
  }

  return v;
}

// constructor with parameters
struct c_vector_int /*  */ *ctor_vector_with_param(struct c_vector_int *v,
                                                   int size, int value) {
  if (!v) {
    return NULL;
  }

  v->size = size;
  v->capacity = (size < 16) ? 16 : size * 2;

  v->data = malloc(v->capacity * sizeof(int));
  if (!v->data) {
    return NULL;
  }

  for (int i = 0; i < size; i++) {
    v->data[i] = value;
  }

  return v;
}

// destructor
void dtor_vector_int(struct c_vector_int *v) {

  if (!v)
    return;

  if (v->data) {
    free(v->data);
    v->data = NULL;
  }

  v->size = 0;
  v->capacity = 0;
}

// vector "methods"
int GetSize(struct c_vector_int *v) {
  if (!v) {
    return 0;
  }

  return v->size;
}

struct c_vector_int /* */ *PushBack(struct c_vector_int *v, int value) {
  if (!v)
    return NULL;

  if (v->size >= v->capacity) {
    int new_capacity = (v->capacity == 0) ? 16 : v->capacity * 2;

    int *new_data = realloc(v->data, new_capacity * sizeof(int));
    if (!new_data) {
      return NULL;
    }

    v->data = new_data;
    v->capacity = new_capacity;
  }

  v->data[v->size] = value;
  v->size += 1;

  return v;
}

int PopBack(struct c_vector_int *v) {
  if (!v)
    return 0;
  if (v->size == 0)
    return 0;

  v->size -= 1;
  return v->data[v->size];
}

void Clear(struct c_vector_int *v) {

  if (!v)
    return;

  v->size = 0;
}

int Resize(struct c_vector_int *v, int new_size) {

  if (!v || new_size < 0)
    return -1;

  if (new_size > v->capacity) {
    int new_capacity = new_size * 2;

    int *new_data = realloc(v->data, new_capacity * sizeof(int));
    if (!new_data)
      return -1;

    v->data = new_data;
    v->capacity = new_capacity;
  }

  for (int i = v->size; i < new_size; i++) {
    v->data[i] = 0;
  }

  v->size = new_size;
  return 0;
}

int Reserve(struct c_vector_int *v, int new_capacity) {

  if (!v) {
    return -1;
  }
  if (v->capacity > new_capacity) {
    return 0;
  }

  int *new_data = realloc(v->data, new_capacity * sizeof(int));
  if (!new_data) {
    return -1;
  }

  v->data = new_data;
  v->capacity = new_capacity;

  return 0;
}

int IsEmpty(struct c_vector_int *v) { return !v || v->size == 0; }

int GetFront(struct c_vector_int *v) {

  if (!v || v->size == 0) {
    return -1;
  }

  return v->data[0];
}

int GetBack(struct c_vector_int *v) {

  if (!v || v->size == 0) {
    return -1;
  }

  return v->data[v->size - 1];
}

int Swap(struct c_vector_int *lhs, struct c_vector_int *rhs) {

  if (!lhs || !rhs) {
    return 1;
  }

  int *temp_data = lhs->data;
  int temp_size = lhs->size;
  int temp_cap = lhs->capacity;

  lhs->data = rhs->data;
  lhs->size = rhs->size;
  lhs->capacity = rhs->capacity;

  rhs->data = temp_data;
  rhs->size = temp_size;
  rhs->capacity = temp_cap;

  return 0;
}

int Erase(struct c_vector_int *v, int index) {

  if (!v || v->size <= 0 || index < 0 || index >= v->size) {
    return -1;
  }

  for (int i = index; i < v->size - 1; ++i) {
    v->data[i] = v->data[i + 1];
  }

  v->size -= 1;

  return 0;
}
