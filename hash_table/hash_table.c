#include <stdlib.h>
#include "hash_table.h"
#include "../linked_list/char/char_list.h"

#define FNV_OFFSET_BASIS 2166136261
#define FNV_PRIME 16777619

HashTableLinked *newHashTable(int size)
{
    HashTableLinked *table = malloc(sizeof(HashTableLinked));
    table->size = size;
    table->table = malloc(sizeof(CharLinkedList *) * size);
    for (int i = 0; i < size; i++)
    {
        table->table[i] = newCharList();
    }
    return table;
}

unsigned int hash(char *value, unsigned int hash_size)
{
    unsigned int hash = FNV_OFFSET_BASIS;
    while (*value != '\0')
    {
        hash = hash ^ *value;
        hash = hash * FNV_PRIME;
        value++;
    }
    return hash % hash_size;
}

void hash_table_add_item(HashTableLinked *table, char *value)
{
    unsigned int index = hash(value, table->size);
    CharLinkedList *list = table->table[index];
    char_list_push_item(list, value);
}

int hash_table_search_item(HashTableLinked *table, char *value)
{
    unsigned int index = hash(value, table->size);
    return char_list_search_item(table->table[index], value);
}

void free_hash_table(HashTableLinked *table)
{
    for (int i = 0; i < table->size; i++)
    {
        char_free_list(table->table[i]);
    }
    free(table->table);
    free(table);
}