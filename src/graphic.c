#include "graphic.h"
#include <stdlib.h>

void moveright(uint8_t matc, matrix_t *matv) {
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

void moverightn(uint8_t matc, matrix_t *matv, uint8_t amount) {
  for (amount; amount > 0; amount--)
    moveright(matc, matv);
  moveright(matc, matv);
}

void moveright8(uint8_t matc, matrix_t *matv) {
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

void moveleft(uint8_t matc, matrix_t *matv) {
  int8_t r, c, m;
  for (m = 0; m < matc; m++) {
    for (r = 0; r < 8; r++) {
      for (c = 7; c > 0; c--) {
        bitcopy(matv + m, r, c - 1, matv + m, r, c);
      }
      if (m < matc - 1)
        bitcopy(matv + m + 1, r, 7, matv + m, r, 0);
      else
        bitclear(matv + m, r, 0);
    }
  }
}

void moveleftn(uint8_t matc, matrix_t *matv, uint8_t amount) {
  for (amount; amount > 0; amount--)
    moveleft(matc, matv);
  moveleft(matc, matv);
}

matrix_t num_proto[] = {
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

matrix_t small_letter[] = {
    0,
};

matrix_t capital_letter[] = {
    0,
};

void drawchar(matrix_t *matv, char ch, char dir) {
  matrix_t m;

  if (ch >= '0' && ch <= '9')
    m = num_proto[ch - '0'];
  else if (ch >= 'a' && ch <= 'z') {
    m = small_letter[ch - 'a'];
  } else if (ch >= 'A' && ch <= 'Z') {
    m = capital_letter[ch - 'A'];
  } else {
    switch (ch) {
    case ':':
      m = 0xC0C00000C0C000;
      break;

    default:
      m = 0;
    }
  }

  if (dir == 'l') {
    while (!(m & 0x8080808080808080))
      moveleft(1, &m);
  }

  if (dir == 'r') {
    while (!(m & 0x0101010101010101))
      moveright(1, &m);
  }

  *matv |= m;
}

void moveup(uint8_t matc, matrix_t *matv) {
  int8_t r, c, m;
  for (m = matc - 1; m >= 0; m--) {
    for (c = 0; c < 8; c++) {
      for (r = 7; r > 0; r--) {
        bitcopy(matv + m, r - 1, c, matv + m, r, c);
      }
      bitclear(matv, 0, c);
    }
  }
}

void movedown(uint8_t matc, matrix_t *matv) {
  int8_t r, c, m;
  for (m = matc - 1; m >= 0; m--) {
    for (c = 0; c < 8; c++) {
      for (r = 0; r < 7; r++) {
        bitcopy(matv + m, r + 1, c, matv + m, r, c);
      }
      bitclear(matv, 7, c);
    }
  }
}

#define getlayer(C, L) ((C) & (1 << L))
#define setlayer(C, L) ((*(C)) |= (1 << L))
#define clearlayer(C, L) ((*(C)) &= ~(1 << L))
void copylayer(cell_t *source, cell_t *destination, int L) {
  if (getlayer(*source, L))
    setlayer(destination, L);
  else
    clearlayer(destination, L);
}

void move(canvas_t *canvas, int layer, dir_t direction) {
  if (layer < 0 || layer > LAYER_MAX)
    exit(-1);
  int r = canvas->rsize, c = canvas->csize;
  int rcur, ccur, dr, dc;

  switch (direction) {
  case LEFT:
    for (ccur = 0; ccur < c - 1; ccur++)
      for (rcur = 0; rcur < r; rcur++)
        copylayer(canvas->cellv + (rcur * c + ccur + 1),
                  canvas->cellv + (rcur * c + ccur), layer);
    for (rcur = 0; rcur < r; rcur++)
      clearlayer(canvas->cellv + (rcur * c + (c - 1)), layer);
    break;

  case RIGHT:
    for (ccur = c - 1; ccur > 0; ccur--)
      for (rcur = 0; rcur < r; rcur++)
        copylayer(canvas->cellv + (rcur * c + ccur - 1),
                  canvas->cellv + (rcur * c + ccur), layer);
    for (rcur = 0; rcur < r; rcur++)
      clearlayer(canvas->cellv + ((c - 1)), layer);
    break;

  case UP:
    for (rcur = 0; rcur < r - 1; rcur++)
      for (ccur = 0; ccur < c; ccur++)
        copylayer(canvas->cellv + ((rcur + 1) * c + ccur),
                  canvas->cellv + (rcur * c + ccur), layer);
    for (ccur = 0; ccur < c; ccur++)
      clearlayer(canvas->cellv + ((r - 1) * c + ccur), layer);
    break;

  case DOWN:
    for (rcur = r - 1; rcur > 0; rcur--)
      for (ccur = 0; ccur < c; ccur++)
        copylayer(canvas->cellv + ((rcur - 1) * r + ccur),
                  canvas->cellv + (rcur * c + ccur), layer);
    for (ccur = 0; ccur < c; ccur++)
      clearlayer(canvas->cellv + (ccur), layer);
    break;
  }
}

void draw(canvas_t *canvas, int layer, matrix_t obj, int row, int col,
          align_t align) {
  if (layer < 0 || layer > LAYER_MAX)
    exit(-1);
  if (row < 0 || col < 0)
    exit(-1);
  if (row >= canvas->rsize || col >= canvas->csize)
    exit(-1);

  if (align == L || align == UL || align == DL)
    while (!(obj & 0x8080808080808080))
      moveleft(1, &obj);

  if (align == R || align == UR || align == DR)
    while (!(obj & 0x0101010101010101))
      moveright(1, &obj);

  if (align == U || align == UL || align == UR)
    while (!(obj & 0xFF00000000000000))
      moveup(1, &obj);

  if (align == D || align == DL || align == DR)
    while (!(obj & 0x00000000000000FF))
      movedown(1, &obj);

  for (int i = 0; i < 8; i++) {
    if (row + i > canvas->rsize)
      continue;
    for (int j = 0; j < 8; j++) {
      if (col + j > canvas->csize)
        continue;
      if (bitcheck(&obj, 7 - i, 7 - j))
        setlayer(canvas->cellv + ((row + i) * canvas->csize) + (col + j),
                 layer);
    }
  }
}

matrix_t conversion(canvas_t *canvas, int row, int col) {
  matrix_t ret = 0;

  if (row < 0 || col < 0)
    exit(-1);
  if (row + 7 >= canvas->rsize || col + 7 >= canvas->csize)
    exit(-1);

  for (int r = 7; r >= 0; r--)
    for (int c = 7; c >= 0; c--)
      if (canvas->cellv[(7 - r + row) * canvas->csize + (7 - c + col)])
        bitset(&ret, r, c);

  return ret;
}