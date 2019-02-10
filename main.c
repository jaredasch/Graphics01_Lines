#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  clear_screen(s);

  for(int i = 0; i <= 500; i+=10){
      c.blue = 256 - (i * 256 / 500);
      c.green = (i * 256 / 500);
      c.red = (i * 256 / 500);
      draw_line(0, i, i, 500, s, c); // Octants 1 and 2
      draw_line(500, i, i, 0, s, c); // Octants 5 and 6
      draw_line(i, 0, 0, 500-i, s, c); // Octants 7 and 8
      draw_line(500, i, 500-i, 500, s, c); // Octants 3 and 4
  }

  save_extension(s, "lines.png");
}
