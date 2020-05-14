#ifndef __LINKEDLIST_TEST_H
#define __LINKEDLIST_TEST_H
#include "../linkedlist.h"
typedef char *Char_ptr;
typedef int *Int_ptr;

void print_status(Status);
void describe(Char_ptr);
void it(Char_ptr);
void assert_is_empty_list(List_ptr);
Status assert_is_null(Element);
Status assert_equal(int, int);
Status assert_is_int_equal(Element, Element);
Status assert_is_char_equal(Element, Element);

#endif