#include "linkedlist.h"

void display_int(Element element)
{
  printf("Element is %d\n", *(int *)element);
}

void display_char(Element element)
{
  printf("Element is %c\n", *(char *)element);
}

int main()
{
  List_ptr list = create_list();
  int num = 1;
  char alphabet = 'a';
  Status status = add_to_list(list, &num);
  printf("Status(add_to_list) is :%d\n", status);
  status = add_to_start(list, &alphabet);
  printf("Status is(add_to_start) :%d\n", status);
  return 0;
}
