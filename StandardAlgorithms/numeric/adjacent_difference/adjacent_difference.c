
#include "adjacent_difference.h"
#include "AdjacentDifferenceLemmas.h"

size_type
adjacent_difference(const value_type* a, size_type n, value_type* b)
{
  if (n > 0) {
    b[0] = a[0];

    /*@
       loop invariant index:      1 <= i <= n;
       loop invariant unchanged:  Unchanged{Here,Pre}(a, n);
       loop invariant difference: AdjacentDifference(a, i, b);
       loop assigns i, b[1..n-1];
       loop variant n - i;
    */
    for (size_type i = 1u; i < n; ++i) {
      //@ assert bound: VALUE_TYPE_MIN <= Difference(a, i) <= VALUE_TYPE_MAX;
      /*@
        assigns b[i];
        ensures step: Unchanged{Old,Here}(b, i);
        ensures step: b[i] == Difference(a, i);
      */
      b[i] = a[i] - a[i - 1u];
      //@ assert difference: AdjacentDifference{Here}(a, i+1, b);
    }
  }

  return n;
}

