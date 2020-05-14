#include "test.h"

void print_status(Status status)
{
  if (status)
    printf("✅\n");
  else
    printf("❌\n");
}

void it(Char_ptr message)
{
  printf("%s", message);
}

void describe(Char_ptr message)
{
  static int test_number = 1;
  printf("\n%d => %s\n", test_number, message);
  test_number++;
}

Status assert_is_int_equal(Element actual_value, Element expected_value)
{
  return *(int *)actual_value == *(int *)expected_value;
}

Status assert_is_char_equal(Element actual_value, Element expected_value)
{
  return *(char *)actual_value == *(char *)expected_value;
}

Status assert_equal(int actual, int expected)
{
  return actual == expected;
}

Status assert_is_null(Element element)
{
  return element == NULL;
}

void assert_is_empty_list(List_ptr list)
{
  Status status = assert_equal(list->length, 0);
  status = status ? assert_is_null(list->first) : Failure;
  status = status ? assert_is_null(list->last) : Failure;
  print_status(status);
}