// list/list.c
//
//Yasmin Senior 

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

node_t *node_alloc(elem value){
  node_t *node = (node_t*) malloc(sizeof(node_t));
  node->value = value;
  node->next = NULL;
  return node;
}

void node_free(node_t *node) {
   if (node->next != NULL) {
     node_free(node->next);
   } else {
     free(node);
   }
}

list_t *list_alloc() { 
  list_t *new_list = (list_t*) malloc(sizeof(list_t));
  new_list->head = NULL;
  return new_list;
}

void list_free(list_t *l) {
  node_t* current = l->head;
  if (current != NULL) {
    node_free(current);
  }
}

void list_print(list_t *l) {
  node_t *current = l->head;
  while (current != NULL){
    printf("%d ", current->value);
    current = current->next;
  }
  printf("\n");
}

int list_length(list_t *l) {
  int node_count = 0;
  node_t *current = l->head;
  while(current != NULL)
  {
    node_count ++;
    current = current->next; 
  }
  return node_count; 
}

void list_add_to_back(list_t *l, elem value) {
  node_t *current = l->head;
  node_t *new_node = node_alloc(value);
  if (current == NULL) {
    l->head = new_node;
    return;
  }

  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *new_node = node_alloc(value);
  new_node->next = l->head;
  l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if ((index >= list_length(l)) || (index < 0)) {
    return;
  }
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  
  node_t *current = l->head;
  int curr_index = 0;
  for (curr_index = 0; curr_index < index-1; curr_index++) {
    current = current->next;
  }
  
  if (current == NULL) {
    l->head = new_node;
  } else {
    new_node->next = current->next;
    current->next = new_node;
  }
}

elem list_remove_from_back(list_t *l) { 
  node_t *current = l->head;
  node_t *to_ret = current;
  while ((current != NULL) && (current->next != NULL)) {
    if (current->next->next == NULL) {
      to_ret = current->next;
      current->next = NULL;
    } else {
      current = current->next;
    }
  }
  return to_ret->value;
}

elem list_remove_from_front(list_t *l) { 
  if (l->head == NULL) {
    return 0;
  } else {
    int to_ret = l->head->value;
    l->head = l->head->next;
    return to_ret;
  }
}

elem list_remove_at_index(list_t *l, int index) { 
  if ((index >= list_length(l)) || (index < 0)) {
    return 0;
  }
  
  node_t *current = l->head;
  int curr_index = 0;
  for (curr_index = 0; curr_index < index-1; curr_index++) {
    current = current->next;
  }
  int to_ret = current->next->value;
  current->next = current->next->next;
  return to_ret; 
}

bool list_is_in(list_t *l, elem value) { 
  node_t *current = l->head;
  
  while (current != NULL) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;; 
}

elem list_get_elem_at(list_t *l, int index) { 
  if ((index >= list_length(l)) || (index < 0)) {
    return 0;
  }
  
  node_t *current = l->head;
  int curr_index = 0;
  
  for (curr_index; curr_index < index; curr_index++) {
    current = current->next;
  }
  return current->value; 
}

int list_get_index_of(list_t *l, elem value) { 
  node_t *current = l->head;
  int index = 0;
  
  while (current != NULL) {
    if (current->value == value) {
      return index;
    }
    current = current->next;
    index += 1;
  }
  return -1;
}
