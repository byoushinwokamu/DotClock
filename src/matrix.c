#include "matrix.h"

uint8_t bitcheck(const matrix *mat, uint8_t row, uint8_t col) {
  return (*mat) & (1ULL << (row * 8 + col)) ? 1 : 0;
}

void bitset(matrix *mat, uint8_t row, uint8_t col) {
  *mat |= 1ULL << (row * 8 + col);
}

void bitclear(matrix *mat, uint8_t row, uint8_t col) {
  *mat &= ~(1ULL << (row * 8 + col));
}

void bitcopy(const matrix *mats, uint8_t rows, uint8_t cols, matrix *matd,
             uint8_t rowd, uint8_t cold) {
  if (bitcheck(mats, rows, cols))
    bitset(matd, rowd, cold);
  else
    bitclear(matd, rowd, cold);
}

void transpose(matrix *mat) {
  uint8_t r, c, t;

  for (r = 0; r < 7; r++) {
    for (c = r + 1; c < 8; c++) {
      t = bitcheck(mat, r, c) ? 1 : 0;
      t |= bitcheck(mat, r, c) ? 2 : 0;

      switch (t) {
      case 1: // (r,c)=1 and (c,r)=0
        bitclear(mat, r, c);
        bitset(mat, c, r);
        break;
      case 2: // (r,c)=0 and (c,r)=1
        bitset(mat, r, c);
        bitclear(mat, c, r);
        break;
      }
    }
  }
}

void rotate_cw(matrix *mat) {
  uint8_t r, c, t;

  for (r = 0; r < 4; r++) {
    for (c = 0; c < 4; c++) {
      t = bitcheck(mat, r, c);

      bitcopy(mat, 8 - r, c, mat, r, c);
      bitcopy(mat, 8 - r, 8 - c, mat, 8 - r, c);
      bitcopy(mat, r, 8 - c, mat, 8 - r, 8 - c);

      if (t)
        bitset(mat, r, 8 - c);
      else
        bitclear(mat, r, 8 - c);
    }
  }
}
