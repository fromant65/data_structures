#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char_list.h"
#include "../../nodes/char_node.h"

CharLinkedList *newCharList()
{
    CharLinkedList *l = malloc(sizeof(CharLinkedList));
    if (l == NULL)
    {
        printf("There was an error creating the list\n");
        exit(1);
    }
    l->first = NULL;
    l->size = 0;
    return l;
}

void char_list_push_item(CharLinkedList *l, char* value)
{
    CharNode *n = malloc(sizeof(CharNode));
    if (n == NULL)
    {
        printf("Mistake at insert elements to the list\n");
        exit(1);
    }
    n->next = NULL;
    n->value = value;
    if (l->first == NULL)
    {
        l->first = n;
    }
    else
    {
        CharNode *aux = l->first;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = n;
    }
    l->size++;
}

void char_list_add_item(CharLinkedList *l, char* value, int index)
{
    if (index > l->size)
    {
        printf("Indicated index is greater than list size");
        return;
    }
    CharNode *n = malloc(sizeof(CharNode));
    if (n == NULL)
    {
        printf("Mistake at insert elements to the list\n");
        exit(1);
    }
    n->value = value;
    if (l->first == NULL)
    {
        n->next = NULL;
        l->first = n;
    }
    else if (index == 0)
    {
        n->next = l->first;
        l->first = n;
    }
    else
    {
        CharNode *aux = l->first;
        for (int i = 1; i < index; i++)
        {
            aux = aux->next;
        }
        n->next = aux->next;
        aux->next = n;
    }
    l->size++;
}

void char_list_delete_item(CharLinkedList *l, char* value)
{
    if (l->first == NULL)
    {
        printf("The list are empty\n");
        return;
    }
    else
    {
        CharNode *aux = l->first;
        CharNode *ant = NULL;
        while (aux != NULL && strcmp(aux->value,value))
        {
            ant = aux;
            aux = aux->next;
        }
        if (aux == NULL)
        {
            printf("The value doesn't exists %d\n", value);
            return;
        }
        if (ant == NULL)
        { // The value is in the first node
            l->first = aux->next;
        }
        else
        {
            ant->next = aux->next;
        }
        free(aux);
        l->size--;
    }
}

// char *stringify_list(CharLinkedList *l)
// {
//     char *str = malloc(sizeof(char) * l->size * 12);
//     str[0] = '\0';
//     CharNode *node = l->first;
//     for (int i = 0; node != NULL; i++)
//     {
//         sprintf(str + strlen(str), "%d ", node->value);
//         node = node->next;
//     }
//     sprintf(str + strlen(str) - 1, "\n"); // Replacing the last blankspace with a line jump
//     return str;
// }

void char_print_list(CharLinkedList *l)
{
    CharNode* aux = l->first;
    for(int i = 0; i < l->size ; i++){        
        printf("%s ", aux->value);
        aux=aux->next;
    }
}

void char_free_list(CharLinkedList *l)
{
    if (l->first == NULL)
    {
        free(l);
        return;
    }
    else
    {
        CharNode *aux = l->first;
        CharNode *next;
        while (aux != NULL)
        {
            next = aux->next;
            free(aux);
            aux = next;
        }
        free(l);
    }
}