/*
Un centro clínico de la ciudad, dispone de una caldera para producir, entre otras cosas, aire comprimido que es

almacenado en un recipiente.

El recipiente recibe constantemente presión de la caldera, pero éste tiene una capacidad máxima y por lo

tanto requiere de un control continuo, cuya situación es considerada de acuerdo a la siguiente escala:

Presion promedio            180         350         590         750(máximo)
                  -----------/-----------/-----------/-----------/
Situacion         baja        moderada    aceptable   riesgo


En donde cada situación incluye el valor de su derecha.

Durante un periodo de trabajo de la caldera, un operador toma dos lecturas de la presión, cada cierto tiempo, es

decir varias veces. Considerando que el control no sea necesario siempre, por estar la caldera en

mantenimiento, diseñe un algoritmo para:

a) Calcular, cada vez que el operador tome las dos lecturas, la presión promedio, y de acuerdo a la escala

anterior emitir la situación correspondiente del recipiente.

b) Calcular el porcentaje de veces, que la situación se mantuvo en situación Moderada.

c) Considerando que las lecturas se toman en orden y que se debe llevar una numeración de las mismas;

determinar ¿En que numero de las lecturas se registro la mayor presión promedio, solo dentro de la

situación de Riesgo?.

Si sucedió en varias ocasiones considere la última vez que ocurrió.

Si nunca ocurrió la situación de riesgo, indicarlo.
*/

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>

void clearIBuffer();//aun no necesitamos saber que es, pero como adelanto es un prototipo de funcion

int main(){
  char r;
  float mayorPRiesgo = -99999, lectura1, lectura2, presion_promedio, porc_Moderada;
  int cont_Lecturas, cont_Moderada, situacion, nMayorPRiesgo;

  printf("Bienvenido al control de la caldera!\n\nVa a ingresar lecturas al control?(s/n)");
  r = getchar();

  if(r == 's' || r == 'S'){//para asegurarnos si responde otra cosa diferente de si no se ejecute la parte principal del algoritmo
      cont_Lecturas = cont_Moderada = nMayorPRiesgo = 0;//inicializamos todo

      while(r == 's' || r == 'S'){//usamos el while porque nos dicen que el control no se necesita siempre
        cont_Lecturas++;
        printf("\n\nSET DE LECTURAS #%d\n",cont_Lecturas);
        printf("Ingrese la lectura #1:");
        scanf("%f",&lectura1);
        printf("\nIngrese la lectura #2:");
        scanf("%f",&lectura2);

        presion_promedio   = (lectura1 + lectura2)/2.0;//añadimos el .0 porque algunos compiladores necesitan que se diferencien lso tipos de dato al momento de las operaciones
        printf("\n\nLa presion promedio es %.2f.",presion_promedio);
        /*En este caso usamos if/else porque tenemos que comparar entre valores numéricos (rangos) variables*/
        if(presion_promedio >= 0 && presion_promedio <= 180)
          situacion = 1;
        else
          if(presion_promedio <= 350)
            situacion = 2;
          else
            if(presion_promedio <= 590)
              situacion = 3;
            else
              if(presion_promedio <= 750)
                situacion = 4;
              else
                printf("\n\n PUUUUUM!!!! EXPLOTO LA CALDERA");

        /*Aquí usamos switch porque sabemos que siempre vamos a tener estos valores estáticos que salen de los if/else anteriores*/
        printf("\n");
        switch(situacion){
          case 1: printf("SITUACION: Presion baja");break;
          case 2:
                  printf("SITUACION: Presion moderada");

                  cont_Moderada++;
                  break;
          case 3: printf("SITUACION: Presion aceptable");break;
          case 4:
                  printf("SITUACION: Riesgo!");

                  if(presion_promedio >= mayorPRiesgo){
                    mayorPRiesgo = presion_promedio;
                    nMayorPRiesgo = cont_Lecturas;
                  }
                  break;
        }

        printf("\nDesea ingresar otro juego de lecturas?(s/n)");
        clearIBuffer();
        r = getchar();
      }

      porc_Moderada = ((float)cont_Moderada / (float)cont_Lecturas) * 100.0;
      //para algunos compiladores (GCC que es el que uso) y arquitecturas (como ARM) hya que especificar la conversion de entero a float para poder operar, de lo contrario haría una división inexacta entre enteros y en este caso perderíamos presicion decimal (que necesitamos para hallar el porcentaje).

      printf("El porcentaje de veces que la situacion se mantuvo en moderada es %.2f.\n",porc_Moderada);

      if(mayorPRiesgo == -99999)
        printf("Nunca ocurrió la situación de riesgo\n");
      else
        printf("La mayor presion en el rango de riego fue de %.2f y ocurrió en el juego de lecturas #%d",mayorPRiesgo,nMayorPRiesgo);

  }



  return 0;
}

void clearIBuffer(){//hice esto por el tipo de shell que uso en Linux. Creo que en Winbugs no es necesario limpiar "manualmente" la entrada estándar
  char c;
  do{
    c = getchar();
  }while(c != '\n' && c != 'EOF');
}
