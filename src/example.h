#ifndef EXAMPLE_H_INCLUDED
#define EXAMPLE_H_INCLUDED

typedef struct example example;

struct example
{
  int counter;
};

example *example_new();
void     example_construct(example *);
void     example_destruct(example *);
void     example_delete(example *);

#endif /* EXAMPLE_H_INCLUDED */
