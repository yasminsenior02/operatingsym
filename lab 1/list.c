#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include "list.h"

list_t *list_alloc() {
  list_t* new_list = (list_t*)malloc(sizeof(list_t));
  new_list->head = NULL;
  return new_list;
}

char listToString(list_t *list){
  char temp[250];
}

node_t *node_alloc(elem val){
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->value = val;
  new_node->next = NULL;
  return new_node;
}

void list_free(list_t *l) {
  node_t*cur = l->head;
  while (cur != NULL){
    node_t *temp_cur = cur->next;
    free(cur);
    cur = temp_cur;
  }
  if (cur == NULL){
    printf("Linked list is empty, no remaining values\n");
  }
}

void node_free (node_t *n){
  free(n);
}

void list_print(list_t *l) {
  node_t *cur = l->head;
  while(cur != NULL){
    cur = cur->next;
  }
  if (cur == NULL){
    printf("Linked list is empty, no remaining values\n");
  }
}

int list_length(list_t *l) {
  int length = 0;
  node_t *cur = l->head;
  while(cur != NULL){
    length++;
    cur = cur->next;
  }
  return length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *added_val;
  node_t *cur = l->head;
  added_val = node_alloc(value);
  while(cur->next != NULL){
    cur = cur -> next;
  }
  cur -> next = added_val;
  added_val -> next = NULL;
  if (cur == NULL){
    printf("Linked list is empty, no remaining values\n");
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t *added_val;
  added_val = node_alloc(value);
  node_t *cur = l->head;
  added_val ->next = l->head;
  l->head = added_val;
}

void list_add_at_index(list_t *l, elem value, int index) {
  int add = 0;
  node_t *cur = l->head;
  node_t *temp = NULL;
  node_t *added_val;
  added_val = node_alloc(value);
  if (index == 0){
    return list_add_to_front(1,value);
  }
  while(add < index){
    temp = cur;
    cur = cur->next;
    add++;
  }
  temp->next = added_val;
  added_val->next = cur;
}

elem list_remove_from_back(list_t *l) { 
  node_t *cur = l->head;
  if (cur == NULL){
    return ; //because this function isn't void
  }
  while(cur->next != NULL){
    cur = cur->next;
  }
  elem previous = cur->value;
  free(cur);
  return previous;
}

elem list_remove_from_front(list_t *l) { 
  node_t *cur = l->head;
  if(cur == NULL){
    printf("Linked list is empty, no remaining values\n");
    return ;
  }
  node_t *list_start = l->head;
  elem nextval = l->head->value;
  list_start = l->head;
  l->head = l->head->next;
  free(list_start);
  return nextval;
}

elem list_remove_at_index(list_t *l, int index) { 
  node_t *cur = l->head;
  if (cur == NULL){
    printf("Linked list is empty, no remaining values\n");
    return ;
  }
  int remove = 0;
  node_t *temp = l->head;
  while(temp->next != NULL && remove < index){
    temp = temp->next;
    remove++;
  }
  node_t *remove_elem = temp->next;
  elem val = temp->next->value;
  temp -> next = temp->next->next;
  free(remove_elem);
  return val;
}

bool list_is_in(list_t *l, elem value) {
  node_t *cur = l->head;
  while(cur != NULL){
    if (cur->value == value){
      return true;
    }
    cur = cur->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) { 
  int get_elem = 0;
  node_t *cur = l->head;
  while(cur != NULL){
    if (get_elem == index){
      return cur->value;
    }
    cur = cur->next;
    get_elem++;
  }
  return -1;
}
 
int list_get_index_of(list_t *l, elem value) { 
  int get_index = 0;
  node_t *cur = l->head;
  if (cur == NULL){
    printf("Linked list is empty, no remaining values\n");
    return ;
  }
  while (cur != NULL){
    if (cur->value == value){
      return get_index;
    }
    get_index++;
    cur = cur->next;
  }
  return -1;
}