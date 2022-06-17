// GUERRA DE TANQUE v0.5
#include "guerratanque.h"
#define B 1

int map[MAPW*MAPH] = {
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
    B,B,B,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,B,B,B,
    B,B,B,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,B,B,B,
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
    B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,B
};

int inside(int x, int y, int left, int top, int right, int bottom)
{
    if (x>left && x< right && y >top && y< bottom)
       return 1;
    else
       return 0;
}

BITMAP *grabframe(BITMAP *source, 
                  int width, int height, 
                  int startx, int starty, 
                  int columns, int frame)
{
    BITMAP *temp = create_bitmap(width,height);

    int x = startx + (frame % columns) * width;
    int y = starty + (frame / columns) * height;

    blit(source,temp,x,y,0,0,width,height);

    return temp;
}

int main() 
{ 
  //inicia tudo
  allegro_init();
  install_keyboard();
  install_timer();
  srand(time(NULL));
  preparatela();
  apresenta();
  preparatanque(1);

  //laço do jogo
  while(!gameover)
  {
      // move os tanques e as balas
      for (n=0;n<2;n++)
      {
          movertanque(n);
          movebala(n);
      }
      
      // desenha o fundo
      blit(back,buffer,0,0,0,0,back->w,back->h);
      
      //desenha as janelas com rolamento
      for (n=0;n<2;n++)
      {
           blit(scroll, buffer, scrollx[n], scrolly[n], startx[n], starty[n], SCROLLW, SCROLLH);
      }
      
      //atualiza o radar
      rectfill(buffer,radarx+1, radary+1, radarx+99, radary+88, BLACK);
      rect(buffer,radarx, radary, radarx+100, radary+89, WHITE);
      
      //desenha mini tanques no radar
      for (n=0;n<2;n++)
      {
           stretch_sprite(buffer,tank_bmp[n][tanque[n]->dir],radarx+scrollx[n]/10+(SCROLLW/10)/2-4, radary+scrolly[n]/12 + (SCROLLH/12)/2-4, 8, 8);

      }                 
      
      // desenha a area de visualizacao do player no radar
      for (n=0; n<2; n++)
      {
          rect(buffer,radarx+scrollx[n]/10,radary+scrolly[n]/12,radarx+scrollx[n]/10+SCROLLW/10,radary+scrolly[n]/12+SCROLLH/12, GRAY);
      }
      
      //mostra o score
      for (n=0;n<2;n++)
      {
          textprintf(buffer, font, startx[n], HEIGHT-10, BURST, "Placar: %d", scores[n]);
      }
      
      //desenha os tanques e as balas
      for (n=0;n<2;n++)
      {
          criatanque(n);
          criabala(n);
      }
      
      //atualiza a tela
      acquire_screen();
      blit(buffer,screen,0,0,0,0,WIDTH,HEIGHT);
      release_screen();

      //verifica a tecla
      if (keypressed())
          teclado();
      //velocidade
      rest(20);      

  }
    //limpa a memoria
    destroy_bitmap(explode_bmp);
    destroy_bitmap(back);
    destroy_bitmap(scroll);
    destroy_bitmap(buffer);
    for (n=0; n<8; n++)
    {
        destroy_bitmap(tank_bmp[0][n]);
        destroy_bitmap(tank_bmp[1][n]);
    }  

allegro_exit();
}
END_OF_MAIN();
