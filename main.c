#include "graphic.h"
#include "matrix.h"
#include "print_dot.h"

int main(int argc, char **argv) {
  // matrix m1 = 0x8080808080808080;
  // matrix m2 = 0x00000000FFFFFFFF;
  // matrix m3 = 0x0101010101010101;
  // matrix m4 = 0x0102040810204080;
  // matrix m5 = 0x8040201008040201;
  // matrix mar[5] = {m1, m2, m3, m4, m5};
  matrix mar[5] = {
      0,
  };

  drawchar(mar, '9');
  moverightn(5, mar, 3);

  drawchar(mar, '8');
  moverightn(5, mar, 3);

  drawchar(mar, '7');
  moverightn(5, mar, 3);

  drawchar(mar, '6');
  moverightn(5, mar, 3);

  drawchar(mar, '5');
  moverightn(5, mar, 4);

  drawchar(mar, '4');
  moverightn(5, mar, 3);

  drawchar(mar, '3');
  moverightn(5, mar, 3);

  drawchar(mar, '2');
  moverightn(5, mar, 3);

  drawchar(mar, '1');
  moverightn(5, mar, 3);

  drawchar(mar, '0');

  printdot(5, mar);
}