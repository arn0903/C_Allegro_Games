#include "Game.h"


///play game 2: Star Wars shooter
void game2()
{


    t_object * star, *star2;
    BITMAP * DBuffer, * s1, *s2, *background, *aim, *blast, *fire, *ship;
    int counter =0, lpoints =5;

    srand(time(NULL));


    //create the bitmaps
    DBuffer = create_bitmap(SCREEN_W, SCREEN_H);
    ship= load_bitmap("src/cockpit.bmp", NULL);
    s1 = load_bitmap("src/deathstar.bmp", NULL);
    s2 =load_bitmap("src/deathstar2.bmp", NULL);
    background = load_bitmap("src/space.bmp", NULL);
    aim = load_bitmap("src/aim.bmp", NULL);
    blast = load_bitmap("src/blast.bmp", NULL);
    fire = load_bitmap("src/flames.bmp", NULL);

    //create the objects
    star = create(s1);
    star2 = create(s2);


    while (!key[KEY_DOWN])
    {

        clear_bitmap(DBuffer);

        //show background
        blit(background, DBuffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);


        //move object
        star2->posx +=  star2->movx;
        star2->posy += star2->movy;

        bounce(star2);


        //show blast
        if(mouse_b&1)
            masked_blit(blast, DBuffer, 0, 0, mouse_x, mouse_y-30, blast->w, blast->h);


        //if we touch it
        if(mouse_x > star2->posx && mouse_x < star2->posx+s2->w && mouse_y > star2->posy && mouse_y < star2->posy+s2->h && mouse_b&1)
        {
            counter++;

            //show flames
            masked_blit(fire, DBuffer, 0, 0, star2->posx,star2->posy-50, fire->w, fire->h);


            //if counter reaches 100
            if(counter==100)
            {
                //object is destroyed
                circlefill(s1,0,100, s1->h,makecol(255,0,255));

                allegro_message("YOU'VE WON THE BATTLE BUT NOT THE WAR");
            }


            //calculate how many life points are left
            if(counter>0)
            {
                lpoints = 5;

                if(counter>20)
                {
                    lpoints = 4;

                    if(counter>40)
                    {
                        lpoints = 3;

                        if(counter>60)
                        {
                            lpoints = 2;

                            if(counter>80)

                                lpoints = 1;

                            if(counter==99)
                                lpoints = 0;

                        }
                    }
                }

            }

        }

        //show everything
        masked_blit(star2->image, DBuffer, 0, 0, star2->posy, star2->posx, star2->sy, star2->sx);
        masked_blit(star->image, DBuffer, 0, 0, star2->posy, star2->posx, star2->sy, star2->sx);
        masked_blit(aim, DBuffer, 0, 0, mouse_x,mouse_y, 70, 70);
        masked_blit(ship, DBuffer, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
        textprintf_ex(DBuffer, font, 0, 10, makecol(255, 255, 0), -1, "Life left: %d", lpoints);

        blit(DBuffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

    }

    //free space
    destroy_bitmap(DBuffer);
    destroy_bitmap(s1);
    destroy_bitmap(background);
    destroy_bitmap(aim);
    destroy_bitmap(blast);
    destroy_bitmap(fire);
    destroy_bitmap(ship);

}
