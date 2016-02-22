/*

Github: TemetNosce95
2016
                          EJERCICIO
El condominio de un edificio, ha planeado hacer una recolecta en cada uno de los
pisos, aunque no se sabe hasta cual llegaran. En cada piso hay 5 apartamentos. En
cada apartamento se solicita la colaboración en Bs y se toma nota del número de
personas que lo habitan. El algoritmo a diseñar debe responder las siguientes
interrogantes:

a) Calcular para cada apartamento, en promedio, cuanto aporto cada persona que lo
habita.
b) Determinar que piso contribuyo con la colaboración más baja. No tome en cuenta
el 1er. piso, ya que allí funciona las áreas comunes y la conserjería.
c) El año anterior se realizo la misma jornada y se logro recolectar una cantidad en
Bs. conocida. Determine que variación hubo éste año respecto al anterior.
*/

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <ncurses.h>
#include <math.h>
#include <limits.h>

#define NORMAL  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"

#define apartamentos_por_piso 3

int main(){
  float aporte,promedioAporte, aportePiso, colaboracionMasBaja, recolectadoAnhoAnterior;
  int nPersonas,contadorPiso,pisoColaboracionMasBaja, i;

  int r;//caracter que usaremos para controlar el ciclo de los pisos

  colaboracionMasBaja = INT_MAX;//limite superior para los int (en la implementacion de limits.h en estandar C no se encuentra declarado el macro FLT_MAX)
  promedioAporte=0;
  contadorPiso = 0;//inicializamos el contador en 0

  do{
    aportePiso = 0;
    fflush(stdin);
    contadorPiso++;
    printf(RED);printf("\n\nPiso #%d:\n\n",contadorPiso);
    for(i=0; i < apartamentos_por_piso; i++){
        printf(BLUE);printf("\n\tApartamento #%d",i+1);
        printf(GREEN);printf("\n\t\tIngrese el # de personas en el departamento: ");scanf("%d",&nPersonas);//pedimos el numero de eprsonas
        printf("\n\t\tIngrese el aporte:");scanf("%f",&aporte);//pedimos el monto del aporte

        promedioAporte=aporte/nPersonas;

        printf("\n\t\tEl aporte promedio por persona fue %f \n",promedioAporte);
        aportePiso += aporte;
    }

    if(contadorPiso != 1 && aportePiso < colaboracionMasBaja){
      colaboracionMasBaja = aportePiso;
      pisoColaboracionMasBaja = contadorPiso;
    }

    printf("%s\n\n\nQuedan pisos por registrar?",YELLOW);
    //scanf("%c",&r);
    scanf("%d",&r);
  }while(r == 1);

  printf("El piso con el menor aporte fue el #%d y su aporte fue de %.3f",pisoColaboracionMasBaja,colaboracionMasBaja);


  return 0;
}
