#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  draw_line(150, 150, 350, 250, s, c);
  draw_line(350, 250, 250, 450, s, c);
  draw_line(250, 450, 50, 350, s, c);
  draw_line(50, 350, 150, 150, s, c);

  display(s);
  save_extension(s, "lines.png");
}
