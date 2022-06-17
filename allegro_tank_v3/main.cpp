#include <allegro.h>
#include "tanque.h"


void criatanque(int num)
{
    int dir = tanque[num].dir;
    int x   = tanque[num].x-15;
    int y   = tanque[num].y-15;
    draw_sprite(screen,tank_bmp[num][dir],x,y);
}

void destroitanque(int num)
{

     int x = tanque[num].x-17;
     int y = tanque[num].y-17;     
     //apaga o tanque
     rectfill(screen,x,y,x+33,y+33,BLACK);
}

void movertanque(int num) 
{
     int dir = tanque[num].dir;
     int speed = tanque[num].speed;
     //atualiza a posição do tanque de acordo com a direção
     switch(dir)
     {
          case 0:
               tanque[num].y -= speed;
               break;
          case 1:
               tanque[num].x += speed;
               tanque[num].y -= speed;               
               break;
          case 2:
               tanque[num].x += speed;
               break;
          case 3:
               tanque[num].x += speed;
               tanque[num].y += speed;               
               break;
          case 4:
               tanque[num].y += speed;
               break;
          case 5:
               tanque[num].x -= speed;
               tanque[num].y += speed;
               break;
          case 6:
               tanque[num].x -= speed;
               break;
          case 7:
               tanque[num].x -= speed;
               tanque[num].y -= speed;               
               break;
     }
     
     //matem o tanque dentro da tela
     if (tanque[num].x > SCREEN_W-22)
     {
        tanque[num].x = SCREEN_W-22;
        tanque[num].speed = 0;
     }
     if (tanque[num].x < 22)
     {
        tanque[num].x = 22;
        tanque[num].speed = 0;
     }
     if (tanque[num].y > SCREEN_H-22)
     {
        tanque[num].y = SCREEN_H-22;
        tanque[num].speed = 0;
     }
     if (tanque[num].y < 42)
     {
        tanque[num].y = 42;
        tanque[num].speed = 0;
     }              
}

void explode(int num, int x, int y)
{
     int n;
     //carrega imagem da explosão
     if (explode_bmp == NULL)
     {
         explode_bmp = load_bitmap("explode.bmp",NULL);
     }
     
     // desenha a explosão várias vezes na tela
     for (n = 0; n <5 ; n++)
     {
         rotate_sprite(screen, explode_bmp,x + rand()%10-20,y+rand()%10-20,itofix(rand()%255));
         rest(60);
     }
     
     //limpa a explosão
     circlefill(screen,x,y,50,BLACK);
 
}

void atualizabala(int num)
{
     int x = balas[num].x;
     int y = balas[num].y;     
     
     if(!balas[num].viva) return;

         //apaga bala
         rectfill(screen,x,y,x+10,y+10, BLACK);
         
         //move bala
         balas[num].x += balas[num].xvelocidade;
         balas[num].y += balas[num].yvelocidade;         
         x = balas[num].x;
         y = balas[num].y;         
         
         //manter dentro da tela
         if (x < 6 || x > SCREEN_W-6 || y < 20 || y > SCREEN_H-6)
         {
               balas[num].viva=0;
               return;
         }
         
         //ver se existiu uma colisão
         int tx = tanque[!num].x;
         int ty = tanque[!num].y;
         
         if (x > tx-16 && x < tx+16 && y > ty-16 && y < ty+16)
         {
               //destroy a bala
               balas[num].viva = 0;
               
               // explode o tanque
               explode(num,x,y);
               placar(num);
               destroitanque(0);
               destroitanque(1);
               preparatanque(0);
               
         }
         
         else {         
            //desenha  a bala
            draw_sprite(screen, bullet_bmp, x, y);
            
            //atualiza a posição da bala para debug
            textprintf(screen, font, SCREEN_W/2-50,1,TAN,"B1 %-3dx%-3d B2 %-3dx%-3d", balas[0].x,balas[0].y,balas[1].x,balas[1].y);
         
         }
}

void atira(int num)
{
     int x = tanque[num].x;
     int y = tanque[num].y;
     
     // carrega o bitmap da bala de caso não esteja carregado
     if (bullet_bmp == NULL);
     {
          bullet_bmp = load_bitmap("bullet.bmp",NULL);
     }
     
     //canhão carregado?
     if (!balas[num].viva)
     {
          balas[num].viva = 1;
          
          // atira a bala na direção que o tanque esta apontando
          switch (tanque[num].dir)
          {
                 //norte
                 case 0:
                      balas[num].x = x-2;
                      balas[num].y = y-22;
                      balas[num].xvelocidade = 0;
                      balas[num].yvelocidade = -VELOCIDADE_DA_BALA;
                      break;
                 //nordeste
                 case 1:
                      balas[num].x = x+18;
                      balas[num].y = y-18;
                      balas[num].xvelocidade = VELOCIDADE_DA_BALA;
                      balas[num].yvelocidade = -VELOCIDADE_DA_BALA;
                      break;
                 //leste
                 case 2:
                      balas[num].x = x+22;
                      balas[num].y = y-2;
                      balas[num].xvelocidade = VELOCIDADE_DA_BALA;
                      balas[num].yvelocidade = 0;
                      break;
                 //sudeste
                 case 3:
                      balas[num].x = x+18;
                      balas[num].y = y+18;
                      balas[num].xvelocidade = VELOCIDADE_DA_BALA;
                      balas[num].yvelocidade = VELOCIDADE_DA_BALA;
                      break;                 
                 //sul
                 case 4:
                      balas[num].x = x-2;
                      balas[num].y = y+22;
                      balas[num].xvelocidade = 0;
                      balas[num].yvelocidade = VELOCIDADE_DA_BALA;
                      break;                 
                 //sudoeste
                 case 5:
                      balas[num].x = x+-8;
                      balas[num].y = y+18;
                      balas[num].xvelocidade = -VELOCIDADE_DA_BALA;
                      balas[num].yvelocidade = VELOCIDADE_DA_BALA;
                      break;                 
                 //oeste
                 case 6:
                      balas[num].x = x-22;
                      balas[num].y = y-2;
                      balas[num].xvelocidade = -VELOCIDADE_DA_BALA;
                      balas[num].yvelocidade = 0;
                      break;                                                             
                 //noroeste
                 case 7:
                      balas[num].x = x-18;
                      balas[num].y = y-18;
                      balas[num].xvelocidade = -VELOCIDADE_DA_BALA;
                      balas[num].yvelocidade = -VELOCIDADE_DA_BALA;
                      break;                                  
          }
     }
}

