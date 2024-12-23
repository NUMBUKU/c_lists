# include "arr.h"

const size_t FSIZE = sizeof(float);

int new_vector (Vector * arr, size_t size){
    float * data = ( float * ) malloc(size * FSIZE);

    if (data == NULL) return 1; // handle allocation error

    arr->data = data;
    arr->size = size;

    return 0;
}

int push_back (Vector * arr, float x){
    float * data = ( float * ) realloc(arr->data, (arr->size + 1) * FSIZE);

    if (data == NULL) return 1; // handle allocation error

    arr->data = data;
    arr->data[arr->size] = x;
    arr->size++;

    return 0;
}

int pop_back (Vector * arr){
    float * data = ( float * ) realloc(arr->data, (arr->size - 1) * FSIZE);

    if (data == NULL) return 1; // handle allocation error

    arr->data = data;
    arr->size--;

    return 0;
}

void dealloc (Vector * arr){
    free(arr->data);
}

void print_vector(Vector * arr, int precision){
    for (int i = 0; i < arr->size; i++)
        printf("%.*f ", precision, arr->data[i]);
}
