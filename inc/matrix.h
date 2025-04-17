#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdint.h>

typedef unsigned long long matrix;

uint8_t bitcheck(const matrix *mat, uint8_t row, uint8_t col);
void bitset(matrix *mat, uint8_t row, uint8_t col);
void bitclear(matrix *mat, uint8_t row, uint8_t col);
void bitcopy(const matrix *mats, uint8_t rows, uint8_t cols, matrix *matd,
             uint8_t rowd, uint8_t cold);
void transpose(matrix *mat);
void rotate_cw(matrix *mat);

#endif