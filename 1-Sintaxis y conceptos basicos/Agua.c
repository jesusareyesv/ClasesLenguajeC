/*
En una planta de potabilizacion de agua se toman muestras del vital liquido para determinar su pureza de acuerdo a la cantidad de
contaminantes presentes en ella. Las muestras de agua se dividen en cuatro clases según su uso:

1) Para uso agrícola: si contiene entre 0.2 y 0.6 mg/l de arsenico y entre 0.01 y 0.09 mg/l de cadmio
2) Para uso pecuario: si contiene entre 0.7 y 1.2 mg/l de arsenico y entre 0.10 y 0.13 mg/l de cadmio
3) Para uso doméstico: si contiene entre 1.3 y 2.1 mg/l de arsenico y entre 0.14 y 0.25 mg/l de cadmio
4) Sin clasificacion oficial, no apta.

Se requiere realizar un programa que dado un numero indeterminado (pero siempre habrá muestras a analizar) de muestras de agua pueda clasificar cada una. Además,
cuando se dejen de realizar muestras se debe mostrar la cantidad total de muestras, la cantidad total de muestras de cada tipo y el porcentaje que representan del total.
Por ultimo, se debe hacer un promedio del arsénico que presentan las muestras clasificadas como de uso pecuario.

NOTA: Se deben validar los datos a ingresar.
*/
#include <stdlib.h>
#include <stdio.h>

void clearIBuffer();

int main(){
  char r;
  float arsenico, cadmio, promedio_arsenico, porcentaje_agricola, porcentaje_pecuario, porcentaje_domestico, porcentaje_sc,acumulador_arsenico_pecuario;
  int contador_muestras,contador_agricola,contador_pecuario,contador_domestico, contador_sin_clasificacion;

  contador_agricola = contador_pecuario = contador_domestico = contador_sin_clasificacion = 0;
  acumulador_arsenico_pecuario = 0;
  contador_muestras = 1;

  do{
    printf("Muestra #%d:\nIngrese la cantidad de los elementos presentes en la muestra de agua.",contador_muestras);

    do{
      printf("\n\nArsenico = ");
      scanf("%f",&arsenico);
    }while(arsenico < 0);

    do{
      printf("\nCadmio = ");
      scanf("%f",&cadmio);
    }while(cadmio < 0);

    /* SIN TERMINAR */
    if( arsenico >= 0.2 && arsenico <= 0.6 && cadmio >= 0.01 && cadmio <= 0.09)
      contador_agricola++;
    else{
      if(arsenico >= 0.7 && arsenico <= 1.2 && cadmio >= 0.10 && cadmio <= 0.13){
        contador_pecuario++;
        acumulador_arsenico_pecuario += arsenico;
      }else{
        if(arsenico >= 1.3 && arsenico <= 2.1 && cadmio >= 0.14 && cadmio <= 0.25)
          contador_domestico++;
        else
          contador_sin_clasificacion++;
      }
    }

    printf("Desea registrar otra muestra? (s/n)");
    clearIBuffer();
    r = getchar();
  }while(r == 's' || r == 'S');

  porcentaje_agricola = contador_agricola / contador_muestras * 100;
  porcentaje_pecuario = contador_pecuario / contador_muestras * 100;
  porcentaje_domestico = contador_domestico / contador_muestras * 100;
  porcentaje_sc = contador_sin_clasificacion / contador_muestras * 100;

  promedio_arsenico = acumulador_arsenico_pecuario / contador_pecuario;

  printf("\n\n\tINFORME\n\nCantidad de muestras analizadas = %d.",contador_muestras);
  printf("\nMuestras agricola = %d, Porcentaje = %f.",contador_agricola,porcentaje_agricola);
  printf("\nMuestras pecuario = %d, Porcentaje = %f.",contador_pecuario,porcentaje_pecuario);
  printf("\nMuestras domestico = %d, Porcentaje = %f.",contador_domestico,porcentaje_domestico);
  printf("\nMuestras sin clasificacion = %d, Porcentaje = %f.",contador_sin_clasificacion,porcentaje_sc);

  printf("\n\nEl promedio de arsenico en muestars de tipo pecuario fue %f.\n",promedio_arsenico);

  return 0;
}

void clearIBuffer(){//hice esto por el tipo de shell que uso en Linux. Creo que en Winbugs no es necesario limpiar "manualmente" la entrada estándar
  char c;
  do{
    c = getchar();
  }while(c != '\n' && c != 'EOF');
}
