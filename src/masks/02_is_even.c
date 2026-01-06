#include <assert.h>
#include <limits.h>

/* Returns 1 when argument is even and 0 when odd. */
char is_even(int x) { return (char)(~x & 0x01); }

int main() {
  char odd = 0;
  char even = 1;

  /* Unit Tests */
  assert(is_even(0) == even);

  assert(is_even(1) == odd);
  assert(is_even(-1) == odd);

  assert(is_even(2) == even);
  assert(is_even(-2) == even);

  assert(is_even(INT_MIN) == even); // INT_MIN = -1 * 2^32
  assert(is_even(INT_MAX) == odd);  // INT_MAX = 2^32 - 1

  return 0;
}
