#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdlib.h>

#include "example.h"

example *example_new()
{
  example *e;

  e = malloc(sizeof *e);
  if (!e)
    return NULL;

  example_construct(e);
  return e;
}

void example_construct(example *e)
{
  *e = (example) {.counter = 0};
}

void example_destruct(example *e)
{
  (void) e;
}

void example_delete(example *e)
{
  example_destruct(e);
  free(e);
}
