# include <stdio.h>

# include "src\arr.h"

const int size = 5;

int main (int arc, char ** argv){
    Vector v = {0};

    if (new_vector(&v, size)){
        printf("allocation failed");
        return 1;
    }

    for (int i = 0; i < size; i++) v.data[i] = i;

    print_vector(&v, 0);
    printf("\n");

    if (pop_back(&v)){
        printf("reallocation failed");
        return 1;
    }

    print_vector(&v, 0);
    printf("\n");

    if (push_back(&v, -10.5)){
        printf("reallocation failed");
        return 1;
    }

    print_vector(&v, 1);
    printf("\n");


    dealloc(&v);
    printf("\ndone");

    return 0;
}