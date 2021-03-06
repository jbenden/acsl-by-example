
#include "random_number.h"

unsigned short random_seed[3] = { 0x243f, 0x6a88, 0x85a3 };

/* see IEEE 1003.1-2008, 2016 Edition for specification */
/*@
  assigns random_seed[0..2];
  ensures 0 <= \result <= 0x7fffffff;
*/
static long my_lrand48(void)
{
  unsigned long long state = (unsigned long long)random_seed[0] << 32
          | (unsigned long long)random_seed[1] << 16
          | (unsigned long long)random_seed[2];

  state = (0x5deece66dull * state + 0xbull) % (1ull << 48);

  long result = state / (1ull << 17);

  random_seed[0] = state >> 32 & 0xffff;
  random_seed[1] = state >> 16 & 0xffff;
  random_seed[2] = state >>  8 & 0xffff;

  return result;
}

size_type random_number(size_type n)
{
  return my_lrand48() % n;
}

