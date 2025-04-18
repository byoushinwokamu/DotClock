#include "graphic.h"
#include "matrix.h"
#include "print_dot.h"

matrix_t mar[5];

int main(int argc, char **argv) {
  drawchar(mar + 4, '0', 'r'), moveleftn(5, mar, 3);
  drawchar(mar + 4, '1', 'r'), moveleftn(5, mar, 3);
  drawchar(mar + 4, '2', 'r'), moveleftn(5, mar, 3);
  drawchar(mar + 4, '3', 'r'), moveleftn(5, mar, 4);
  drawchar(mar + 4, '4', 'r'), moveleftn(5, mar, 3);
  drawchar(mar + 4, '5', 'r'), moveleftn(5, mar, 3);
  drawchar(mar + 4, '6', 'r'), moveleftn(5, mar, 3);
  drawchar(mar + 4, '7', 'r'), moveleftn(5, mar, 3);
  drawchar(mar + 4, '8', 'r'), moveleftn(5, mar, 3);
  drawchar(mar + 4, '9', 'r'), printdot(5, mar);

  return 0;
}