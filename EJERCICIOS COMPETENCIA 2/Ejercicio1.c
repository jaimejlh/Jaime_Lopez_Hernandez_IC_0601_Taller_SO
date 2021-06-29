#include <stdio.h>
#include<stdlib.h>

int main()
{
int x; //Declaración de x de tipo entero
int *p; //Declaración del puntero p de tipo entero
x=10;  //Asignar 10 a x
p = &x; //Asignación de x al puntero p

int y; //Declaración de x de tipo entero
int *puntero; //Declaración del puntero puntero de tipo entero
y=20;   //Asignar 20 a y
puntero = &y; //Asignación de y al puntero puntero
//imprimir el contenido de puntero p
printf("El contenido del puntero p es: %d \n",*p);
*p += 1; //Sumar 1 al puntero p
printf("El nuevo contenido del puntero p es: %d \n",*p);
*p += 2;  //Sumar 2 al puntero p
printf("El nuevo contenido del puntero p es: %d \n",*p);
//Imprimir el puntero puntero
printf("El valor de puntero Puntero es: %d \n",*puntero);
return 0;
}