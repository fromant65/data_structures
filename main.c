#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "./linked_list/list.h"

int main()
{
    setlocale(LC_ALL, "spanish"); // Cambia locale - Para Linux
    SetConsoleCP(1252);           // Cambiar STDIN -  Para máquinas Windows
    SetConsoleOutputCP(1252);     // Cambiar STDOUT - Para máquinas Windows
    LinkedList *l = newList();
    print_list(l);
    push(l, 1);
    print_list(l);
    push(l, 2);
    print_list(l);
    push(l, 3);
    print_list(l);
    push(l, 5);
    print_list(l);
    delete_item(l, 2);
    print_list(l);
    delete_item(l, 4);
    print_list(l);
    free_list(l);
    return 0;
}