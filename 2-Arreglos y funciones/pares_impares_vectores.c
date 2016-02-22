/*
  Github: TemetNosce95
  2016

  Cree un programa que llene 2 arreglos de 200 posiciones cada uno con numeros enteros aleatorios en el intervalo [1,200].
  Luego de llenarlos se debe calcular y mostrar el total de impares y pares en ambos arreglos.
  Además, debe mostrar por cada arreglo cuantos numeros son múltiplos de 2,3,5 y 7 respectivamente.
  Por último deberá calcular el promedio de los valores en cada array, y hallarles la raíz cuadrada a ambos promedios.
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define tamano_array 200

int main(){
  int a[tamano_array], b[tamano_array], i;
  int contador_pares_a, contador_pares_b, contador_impares_a, contador_impares_b, contador_multp_2_a, contador_multp_2_b, contador_multp_3_a, contador_multp_3_b, contador_multp_5_a, contador_multp_5_b, contador_multp_7_a, contador_multp_7_b;
  float acumulador_a, acumulador_b, promedio_a, promedio_b;

  contador_impares_a = contador_impares_b = contador_pares_a = contador_pares_b = contador_multp_2_a = contador_multp_2_b = contador_multp_3_a = contador_multp_3_b = contador_multp_5_a = contador_multp_5_b = contador_multp_7_a = contador_multp_7_b = 0;
  acumulador_a = acumulador_b = 0;//Los contadores y acumuladores deben inicializarse al principio del programa (a menos que se indique lo contrario)

  srand(time(NULL));

  for(i = 0; i < tamano_array; i++){
    a[i] = rand()%200 + 1; //genera enteros aleatorios entre [0,199] + 1, es decir, los generará entre [1,200]
    b[i] = rand()%200 + 1; //genera enteros aleatorios entre [0,199] + 1, es decir, los generará entre [1,200]
  }

  for(i = 0; i < tamano_array; i++){
    if(a[i] % 2 == 0){
      contador_pares_a++; // el (variable)++ usa el operador unario de post-incremento, es igual a hacer variable = variable + 1; pero en menos espacio
      contador_multp_2_a++;//el modulo entre 2 puede servir para discriminar tanto los pares como los multiplos de 2
    }else
      contador_impares_a++;

    if(b[i] % 2 == 0){
      contador_pares_b++;
      contador_multp_2_b++;
    }else
      contador_impares_b++;

    if(a[i] % 3 == 0)
      contador_multp_3_a++;

    if(b[i] % 3 == 0)
      contador_multp_3_b++;

    if(a[i] % 5 == 0)
      contador_multp_5_a++;

    if(b[i] % 5 == 0)
      contador_multp_5_b++;

    if(a[i] % 7 == 0)
      contador_multp_7_a++;

    if(b[i] % 7 == 0)
      contador_multp_7_b++;

    acumulador_a += a[i];
    acumulador_b += b[i];
  }

  printf("\nVECTORES CARGADOS\n\nA[i]\t\tB[i]\n-----------------------------------\n");
  for(i = 0; i < tamano_array; i++){
    printf("%d\t\t%d\n",a[i],b[i]);
  }
  printf("\n\nEl numero de numeros pares en A es %d e impares es %d.\n",contador_pares_a,contador_impares_a);
  printf("El numero de numeros pares en B es %d e impares es %d.\n\n",contador_pares_b,contador_impares_b);

  printf("En A hay %d multiplos de 2, %d multiplos de 3, %d multiplos de 5 y %d multiplos de 7.\n",contador_multp_2_a, contador_multp_3_a, contador_multp_5_a, contador_multp_7_a);
  printf("En B hay %d multiplos de 2, %d multiplos de 3, %d multiplos de 5 y %d multiplos de 7.\n\n\n",contador_multp_2_b, contador_multp_3_b, contador_multp_5_b, contador_multp_7_b);

  promedio_a = (float) acumulador_a / (float) tamano_array;
  promedio_b = (float) acumulador_b / (float) tamano_array;

  printf("El promedio de los numeros de A fue %f.\n",promedio_a);
  printf("El promedio de los numeros de B fue %f.\n\n",promedio_b);

  return 0;
}
