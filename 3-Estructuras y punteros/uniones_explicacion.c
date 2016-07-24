#include <stdlib.h>
#include <stdio.h>

/* Las uniones son otro tipo de dato definido por el programador
    Su declaración en implementación es idéntico al de las estructuras y la única diferencia entre las dos es apreciable a
   nivel de memoria.

    A diferencia de las estructuras, todas las variables internas ocupan la misma dirección de memoria
    (cuyo tamaño está determinado por el tipo de dato de mayor tamaño). Es decir, si tenemos una estructura con
    2 variables (int a; double b;) cada uno tiene su propia dirección de memoria y por ende son independientes entre sí;
    el tamaño total de esa estructura en memoria serían 12 bytes (4 + 8). En cambio, en una unión la dirección de memoria es
    compartida, es decir, si modificamos una la otra también se modifica; el tamaño total de al unión en memoria es el tamaño del
    tipo de dato más grande.
*/

  // NOTA IMPORTANTE: El tamaño de los tipos de datos puede variar de una arquitectura a otra


  // Definimos 2 tipos de dato (1 union y 1 estructura) con los mismas variables internas (para apreciar su comportamiento)
  union Omega {
    int alpha;
    float beta;
    double gamma;
  };
  // El tamaño total de la unión será el del tipo de dato más grande (8 bytes)

  struct Ksi {
    int alpha;
    float beta;
    double gamma;
  };

  union Delta {
    int x;
    int y;
  };

int main(void){
  // Declaramos la union al igual que otro tipo de dato (igual que als estructuras)
  union Omega theta1;
  struct Ksi theta2;
  union Delta delta1;

  /*
   NOTA: a diferencia del archivo estructuras-explicacion.cpp (que es un archivo de código para C++), en los ficheros
   .c como éste es necesario colocar las palabras reservadas 'union' y 'struct' antes de la declaración de cada uno de
   las variables para que el compilador (GCC en este caso) pueda reconocerlos como tipos de dato definidos por el
   programador y no arroje errores de tipo de dato desconocido. (GCC respeta los estándares de C y C++, y nosotros
   también deberíamos hacerlo).
  */

  // Asignamos valores a las variables internas
  delta1.x = 375;
  delta1.y = 45213;

  // En tiempo de ejecución podemos observar que el asignar un valor a 'y' modifica el valor de 'x' y viceversa
  // (porque comparten la misma dirección de memoria).
  printf("D1.x = %d\t\t D1.y = %d",delta1.x, delta1.y);

  theta1.alpha = theta2.alpha = 2;
  theta1.beta = theta2.beta = 3.0;
  theta1.gamma = theta2.gamma = 4.0;

  /*
     Podremos ver que la union solo reconoce como ultimo valor valido al ingresado en 'gamma'
     Esto ocurre porque la codificación de un int, float y double son diferentes entre sí.
     Si guardamos uno en la misma dirección del otro cuando el sistema los decodifique se pueden ver cosas inesperadas.
     HAY QUE TENER MUCHO CUIDADO CON LAS UNIONES Y SU IMPLEMENTACION.
  */
  printf("\n T1.alpha = %d\t\t T2.alpha = %d", theta1.alpha, theta2.alpha);
  printf("\n T1.beta = %f\t\t T2.beta = %f", theta1.beta, theta2.beta);
  printf("\n T1.gamma = %f\t\t T2.gamma = %f", theta1.gamma, theta2.gamma);

  system("PAUSE");
  return 0;
}
