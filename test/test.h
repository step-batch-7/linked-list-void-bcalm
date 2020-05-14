#ifndef __LINKEDLIST_TEST_H
#define __LINKEDLIST_TEST_H

typedef char *Char_ptr;
typedef int *Int_ptr;

void print_status(Status);
void describe(Char_ptr);
void it(Char_ptr);
Status assert_is_int_equal(Element, Element);
Status assert_is_char_equal(Element, Element);

#endif