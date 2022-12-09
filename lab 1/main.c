#include <stdio.h>

#include "list.h"
#include <assert.h>

int main() {
  printf("Tests for linked list implementation\n");
  printf("\n--------------------------------------\n");

  printf("\n1. LIST_ADD_TO_FRONT_EMPTYLIST\n");
  list_t *test1_list = list_alloc();
  list_add_to_front(test1_list, 15);
  list_print(test1_list);
  assert(1 == list_length(test1_list));
  list_free(test1_list);
  printf("PASS LIST_ADD_TO_FRONT_EMPTYLIST\n");
  printf("\n--------------------------------------\n");
  
  printf("\n2. LIST_ADD_TO_FRONT_NONEMPTYLIST\n");
  list_t *test2_list = list_alloc();
  list_add_to_back(test2_list, 5);
  list_add_to_front(test2_list, 4);
  list_print(test2_list);
  assert(2 == list_length(test2_list));
  list_free(test2_list);
  printf("PASS LIST_ADD_TO_FRONT_NONEMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n3. LIST_ADD_TO_BACK_EMPTYLIST\n");
  list_t *test3_list = list_alloc();
  list_add_to_back(test3_list, 5);
  list_print(test3_list);
  assert(1 == list_length(test3_list));
  list_free(test3_list);
  printf("PASS LIST_ADD_TO_BACK_EMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n4. LIST_ADD_TO_BACK_NONEMPTYLIST\n");
  list_t *test4_list = list_alloc();
  list_add_to_front(test4_list, 3);
  list_add_to_back(test4_list, 5);
  list_print(test4_list);
  assert(2 == list_length(test4_list));
  list_free(test4_list);
  printf("PASS LIST_ADD_TO_BACK_NONEMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n6. LIST_ADD_TO_ITH_OUT_OF_RANGE_EMPTYLIST\n");
  list_t *test6_list = list_alloc();
  list_print(test6_list);
  list_add_at_index(test6_list, 3, 8);
  list_print(test6_list);
  list_add_at_index(test6_list, 3, -2);
  assert(0 == list_length(test6_list));
  list_free(test6_list);
  printf("PASS LIST_ADD_TO_ITH_OUT_OF_RANGE_EMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n7. LIST_ADD_TO_ITH_NONEMPTYLIST\n");
  list_t *test7_list = list_alloc();
  list_add_to_back(test7_list, 7);
  list_add_to_back(test7_list, 9);
  list_print(test7_list);
  list_add_at_index(test7_list, 3, 1);
  list_print(test7_list);
  assert(3 == list_length(test7_list));
  list_free(test7_list);
  printf("PASS LIST_ADD_TO_ITH_NONEMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n8. LIST_REMOVE_FROM_FRONT_EMPTYLIST\n");
  list_t *test8_list = list_alloc();
  list_print(test8_list);
  list_remove_from_front(test8_list);
  list_print(test8_list);
  assert(0 == list_length(test8_list));
  list_free(test8_list);
  printf("PASS LIST_REMOVE_FROM_FRONT_EMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n9. LIST_REMOVE_FROM_FRONT_NONEMPTYLIST\n");
  list_t *test9_list = list_alloc();
  list_add_to_back(test9_list, 6);
  list_add_to_back(test9_list, 9);
  list_print(test9_list);
  list_remove_from_front(test9_list);
  list_print(test9_list);
  assert(1 == list_length(test9_list));
  list_free(test9_list);
  printf("PASS LIST_REMOVE_FROM_FRONT_NONEMPTYLIST\n");
  printf("\n--------------------------------------\n");


  printf("\n11. LIST_REMOVE_FROM_BACK_NONEMPTYLIST\n");
  list_t *test11_list = list_alloc();
  list_add_to_back(test11_list, 6);
  list_add_to_back(test11_list, 9);
  list_print(test11_list);
  list_remove_from_back(test11_list);
  list_print(test11_list);
  assert(1 == list_length(test11_list));
  list_free(test11_list);
  printf("PASS LIST_REMOVE_FROM_BACK_NONEMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n12. LIST_REMOVE_FROM_ITH_EMPTYLIST\n");
  list_t *test12_list = list_alloc();
  list_print(test12_list);
  list_remove_at_index(test12_list, 0);
  list_print(test12_list);
  assert(0 == list_length(test12_list));
  list_free(test12_list);
  printf("PASS LIST_REMOVE_FROM_ITH_EMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n13. LIST_REMOVE_FROM_ITH_OUT_OF_RANGE\n");
  list_t *test13_list = list_alloc();
  list_add_to_back(test13_list, 6);
  list_add_to_back(test13_list, 9);
  list_print(test13_list);
  list_remove_at_index(test13_list, 6);
  list_print(test13_list);
  assert(2 == list_length(test13_list));
  list_free(test13_list);
  printf("PASS LIST_REMOVE_FROM_ITH_OUT_OF_RANGE\n");
  printf("\n--------------------------------------\n");

  printf("\n14. LIST_REMOVE_FROM_ITH_NONEMPTYLIST\n");
  list_t *test14_list = list_alloc();
  list_add_to_back(test14_list, 6);
  list_add_to_back(test14_list, 9);
  list_print(test14_list);
  list_remove_at_index(test14_list, 1);
  list_print(test14_list);
  assert(1 == list_length(test14_list));
  list_free(test14_list);
  printf("PASS LIST_REMOVE_FROM_ITH_NONEMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n15. SEARCH_NONEMPTYLIST\n");
  list_t *test15_list = list_alloc();
  list_add_to_back(test15_list, 6);
  list_add_to_back(test15_list, 9);
  list_print(test15_list);
  assert(true == list_is_in(test15_list, 9));
  list_free(test15_list);
  printf("PASS SEARCH_NONEMPTYLIST\n");
  printf("\n--------------------------------------\n");

  printf("\n16. FINDING_BY_INDEX_NONEMPTYLIST\n");
  list_t *test16_list = list_alloc();
  list_add_to_back(test16_list, 6);
  list_add_to_back(test16_list, 9);
  list_print(test16_list);
  assert(9 == list_get_elem_at(test16_list, 1));
  list_free(test16_list);
  printf("PASS FINDING_BY_INDEX_NONEMPTYLIST\n");
  printf("\n--------------------------------------\n");

  // printf("\n17. RETURN_ELEM_BY_INDEX_EMPTYLIST\n");
  // list_t *test17_list = list_alloc();
  // list_print(test17_list);
  // assert(NULL == list_get_elem_at(test17_list, 0));
  // list_free(test17_list);
  // printf("PASS RETURN_ELEM_BY_INDEX_EMPTYLIST\n");
  // printf("\n--------------------------------------\n");

  printf("\n18. RETURN_ELEM_BY_INDEX_NONEMPTYLIST\n");
  list_t *test18_list = list_alloc();
  list_add_to_back(test18_list, 6);
  list_add_to_back(test18_list, 9);
  list_print(test18_list);
  assert(6 == list_get_elem_at(test18_list, 0));
  list_free(test18_list);
  printf("PASS RETURN_ELEM_BY_INDEX_NONEMPTYLIST\n");
  printf("\n--------------------------------------\n");

  return 0;
}