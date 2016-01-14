#include <stdio.h> //Librería estandar de entrada y salida (I/O)
#include <stdlib.h>
#include <curses.h>

#define tamano_cadena 40

#define NORMAL  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"

/**
    NOTA IMPORTANTE:
    El espacio que ocupan en memoria los tipos de datos
    varían de acuerdo a la arquitectura sobre la que
    se vaya a compilar el programa.
*/

int main(){
  int entero; //Entero con signo de 4 bytes
  unsigned long long entero_Largo; // Entero largo de 4 bytes (tamano constante en la arquitectura, a diferencia del int)
  float real=987.2;  //Real 4 bytes
  double real_Largo=6875.3123; //Real de 8 bytes

  char caracter;//1 byte
  char cadena1[20];
  char cadena2[tamano_cadena];


  printf(GREEN);
  unsigned int entero_sinSigno = -2; //entero sin signo de 4 bytes

  //unsigned float real_sinSingno; // real sin signo de 4 bytes

  //ASIGNACION

  entero = 20;
  entero_Largo = 34;

  //
  printf("Entero:  %d Tamano en bytes = %d",entero, sizeof(entero));
  printf("\nReal: %f Tamano en bytes = %d",real, sizeof(real));
  printf("\nEntero largo = %d Tamano = %d",entero_sinSigno,sizeof(long long));
  //printf("Entero largo = %");

  printf(YELLOW);
  printf("\n\nIngrese un entero:");
  scanf("%d",&entero);
  printf("\nIngrese entero largo:");
  scanf("%llu",&entero_Largo);
  printf("\nIngrese un real:");
  scanf("%f",&real);
  printf("\nIngrese un real largo:");
  scanf("%lf",&real_Largo);

  printf(RED);printf("\n\nIngrese un caracter:");
  fflush(stdin);
  scanf("%c",&caracter);//correcto
  //scanf("%s",&cadena1);//maaal!!!!

  printf(BLUE);printf("\n\nIngrese cadena1:");
  fflush(stdin);//Funcion usada ṕara limpiar el búfer de entrada (stdin)
  fgets(cadena1,tamano_cadena,stdin);
  printf(RED);printf("\n\nIngrese cadena2:");
  fflush(stdin);
  fgets(cadena2,tamano_cadena,stdin);

  printf(BLUE);
  printf("Entero1 = %d, Entero2 = %llu, Real1 = %f, Real2 = %.2lf \n\n",entero,entero_Largo,real,real_Largo);
  printf("Cadena1 = %s, Cadena2 = %s, Caracter = %c \n", cadena1,cadena2,caracter);

  printf(NORMAL);
  system("PAUSE");//em Windows
  //getch(); // en linux

  return 0;
}
