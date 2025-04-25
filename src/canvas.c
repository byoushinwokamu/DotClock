#include "canvas.h"
#include <stdio.h>
#include <stdlib.h>

canvas_t *newcanvas(int row, int col) {
  canvas_t *ret = (canvas_t *)calloc(1, sizeof(canvas_t));
  ret->cellv = (cell_t *)calloc(row * col, sizeof(cell_t));
  ret->rsize = row, ret->csize = col;
  return ret;
}

void deletecanvas(canvas_t *canvas) {
  free(canvas->cellv);
  free(canvas);
}

void printcanvas(canvas_t *can) {
  int rs = can->rsize, cs = can->csize;
  for (int r = 0; r < rs; r++) {
    for (int c = 0; c < cs; c++) {
      printf("%s", can->cellv[r * cs + c] ? "■ " : "□ ");
    }
    printf("\n");
  }
  printf("\n");
}