#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "matrix.h"

// typedef enum { LEFT, RIGHT } DIR;

// void movedots(uint8_t matc, matrix *matv, DIR dir, uint8_t amount);
void moveright(uint8_t matc, matrix *matv);
void moverightn(uint8_t matc, matrix *matv, uint8_t amount);
void moveright8(uint8_t matc, matrix *matv);
void drawchar(matrix *matv, char ch);

#endif