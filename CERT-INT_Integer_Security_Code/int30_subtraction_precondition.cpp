#include <cstdio>
void func(unsigned int ui_a, unsigned int ui_b) {
  if (ui_a < ui_b)
    printf("Error: Subtraction would cause unsigned wrap\n");
  else
    printf("Result: %u - %u = %u\n", ui_a, ui_b, ui_a - ui_b);
}
int main() {
  func(100U, 200U);
  return 0;
}
