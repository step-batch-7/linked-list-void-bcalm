#include "linkedlist.h"

List_ptr create_list()
{
  List_ptr list = malloc(sizeof(LinkedList));
  list->first = NULL;
  list->last = NULL;
  list->length = 0;
  return list;
}

Status add_to_list(List_ptr list, Element value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL)
  {
    return Failure;
  }
  new_node->element = value;
  new_node->next = NULL;
  Node_ptr *ptr_to_set = &list->first;
  if (list->last != NULL)
  {
    ptr_to_set = &list->last->next;
  }
  (*ptr_to_set) = new_node;
  list->last = new_node;
  list->length += 1;
  return Success;
}

Status add_to_start(List_ptr list, Element value)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL)
  {
    return Failure;
  }
  new_node->element = value;
  new_node->next = list->first;

  if (list->length == 0)
  {
    list->last = new_node;
  }
  list->first = new_node;
  list->length++;
  return Success;
}

Status insert_at(List_ptr list, Element value, int position)
{
  Node_ptr new_node = malloc(sizeof(Node));
  if (new_node == NULL || list->length < position || position < 0)
  {
    return Failure;
  }
  new_node->element = value;
  new_node->next = NULL;

  if (position == 0)
  {
    return add_to_start(list, value);
  }
  if (position == list->length)
  {
    return add_to_list(list, value);
  }
  Node_ptr current = list->first;
  for (int length = 0; length < position - 1; length++)
  {
    current = current->next;
  }
  new_node->next = current->next;
  current->next = new_node;
  list->length++;
  return Success;
}

List_ptr reverse(List_ptr list)
{
  List_ptr reverse_list = create_list();
  if (list->first == NULL)
  {
    return reverse_list;
  }
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    add_to_start(reverse_list, p_walk->element);
    p_walk = p_walk->next;
  }
  return reverse_list;
};

void display_void(List_ptr list, Display display_func)
{
  if (list->first == NULL)
  {
    printf("List is empty \n");
    return;
  }
  Node_ptr p_walk = list->first;
  while (p_walk != NULL)
  {
    display_func(p_walk->element);
    p_walk = p_walk->next;
  }
  printf("Total elements in list is/are %d", list->length);
}
