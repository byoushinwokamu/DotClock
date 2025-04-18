#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "matrix.h"

void moveright(uint8_t matc, matrix_t *matv);
void moverightn(uint8_t matc, matrix_t *matv, uint8_t amount);
void moveright8(uint8_t matc, matrix_t *matv);
void moveleft(uint8_t matc, matrix_t *matv);
void moveleftn(uint8_t matc, matrix_t *matv, uint8_t amount);
void drawchar(matrix_t *matv, char ch, char dir);

#endif