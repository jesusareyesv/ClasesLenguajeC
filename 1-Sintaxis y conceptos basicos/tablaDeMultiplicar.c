/*


Github: TemetNosce95
2016

    Escriba un programa que genere las tablas de multiplicar del 0 al 30.
*/

#include <stdlib.h>
#include <stdio.h>

int main(){
  int i,j;

  printf("TABLAS DE MULTIPLICAR:\n\n");

  for(i = 0; i <= 30; i++){
    printf("Tabla del %d:\n",i);
    for(j = 0; j <= 30; j++){
      printf("%d x %d = %d\n",i,j,i*j);
    }
    printf("\n\n");
  }

  return 0;
}
