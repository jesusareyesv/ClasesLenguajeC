/*
Github: TemetNosce95
2016
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define tamano 10

int main(){

//------------------------------------------------------------------------------ Arreglos estáticos

  int A[tamano],B[tamano][tamano], C[tamano/2];
  float D[tamano];

  printf("Hola\n");

  srand(time(0));

  int i,j;

  printf("\nSe están cargando algunos numeros aleatorios en los vectores A y D.\n");

  for(i = 0; i < tamano; i++){
    A[i] = rand()%100;
    D[i] = (float) (rand()%100) / (float) (rand()%100 + 1);
  }

  printf("\nLos numeros cargados automáticamente son:\n");
  for(i = 0; i < tamano; i++)
    printf("A[%d] = %d; D[%d] = %.2f\n",i,A[i],i,D[i]);

  printf("\nIngrese 5 numeros enteros separados por ENTER\n");

  fflush(stdin);

  for(i = 0; i < (int)(tamano/2); i++){
    scanf("\n%d",&C[i]);
  }

  printf("\nLos numeros ingresados son:\n");
  for(i = 0; i < (tamano/2); i++){
    printf("C[%d] = %d\n",i,C[i]);
  }
//------------------------------------------------------------------------------ Breve bosquejo de arreglos dinámicos

    int *E, **F;

    E = (int*) malloc(3*sizeof(int));//Vector dinámico

    F = (int**) malloc(3*sizeof(int*));//Vector de punteros a vectores

    for(i = 0; i < 3; i++)
      F[i] = (int*) malloc(3*sizeof(int));//vector individual de enteros dentro del vector de punteros a enteros

    if(E && F){
      printf("\n Arreglos dinámicos creados con éxito :D.\n");
      printf("\nIngrese la data a guardar en E (vector):\n");
      for(i = 0; i < 3; i++)
        scanf("\n%d",&E[i]);

      printf("\nIngrese la data a guardar en F (matriz):\n");
      for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
          scanf("\n%d",&F[i][j]);

      printf("\nInformacion guardada en E:\n\n");
      for(i = 0; i < 3; i++)
        printf("E[%d] = %d\n",i,E[i]);

      printf("\nInformacion guardada en F:\n\n");
      for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++)
          printf("%d ",F[i][j]);
        printf("\n");
      }

      free(E);//cada vez que se crea un arreglo dinamico se debe liberar la memoria "manualmente"
      for(i = 0; i < 3; i++)
        free(F[i]);
      free(F);

    }

}
