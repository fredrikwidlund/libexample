#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

#include "../src/example.h"

void core()
{
  example *e;

  e = example_new();
  assert_true(e);

  example_delete(e);
}

void memory()
{
  extern int debug_out_of_memory;
  example *e;

  debug_out_of_memory = 1;
  e = example_new();
  assert_false(e);
  debug_out_of_memory = 0;
}

int main()
{
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(core),
    cmocka_unit_test(memory)
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}

