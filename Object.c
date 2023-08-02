#include "Game.h"


///create an object
t_object * create(BITMAP* chara)
{
    t_object *s = NULL;
    int speed =rand()%10;  //randomise the speed

    s = (t_object*)malloc(sizeof(t_object));
    if (s == NULL)
        printf ("memory alloc problem\n");

    else
    {
        //initialisation des parametres
        s->image = chara;
        s->sy = chara->w;
        s->sx = chara->h;
        s->posy = 0;
        s->posx = 0;

        s->movy = speed;
        s->movx = speed;

    }

    return s;
}


t_object * create2(BITMAP* chara)
{
    t_object *o = NULL;

    o = (t_object*)malloc(sizeof(t_object));
    if (o == NULL)
        printf ("memory alloc problem\n");

    else
    {
        o->image = chara;
        o->sy = chara->w;
        o->sx = chara->h;

        o->posx = rand()%((SCREEN_W-o->sx)-0+1)+0;   //randomise the position and speed
        o->posy = rand()%((SCREEN_H-o->sy)-0+1)+0;
        do
        {
            o->movx = rand()%(1-(-1)+1)-1;
            o->movy = rand()%(1-(-1)+1)-1;
        }
        while((o->movx==0)&&(o->movy==0));

    }

    return o;
}



///bounce off screen
void bounce(t_object *sprite)
{
    if (sprite->posx + sprite->sx>=SCREEN_H)
        sprite->movx = sprite->movx *(-1);
    if (sprite->posy + sprite->sy>=SCREEN_W)
        sprite->movy = sprite->movy *(-1);
    if (sprite->posx<0)
        sprite->movx = sprite->movx *(-1);
    if (sprite->posy<0)
        sprite->movy = sprite->movy *(-1);

}



///make it disappear
void disappear(BITMAP *avatar, t_object *notes)
{

    if(mouse_x>notes->posx&&mouse_x<notes->posx+avatar->w&&mouse_y>notes->posy&&mouse_x>notes->posy+avatar->h&&mouse_b&1)
    {
        clear_bitmap(avatar);
        notes->posx = 1000;
        notes->posy = 1000;
    }
}
