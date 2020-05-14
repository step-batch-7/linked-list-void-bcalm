#include "linkedlist.h"

void display_char(Element element)
{
  printf("Element is %c\n", *(char *)element);
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
  *(int *)element +=1;
}

Status is_even(Element number)
{
  int num = *(int *)number;
  return num % 2 == 0;
}
int main()
{
  List_ptr list = create_list();
  int num1 = 1;
  int num2 = 2;
  int num3 = 3;
  int num4 = 4;
  int num5 = 5;
  int num6 = 6;
  add_to_list(list, &num1);
  add_to_list(list, &num2);
  add_to_list(list, &num3);
  add_to_list(list, &num4);
  add_to_list(list, &num5);
  add_to_list(list, &num6);
  int num = 0;
  forEach(list, &sum);
  display_int(element);
  return 0;
}
