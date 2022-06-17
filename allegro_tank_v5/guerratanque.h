// TANQUE DE GUERRA 0.5
#ifndef _GUERRATANQUE_H
#define _GUERRATANQUE_H

#include <conio.h>
#include <allegro.h>

//constantes do jogo
#define MODE GFX_AUTODETECT_WINDOWED
#define WIDTH 640
#define HEIGHT 480
#define VELOCIDADE_MAXIMA 4
#define VELOCIDADE_DA_BALA 10
#define TILEW 32
#define TILEH 32
#define TILES 39
#define COLS 10
#define MAP_ACROSS 31
#define MAP_DOWN 33
#define MAPW MAP_ACROSS * TILEW
#define MAPH MAP_DOWN * TILEH
#define SCROLLW 310
#define SCROLLH 375

//CORES
#define TAN makecol(255,242,169)
#define COR1 makecol(25,242,169)
#define COR2 makecol(255,142,0)
#define BURST makecol(255,189,73)
#define BLACK makecol(0,0,0)
#define WHITE makecol(255,255,255)
#define GRAY makecol(128,128,128)
#define GREEN makecol(0,255,0)

typedef struct SPRITE
{
        int dir, alive;
        int x,y;
        int width,height;
        int xspeed,yspeed;
        int xdelay,ydelay;
        int xcount,ycount;
        int curframe,maxframe,animdir;
        int framecount,framedelay;
}SPRITE;

SPRITE mytanks[2];
SPRITE *tanque[2];
SPRITE mybullets[2];
SPRITE *balas[2];

int scores[2];

int acertou;
int gameover;
int scrollx[2], scrolly[2];
int startx[2],starty[2];
int tilex, tiley, n;
int radarx, radary;

// soda limonada
BITMAP *tank_bmp[2][8];
BITMAP *bullet_bmp;
BITMAP *explode_bmp;

//mapa do jogo
extern int map[];

// double buffer
BITMAP *buffer;
// tiles
BITMAP *tiles;
// background virtual
BITMAP *scroll;
// screen background
BITMAP *back;

//prototipos das funcoes
void criatanque(int num);
void destroitanque(int num);
void movertanque(int num);
void explode(int num, int x, int y);
void movebala(int num);
void criabala(int num);
void atira(int num);
void frente(int num);
void atras(int num);
void esquerda(int num);
void direita(int num);
void teclado();
void preparatanque(int i);
void placar(int);
void preparatela();
void apresenta();
int inside(int,int,int,int,int,int);
BITMAP *grabframe(BITMAP *, int,int,int,int,int,int);

#endif
