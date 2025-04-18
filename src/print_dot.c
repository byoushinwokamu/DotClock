#include "print_dot.h"

void printdot(uint8_t matc, const matrix_t *matv) {
  int8_t r, c, m;
  if (matc == 0)
    return;
  for (r = 7; r >= 0; r--) {
    for (m = 0; m < matc; m++) {
      for (c = 7; c >= 0; c--) {
        printf("%s", bitcheck(matv + m, r, c) ? "■ " : "□ ");
      }
    }
    printf("\n");
  }
  printf("\n");
}