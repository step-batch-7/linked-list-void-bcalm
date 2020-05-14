#include "test.h"

void print_status(Status status)
{
  if (status)
    printf("    ✅ ");
  else
    printf("    ❌ ");
}

int increase_test_count()
{
  static int test_number = -1;
  test_number++;
  return test_number;
}

void describe(Char_ptr message)
{
  printf("\n\n%s\n\n", message);
}

void assert_is_null(Element element, Char_ptr message)
{
  Status status = element == NULL;
  print_status(status);
  printf("%s\n", message);
  increase_test_count();
}

void assert_equal(int actual, int expected, Char_ptr message)
{
  Status status = actual == expected;
  print_status(status);
  printf("%s\n", message);
  increase_test_count();
}

void assert_is_int_equal(Element actual, int expected, Char_ptr message)
{
  Status status = *(int *)actual == expected;
  print_status(status);
  printf("%s\n", message);
  increase_test_count();
}
void assert_is_char_equal(Element actual, char expected, Char_ptr message)
{
  Status status = *(char *)actual == expected;
  print_status(status);
  printf("%s\n", message);
  increase_test_count();
}

void assert_is_list_equal(List_ptr actual, List_ptr expected, Matcher matcher, Char_ptr message)
{
  Status status = actual->length == expected->length;
  Node_ptr actual_current = actual->first;
  Node_ptr expected_current = actual->first;
  while (actual_current != NULL)
  {
    if (!matcher(actual_current->element, expected_current->element))
    {
      status = Failure;
    }
    actual_current = actual_current->next;
    expected_current = expected_current->next;
  }
  print_status(status);
  printf("%s\n", message);
  increase_test_count();
}