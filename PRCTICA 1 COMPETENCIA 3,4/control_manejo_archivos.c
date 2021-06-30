#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#define TAM_NOMBRE 100

typedef struct Lista Lista;
typedef struct Nodo Nodo;
typedef struct Nodo{
	Nodo *siguiente; 
	char *cadenas;
};

struct Lista{
	Nodo *inicio;
};
					
int existe_archivo(char *nombre_arch);
int crear_archivo(char *nombre_arch);
void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch);

Lista *lista_nueva(void);
void insertarEnLista(Lista *L, char *cadenas);
void imprimirLista(const Lista *L);
void listaLibera(Lista *L);

int main(int argc, char const *argv[]){

	//Estructura FILE
	FILE *ptrArchivo;
	FILE *ptrArchivo2;
	
	int existe_arch = 0;
	char nombre_arch[TAM_NOMBRE];	
	strcpy(nombre_arch, argv[1]);
	char nombre_arch2[TAM_NOMBRE];
	strcpy(nombre_arch2, argv[2]);
	int i;
	Lista *Ln;
	Ln = lista_nueva();		
	
	//control archivo de lectura
	do{
		existe_arch = existe_archivo(nombre_arch);
		if(existe_arch){
			printf("\nEl archivo: %s, YA EXISTE.\n", nombre_arch);
		}
		else{
			printf("El archivo: %s, NO EXISTE.\n", nombre_arch);
			if(crear_archivo(nombre_arch)){
			}
			else{
				printf("El archivo:%s, NO se pudo crear.\n", nombre_arch);
			}
		}
	}while(existe_arch==0);	

	//Open files
	ptrArchivo = fopen(argv[1],"r");
	ptrArchivo2 =fopen(argv[2],"w");

	if(ptrArchivo==NULL){
		perror("\nError al intentar abrir el archivo");
		return 1;
	}

	char aux[20];
	char ordenalfabetico[20][20];
	int comp,comp2,comp3;
	int l=0;

printf("\nLista de palabras leidas en entrada\n");
	while(feof(ptrArchivo)==0){
		fscanf(ptrArchivo, "%s", ordenalfabetico[l]);
		insertarEnLista(Ln, ordenalfabetico[l]);
		printf("%s: Palabra leida correctamente\n", ordenalfabetico[l]);
		l++;
	}

//Metodo de ordenamiento de burbuja
for(comp=0; comp<l-1; comp++){
       	comp3=comp;
       	strcpy(aux, ordenalfabetico[comp]);
       	for(comp2=comp+1; comp2<l; comp2++){
           if(strcmp(ordenalfabetico[comp2], aux)<0){
               	comp3=comp2;
               	strcpy(aux, ordenalfabetico[comp2]);
           	}
        }
        	strcpy(ordenalfabetico[comp3],ordenalfabetico[comp]);
        	strcpy(ordenalfabetico[comp],aux);
    	}
    	
printf("\nDatos en el archivo de salida"); 
	for(comp=0; comp<l; comp++)
    	{
        printf(" %s",ordenalfabetico[comp]);
        fprintf(ptrArchivo2,"%s\n",ordenalfabetico[comp]);
        insertarEnLista(Ln,ordenalfabetico[comp]);
        listaLibera(Ln);
        printf("\n");
    }

	fclose(ptrArchivo);
	printf("\nEl archivo ha sido leido.");

	if(ptrArchivo2==NULL){
		printf("Error al crear el archivo de escritura\n");
		return 0;
	}

	fclose(ptrArchivo2);
	printf("\nEl archivo de escritura creado\n");
	return 0;
	}

Lista *lista_nueva(void){

	Lista *Ln;
	Ln = (Lista *) malloc(sizeof(Lista));
	Ln -> inicio = NULL;
	return Ln;
}

void insertarEnLista(Lista *Ln, char *cadenas){

	Nodo *n1, *n2;
	if(Ln->inicio == NULL){
		Ln->inicio = (Nodo *)malloc(sizeof(Nodo));
		Ln->inicio->cadenas = cadenas;
		Ln->inicio->siguiente = NULL;
		return;
	}
	n1 = Ln->inicio;
	while(n1 !=NULL){
		n2 = n1;
		n1 = n1->siguiente;
		return;
	}
	n2->siguiente = (Nodo *)malloc(sizeof(Nodo));
	n2->siguiente->siguiente = NULL;
	n2->siguiente->cadenas = cadenas;
}

void imprimirLista(const Lista *Ln){
	Nodo *i;
	for(i = Ln->inicio; i == NULL; i= i->siguiente){
		printf("%s", i->cadenas);
	}
	printf("\n");
}

void listaLibera(Lista *Ln){
	if(Ln->inicio == NULL){
		return;
	}

	if(Ln->inicio->siguiente == NULL){
		return;
	}
	Nodo *n1,*n2,*n3;
	while(n1 != NULL){
		n2 = n1;
		n1 = n1->siguiente;
	}
	free(n2);
	n3->siguiente = NULL;
	listaLibera(Ln);
}

//control archivo1
int existe_archivo(char *nombre_arch){
	FILE *ptrArchivo;
	int existe = 0;
	ptrArchivo = fopen(nombre_arch, "r");
	if( ptrArchivo != NULL ){
		existe = 1;
		cerrar_archivo(ptrArchivo, nombre_arch);
	}	
	return existe;
}

int crear_archivo(char *nombre_arch){
	int creado = 0;
	FILE *ptrArchivo;
	ptrArchivo = fopen(nombre_arch, "w");
	if( ptrArchivo == NULL ){
		printf("El archivo: %s, No pudo crearse (uso de w).\n", nombre_arch);
	}	
	else{
		creado = 1;
		printf("Archivo: %s, Creado (uso de w).\n", nombre_arch);
	}
	return creado;
}

void cerrar_archivo(FILE *ptrArchivo, char *nombre_arch){
	fclose(ptrArchivo);
}
