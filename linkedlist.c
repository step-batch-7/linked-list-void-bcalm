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

Element remove_from_start(List_ptr list)
{
  if (list->first == NULL)
  {
    return NULL;
  }
  Node_ptr first_node = list->first;
  if (list->length == 1)
  {
    list->last = NULL;
  }
  Element removed_element = first_node->element;
  list->first = first_node->next;
  free(first_node);
  list->length -= 1;
  return removed_element;
}

Element remove_from_end(List_ptr list)
{
  if (list->first == NULL)
  {
    return NULL;
  }
  list->length--;
  Element removed_element;
  if (list->first->next == NULL)
  {
    removed_element = list->first->element;
    free(list->first);
    list->first = NULL;
    list->last = NULL;
    return removed_element;
  }

  Node_ptr current = list->first;
  while (current->next->next != NULL)
  {
    current = current->next;
  }
  removed_element = current->next->element;
  free(current->next);
  current->next = NULL;
  list->last = current;
  return removed_element;
}

Element remove_at(List_ptr list, int position)
{
  if (list->first == NULL || list->length - 1 < position || position < 0)
  {
    return NULL;
  }
  if (position == 0)
  {
    return remove_from_start(list);
  }
  if (position == list->length - 1)
  {
    return remove_from_end(list);
  }
  Node_ptr current = list->first;
  for (int count = 0; count < position - 1; count++)
  {
    current = current->next;
  }

  Node_ptr removed_node = current->next;
  Element removed_element = removed_node->element;
  Node_ptr next_node = removed_node->next;
  current->next = next_node;
  free(removed_node);
  list->length--;
  return removed_element;
}

Element remove_first_occurrence(List_ptr list, Element element, Matcher matcher)
{
  Node_ptr current = list->first, previous_node, node_to_free;
  while (current != NULL)
  {
    if ((*matcher)(current->element, element))
    {
      if (current == list->first)
      {
        return remove_from_start(list);
      }
      node_to_free = previous_node->next;
      if (current == list->last)
      {
        previous_node->next = NULL;
        list->last = previous_node;
      }
      else
      {
        previous_node->next = current->next;
      }
      list->length--;
      Element removed_element = node_to_free->element;
      free(node_to_free);
      return removed_element;
    }
    previous_node = current;
    current = current->next;
  }
  return NULL;
}

List_ptr remove_all_occurrences(List_ptr list, Element element, Matcher matcher)
{
  Node_ptr current = list->first;
  Node_ptr previous_node, next_node;
  Element removed_element;
  List_ptr removed_element_list = create_list();

  while (current != NULL)
  {
    next_node = current->next;
    if ((*matcher)(current->element, element))
    {
      if (current == list->first)
      {
        removed_element = remove_from_start(list);
        next_node = list->first;
      }
      else
      {
        removed_element = current->element;
        if (current == list->last)
        {
          previous_node->next = NULL;
          list->last = previous_node;
        }
        else
        {
          previous_node->next = current->next;
        }
        list->length--;
        free(current);
        current = previous_node;
      }
      add_to_list(removed_element_list, removed_element);
    }
    previous_node = current;
    current = next_node;
  }
  return removed_element_list;
}

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
  printf("Total elements in list is/are %d\n", list->length);
}
