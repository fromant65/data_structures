#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "hash_table.h"
#include "hash_table_test.h"

void test_newHashTable();
void test_hash();
void test_hash_table_add_item();
void test_hash_table_search_item();

void test_hash_table()
{
    printf("Testing newHashTable...\n");
    test_newHashTable();
    printf("Testing hash function...\n");
    test_hash();
    printf("Testing hash_table_add_item...\n");
    test_hash_table_add_item();
    printf("Testing hash_table_search_item...\n");
    test_hash_table_search_item();
}

void test_newHashTable(){
    HashTableLinked* table = newHashTable(10);
    for(int i=0;i<10;i++){
        assert(table->table[i]->size==0);
    }
    free_hash_table(table);
}
void test_hash(){
    assert(hash("ivo",10)==1);
}
void test_hash_table_add_item(){
    HashTableLinked* table = newHashTable(10);
    hash_table_add_item(table, "ivo");
    assert(!strcmp(table->table[1]->first->value, "ivo"));
    free_hash_table(table);
}
void test_hash_table_search_item(){
    HashTableLinked* table = newHashTable(10);
    hash_table_add_item(table, "ivo");
    assert(hash_table_search_item(table, "ivo"));
    assert(!hash_table_search_item(table, "bolivo"));
    free_hash_table(table);
}