#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here

void draw_line_OCT1(int x0, int y0, int x1, int y1, screen s, color c){
    int a = y1 - y0;
    int b = x0 - x1;
    int d = 2 * a + b;
    int x = x0; int y = y0;
    while(x <= x1){
        plot(s, c, x, y);
        if(d > 0){
            y++;
            d += 2 * b;
        }
        x++;
        d += 2 * a;
    }
}

void draw_line_OCT2(int x0, int y0, int x1, int y1, screen s, color c){
    int a = y1 - y0;
    int b = x0 - x1;
    int d = a + 2 * b;
    int x = x0; int y = y0;
    while(y <= y1){
        plot(s, c, x, y);
        if(d < 0){
            x++;
            d += 2 * a;
        }
        y++;
        d += 2 * b;
    }
}

void draw_line_OCT7(int x0, int y0, int x1, int y1, screen s, color c){
    int a = y1 - y0;
    int b = x0 - x1;
    int d = a - 2 * b;
    int x = x0; int y = y0;
    while(y >= y1){
        plot(s, c, x, y);
        if(d > 0){
            x++;
            d += 2 * a;
        }
        y--;
        d -= 2 * b;
    }
}

void draw_line_OCT8(int x0, int y0, int x1, int y1, screen s, color c){
    int a = y1 - y0;
    int b = x0 - x1;
    int d = 2 * a - b;
    int x = x0; int y = y0;
    while(x <= x1){
        plot(s, c, x, y);
        if(d < 0){
            y--;
            d -= 2 * b;
        }
        x++;
        d += 2 * a;
    }
}

void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
    if(x1 < x0){
        draw_line(x1, y1, x0, y0, s, c);
    } else {
        if(y1 - y0 < 0){
            if(y0 - y1 >= x1 - x0){
                draw_line_OCT7(x0, y0, x1, y1, s, c);
            } else {
                draw_line_OCT8(x0, y0, x1, y1, s, c);
            }
        } else {
            if(y1 - y0 <= x1 - x0){
                draw_line_OCT1(x0, y0, x1, y1, s, c);
            } else {
                draw_line_OCT2(x0, y0, x1, y1, s, c);
            }
        }
    }
}
