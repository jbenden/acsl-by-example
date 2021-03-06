
#include "copy_backward.h"
#include "Unchanged.h"

void copy_backward(const value_type* a, size_type n, value_type* b)
{
  /*@
    loop invariant bound:     0 <= i <= n;
    loop invariant equal:     EqualRanges{Here,Pre}(b, i, n, a);
    loop invariant unchanged: Unchanged{Here,Pre}(a, i);
    loop assigns i, b[0..n-1];
    loop variant i;
   */
  for (size_type i = n; i > 0u; --i) {
    b[i-1u] = a[i-1u];
  }
}

