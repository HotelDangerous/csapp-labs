#include <assert.h>
#include <limits.h>

/* Returns 1 if x >= 0, otherwise returns 0.
 * Assumes 32-bit two's complement int with arithmetic right shift. */
int check_sign_int(int x) { return ~(x >> 31) & 0x01; }

int main() {
  int non_neg = 1;
  int neg = 0;

  /* Unit Testing */
  assert(check_sign_int(0) == non_neg);

  assert(check_sign_int(-1) == neg);
  assert(check_sign_int(1) == non_neg);

  assert(check_sign_int(0x7FFFFFFF) == non_neg);
  assert(check_sign_int(0x8FFFFFFF) == neg);

  assert(check_sign_int(0x0FFFFFFF) == non_neg);
  assert(check_sign_int(0xFFFFFFFF) == neg);

  assert(check_sign_int(INT_MIN) == neg);     // INT_MIN = -1 * 2^31
  assert(check_sign_int(INT_MAX) == non_neg); // INT_MAX = 2^31 - 1

  return 0;
}
