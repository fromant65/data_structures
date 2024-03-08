#ifndef TYPES_FUNCTIONS_H
#define TYPES_FUNCTIONS_H
#include <stdlib.h>
/**
 * @brief Enumeration for data types.
 * 
 * This enumeration defines the types of data that can be handled by the system.
 */
enum Types{
    INT, ///< Integer type.
    DOUBLE, ///< Double-precision floating-point type.
    CHAR, ///< Character type.
    STRING ///< String type.
};

/**
 * @brief Gets the size of a given type.
 * 
 * This function returns the size in bytes of a given type.
 * 
 * @param type The type for which to get the size.
 * @return The size in bytes of the given type.
 */
size_t getTypeSize(enum Types size);

/**
 * Reading Functions
*/
void* readInt(); ///< Reads an integer from the standard input.
void* readDouble(); ///< Reads a double from the standard input.
void* readChar(); ///< Reads a character from the standard input.
void* readString(); ///< Reads a string from the standard input.

/**
 * Writing functions.
 */
void printInt(void*, char*); ///< Prints an integer to the standard output.
void printDouble(void*, char*); ///< Prints a double to the standard output.
void printChar(void*, char*); ///< Prints a character to the standard output.
void printString(void*, char*); ///< Prints a string to the standard output.

typedef void (*FreeingFunction)(void*);
/**
 * @brief Returns the appropriate freeing function for a given type.
 * 
 * 
 * @param type The type for which to get the freeing function.
 * @return A freeing function for a specific type.
 */
FreeingFunction freeType(enum Types type);

/**
 * @brief Freeing function for static types.
 * 
 * This function frees the memory allocated for a static type of data allocated on the stack.
 * It just frees the pointer memory
 */
void freeStaticType(void*); ///< Frees memory for static data.

/**
 * @brief Freeing function for string types.
 * 
 * This function frees the memory allocated for data of a string type.
 * It frees the string memory and the pointer memory
 */
void freeStringType(void*); ///< Frees memory for string data.

typedef void* (*ReadFunction)();
typedef void (*PrintFunction)(void*, char*);
extern ReadFunction readingFunctions[]; ///< Array of reading functions.
extern PrintFunction printingFunctions[]; ///< Array of printing functions.
#endif