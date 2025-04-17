#include "graphic.h"

// void movedots(uint8_t matc, matrix *matv, DIR dir, uint8_t amount) {
//   int8_t r, c, m;
//   int8_t am = dir == LEFT ? -(int8_t)amount : amount;
//   int8_t ccur = dir == LEFT ? amount : (8 * matc - amount);
//   int8_t mcur = dir == LEFT ? 0 : matc - 1;

//   if (dir == LEFT)
//     while (ccur >= 8)
//       ccur -= 8, mcur += 1;
// }

void moveright(uint8_t matc, matrix *matv) {
  int8_t r, c, m;
  for (m = matc - 1; m >= 0; m--) {
    for (r = 0; r < 8; r++) {
      for (c = 0; c < 7; c++) {
        bitcopy(matv + m, r, c + 1, matv + m, r, c);
      }
      if (m > 0)
        bitcopy(matv + m - 1, r, 0, matv + m, r, 7);
      else
        bitclear(matv, r, 7);
    }
  }
}

void moveright8(uint8_t matc, matrix *matv) {
  int8_t r, c, m;
  for (m = matc - 1; m > 0; m--) {
    for (r = 0; r < 8; r++) {
      for (c = 0; c < 8; c++) {
        bitcopy(matv + m - 1, r, c, matv + m, r, c);
      }
    }
  }
  *matv = 0;
}