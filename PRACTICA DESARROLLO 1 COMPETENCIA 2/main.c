#include "scheduler.h"

void reproducir_musica(void);
void abrir_youtube(void);
void escribir_texto_word(void);
void descargar_archivo(void);
void subiendo_archivo(void);
void compilando_programa(void);
void ejecutando_programa(void);
void usando_terminal(void);


int main(int argc, char const *argv[]){

	process *p1 = crear_Proceso(1, UN_SEGUNDO, "Proceso_1", reproducir_musica, ACTIVO); 		
	process *p2 = crear_Proceso(1, DOS_SEGUNDOS, "Proceso_2", abrir_youtube, NO_ACTIVO);
	process *p3 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_3", escribir_texto_word, ACTIVO); 
	process *p4 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_4", descargar_archivo, ACTIVO);   	
	process *p5 = crear_Proceso(3, TRES_SEGUNDOS, "Proceso_5", subiendo_archivo, ACTIVO);		
	process *p6 = crear_Proceso(4, TRES_SEGUNDOS, "Proceso_6", compilando_programa, NO_ACTIVO);
	process *p7 = crear_Proceso(0, TRES_SEGUNDOS, "Proceso_7", ejecutando_programa, ACTIVO);		
	process *p8 = crear_Proceso(2, CUATRO_SEGUNDOS, "Proceso_8", usando_terminal, ACTIVO);		
	process *p9 = crear_Proceso(5, CUATRO_SEGUNDOS, "Proceso_9", usando_terminal, NO_ACTIVO);	

	array_procesos *array = crear_ArrayProcesos();

	agregar_Proceso(array, *p1);
	agregar_Proceso(array, *p2);
	agregar_Proceso(array, *p3);
	agregar_Proceso(array, *p4);
	agregar_Proceso(array, *p5);
	agregar_Proceso(array, *p6);
	agregar_Proceso(array, *p7);
	agregar_Proceso(array, *p8);
	agregar_Proceso(array, *p9);

	ejecutar_Procesos(array);

	free(array);
	free(p1);
	free(p2);
	free(p3);
	free(p4);
	free(p5);
	free(p6);
	free(p7);
	free(p8);
	free(p9);

	return 0;
}


void *hilo(void *aVa){
	char *tex = (char *)aVa;
	printf("%s", tex);
}

void reproducir_musica(void){
	pthread_t action1;
	pthread_create(&action1, NULL, hilo, "Reproduciendo música...\n");
}

void abrir_youtube(void){
	pthread_t action2;
	pthread_create(&action2, NULL, hilo, "Iniciado Youtube...\n");
}


void escribir_texto_word(void){
	pthread_t action3;
	pthread_create(&action3, NULL, hilo, "Escribiendo en word...\n");
}

void descargar_archivo(void){
	pthread_t action4;
	pthread_create(&action4, NULL, hilo, "Descargando archivo...\n");
}

void subiendo_archivo(void){
	pthread_t action5;
	pthread_create(&action5, NULL, hilo, "Subiendo archivo...\n");
}

void compilando_programa(void){
	pthread_t action6;
	pthread_create(&action6, NULL, hilo, "Compilando programa...\n");
}

void ejecutando_programa(void){
	pthread_t action7;
	pthread_create(&action7, NULL, hilo, "Programa en ejecuciòn...\n");
}

void usando_terminal(void){
	pthread_t action8;
	pthread_create(&action8, NULL, hilo, "Terminal en uso...\n");
}
