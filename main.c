#include "graphic.h"
#include "matrix.h"
#include "print_dot.h"

int main(int argc, char **argv) {
  // matrix m = 0xC0000C0000C0000C;
  matrix m1 = 0x8080808080808080;
  matrix m2 = 0x00000000FFFFFFFF;
  matrix m3 = 0x0101010101010101;
  matrix m4 = 0x0102040810204080;
  matrix m5 = 0x8040201008040201;
  matrix mar[5] = {m1, m2, m3, m4, m5};
  printdot(5, mar);
  moveright(5, mar);
  printdot(5, mar);
  moveright8(5, mar);
  printdot(5, mar);
}