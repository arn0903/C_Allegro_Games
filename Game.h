#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#define NELEM 50

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro.h>

typedef struct objet
{
    int posx;
    int posy;
    int movx;
    int movy;
    int sx;
    int sy;
    BITMAP *image;
} t_object;


t_object * create(BITMAP * chara);
t_object * create2(BITMAP * chara);
void bounce(t_object *sprite);
void disappear(BITMAP *avatar, t_object *notes);

void inititAllegro();
void menu();

void game1();
void game2();
void game3();



#endif // GAME_H_INCLUDED
