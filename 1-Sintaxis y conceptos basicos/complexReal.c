#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <ncurses.h>
#include <math.h>
#include <string.h>

#define NORMAL  "\x1B[0m"
#define RED  "\x1B[31m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE  "\x1B[34m"
#define MAGENTA  "\x1B[35m"
#define CYAN  "\x1B[36m"
#define WHITE  "\x1B[37m"

#define tamanoVector 5

int main(){
  int i = 0, clave[tamanoVector];
  double complejo[tamanoVector][2];
  bool banderaClaveExistente = false;

  printf("Bienvenido al programa de codificacion de claves bancarias:\n\n Seleccione la opcion ");
}
