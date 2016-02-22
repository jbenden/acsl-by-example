
#ifndef EQUAL_RANGE_H_INCLUDED
#define EQUAL_RANGE_H_INCLUDED

#include "ForallCompare.h"
#include "Sorted.h"

struct spair {
  size_type first;
  size_type second;
};

typedef struct spair size_type_pair;

/*@
  requires \valid_read(a + (0..n-1));
  requires Sorted(a, n);

  assigns \nothing;

  ensures result:  0 <= \result.first <= \result.second <= n;
  ensures left:    StrictUpperBound(a, 0, \result.first, val);
  ensures middle:  ConstantRange(a, \result.first,
                                    \result.second, val);
  ensures right:   StrictLowerBound(a, \result.second, n, val);
 */
size_type_pair
equal_range(const value_type* a, size_type n, value_type val);

#endif /* EQUAL_RANGE_H_INCLUDED */

