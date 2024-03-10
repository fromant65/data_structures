#ifndef OBJECT_H
#define OBJECT_H
#include <stdlib.h>
#include "../types/types_functions.h"
#include <stdbool.h>

/**
 * @brief Generic Object structure.
 * 
 * This structure represents a generic object with a pointer to the data,
 * the size of the object, the type of the object, and a flag indicating
 * whether the data is static (on the stack) or dynamic (on the heap).
 */
typedef struct{
    void* ref; //!< Pointer to the memory address of the data.
    size_t size; //!< Size of the object.
    enum Types type; //!< Type of the object.
    bool is_data_static; //!< Flag indicating if the data is on the stack (true) or on the heap (false).
} Object;

/**
 * @brief Creates a new Object of a specified type.
 * 
 * This function initializes a new Object with the specified type and data.
 * If the data is static, it copies the data to dynamically allocated memory.
 * 
 * @param type The type of the Object.
 * @param data Pointer to the data to be stored in the Object.
 * @return A new Object of the specified type with the given data.
 */
Object newObject(enum Types type, void* data);

/**
 * @brief Prints the Object's data with a specified separator.
 * 
 * This function prints the data contained in an Object to the standard output,
 * using a specified separator after the data elements.
 * 
 * @param obj The Object to print.
 * @param separator The separator to use after data elements.
 */
void printObject(Object obj, char* separator);

/**
 * @brief Frees the memory of an Object's data.
 * 
 * This function frees the memory allocated for an Object's data,
 * ensuring that no memory leaks occur.
 * 
 * @param obj The Object whose data memory should be freed.
 */
void freeObjectData(Object obj);

#endif