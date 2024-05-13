#include "glist.h"
#include <assert.h>
#include <stdlib.h>

GList newGlist() { return NULL; }

void glistFree (GList list, DestructorFunction destroy) {
  GNode *nodeToDelete;
  while (list != NULL) {
    nodeToDelete = list;
    list = list->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
}

int glistEmpty(GList list) { return (list == NULL); }


GList glistAdd(GList list, void *data, CopyFunction copy) {
  GNode *newNode = malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->next = list;
  newNode->data = copy(data);
  return newNode;
}

void glistMap(GList list, ParsingFunction visit) {
  for (GNode *node = list; node != NULL; node = node->next)
    visit(node->data);
}

GList glistFilter(GList lista, CopyFunction c, BooleanFunction p){
  GList newList = newGlist();
  GList temp = lista;
  while(temp!=NULL){
    if(p(temp->data)==1){
      newList = glistAdd(newList, temp->data, c);
    }
    temp = temp->next;
  }
  return newList;
}

GList glistDelete(GList list, DestructorFunction destructor){
    if(glistEmpty(list)) return list;
    GList aux = list->next;
    destructor(list->data);
    free(list);
    return aux;
}
