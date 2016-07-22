#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

//Las estructuras y uniones son tipos de datos declarados por el programador que pueden contener en su interior varios tipos de datos

//Hay varias formas de declarar estructuras en C

//Esta forma define el tipo de dato con su identificador antes de instanciar, es decir, creo el molde y le asigno una etiqueta pero no le pongo nada adentro
struct Alpha{
	int a;
	int b;
};

typedef struct{
	//Los datos dentro de una estructura son diferentes a los datos de otras, así que se pueden llamar igual en caso de ser necesario.
	int a;
	int b;
	
	float x,y;
}Beta;//Así le asignamos la etiqueta luego de la declaración

struct Persona{
	char nombre[50];
	int edad;
	float altura;
	float peso;
} gerente{
// De esta forma podemos declarar una estructura y definir una variable de ese tipo al mismo tiempo.
// Puede ser conveniente en algunos casos hacer esto.
// El unico problema de esta declaración es que la hice por fuera del main y por lo tanto 'gerente' es una variable global (desaconsejado)
	"Carlos Mora",
	32,
	1.70,
	86.567
};

struct Circulo{ 
// Una estructura puede contener funciones en su interior para operar sus variables anidadas
// Es parecido a los metodos de la programación orientada a objetos
	float radio;
	
	float perimetro(){
		//podemos invocar a la variable radio desde aquí porque dentro de la estructura está definida como variable global para sus funciones internas
		return radio*2*3.1416;
	}
	
	float arco(float theta){
		return radio*theta;
	}
};

int main(void){
	Alpha punto_1,punto_2; // declaramos variables del tipo Alpha (la estructura que creamos arriba)
	Beta punto_3,punto_4; // declaramos variables del tipo Beta (la estructura que creamos arriba)
	
	Circulo c1; // declaramos variables del tipo Circulo (la estructura que creamos arriba)
	float angulo;
	
	//Cargamos valores a ambas variables que hemos creado
	
	//punto_1 = 4; // definicion errónea, porque la variable es del tipo Alpha, no es un entero, por lo tanto no podemos igualarlas
	
	// definición correcta (usando llaves {} ), asignamos un valor para cada uno de los enteros que se encuentran dentro de la estructura
	punto_1 = {4,6}; 
	
	printf("P1.a = %d y P1.b = %d",punto_1.a,punto_1.b);
	// Comprobamos que cargamos correctamente las variables
	// Como podemos ver, las variables dentro de la estructura se usan igual que cualquier otra del tipo int, float... sólo que se encuentran
	// anidadas dentro de otro identificador (nombre) que pertenece a un tipo estructura definido por el programador
	
	// Seguimos jugando un poco con la asignación de valores para comprobar que en efecto estas variables son como cualquier otra.
	punto_2.a = 2; punto_2.b = 8;  
	punto_2.a = 20; punto_2.b = 80;
	
	//Lo mismo que funciona con los enteros sirve para los reales
	punto_3.x = 45.2654564; punto_3.y = 789.156;
	punto_4 = {2, 3, 45.6, 12.96};
	
	c1.radio = 4; // Asignamos un valor a la variable anidada radio de la variable c1
	printf("\n\nPerimetro del circulo = %f",c1.perimetro()); // Usamos una funcion interna de la estructura para hallar el perimetro del circulo
	
	
	
	// En las siguientes instrucciones calculamos el arco recorrido por un movil sobre una circunferencia usando la misma variable c1

	printf("\nIngrese un valor para el radio de la circunferencia: ");
	// podemos leer directamente sobre la variable anidada
	scanf("%f",&c1.radio); 
	
	printf("\nIngrese el valor del angulo desplazado: ");
	scanf("%f",&angulo);
	
	// Llamamos a la funcion arco de la estructura para calcular el desplazamiento
	printf("\n\nLa longitud del arco del circulo recorrida es %.2f",c1.arco(angulo)); 
	
	
	// Imprimimos el nombre del gerente que declaramos como variable global antes del main, en tiempo de ejecución podemos ver que funciona perfectamente ese tipo de carga.
	printf("\n%s\n",gerente.nombre); 
	
	system("PAUSE");
	return 0;
}
