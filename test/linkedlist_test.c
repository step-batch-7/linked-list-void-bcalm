#include "test.h"

Status match_int(Element element1, Element element2)
{
  return *(int *)element1 == *(int *)element2;
}

void run_create_list()
{
  List_ptr list = create_list();
  describe("create_list:");
  assert_equal(list->length, 0, "should create a list with length 0");
  assert_is_null(list->first, "should create a list with first point pointing to null");
  assert_is_null(list->first, "should create a list with last point pointing to null");
}

void run_add_to_start()
{
  List_ptr list = create_list();
  int num = 1;
  Status status = add_to_start(list, &num);
  describe("add_to_start:");
  assert_equal(status, 1, "should successfully insert the given element");
  assert_is_int_equal(list->first->element, 1, "should add to the starting of the list");
  assert_is_int_equal(list->last->element, 1, "should add to the last of the list when list is empty");
  assert_equal(list->length, 1, "should update the length of the list");
}

void run_add_to_list()
{
  List_ptr list = create_list();
  int num = 1;
  Status status = add_to_list(list, &num);
  describe("add_to_list:");
  assert_equal(status, 1, "should successfully insert the given element");
  assert_is_int_equal(list->first->element, 1, "should add to the starting of the list when list is empty");
  int num2 = 2;
  add_to_list(list, &num2);
  assert_is_int_equal(list->last->element, 2, "should add to the last of the list");
  assert_equal(list->length, 2, "should update the length of the list");
}

void run_insert_at()
{
  List_ptr list = create_list();
  describe("insert_at");
  int num = 1;
  Status status = insert_at(list, &num, 0);
  assert_equal(status, 1, "should successfully insert the given element");
  assert_is_int_equal(list->first->element, 1, "should add to the zeroth position");
  status = insert_at(list, &num, 1);
  assert_is_int_equal(list->last->element, 1, "should add to the end of the list");
  status = insert_at(list, &num, 1);
  assert_is_int_equal(list->last->element, 1, "should add to the middle of the list");
  assert_equal(list->length, 3, "should update the length of the list");
  status = insert_at(list, &num, 5);
  assert_equal(status, 0, "should not insert at the invalid position");
}

void run_remove_from_start()
{
  List_ptr list = create_list();
  Element element = remove_from_start(list);
  describe("remove_to_start:");
  assert_is_null(element, "should not remove the element when list is empty");
  int num = 1;
  add_to_start(list, &num);
  element = remove_from_start(list);
  assert_is_int_equal(element, 1, "should remove the starting element of the list");
  assert_is_null(list->last, "should remove the last element of the list when list has only one element");
  assert_equal(list->length, 0, "should update the length of the list");
}

void run_remove_from_end()
{
  List_ptr list = create_list();
  Element element = remove_from_end(list);
  describe("remove_to_end:");
  assert_is_null(element, "should not remove the element when list is empty");
  int num = 1;
  add_to_start(list, &num);
  element = remove_from_end(list);
  assert_is_null(list->first, "should remove the starting element of the list when list has only one element");
  assert_is_int_equal(element, 1, "should remove the last element of the list");
  assert_equal(list->length, 0, "should update the length of the list");
}

void run_remove_at()
{
  List_ptr list = create_list();
  describe("remove_at");
  int num = 1;
  Element element = remove_at(list, 0);
  assert_is_null(element, "should not remove the element when list is empty");
  add_to_start(list, &num);
  element = remove_at(list, 0);
  assert_is_int_equal(element, 1, "should remove the element from zeroth position");
  add_to_start(list, &num);
  add_to_start(list, &num);
  element = remove_at(list, 1);
  assert_is_int_equal(element, 1, "should remove the element from last position");
  add_to_start(list, &num);
  add_to_start(list, &num);
  element = remove_at(list, 2);
  assert_is_int_equal(element, 1, "should remove the element from last middle of the list");
  element = remove_at(list, 5);
  assert_is_null(element, "should not remove the element from invalid position");
  assert_equal(list->length, 2, "should update the count of the list");
}

void run_reverse()
{
  List_ptr list = create_list();
  int num = 1;
  int num2 = 2;
  add_to_start(list, &num);
  add_to_start(list, &num2);
  List_ptr expected_list = create_list();
  add_to_list(expected_list, &num);
  add_to_list(expected_list, &num2);
  describe("reverse");
  List_ptr actual_list = reverse(list);
  assert_is_list_equal(actual_list, expected_list, &match_int, "should reverse the list");
  List_ptr empty_list = create_list();
  actual_list = reverse(empty_list);
  assert_is_list_equal(actual_list, empty_list, &match_int, "should reverse the list the empty list");
}

void run_remove_first_occurrence()
{
  List_ptr list = create_list();
  int num = 1;
  int num2 = 2;
  add_to_start(list, &num);
  describe("remove_first_occurrence:");
  Element element = remove_first_occurrence(list, &num2, &match_int);
  assert_is_null(element, "should not remove any element if element is not present in the list");
  element = remove_first_occurrence(list, &num, &match_int);
  assert_is_int_equal(element, 1, "should remove the first occurrence of given number");
  assert_is_null(list->first, "should remove the last point also when list has only one element");
  add_to_start(list, &num);
  add_to_start(list, &num2);
  add_to_start(list, &num);
  element = remove_first_occurrence(list, &num, &match_int);
  assert_equal(list->length, 2, "should not remove more than one element");
}

int main(void)
{
  run_create_list();
  run_add_to_start();
  run_add_to_list();
  run_insert_at();
  run_remove_from_start();
  run_remove_from_end();
  run_remove_at();
  run_reverse();
  run_remove_first_occurrence();
  int test_count = increase_test_count();
  printf("\nTotal: %d Passing\n", test_count);
  return 0;
}