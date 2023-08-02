#include "Game.h"


///play game 3: Object popper
void game3()
{

    t_object * lampe, * piano, *notes, *ballon, *pipe;
    BITMAP * DBuffer, * lamp_b, *piano_b, *book_b, *baloon_b, *smoke_b, *aim;


    show_mouse(screen);
    srand(time(NULL));


    //create the bitmaps
    DBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    lamp_b = load_bitmap("src/lamp.bmp", NULL);
    piano_b = load_bitmap("src/piano.bmp", NULL);
    book_b = load_bitmap("src/book.bmp", NULL);
    baloon_b = load_bitmap("src/baloon.bmp", NULL);
    smoke_b = load_bitmap("src/smoke.bmp", NULL);
    aim = load_bitmap("src/aim.bmp", NULL);

    //create the objects
    lampe= create2(lamp_b);
    piano = create2(piano_b);
    notes = create2(book_b);
    ballon = create2(baloon_b);
    pipe = create2(smoke_b);

    while (!key[KEY_LEFT])
    {
        clear_bitmap(DBuffer);

        //move the elements
        piano->posx += piano->movx;
        piano->posy += piano->movy;


        lampe->posy += lampe->movy;
        lampe->posx += lampe->movx;

        notes->posy += notes->movy;
        notes->posx += notes->movx;

        ballon->posy += ballon->movy;
        ballon->posx += ballon->movx;

        pipe->posy += pipe->movy;
        pipe->posx += pipe->movx;


        //make them disappear
        disappear(lamp_b, lampe);
        disappear(piano_b, piano);
        disappear(book_b, notes);
        disappear(baloon_b, piano_b);
        disappear(smoke_b, pipe);
        disappear(baloon_b, ballon);


        //make them bounce
        bounce(notes);
        bounce(lampe);
        bounce(piano);
        bounce(ballon);
        bounce(pipe);


        //show everything
        masked_blit(lampe->image, DBuffer, 0, 0, lampe->posy, lampe->posx, lampe->sy, lampe->sx);
        masked_blit(piano->image, DBuffer, 0, 0, piano->posy, piano->posx, piano->sy, piano->sx);
        masked_blit(notes->image, DBuffer, 0, 0, notes->posy, notes->posx, notes->sy, notes->sx);
        masked_blit(ballon->image, DBuffer, 0, 0, ballon->posy, ballon->posx, ballon->sy, ballon->sx);
        masked_blit(pipe->image, DBuffer, 0, 0, pipe->posy, pipe->posx, pipe->sy, pipe->sx);
        masked_blit(aim, DBuffer, 0, 0, mouse_x,mouse_y, 70, 70);


        blit(DBuffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);


    }

    //free space
    destroy_bitmap(DBuffer);
    destroy_bitmap(lamp_b);
    destroy_bitmap(piano_b);
    destroy_bitmap(book_b);
    destroy_bitmap(baloon_b);
    destroy_bitmap(smoke_b);

}
