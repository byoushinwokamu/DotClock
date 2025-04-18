#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stdint.h>

typedef unsigned long long matrix_t;

uint8_t bitcheck(const matrix_t *mat, uint8_t row, uint8_t col);
void bitset(matrix_t *mat, uint8_t row, uint8_t col);
void bitclear(matrix_t *mat, uint8_t row, uint8_t col);
void bitcopy(const matrix_t *mats, uint8_t rows, uint8_t cols, matrix_t *matd,
             uint8_t rowd, uint8_t cold);
void transpose(matrix_t *mat);
void rotate_cw(matrix_t *mat);

#endif