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

Element square(Element value)
{
  int *result = malloc(sizeof(int));
  *result = (*(int *)value) * (*(int *)value);
  return (Element)result;
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
int main()
{
  return 0;
}
