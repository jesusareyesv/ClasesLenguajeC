#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define tamano_v 80
#define cota1_naleatorios 1000

int main(){
  int a[tamano_v],b[tamano_v],c[tamano_v],d[tamano_v/2],e[tamano_v];
  float f[tamano_v];
  int i=0;

  /*CARGAMOS Y MOSTRAMOS LOS VECTORES*/

  for(i=0; i < tamano_v; i++){

    //Cargamos A con numeros aleatorios entre 0 y 999
    a[i] = rand()%cota1_naleatorios;//[0,999]

    //Cargamos B con numeros aleatorios entre 200 y 1199
    b[i] = rand()%cota1_naleatorios + 200;//[200,1199]

    //Cargamos C con el producto entre A y B
    c[i] = a[i] * b[i];

    //Llenamos D con el cuadrado de los valores aleatorios generados por rand()
    if(i < tamano_v/2){
      d[i] = pow(rand()%cota1_naleatorios,2);
    }
  }


  for(i = 0; i < tamano_v/2; i++){
    e[i] = a[i];
    e[i+1] = b[rand()%tamano_v];//valor de una posicion aleatoria en b
    e[i+2] = c[i + tamano_v/2];//valor de las posiciones de la 2da mitad del vector C
    e[i+3] = d[i+1];//valor de la posiciion siguiente del vectod D
  }

  printf("VECTORES CARGADOS: \n\nA\tB\tC\n\n");
  for(i = 0; i < tamano_v; i++){
    printf("%d\t%d\t%d\n",a[i],b[i],c[i]);
  }

  printf("\n\n\tD,\tE\n\n");
  for(i = 0; i < tamano_v/2; i++)
    printf("\t%d\t%d\n",d[i],e[i]);

  //Almacenamos en el vector F la raiz cuadrada del valor absoluto de la diferencia entre cada posición de A y B
  printf("Llenando el vector F\n");
  printf("\n\nVector A\tVector B\tVector F\n\n");
  for(i = 0; i < tamano_v; i++){
    f[i] = sqrt(abs(a[i] - b[i]));
    printf("%d\t%d\t%.4f\n",a[i],b[i],f[i]);
  }

  //Contamos la cantidad de pares en A y la cantidad de impares en B
  //y hallamos la media de cada vector
  int contador_paresA=0,contador_imparesB=0,suma_A=0,suma_B=0;
  float mediaA,mediaB;

  for(i=0; i < tamano_v; i++){
    if(a[i] % 2 == 0)
      contador_paresA++;//reducción de contador_paresA = contador_paresA + 1;

    if(b[i] % 2 != 0)
      contador_imparesB++;

    suma_A = suma_A + a[i];
    suma_B += b[i];
  }

  mediaA = suma_A / tamano_v;
  mediaB = suma_B / tamano_v;

  printf("Media de A = %.3f y Media de B = %.3f.\n",mediaA,mediaB);
  printf("Cantidad de pares en A = %d, Cantidad de impares B = %d.\n\n",contador_paresA,contador_imparesB);

  printf("Ordenando A y B por burbuja.\n\n\n");

  int aux;

  //Burbuja
  int j;
  for(i = 1; i < tamano_v; i++){
    for(j = 0; j< tamano_v - 1; j++){
      if(a[j] > a[j+1]){
        aux = a[j];
        a[j] = a[j+1];
        a[j+1] = aux;
      }
    }
  }

  for(i = 1; i < tamano_v; i++){
    for(j = 0; j< tamano_v - 1; j++){
      if(b[j] < b[j+1]){
        aux = b[j];
        b[j] = b[j+1];
        b[j+1] = aux;
      }
    }
  }

  printf("ORDENADOS:\nVector A\tVectorB\n\n");

  for(i = 0; i < tamano_v; i++)
    printf("%d\t%d\n",a[i],b[i]);

  return 0;
}
