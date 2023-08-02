#include "Game.h"


///Allegro initialisation
void inititAllegro()
{
    allegro_init();
    set_color_depth(desktop_color_depth());

    install_mouse();
    install_keyboard();

    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,1000,600,0,0))!=0)
    {
        allegro_message("Graphic mode problem");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}


///main game menu
void menu()
{
    BITMAP *M;

    M = load_bitmap("src/menuback.bmp", NULL);

    rect(M, 220, 160, 750, 250, makecol(255,0,0));
    rect(M, 220, 260, 750, 350, makecol(255,150,150));
    rect(M, 220, 360, 750, 450, makecol(0,0,255));

    if(mouse_x>220&&mouse_x<750&&mouse_y>160&&mouse_y<250&&mouse_b&1)
    {
        while(!key[KEY_UP])
        {
            game1();
        }
    }

    if(mouse_x>220&&mouse_x<750&&mouse_y>260&&mouse_y<350&&mouse_b&1)
    {
        while(!key[KEY_DOWN])
        {
            game2();
        }
    }

    if(mouse_x>220&&mouse_x<750&&mouse_y>360&&mouse_y<450&&mouse_b&1)
    {
        while(!key[KEY_LEFT])
        {
            game3();
        }
    }

    show_mouse(M);
    blit(M, screen, 0, 0, 0, 0, M->w, M->h);


}

