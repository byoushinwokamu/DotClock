#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

// legacy
#include "matrix.h"

void moveright(uint8_t matc, matrix_t *matv);
void moverightn(uint8_t matc, matrix_t *matv, uint8_t amount);
void moveright8(uint8_t matc, matrix_t *matv);
void moveleft(uint8_t matc, matrix_t *matv);
void moveleftn(uint8_t matc, matrix_t *matv, uint8_t amount);
void drawchar(matrix_t *matv, char ch, char dir);

// renewal
#include "canvas.h"
typedef enum { LEFT, RIGHT, UP, DOWN } dir_t;
typedef enum { NOALIGN, L, UL, DL, R, UR, DR, U, D } align_t;

void moveup(uint8_t matc, matrix_t *matv);
void movedown(uint8_t matc, matrix_t *matv);
void move(canvas_t *canvas, int layer, dir_t direction);
void draw(canvas_t *canvas, int layer, matrix_t obj, int row, int col,
          align_t align);
matrix_t conversion(canvas_t *canvas, int row, int col);

#endif