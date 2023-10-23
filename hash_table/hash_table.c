#include <stdlib.h>
#include "hash_table.h"
#include "../linked_list/char/char_list.h"

HashTableLinked* newHashTable(int size){
    HashTableLinked *table = malloc(sizeof(HashTableLinked));
    table->size=size;
    table->table = malloc(sizeof(CharLinkedList*)*size);
    for(int i=0;i<size;i++){
        table->table[i]=newCharList();
    }
    return table;
}

unsigned int hash(char* value, unsigned int hash_size){
    unsigned int h = 0;
    unsigned int a= 31415;
    unsigned int b = 27183;
    while (*value !='\0')
    {
        h=(a*h+*value)%hash_size;
        a=a*b%(hash_size-1);
        value++;
    }
    return h; 
}

void hash_table_add_item(HashTableLinked* table, char* value){
    unsigned int index = hash(value, table->size);
    CharLinkedList* list= table->table[index];
    char_list_push_item(list, value);
}

int hash_table_search_item(HashTableLinked* table, char* value){
    unsigned int index = hash(value, table->size);
    CharLinkedList* list= table->table[index];
    return char_list_search_item(table->table[index],value);
}

void free_hash_table(HashTableLinked* table){
    for(int i=0;i<table->size;i++)
    {
        char_free_list(table->table[i]);
    }
    free(table->table);
    free(table);
}