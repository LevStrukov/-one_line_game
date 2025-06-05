#define WIDTH  800
#define HEIGHT 600

#include "menu.h"
#include "graphics.h"

int main()
{
   initwindow(WIDTH, HEIGHT, "One Line Game", 0, 0, true);
   load();
   start();
   menu();
   closegraph();
   return 0;
}