#include <cstdio>
#include <climits>
void func(unsigned int ui_a, unsigned int ui_b) {
  if (UINT_MAX - ui_a < ui_b)
    printf("Error: Addition would cause overflow\n");
  else
    printf("Result: %u + %u = %u\n", ui_a, ui_b, ui_a + ui_b);
}
int main() {
  func(4000000000U, 500000000U);
  return 0;
}
