#include <stdio.h>
#include<stdlib.h>

int main()
{
int arrayInt[5]; //Declaración del array
//inicialización del array
for(int i=0; i < 5; i++){
		arrayInt[i] = i;
	}
	
int *punteroInt; //Declaración del puntero
punteroInt = &arrayInt[0]; //Asignación del array al puntero

int *punteroIntDos; //Declaración del puntero dos
punteroIntDos = &arrayInt[0]; //Asignación del array en la posicion 0 al puntero
//Imprimir el contenido
printf("Contenido del primer elemento del array: %d \n",arrayInt[0]);
printf("Contenido del primer elemento del punteroInt: %d \n",*punteroInt);
printf("Contenido del primer elemento del punteroIntDos: %d \n",*punteroIntDos);
printf("Contenido del quinto elemento del array: %d \n",arrayInt[4]);
//Aritmetica de punteros
printf("El valor del quinto elemento de punteroInt es: %i \n", *punteroInt + 4);
printf("El valor del quinto elemento de punteroIntDos es: %i \n", *punteroIntDos + 4);
//ciclos de impresion
printf("PunteroInt ----------------------------------------------------------\n");
for(int i=0; i < 5; i++){
		printf("Posicion: %d, valor: %d \n", i, *punteroInt);
		*punteroInt++;
	}
printf("PunteroIntDos -------------------------------------------------------\n");
	for(int j=0; j < 5; j++){
		printf("Posicion: %d, valor: %d \n", j, *punteroIntDos);
		*punteroIntDos++;
	}

return 0;
}