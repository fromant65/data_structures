#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "../linked_list/char/char_list.h"
#include "../nodes/char_node.h"
typedef struct 
{
    CharLinkedList **table;
    int size;
}HashTableLinked;

HashTableLinked* newHashTable(int size);
unsigned int hash(char* value,unsigned int hash_size);
void hash_table_add_item(HashTableLinked* table, char* value);
int hash_table_search_item(HashTableLinked* table, char* value);
void free_hash_table(HashTableLinked* table);
#endif
