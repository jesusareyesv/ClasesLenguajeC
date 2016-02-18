/*
En una planta de potabilizacion de agua se toman muestras del vital liquido para determinar su pureza de acuerdo a la cantidad de
contaminantes presentes en ella. Las muestras de agua se dividen en tres clases según su uso:

1) Para uso agrícola: si contiene 0,10 mg/l de arsénico 0,01 mg/l de cadmio y 0.20 mg/l cromo
2) Para uso pecuario: si contiene 0,20 mg/l de arsénico 0,05 mg/l de cadmio y 1,00 mg/l cromo
3) Para uso doméstico: si contiene 0,01 mg/l de arsénico 0,01 mg/l de cadmio y 0.05 mg/l cromo

Se requiere realizar un programa que dado un numero indeterminado (pero siempre habrá muestras a analizar) de muestras de agua pueda clasificar cada una. Además,
cuando se dejen de realizar muestras se debe mostrar la cantidad total de muestras de cada tipo, y el porcentaje que representan del total.
Por ultimo, se debe hacer un promedio del arsénico que presentan las muestras clasificadas como de uso pecuario.
*/
#include <stdlib.h>
#include <stdio.h>

int main(){
  char r;
  float aresenico, cromo, cadmio;
  int contador_muestras = 1;

  do{
    printf("Muestra #%d:\nIngrese la cantidad de los elementos.\n\nArsenico = ",contador_muestras);
    scanf("%f",&aresenico);

    printf("\nCadmio = ");
    scanf("%f",&cadmio);

    printf("\nCromo = ");
    scanf("%f",&cromo);

    /* SIN TERMINAR */

    printf("Desea registrar otra muestra? (s/n)");
    r = getchar();
  }while(r == 's' || r == 'S');

  return 0;
}
