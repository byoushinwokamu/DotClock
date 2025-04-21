#ifndef _CANVAS_H_
#define _CANVAS_H_

#define LAYER_MAX (31)
typedef unsigned int cell_t;
typedef struct {
  cell_t *cellv;
  int rsize, csize;
} canvas_t;

canvas_t *newcanvas(int row, int col);
void printcanvas(canvas_t *can);

#endif