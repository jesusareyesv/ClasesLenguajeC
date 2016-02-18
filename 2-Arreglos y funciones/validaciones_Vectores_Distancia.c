#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <ncurses.h>
#include <math.h>
#include <string.h>

#define NORMAL  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"

#define nPuntos 4

int main(){
  float partida[2], fin[2];
  float partidaM[2][nPuntos], finM[2][nPuntos],distanciaM[nPuntos];
  float distancia;

  int i,j,respuesta;

  printf(RED);printf("DISTANCIA CARTESIANA");

  do{
    printf(BLUE);printf("\n\n\n/*********************** MENU PRINCIPAL ***********************/\n");
    printf(CYAN); printf("1) Dos puntos.\n2)Conjunto de 4 pares de puntos.\n\nRespuesta:");
    fflush(stdin);
    scanf("%d", &respuesta);
  }while(respuesta > 2 || respuesta < 1);


  switch (respuesta) {
    case 1:
        printf(NORMAL);
        fflush(stdin);
        printf("Ingrese X1=");scanf("%f",partida[0]);
        printf("Ingrese Y1=");scanf("%f",partida[1]);
        printf("Ingrese X2=");scanf("%f",fin[0]);
        printf("Ingrese Y2=");scanf("%f",fin[2]);

        distancia = sqrt(pow(fin[0]-partida[0],2)+pow(fin[1]-partida[1],2));
        printf(RED);printf("La distancia es: %f",distancia);
        break;
    case 2:
        printf(NORMAL);
        for(i = 0; i < nPuntos; i++){
          fflush(stdin);

          printf("\n\n[INICIO]Ingrese X(%d)a:",i+1);
          scanf("%f",&partidaM[0][i]);
          printf("\nIngrese Y(%d)a:",i+1);
          scanf("%f",&partidaM[1][i]);

          printf("\n\n[FIN]\nIngrese X(%d)b:",i+1);
          scanf("%f",&finM[0][i]);
          printf("\nIngrese Y(%d)b:",i+1);
          scanf("%f",&finM[1][i]);

          distanciaM[i] = sqrt(pow(finM[0][i]-partidaM[0][i],2)+pow(finM[1][i]-partidaM[1][i],2));
        }

        printf(MAGENTA);
        printf("P1\tP2\nDistancia\n\n");
        printf(GREEN);
        for(i = 0; i < nPuntos; i++)
          printf("(%.2f,%.2f)\t(%.2f,%.2f)\t%.2f\n",partidaM[0][i],partidaM[1][i],finM[0][i],finM[1][i],distanciaM[i]);
        break;
  }
 return 0;
}
