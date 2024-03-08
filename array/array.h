#ifndef ARRAY_H
#define ARRAY_H
#include "../object/object.h"
#include "../types/types_functions.h"

/**
 * @brief Generic Object array.
 * 
 * This structure represents a generic object array with a pointer to the data,
 * the length of the data, the maximum size of the array, and the type of the data.
 */
typedef struct{
    Object* data; //!< Pointer to the data.
    size_t length; //!< Length of the data.
    size_t max_size; //!< Maximum size of the array.
    enum Types type; //!< Type of the data.
} Array;

/**
 * @brief Creates a new Array of a specified type.
 * 
 * This function initializes a new Array with the specified type.
 * 
 * @param type The type of the Array.
 * @return A new Array of the specified type.
 */
Array newArray(enum Types type);

/**
 * @brief Adds an Object to the end of an Array.
 * 
 * This function appends an Object to the end of an Array.
 * 
 * @param array Pointer to the Array.
 * @param obj The Object to add.
 */
void arrayPush(Array* array, Object obj);

/**
 * @brief Removes the last Object from an Array.
 * 
 * This function removes the last Object from an Array.
 * 
 * @param array Pointer to the Array.
 */
void arrayPop(Array* array);

/**
 * @brief Inserts an Object at a specific index in an Array.
 * 
 * This function inserts an Object at the specified index in an Array.
 * 
 * @param array Pointer to the Array.
 * @param index The index at which to insert the Object.
 * @param obj The Object to insert.
 */
void arrayInsert(Array* array, int index, Object obj);

/**
 * @brief Deletes an Object at a specific index in an Array.
 * 
 * This function deletes the Object at the specified index in an Array.
 * 
 * @param array Pointer to the Array.
 * @param index The index of the Object to delete.
 */
void arrayDelete(Array* array, int index);

/**
 * @brief Extends the size of an Array.
 * 
 * This function extends the size of an Array by a factor of 2, increasing its capacity.
 * 
 * @param array Pointer to the Array.
 */
void arrayExtend(Array* array);

/**
 * @brief Reduces the size of an Array.
 * 
 * This function reduces the size of an Array, decreasing its capacity to its actual length.
 * 
 * @param array Pointer to the Array.
 */
void arrayShrink(Array* array);

/**
 * @brief Prints the contents of an Array.
 * 
 * This function prints the contents of an Array to the standard output.
 * 
 * @param array The Array to print.
 */
void arrayPrint(Array array);

/**
 * @brief Frees the memory of an Array.
 * 
 * This function frees the memory allocated for an Array.
 * 
 * @param array Pointer to the Array.
 */
void arrayFree(Array* array);


#endif