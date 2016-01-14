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

#define cantidadNumeros 5

int main(){
    int i = 0;
    int arrayNumeros[cantidadNumeros],posMayor,posMenor,nMayor,nMenor;
    float media,mediaPonderada,suma,sumaPonderada,proporcionMayorMenor;

    printf("%sBienvenido\n\t%sIngrese %d numeros enteros por teclado.%s\n\n",BLUE,GREEN,cantidadNumeros,NORMAL);

    for(i = 0; i < cantidadNumeros; i++){
      printf("\t\t%c: ",'A'+i);
      scanf("%d",&arrayNumeros[i]);
    }

    printf("%sLos números ingresados fueron:\n\n%s",BLUE,MAGENTA);
    for(i = 0; i < cantidadNumeros; i++)
      printf("\t%d,",arrayNumeros[i]);

    //suma para hacer la media
    for(i = 0; i < cantidadNumeros; i++)
      suma = suma + arrayNumeros[i];

    //sacamos la media
    media = suma / cantidadNumeros;

    //suma para calcular la media ponderada de acuerdo al lugar en el vector
    for(i = 0; i < cantidadNumeros; i++){
      if(i%2 == 0)
        sumaPonderada += arrayNumeros[i];
      else
        sumaPonderada += arrayNumeros[i]*i;
    }

    mediaPonderada = sumaPonderada/cantidadNumeros;

    printf("\n\n%sLa media entre los numeros es %.2f y la media ponderada de acuerdo a su posicion es %.2f\n",YELLOW,media,mediaPonderada);

    for(i = 0; i < cantidadNumeros; i++){
      if(arrayNumeros[i] > nMayor){
        nMayor = arrayNumeros[i];//guarda el primer mayor encontrado.En caso de que haya dos iguales se obvia el segundo.
        posMayor = i;  //Cuando necesitamos el último utilizamos >=
      }

      if(arrayNumeros[i] < nMenor){
        nMenor = arrayNumeros[i];//guarda el primer menor encontrado.En caso de que haya dos iguales se obvia el segundo.
        posMenor = i;//Cuando necesitamos el último utilizamos <=
      }

    }

    proporcionMayorMenor = nMayor / nMenor;

    printf("%sEl numero mayor es %d y el menor es %d. La proporción entre ambos es de %.4f.\n\n%s",CYAN,nMayor,nMenor,proporcionMayorMenor,NORMAL);
}
