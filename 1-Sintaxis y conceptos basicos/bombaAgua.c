/*


Github: TemetNosce95
2016

  Con el propósito de controlar el consumo de agua en un proceso industrial, un operador debe abrir y cerrar una
  válvula varias veces, cada cierto tiempo durante una jornada de trabajo. Cada vez que
  el operador abre y cierra la válvula, deja pasar una cantidad de litros de agua, que es medida por un contador y
  cuya lectura puede ser registrada por el operador.

  Al iniciar el proceso, el depósito de agua se encuentra totalmente lleno y su capacidad, en litros, es un
  valor conocido. Aunque no es seguro que se efectúe el proceso; diseñe un algoritmo que permita controlar el
  proceso y responda las siguientes interrogantes:

  a.- Indicar, cada vez que el operador abra y cierre la válvula, la cantidad de agua que queda en el depósito.

  b.- Emitir una advertencia de acuerdo a la siguiente especificación:

    Cantidad en agua en el deposito | Advertencia

    Entre 1150 y 1500 litros        | Situación Normal

    Menos de 1150 litros            | Situación de Cuidado

  c.- Muestre la cantidad de agua que queda en el depósito, una vez que haya finalizado el proceso y calcule el
    porcentaje que tal cantidad representa, de la capacidad del depósito.

*/

#include <stdlib.h>
#include <stdio.h>

void clearIBuffer();//hice esto por el tipo de shell que uso en Linux. Creo que en Winbugs no es necesario limpiar "manualmente" la entrada estándar

int main(){

  float cantidad_agua, capacidad_deposito, agua_restante, porcentaje_final;
  char r;

  printf("Bienvenido!\n\nIngrese la capacidad del deposito de agua: ");
  scanf("%f",&capacidad_deposito);

  agua_restante = capacidad_deposito;

  printf("\n\nSe abrira la valvula? (s/n): ");
  clearIBuffer();//hice esto por el tipo de shell que uso en Linux. Creo que en Winbugs no es necesario limpiar "manualmente" la entrada estándar
  r = getchar();

  while(r == 's' || r == 'S'){
    printf("\nIngrese la cantidad de agua que registró el contador: ");
    scanf("%f",&cantidad_agua);

    agua_restante -= cantidad_agua;

    printf("\n\nLa cantidad de agua restante es %.4f.",agua_restante);

    if(agua_restante >= 1150 && agua_restante <= 1500)
      printf("\nSituacion normal.\n");
    else
      if(agua_restante < 1150)
        printf("\nSituacion de cuidado.\n");

    printf("\n\nSe abrira la valvula de nuevo? (s/n): ");
    clearIBuffer();//hice esto por el tipo de shell que uso en Linux. Creo que en Winbugs no es necesario limpiar "manualmente" la entrada estándar
    r = getchar();
  }

  porcentaje_final = agua_restante / capacidad_deposito * 100;
  printf("\n\n\nEL PROCESO HA FINALIZADO.\nLa cantidad de agua que queda en el deposito es %.4f (representa el %.4f %% de la capacidad del deposito).",agua_restante,porcentaje_final);

  return 0;
}


void clearIBuffer(){//hice esto por el tipo de shell que uso en Linux. Creo que en Winbugs no es necesario limpiar "manualmente" la entrada estándar
  char c;
  do{
    c = getchar();
  }while(c != '\n' && c != 'EOF');
}
