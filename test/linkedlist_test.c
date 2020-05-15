#include "test.h"

Status match_int(Element element1, Element element2)
{
  return *(int *)element1 == *(int *)element2;
}

Status match_char(Element element1, Element element2)
{
  return *(char *)element1 == *(char *)element2;
}

Element square(Element value)
{
  int_ptr result = malloc(sizeof(int));
  *result = (*(int *)value) * (*(int *)value);
  return (Element)result;
}

Element to_upper_case(Element character)
{
  Char_ptr alphabet = malloc(sizeof(char));
  char alphabet_ascii = *(char *)character;
  *alphabet = alphabet_ascii >= 97 && alphabet_ascii <= 122 ? alphabet_ascii - 32 : alphabet_ascii;
  return (Element)alphabet;
}

Element sum(Element num1, Element num2)
{
  int_ptr addition = malloc(sizeof(int));
  *addition = (*(int *)num1) + (*(int *)num2);
  return (Element)addition;
}

void increment(Element element)
{
  *(int *)element += 1;
}

Status is_even(Element number)
{
  int num = *(int *)number;
  return num % 2 == 0;
}

Status is_vowel(Element character)
{
  char alphabet = *(char *)character;
  return alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u';
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

void run_remove_all_occurrences()
{
  List_ptr list = create_list();
  int num = 1;
  int num2 = 2;
  describe("remove_all_occurrences:");
  add_to_start(list, &num);
  add_to_start(list, &num2);
  add_to_start(list, &num);
  List_ptr removed_list = remove_all_occurrences(list, &num, &match_int);
  List_ptr expected_list = create_list();
  add_to_start(expected_list, &num);
  add_to_start(expected_list, &num);
  assert_is_list_equal(removed_list, expected_list, &match_int, "should return the removed elements list");
  assert_equal(list->length, 1, "should update the count");
}
void run_add_unique()
{
  List_ptr list = create_list();
  char alphabet = 'a';
  char alphabet1 = 'b';
  add_to_start(list, &alphabet);
  describe("add_unique");
  Status status = add_unique(list, &alphabet1, &match_char);
  assert_equal(status, 1, "should successfully insert the element");
  assert_equal(list->length, 2, "should update the count");
  status = add_unique(list, &alphabet1, match_char);
  assert_equal(status, 0, "should fail to insert the element when element is already present");
}

void run_clear_list()
{
  List_ptr list = create_list();
  describe("clear_list:");
  Status status = clear_list(list);
  assert_equal(status, 0, "should fail to clear list when list is already empty");
  double num = 2.00;
  add_to_start(list, &num);
  status = clear_list(list);
  assert_equal(status, 1, "should successfully clear the list when list is empty");
  assert_equal(list->length, 0, "should update the count");
  assert_is_null(list->first, "should point out the first to the null");
  assert_is_null(list->last, "should point out the last to the null");
}

void run_map()
{
  describe("Map void:");
  List_ptr expected_list = create_list();
  int number1 = 1;
  int number2 = 4;
  int number3 = 9;
  add_to_start(expected_list, &number1);
  add_to_start(expected_list, &number2);
  add_to_start(expected_list, &number3);
  List_ptr int_list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  add_to_start(int_list, &num1);
  add_to_start(int_list, &num2);
  add_to_start(int_list, &num3);
  List_ptr mapped_list = map(int_list, &square);
  assert_is_list_equal(mapped_list, expected_list, &match_int, "should square all the number of the list");

  List_ptr char_list = create_list();
  char alphabet1 = 'a';
  char alphabet2 = 'b';
  char alphabet3 = 'c';
  add_to_start(char_list, &alphabet1);
  add_to_start(char_list, &alphabet2);
  add_to_start(char_list, &alphabet3);

  List_ptr mapped_char_list = map(char_list, &to_upper_case);
  List_ptr expected_char_list = create_list();
  char cap_alphabet1 = 'A';
  char cap_alphabet2 = 'B';
  char cap_alphabet3 = 'C';
  add_to_start(expected_char_list, &cap_alphabet1);
  add_to_start(expected_char_list, &cap_alphabet2);
  add_to_start(expected_char_list, &cap_alphabet3);
  assert_is_list_equal(mapped_char_list, expected_char_list, &match_char, "should map all alphabets to upper case");

  List_ptr empty_list = create_list();
  List_ptr mapped_empty_list = map(empty_list, &to_upper_case);
  assert_is_list_equal(mapped_empty_list, empty_list, &match_char, "should map the empty list");
}

void run_filter()
{
  describe("Filter void:");
  List_ptr int_list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  add_to_start(int_list, &num1);
  add_to_start(int_list, &num2);
  add_to_start(int_list, &num3);
  List_ptr expected_list = create_list();
  add_to_start(expected_list, &num2);
  List_ptr filtered_list = filter(int_list, &is_even);
  assert_is_list_equal(filtered_list, expected_list, &match_int, "should filter the even numbers");

  List_ptr char_list = create_list();
  char alphabet1 = 'a';
  char alphabet2 = 'b';
  char alphabet3 = 'c';
  add_to_start(char_list, &alphabet1);
  add_to_start(char_list, &alphabet2);
  add_to_start(char_list, &alphabet3);
  List_ptr filtered_char_list = filter(char_list, &is_vowel);
  List_ptr expected_char_list = create_list();
  add_to_start(expected_char_list, &alphabet1);
  assert_is_list_equal(filtered_char_list, expected_char_list, &match_char, "should filter the vowels");

  List_ptr empty_list = create_list();
  List_ptr filtered_empty_list = filter(empty_list, &is_vowel);
  assert_is_list_equal(filtered_empty_list, empty_list, &match_char, "should filter the empty list");
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
  run_remove_all_occurrences();
  run_add_unique();
  run_clear_list();
  run_map();
  run_filter();
  int test_count = increase_test_count();
  printf("\nTotal: %d Passing\n", test_count);
  return 0;
}