// TANQUE DE GUERRA 0.1
#ifndef _TANQUE_H
#define _TANQUE_H
#include <allegro.h>
//constantes do jogo
#define MODE GFX_AUTODETECT_WINDOWED
#define WIDTH 640
#define HEIGHT 480
#define BLOCOS 5
#define BLOCOS_TAMANHO 100
#define VELOCIDADE_MAXIMA 2
#define VELOCIDADE_DA_BALA 6
#define TAN makecol(255,242,169)
#define COR1 makecol(25,242,169)
#define COR2 makecol(255,42,169)
#define BURST makecol(255,189,73)
#define BLACK makecol(0,0,0)
#define WHITE makecol(255,255,255)

//estrutura do tanque
struct tagTanque
{
   int x,y;
   int dir,speed;
   int score;
   
} tanque[2];

//estrutura da bala
struct tagBala
{
   int x,y;
   int viva;
   int xvelocidade,yvelocidade;
} balas[2];

int acertou  = 0;
int gameover = 0;
BITMAP *tank_bmp[2][8];
BITMAP *bullet_bmp;
BITMAP *explode_bmp;

//prototipos das funcoes
void criatanque(int num);
void destroitanque(int num);
void movertanque(int num);
void explode(int num, int x, int y);
void atualizabala(int num);
void atira(int num);
void frente(int num);
void atras(int num);
void esquerda(int num);
void direita(int num);
void teclado();
void preparatanque(int i);
void placar(int);
void print(const char *s, int c);
void preparatela();
void apresenta();
#endif
