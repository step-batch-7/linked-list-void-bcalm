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
  int num = 75;
  char alphabet = 'a';
  Status status = add_to_list(list, &num);
  printf("Status(add_to_list) is :%d\n", status);
  status = add_to_start(list, &alphabet);
  printf("Status is(add_to_start) :%d\n", status);
  status = insert_at(list, &alphabet, 0);
  printf("Status is(insert_at) :%d\n", status);
  status = insert_at(list, &num, 3);
  printf("Status is(insert_at) :%d\n", status);
  status = insert_at(list, &alphabet, 3);
  printf("Status is(insert_at) :%d\n", status);
  status = insert_at(list, &alphabet, 2);
  printf("Status is(insert_at) :%d\n", status);
  display_void(list, &display_char);
  return 0;
}
