#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hash_table.h"
#include "hash_table_test.h"
#include "../linked_list/char/char_list.h"
void test_newHashTable();
void test_hash_table_add_item();
void test_hash_table_search_item();

void test_hash_table()
{
    printf("Testing newHashTable...\n");
    test_newHashTable();
    printf("Testing hash_table_add_item...\n");
    test_hash_table_add_item();
    printf("Testing hash_table_search_item...\n");
    test_hash_table_search_item();
}

void test_newHashTable()
{
    HashTableLinked *table = newHashTable(10);
    for (int i = 0; i < 10; i++)
    {
        assert(table->table[i]->size == 0);
    }
    free_hash_table(table);
}

void test_hash_table_add_item()
{
    HashTableLinked *table = newHashTable(10);
    hash_table_add_item(table, "arbol");
    hash_table_add_item(table, "bizonte");
    hash_table_add_item(table, "carton");
    hash_table_add_item(table, "dentadura");
    hash_table_add_item(table, "elefante");
    hash_table_add_item(table, "fulvio");
    hash_table_add_item(table, "garra");
    hash_table_add_item(table, "horno");
    hash_table_add_item(table, "ivo");
    hash_table_add_item(table, "jesus");
    hash_table_add_item(table, "kirchner");
    int max_size = -1;
    for (int i = 0; i < 10; i++)
    {
        printf("%d: ", i);
        char_print_list(table->table[i]);
        printf("\n");
        if (table->table[i]->size > max_size)
        {
            max_size = table->table[i]->size;
        }
    }
    assert(max_size >= 2);
    free_hash_table(table);
}
void test_hash_table_search_item()
{
    HashTableLinked *table = newHashTable(10);
    hash_table_add_item(table, "ivo");
    assert(hash_table_search_item(table, "ivo"));
    assert(!hash_table_search_item(table, "bolivo"));
    free_hash_table(table);
}