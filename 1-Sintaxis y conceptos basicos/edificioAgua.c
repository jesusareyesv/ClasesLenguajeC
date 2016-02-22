/*
Github: TemetNosce95
2016

El condominio de un edificio de N pisos, necesita controlar el consumo de agua de
sus inquilinos. En cada piso hay varios apartamentos, y de seguro al menos uno está
habitado. Para cada apartamento se debe dar lectura del consumo de agua en litros y
del número de personas que lo habitan. El algoritmo a diseñar debe responder las
siguientes interrogantes:
a) Calcular para cada apartamento, cuántos litros gasta cada persona si el consumo
se distribuye en partes iguales.
b) Determinar cual piso consume más agua. No tome en cuenta el último piso, ya
que allí funciona una lavandería.
c) Calcule la capacidad total en litros que debe tener el tanque a construir, para
satisfacer el consumo total del edificio, considerando que se debe prever un 12,5
% adicional por razones de seguridad.*/

#include <stdlib.h>
#include <stdio.h>
#include <curses.h>//cambiar por conio.h en Winbugs

void clearIBuffer();

int main(){
  float cantidadAgua, aguaPorPiso, capacidadTanque, aguaPorPersona, pisoMasAguaCantidad, consumoTotalEdificio;
  int nPersonas, nApartamento, nPisos, nPisoMasAgua, i;
  char r;

  pisoMasAguaCantidad = consumoTotalEdificio = 0;

  printf("Bienvenido!\n\nPor favor ingrese el número de pisos:");scanf("%d",&nPisos);

  if(nPisos > 0){
    for(i = 0; i < nPisos; i++){
      printf("\n\n/************** PISO #%d **************/\n\n",i+1);
      aguaPorPiso = 0;
      nApartamento = 0;
      do{
        nApartamento++;
        printf("APARTAMENTO %d\n\tIngrese el numero de personas en el departamento:", nApartamento);
        scanf("%d",&nPersonas);

        printf("\tIngrese el consumo de agua (en litros):");
        scanf("%f",&cantidadAgua);

        aguaPorPiso += cantidadAgua;//igual a escribir aguaPorPiso = aguaPorPiso + cantidadAgua;

        aguaPorPersona = cantidadAgua / nPersonas;

        printf("\nLa cantidad de agua por persona es %.2f.",aguaPorPersona);
        printf("\nHay otro apartamento?(s/n)");clearIBuffer();r = getchar();
      }while(r=='s' || r=='S');

      if((aguaPorPiso > pisoMasAguaCantidad) && (i != nPisos - 1))//ignoramos el piso Npisos-1 porque nos dicen que ahi esta la lavanderia
      {
        nPisoMasAgua = i + 1;
        pisoMasAguaCantidad = aguaPorPiso;
      }

      consumoTotalEdificio += aguaPorPiso;
    }

    capacidadTanque = consumoTotalEdificio*0.125+consumoTotalEdificio;
    printf("\n\n\nEl consumo total del edificio es %.2f y el tanque deberia tener una capacidad de %.2f",consumoTotalEdificio,capacidadTanque);
  }else
    printf("El numero de pisos proporcionado es incorrecto.");

  return 0;
}

void clearIBuffer(){//hice esto por el tipo de shell que uso en Linux. Creo que en Winbugs no es necesario limpiar "manualmente" la entrada estándar
  char c;
  do{
    c = getchar();
  }while(c != '\n' && c != 'EOF');
}
