#ifndef __GARRAY_H__
#define __GARRAT_H__

#include <stdlib.h>

/**
 * @brief General type array
 * 
 * This struct represents an array with a generic type (void*)
*/
typedef struct{
    void** data; //!< The array of void* with the data
    size_t size; //!< The maximum size of the array
    size_t last_index; //!< The index of the last element stored in the array
}GArray;

/**
 * @brief comparison function prototype
 * @return -1 if the first parameter is previous than the second,
 *          0 if both parameters are equal,
 *          1 if the second parameter is previous than the first,
*/
typedef int (*ComparisonFunction)(void*,void*);

/**
 * @brief parses a void* to some specific type and performs an action on it
*/
typedef void(*ParsingFunction)(void*);

/**
 * @brief frees the memory at the given pointer
*/
typedef void(*DestructorFunction)(void*);

/**
 * @brief Creates a new empty array 
 * @return an empty GArray struct with space for 1000 records
*/
GArray newGArray();

/**
 * @brief duplicates the size of the array
*/
GArray expandGArray(GArray arr);

/**
 * @brief Inserts an element at the end of the array
*/
GArray GArrayPush(GArray arr, void* data);

/**
 * @brief Deletes the last element of the array
*/
GArray GArrayPop(GArray arr, DestructorFunction f);

/**
 * @brief Inserts the data in the array at the given index and shifts the rest of elements to the right
*/
GArray GArrayInsert(GArray arr, size_t index, void* data);

/**
 * @brief Inserts the data in the array at the given index, 
 * freeing and overwriting the previous element at that position
*/
GArray GArrayUpdate(GArray arr, size_t index, void* data, DestructorFunction f);

/**
 * @brief Deletes the element at the given index and shifts the rest of elements to the left
*/
GArray GArrayDelete(GArray arr, size_t index, DestructorFunction f);

/**
 * @brief Sorts the array acording to some comparison function
*/
GArray GArraySort(GArray arr, ComparisonFunction comp);

/**
 * @brief Maps the parsing function to the array
*/
void GArrayMap(GArray arr, ParsingFunction parse);
#endif