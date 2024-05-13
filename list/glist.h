#ifndef __GLIST_H__
#define __GLIST_H__

typedef void (*DestructorFunction)(void *data);
typedef void *(*CopyFunction)(void *data);
typedef void (*ParsingFunction)(void *data);
typedef int (*BooleanFunction)(void *data);

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode *GList;

/**
 * @brief Returns an empty list
 */
GList newGlist();

/**
 * @brief Destroys every node in the list
 */
void glistFree(GList list, DestructorFunction destructor);

/**
 * @return 1 if the list is empty, 0 if not
 */
int glistEmpty(GList list);

/**
 * @brief Adds an element at the beggining of the list
 */
GList glistAdd(GList list, void *data, CopyFunction copy);

/**
 * @brief Maps the parsing function to the whole list
 */
void glistMap(GList list, ParsingFunction visit);

/**
 * @brief Given a GList, returns a new list with the elements for which p is true (1)
 * @param list the GList
 * @param c function used to create the new list
 * @param p the boolean function
*/
GList glistFilter(GList list, CopyFunction c, BooleanFunction p);

/**
 * @brief Deletes the first element of the list
*/
GList glistDelete(GList list, DestructorFunction destructor);

#endif /* __GLIST_H__ */
