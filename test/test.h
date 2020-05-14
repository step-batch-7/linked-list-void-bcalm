#ifndef __LINKEDLIST_TEST_H
#define __LINKEDLIST_TEST_H
#include "../linkedlist.h"
#include <stdlib.h>

typedef char *Char_ptr;
typedef int *Int_ptr;

void print_status(Status);
void describe(Char_ptr);
int increase_test_count();
void assert_is_null(Element, Char_ptr);
void assert_equal(int, int, Char_ptr);
void assert_is_int_equal(Element, int, Char_ptr);
void assert_is_list_equal(List_ptr, List_ptr, Matcher, Char_ptr);
void assert_is_char_equal(Element, char, Char_ptr);
#endif