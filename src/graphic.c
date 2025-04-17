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

void moverightn(uint8_t matc, matrix *matv, uint8_t amount) {
  for (amount; amount > 0; amount--)
    moveright(matc, matv);
  moveright(matc, matv);
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

matrix num_proto[] = {
    0x40A0A0A0A0A0A040, // 0
    0x40C04040404040E0, // 1
    0x40A0A020408080E0, // 2
    0x40A0204020A0A040, // 3
    0xA0A0A0A0F0202020, // 4
    0xE08080C0202020C0, // 5
    0x40A08040A0A0A040, // 6
    0xE0A0A02040404040, // 7
    0x40A0A040A0A0A040, // 8
    0x40A0A0A04020A040  // 9
};

void drawchar(matrix *matv, char ch) {
  matrix m;

  if (ch >= '0' && ch <= '9')
    m = num_proto[ch - '0'];
  else {
    switch (ch) {
    case ':':
      m = 0xC0C00000C0C000;
      break;

    default:
      m = 0;
    }
  }

  *matv |= m;
}