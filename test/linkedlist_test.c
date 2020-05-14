#include "test.h"

void run_create_list()
{
  List_ptr list = create_list();
  describe("Create list:");
  it("should create empty list pointed to null and count is zero");
  assert_is_empty_list(list);
}

void runtests()
{
  printf("Tests are running...\n");
  run_create_list();
}

int main(void)
{
  printf("Testing start\n");
  printf(".............\n");
  runtests();
  printf(".............\n");
  printf("Testing end\n");
  return 0;
}