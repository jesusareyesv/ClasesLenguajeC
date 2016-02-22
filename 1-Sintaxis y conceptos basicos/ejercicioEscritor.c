/*

Github: TemetNosce95
2016

Un escritor desea colocar a la venta, los ejemplares de su libro en dos formatos, el tradicional (Texto Impreso)

cuyo precio es de Bs.F 75 y el digitalizado (CD) a Bs.F 45. El, desea experimentar las ventas online ( en línea

vía Internet) debido a que no posee un local comercial y además ha escuchado que de esa manera puede llegar a

mayor cantidad de publico.

El escritor requiere de la elaboración de un algoritmo que le permita atender a los clientes, solicitándoles:

sus nombres, y la cantidad de ejemplares de cada formato a adquirir; además el cliente debe revelar su

ubicación geográfica, en el país, indicando una de las siguientes regiones: Occidente, Oriente o Centro.

El escritor ha decidido que por cada ejemplar que el usuario adquiera se le hará un descuento del 2%

sobre el monto total de la compra. Asimismo, si el cliente adquiere mas de 3 ejemplares de un mismo formato

el envío será gratuito, lleve o no ejemplares del otro formato; de lo contrario el costo del envío se establece de

acuerdo a la región tal como se indica:

Para Occidente Bs.F 45

Para Oriente Bs.F 35

Para Centro Bs.F 25

El algoritmo que usted debe construir, considerando que el escritor va experimentar con este sistema de
ventas y que tal vez ningún cliente se interese, debe:

a) Calcular y mostrar el total de ejemplares vendidos, de cada formato. (6 puntos)

b) Indicar a cada cliente, el monto en Bs.F de la compra y el costo de envío. (10 puntos)

c) Calcular y mostrar el descuento promedio otorgado a los clientes. (6 puntos)

d) Determinar a que región pertenece el cliente, que adquirió mas ejemplares del formato digital, pero
ninguno del formato impreso. También identifique a tal cliente. Considere que si varios clientes lo cumplen,
registre sólo el último que cumple los requisitos. (8 puntos)

Valor = 30 puntos*/

#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <string.h>

#define tamanoNombre 40
#define precioFisico 75
#define precioDigital 45
#define envioOccidente 45
#define envioOriente 35
#define envioCentro 25
#define porcentajeDescuento 2 // 2%

void clearIBuffer();

int main(){
  char r, nombre[tamanoNombre], nombreIdentificar[tamanoNombre];
  int region, cantidadTotalDigital, cantidadTotalFisico, ejemplaresFisico, ejemplaresDigital, contadorClientes, mayorFormatoDigital;
  float costoEnvio, descuento, montoCompra, sumaDescuento, descuentoPromedio;

  mayorFormatoDigital = -1654654654;
  cantidadTotalFisico = cantidadTotalDigital = contadorClientes = 0;
  sumaDescuento = 0;

  printf("Bienvenido(a) al sistema de venta de libros online\n\n\t¿Hay algún comprador?(s/n): ");
  r = getchar();

  while(r == 's' || r == 'S'){

    contadorClientes++;
    printf("\n/---------------- DATA ----------------/");
    printf("\nPor favor ingrese su(s) nombre(s):");clearIBuffer();gets(nombre);

    printf("\n\nIngrese la cantidad de ejemplares en físico:"); scanf("%d",&ejemplaresFisico);
    printf("\n\nIngrese la cantidad de ejemplares en digital:"); scanf("%d",&ejemplaresDigital);

    do{
      printf("Ingrese la region geografica donde se encuentra ([1] Occidente, [2] Centro, [3] Oriente):");
      scanf("%d",&region);
    }while(region < 1 || region > 3);

    descuento = (ejemplaresFisico + ejemplaresDigital) * porcentajeDescuento;

    sumaDescuento += descuento;

    montoCompra = ejemplaresFisico * precioFisico + ejemplaresDigital * precioDigital;
    montoCompra -= montoCompra * (descuento / 100);

    printf("/************** FACTURA **************/\nNombre: %s",nombre);
    printf("\nMonto: %.4f",montoCompra);

    if(ejemplaresFisico > 3 || ejemplaresDigital > 3)
      costoEnvio = 0;
    else{
      switch(region){
        case 1: costoEnvio = envioOccidente;break;
        case 2: costoEnvio = envioCentro;break;
        case 3: costoEnvio = envioOriente;break;
      }
    }

    printf("\nCosto de envio: %.4f",costoEnvio);

    if(ejemplaresDigital >= mayorFormatoDigital && ejemplaresFisico == 0){//se guarda el ultimo porque utilizamos >=
      strcpy(nombreIdentificar,nombre);
      mayorFormatoDigital = ejemplaresDigital;
    }

    printf("\n\n¿Hay algún otro comprador?(s/n): ");
    clearIBuffer(); r = getchar();
  }

  descuentoPromedio = sumaDescuento / (float) contadorClientes;

  printf("\n\nEl descuento promedio fue de %.2f por ciento.",descuentoPromedio);
  printf("\nEl cliente que compro mayor cantidad de libros solo en presentaion digital fue %s con %d libros.",nombreIdentificar,mayorFormatoDigital);
  return 0;
}

void clearIBuffer(){//hice esto por el tipo de shell que uso en Linux. Creo que en Winbugs no es necesario limpiar "manualmente" la entrada estándar
  char c;
  do{
    c = getchar();
  }while(c != '\n' && c != 'EOF');
}
