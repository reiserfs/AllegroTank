// GUERRA DE TANQUE
// bala.cpp
#include "guerratanque.h"

void explode(int num, int x, int y)
{
     int n;
     //carrega imagem da explosão
     if (explode_bmp == NULL)
     {
         explode_bmp = load_bitmap("../../explode.bmp",NULL);
     }
     
     // desenha a explosão várias vezes na tela
     for (n = 0; n <5 ; n++)
     {
         rotate_sprite(screen, explode_bmp,x + rand()%10-20,y+rand()%10-20,itofix(rand()%255));
         rest(30);
     } 
}

void criabala(int num)
{
     int n;
     int x,y;
     
     x = balas[num]->x;
     y = balas[num]->y; 

     if(!balas[num]->alive) return;     
     
     for (n=0;n<2;n++)
     {
         if (inside(x,y,scrollx[n],scrolly[n],scrollx[n] + SCROLLW - bullet_bmp->w,scrolly[n] + SCROLLH - bullet_bmp->h))             
             draw_sprite(buffer, bullet_bmp,startx[n]+x-scrollx[n],starty[n]+y-scrolly[n]);
     }
     
     putpixel(buffer,radarx+x/10, radary + y/12, WHITE);
}


void movebala(int num)
{
     int x,y,tx,ty;

     x = balas[num]->x;
     y = balas[num]->y;     
              
     if(!balas[num]->alive) return;

     //move bala
     balas[num]->x += balas[num]->xspeed;
     balas[num]->y += balas[num]->yspeed;         
     x = balas[num]->x;
     y = balas[num]->y;         
     
     //manter dentro da tela
     if (x < 0 || x > MAPW-6 || y < 0 || y > MAPH-6)
     {
           balas[num]->alive=0;
           return;
     }
     
     //ver se existiu uma colisão
      tx = scrollx[!num] + SCROLLW/2;
      ty = scrolly[!num] + SCROLLH/2;
     
     if (inside(x,y,tx-15,ty-15,tx+15,ty+15))
     {
           //destroy a bala
           balas[num]->alive = 0;
           
           // explode o tanque
           x = scrollx[!num] + SCROLLW/2;
           y = scrolly[!num] + SCROLLH/2;

           if (inside(x,y,scrollx[num],scrolly[num],scrollx[num] + SCROLLW, scrolly[num] + SCROLLH))
           {
                explode(num, startx[num] + x - scrollx[num],starty[num] + y - scrolly[num]);
           }
           //explode na tela do inimigo
           explode(num, tanque[!num]->x ,tanque[!num]->y);
           
           scores[num]++;

    //local dos jogadores
    scrollx[0] = 100;
    scrolly[0] = 100;
    scrollx[1] = MAPW - 400;
    scrolly[1] = MAPH - 500;

    }
}    

void atira(int num)
{
     int x = scrollx[num] + SCROLLW/2;
     int y = scrolly[num] + SCROLLH/2;   
     
     //canhão carregado?
     if (!balas[num]->alive)
     {
          balas[num]->alive = 1;
          
          // atira a bala na direção que o tanque esta apontando
          switch (tanque[num]->dir)
          {
                 //norte
                 case 0:
                      balas[num]->x = x-2;
                      balas[num]->y = y-22;
                      balas[num]->xspeed = 0;
                      balas[num]->yspeed = -VELOCIDADE_DA_BALA;
                      break;
                 //nordeste
                 case 1:
                      balas[num]->x = x+18;
                      balas[num]->y = y-18;
                      balas[num]->xspeed = VELOCIDADE_DA_BALA;
                      balas[num]->yspeed = -VELOCIDADE_DA_BALA;
                      break;
                 //leste
                 case 2:
                      balas[num]->x = x+22;
                      balas[num]->y = y-2;
                      balas[num]->xspeed = VELOCIDADE_DA_BALA;
                      balas[num]->yspeed = 0;
                      break;
                 //sudeste
                 case 3:
                      balas[num]->x = x+18;
                      balas[num]->y = y+18;
                      balas[num]->xspeed = VELOCIDADE_DA_BALA;
                      balas[num]->yspeed = VELOCIDADE_DA_BALA;
                      break;                 
                 //sul
                 case 4:
                      balas[num]->x = x-2;
                      balas[num]->y = y+22;
                      balas[num]->xspeed = 0;
                      balas[num]->yspeed = VELOCIDADE_DA_BALA;
                      break;                 
                 //sudoeste
                 case 5:
                      balas[num]->x = x+-8;
                      balas[num]->y = y+18;
                      balas[num]->xspeed = -VELOCIDADE_DA_BALA;
                      balas[num]->yspeed = VELOCIDADE_DA_BALA;
                      break;                 
                 //oeste
                 case 6:
                      balas[num]->x = x-22;
                      balas[num]->y = y-2;
                      balas[num]->xspeed = -VELOCIDADE_DA_BALA;
                      balas[num]->yspeed = 0;
                      break;                                                             
                 //noroeste
                 case 7:
                      balas[num]->x = x-18;
                      balas[num]->y = y-18;
                      balas[num]->xspeed = -VELOCIDADE_DA_BALA;
                      balas[num]->yspeed = -VELOCIDADE_DA_BALA;
                      break;                                  
          }
     }
}
