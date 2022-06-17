// GUERRA DE TANQUE
// tanque.cpp
#include "guerratanque.h"

void criatanque(int num)
{
    int dir = tanque[num]->dir;
    int x   = tanque[num]->x-15;
    int y   = tanque[num]->y-15;
    draw_sprite(buffer,tank_bmp[num][dir],x,y);
    
    //tanque inimigo
    x = scrollx[!num] + SCROLLW/2;
    y = scrolly[!num] + SCROLLH/2;    
    if (inside(x,y,scrollx[num],scrolly[num],scrollx[num] + SCROLLW, scrolly[num] + SCROLLH))
    {
        draw_sprite(buffer,tank_bmp[!num][tanque[!num]->dir],startx[num]+x-scrollx[num]-15,starty[num]+y-scrolly[num]-15);    
    }
}

void movertanque(int num) 
{
     int dir = tanque[num]->dir;
     int speed = tanque[num]->xspeed;
     //atualiza a posição do tanque de acordo com a direção
    switch(dir)
    {
        case 0:
            scrolly[num] -= speed;
            break;
        case 1:
            scrolly[num] -= speed;
            scrollx[num] += speed;
            break;
        case 2:
            scrollx[num] += speed;
            break;
        case 3:
            scrollx[num] += speed;
            scrolly[num] += speed;
            break;
        case 4:
            scrolly[num] += speed;
            break;
        case 5:
            scrolly[num] += speed;
            scrollx[num] -= speed;
            break;
        case 6:
            scrollx[num] -= speed;
            break;
        case 7:
            scrollx[num] -= speed;
            scrolly[num] -= speed;
            break;
    }
     
     //matem o tanque dentro da tela
     if (scrollx[num] < 0)
         scrollx[num] = 0;
     if (scrollx[num] > scroll->w - SCROLLW)
         scrollx[num] = scroll->w - SCROLLW;
     if (scrolly[num] < 0)
         scrolly[num] = 0;
     if (scrolly[num] > scroll->h - SCROLLH)
         scrolly[num] = scroll->h - SCROLLH;
         
     //ver se existiu uma colisão entre os tanques
      int x = scrollx[num] + SCROLLW/2;
      int y = scrolly[num] + SCROLLH/2;
      
      int tx = scrollx[!num] + SCROLLW/2;
      int ty = scrolly[!num] + SCROLLH/2;
      
     
     if (inside(x,y,tx-15,ty-15,tx+15,ty+15))
     {
           //destroy as balas
           balas[num]->alive = 0;
           balas[!num]->alive = 0;
           
           // explode os tanques
           x = scrollx[!num] + SCROLLW/2;
           y = scrolly[!num] + SCROLLH/2;

           if (inside(x,y,scrollx[num],scrolly[num],scrollx[num] + SCROLLW, scrolly[num] + SCROLLH))
           {
                explode(num, startx[num] + x - scrollx[num],starty[num] + y - scrolly[num]);
           }
           //explode na tela do inimigo
           explode(num, tanque[!num]->x ,tanque[!num]->y);
           
            //local dos jogadores
           scrollx[0] = 100;
           scrolly[0] = 100;
           scrollx[1] = MAPW - 400;
           scrolly[1] = MAPH - 500;
    }         
}

