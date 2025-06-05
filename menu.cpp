#include "menu.h"
#include "game.h"
#include "graphics.h"

Button buttons[N_BUTTONS];
IMAGE *menu_image, *about_image, *start_image;

void load()
{
   menu_image  = loadBMP("images/menu.bmp");
   about_image = loadBMP("images/about.bmp");
   start_image = loadBMP("images/start.bmp");
   
   create_button(GAME, 100, 100, "buttons/game.bmp");
   create_button(ABOUT, 100, 200, "buttons/about.bmp");
   create_button(EXIT,  100, 300, "buttons/exit.bmp");
}

void start()
{
   putimage(0, 0, start_image, COPY_PUT);
   swapbuffers();
   getch();
}

void menu()
{
   int state;
   
   while (true)
   {
      putimage(0, 0, menu_image, COPY_PUT);
      for (int i = 0; i < N_BUTTONS; i++)
      {
         putimage(buttons[i].left, buttons[i].top,
                  buttons[i].image, COPY_PUT);
      }
      
      swapbuffers();
      
      state = NONE;
      while (state == NONE)
      {
         while (mousebuttons() != 1);
         state = select_button();
      }
      
      switch (state)
      {
         case GAME:  game();  break;
         case ABOUT: about(); break;
         case EXIT:  close(); return;
      }
   }
}

void about()
{
   putimage(0, 0, about_image, COPY_PUT);
   swapbuffers();
   getch();
}

void close()
{
   freeimage(menu_image);
   freeimage(about_image);
   freeimage(start_image);
   for (int i = 0; i < N_BUTTONS; i++)
   {
      freeimage(buttons[i].image);
   }
}

void create_button(int i, int left, int top,
                   const char *file_name)
{
   buttons[i].image  = loadBMP(file_name);
   buttons[i].left   = left;
   buttons[i].top    = top;
   buttons[i].width  = imagewidth(buttons[i].image);
   buttons[i].height = imageheight(buttons[i].image);
}

int select_button()
{
   int x, y;
   
   x = mousex();
   y = mousey();
   
   for (int i = 0; i < N_BUTTONS; i++)
   {
      if (x > buttons[i].left &&
          x < buttons[i].left + buttons[i].width &&
          y > buttons[i].top &&
          y < buttons[i].top + buttons[i].height)
      {
         return i;
      }
   }
   
   return NONE;
}