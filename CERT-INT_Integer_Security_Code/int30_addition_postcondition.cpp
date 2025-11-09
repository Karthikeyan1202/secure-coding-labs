#include <cstdio>
void func(unsigned int ui_a, unsigned int ui_b) {
  unsigned int usum = ui_a + ui_b;
  if (usum < ui_a)
    printf("Error: Addition caused unsigned wrap\n");
  else
    printf("Result: %u + %u = %u\n", ui_a, ui_b, usum);
}
int main() {
  func(4000000000U, 500000000U);
  return 0;
}
