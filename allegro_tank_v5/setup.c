// GUERRA DE TANQUE
// setup.cpp
#include "guerratanque.h"


void preparatanque(int i)
{
     int n,h;
       
     //jogador 1
     tanque[0] = &mytanks[0];
     tanque[0]->x = 30;
     tanque[0]->y = 40;
     tanque[0]->xspeed = 0;
     if (i) scores[0] = 0;
     tanque[0]->dir = 3; 
     
     // carrega a imagem do tanque 1
     tank_bmp[0][0] = load_bitmap("../../tank1.bmp",NULL);

     //jogador 2
     tanque[1] = &mytanks[1];
     tanque[1]->x = SCREEN_W-30;
     tanque[1]->y = SCREEN_H-30;
     tanque[1]->dir = 7;
     tanque[1]->xspeed = 0;
     if (i) scores[1] = 0;
     
     // carrega a imagem do tanque 2
     tank_bmp[1][0] = load_bitmap("../../tank2.bmp",NULL);
   
     
     // rotaciona nas 8 direções

    for (h=0; h<2;h++)
    {
     for (n=1; n<8; n++)
     {
         tank_bmp[h][n] = create_bitmap(32,32);
         clear_to_color(tank_bmp[h][n],makecol(255,0,255));
         rotate_sprite(tank_bmp[h][n],tank_bmp[h][0],0,0,itofix(n*32));
     }     
    }
     // carrega o bitmap da bala de caso não esteja carregado
     if (bullet_bmp == NULL);
     {
          bullet_bmp = load_bitmap("../../bullet.bmp",NULL);
     }      
       
    for (n=0; n<2;n++)
    {
        balas[n] = &mybullets[n];
        balas[n]->x = 0;
        balas[n]->y = 0;
        balas[n]->width = bullet_bmp->w;
        balas[n]->height = bullet_bmp->h;
    } 
    
    // centraliza os tanques
    tanque[0]->x = 5 + SCROLLW/2;
    tanque[0]->y = 90 + SCROLLH/2;
    tanque[1]->x = 325 + SCROLLW/2;
    tanque[1]->y = 90 + SCROLLH/2;        
                               
}

void preparatela()
{
     //configurao modo de video
     set_color_depth(16);
     int ret = set_gfx_mode(MODE, WIDTH, HEIGHT, 0, 0);
     if (ret != 0) { allegro_message(allegro_error);return; }     
}


void apresenta() {
     // ENTRADA
     textout_centre(screen, font, "TANQUE DE GUERRA - 0.5",SCREEN_W/2, 50, COR2);
     textout_centre(screen, font, "THIAGO N MELO (thiago@oxente.org) - http://thiago.oxente.org",SCREEN_W/2, 80, COR1);
     textout_centre(screen, font, "Controles P1: (WASD  = Movimento, ESPACO = Atirar)",SCREEN_W/2, 120, COR2); 
     textout_centre(screen, font, "Controles P2: (SETAS = Movimento, ENTER  = Atirar)",SCREEN_W/2, 130, COR1);
     textout_centre(screen, font, "Aperte qualquer tecla para iniciar!",SCREEN_W/2, 180, COR2); 
     readkey();
     rectfill(screen, 0, 0, SCREEN_W, SCREEN_H, 0);
     // FIM DA ENTRADA
     
     text_mode(-1);
     //cria o background virtual
     scroll = create_bitmap(MAPW,MAPH);
     if (scroll == NULL)
     {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Erro criando virtual background");
        return;
     }

     //carrega o bitmap do tile
     tiles = load_bitmap("../../tiles.bmp", NULL);
     if (tiles == NULL)
     {
         set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
         allegro_message("Erro carregando o arquivo tiles.bmp");
         return;
     }    
     // desenha os tiles no background virtual

     for (tiley=0; tiley < scroll->h; tiley+=TILEH)
     {
        for (tilex=0; tilex < scroll->w; tilex+=TILEW)
        {
            blit(grabframe(tiles, TILEW+1, TILEH+1, 0, 0, COLS, map[n++]), scroll, 0, 0, tilex, tiley, TILEW, TILEH);
        }
     }

    //limpa os tiles da memoria
    destroy_bitmap(tiles); 
    
    //carrega o fundo da screen
    back = load_bitmap("../../background.bmp",NULL);
    if (back == NULL)
    {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Erro carregando o arquivo background.bmp");
        return;
    }

    //cria o double buffer
    buffer = create_bitmap(WIDTH, HEIGHT);
    if (buffer == NULL)
    {
        set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
        allegro_message("Erro criando o double buffer");
        return;
    }

    //local do radar
    radarx = 270;
    radary = 1;

    //local dos jogadores
    scrollx[0] = 100;
    scrolly[0] = 100;
    scrollx[1] = MAPW - 400;
    scrolly[1] = MAPH - 500;

    //local das janelas
    startx[0] = 5;
    starty[0] = 93;
    startx[1] = 325;
    starty[1] = 93;    
}
