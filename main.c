#include "linkedlist.h"

void display_int(Element element)
{
  printf("Element is %d\n", *(int *)element);
}

void display_char(Element element)
{
  printf("Element is %d\n", *(int *)element);
}

int main()
{
  List_ptr list = create_list();
  int num = 1;
  Status status = add_to_list(list, &num);
  return 0;
}