void frente(int num)
{
     tanque[num].speed++;
     if (tanque[num].speed > VELOCIDADE_MAXIMA) tanque[num].speed = VELOCIDADE_MAXIMA;
}
void atras(int num)
{
     tanque[num].speed--;
     if (tanque[num].speed < -VELOCIDADE_MAXIMA) tanque[num].speed = -VELOCIDADE_MAXIMA;
}
void esquerda(int num)
{
     tanque[num].dir--;
     if (tanque[num].dir < 0) tanque[num].dir = 7;
}
void direita(int num)
{
     tanque[num].dir++;
     if (tanque[num].dir > 7) tanque[num].dir = 0;
}

//ler dados do teclado
void teclado()
{
     // ESC para sair
     if (key[KEY_ESC]) gameover=1;
     
     //WASD / SPACE controla o tanque 1
     if (key[KEY_W]) frente(0);
     if (key[KEY_D]) direita(0);
     if (key[KEY_A]) esquerda(0);
     if (key[KEY_S]) atras(0);
     if (key[KEY_SPACE]) atira(0);

     //arrow / ENTER keys control tank 2
     if (key[KEY_UP]) frente(1);
     if (key[KEY_RIGHT]) direita(1);
     if (key[KEY_DOWN]) atras(1);
     if (key[KEY_LEFT]) esquerda(1);
     if (key[KEY_ENTER]) atira(1);

     //espera um pouco depois de cada tecla
     rest(40);
}

void placar(int p)
{
     //atualiza placar
     int points = ++tanque[p].score;
     //mostra placar
     textprintf(screen, font, SCREEN_W-70*(p+1), 1, BURST, "P%d: %d", p+1, points);
}

void preparatanque(int i)
{
     int n,h;
       
     //jogador 1
     tanque[0].x = 30;
     tanque[0].y = 40;
     tanque[0].speed = 0;
     if (i) tanque[0].score = 0;
     tanque[0].dir = 3; 
     
     // carrega a imagem do tanque 1
     tank_bmp[0][0] = load_bitmap("tank1.bmp",NULL);

     //jogador 2
     tanque[1].x = SCREEN_W-30;
     tanque[1].y = SCREEN_H-30;
     tanque[1].dir = 7;
     tanque[1].speed = 0;
     if (i) tanque[1].score = 0;
     
     // carrega a imagem do tanque 2
     tank_bmp[1][0] = load_bitmap("tank2.bmp",NULL);
   
     
     // rotaciona nas 8 direções

    for (h=0; h<2;h++)
    {
     for (n=1; n<8; n++)
     {
         tank_bmp[h][n] = create_bitmap(32,32);
         clear_bitmap(tank_bmp[h][n]);
         rotate_sprite(tank_bmp[h][n],tank_bmp[h][0],0,0,itofix(n*32));
     }     
    }

}

void preparatela()
{
     //configurao modo de video
     set_color_depth(32);
     int ret = set_gfx_mode(MODE, WIDTH, HEIGHT, 0, 0);
     if (ret != 0) { allegro_message(allegro_error);return; }     
}

void apresenta() {
     textout_centre(screen, font, "TANQUE DE GUERRA - 0.2",SCREEN_W/2, 50, 14);
     textout_centre(screen, font, "THIAGO N MELO (thiago@oxente.org) - http://thiago.oxente.org",SCREEN_W/2, 80, COR1);
     (screen, font, "Controles P1: (WASD  = Movimento, ESPACO = Atirar)",SCREEN_W/2, 120, COR2); 
     textout_centre(screen, font, "Controles P2: (SETAS = Movimento, ENTER  = Atirar)",SCREEN_W/2, 130, COR1);
     textout_centre(screen, font, "Aperte qualquer tecla para iniciar!",SCREEN_W/2, 180, COR2); 
     readkey();
     rectfill(screen, 0, 0, SCREEN_W, SCREEN_H, 0);
     //mostra o titulo do jogo
     textprintf(screen, font, 1, 1, BURST, "TANQUE DE GUERRA - %dx%d", SCREEN_W, SCREEN_H);
     //desenha a borda
     rect(screen, 0, 12, SCREEN_W-1, SCREEN_H-1, TAN);
     rect(screen, 1, 13, SCREEN_W-2, SCREEN_H-2, TAN);         
     
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
     textprintf(screen, font, 0 , SCREEN_H-10, WHITE, "Direcao %d , %d ", tanque[0].dir,tanque[1].dir);
  //apaga os tanques
  destroitanque(0);
  destroitanque(1);

  //move os tanques
  movertanque(0);
  movertanque(1);
  //desenha os tanques
  criatanque(0);
  criatanque(1);

  //atualiza as balas
  atualizabala(0);
  atualizabala(1);
  //verifica teclado

  if (keypressed()) teclado();
  //diminui a velocidade do jogo
  rest(30);
  }

allegro_exit();
}
END_OF_MAIN();
