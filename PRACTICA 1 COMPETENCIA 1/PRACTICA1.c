#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int cambiarColorSemaforo(int);

int main(){
	int duracion = 30, tiempo = 3;
    int sem1 = 0, sem2 = 1;
    bool estado = true;
    time_t com, act;
    com = time(NULL);
    do{
	act = time(NULL);    
        if((int)difftime(act, com) % tiempo == 0 && estado){
            estado = false;
            sem1 = cambiarColorSemaforo(sem1);
            sem2 = cambiarColorSemaforo(sem2);                  
            if(sem1 == 1){
                printf( "\nEl semaforo 1 esta en Verde (pasan autos, se detienen personas) y el semaforo 2 en Rojo (se detienen autos, pasan personas) \n" );
            }
            else{
                printf( "\nEl semaforo 1 esta en Rojo (se detienen autos, pasan personas) y el semaforo 2 en Verde (pasan autos, se detienen personas) \n" );
            }
        }
        else if((int) difftime(act, com) % tiempo > 0 ){
            estado = true;
        }
    }while((int) difftime(act, com) < duracion );
    return 0;
}
int cambiarColorSemaforo(int semaforo){
    if(semaforo == 1){
        semaforo = 0;
    }
    else{
        semaforo = 1;
	}
    return semaforo;
}