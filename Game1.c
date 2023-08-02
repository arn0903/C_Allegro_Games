#include "Game.h"


///play game 1: Where's Waldo
void game1()
{
    BITMAP *page;
    BITMAP *waldo;

    page = create_bitmap(SCREEN_W, SCREEN_H);
    waldo = load_bitmap("src/waldo.bmp", NULL);

    clear_bitmap(page);
    blit(waldo, page, mouse_x, mouse_y, mouse_x,mouse_y, 60, 60);
    blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    if((mouse_x<960)&&(mouse_x>895)&&(mouse_y<275)&&(mouse_y>210))
        textout_ex(screen, font, "you are close", 0, SCREEN_H-30,  makecol(255, 0, 0), -1);
    destroy_bitmap(page);
    destroy_bitmap(waldo);
}
