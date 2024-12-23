# ifndef ARR_H
# define ARR_H

# include <stdlib.h>
# include <stdio.h>

# ifdef __cplusplus
extern "C" {
# endif

/// @brief A vector structure, contains the data array and the size
typedef struct vect_t{
    float * data;
    size_t size;
} Vector;


/// @brief Allocates new heap memory to make a blank vector.
/// @param arr The adress of the vector for which memory should be allocated.
/// @param size The size of the array that should be allocated.
/// @return 1 if there was an allocation error, 0 otherwise.
int new_vector (Vector * arr, size_t size);

/// @brief Pushes a new element to the back of a vector.
/// @param arr The adress of the vector which should be extended by a new element.
/// @param x The element to be added.
/// @return 1 if there was an allocation error, 0 otherwise.
int push_back (Vector * arr, float x);

/// @brief Removes the element at the end of the vector.
/// @param arr The adress of the vector of which an element should be removed
/// @return 1 if there was an allocation error, 0 otherwise.
int pop_back (Vector * arr);


/// @brief Frees the allocated memory.
/// @param arr The adress of the vector of which the memory should be freed.
void dealloc (Vector * arr);

/// @brief Prints the given vector, element by element.
/// @param arr The adress of the vector to be printed.
/// @param precision The amount of figures after the decimal poitn to be displayed.
void print_vector (Vector * arr, int precision);

# ifdef __cplusplus
}
# endif

# endif // ARR_H