#include "linkedlist.h"

void display_char(Element element)
{
  printf("Element is %c\n", *(char *)element);
}

Status match_int(Element element1, Element element2)
{
  return *(int *)element1 == *(int *)element2;
}

void display_int(Element element)
{
  printf("Element is %d\n", *(int *)element);
}

int main()
{

  return 0;
}
