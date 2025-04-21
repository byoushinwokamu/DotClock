#include "asset.h"
#include "graphic.h"
#include "matrix.h"
#include "print_dot.h"

matrix_t mar[5];

int main(int argc, char **argv) {
  canvas_t *canvas = newcanvas(8, 40);

  draw(canvas, 0, C_0_LEGACY, 0, 0, NOALIGN);
  draw(canvas, 1, C_1_LEGACY, 0, 4, NOALIGN);
  draw(canvas, 2, C_2_LEGACY, 0, 8, NOALIGN);
  draw(canvas, 3, C_3_LEGACY, 0, 12, NOALIGN);
  draw(canvas, 4, C_4_LEGACY, 0, 16, NOALIGN);
  draw(canvas, 5, C_5_LEGACY, 0, 21, NOALIGN);
  draw(canvas, 6, C_6_LEGACY, 0, 25, NOALIGN);
  draw(canvas, 7, C_7_LEGACY, 0, 29, NOALIGN);
  draw(canvas, 8, C_8_LEGACY, 0, 33, NOALIGN);
  draw(canvas, 9, C_9_LEGACY, 0, 37, NOALIGN);
  printcanvas(canvas);
  mar[0] = conversion(canvas, 0, 0);
  mar[1] = conversion(canvas, 0, 8);
  mar[2] = conversion(canvas, 0, 16);
  mar[3] = conversion(canvas, 0, 24);
  mar[4] = conversion(canvas, 0, 32);
  printdot(5, mar);

  return 0;
}