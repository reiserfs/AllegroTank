// GUERRA DE TANQUE
// tanque.cpp
#include "guerratanque.h"


void frente(int num)
{
     tanque[num]->xspeed++;
     if (tanque[num]->xspeed > VELOCIDADE_MAXIMA) tanque[num]->xspeed = VELOCIDADE_MAXIMA;
}
void atras(int num)
{
     tanque[num]->xspeed--;
     if (tanque[num]->xspeed < -VELOCIDADE_MAXIMA) tanque[num]->xspeed = -VELOCIDADE_MAXIMA;
}
void esquerda(int num)
{
     tanque[num]->dir--;
     if (tanque[num]->dir < 0) tanque[num]->dir = 7;
}
void direita(int num)
{
     tanque[num]->dir++;
     if (tanque[num]->dir > 7) tanque[num]->dir = 0;
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

