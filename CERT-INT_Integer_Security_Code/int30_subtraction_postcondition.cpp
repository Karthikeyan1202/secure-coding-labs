#include <cstdio>
void func(unsigned int ui_a, unsigned int ui_b) {
  unsigned int udiff = ui_a - ui_b;
  if (udiff > ui_a)
    printf("Error: Subtraction caused unsigned wrap\n");
  else
    printf("Result: %u - %u = %u\n", ui_a, ui_b, udiff);
}
int main() {
  func(100U, 200U);
  return 0;
}
