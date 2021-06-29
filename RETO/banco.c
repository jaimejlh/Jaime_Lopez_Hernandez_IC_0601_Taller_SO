#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

#define NUMERO_DE_CLIENTES 1


struct cliente {
        char nombre[256];
        int cuenta;
};

struct factura {
        int numero_de_factura;
        int cuenta_de_cliente;
        float  saldo;
};

    struct cliente clientes[1];
    struct factura Facturas[1];

int main(){



    menu();
}

void menu(){

    int opciones;

        printf("MENU \n\n");
        printf("1- Registrar \n");
        printf("2- Operaciones \n");
        printf("3- Salir \n");

        scanf("%d", &opciones);

        switch(opciones){
    case 1:
        registrar();
        break;
    case 2:
        opr();
        break;
    case 3:
        system("CLS");
        printf("\nSaliendo...\n");
        exit(0);
    default:
        system("CLS");
        printf("Operacion Invalida - Intente de Nuevo\n\n");
        menu();
        }

}


void registrar(){
    for(int i=0; (i < NUMERO_DE_CLIENTES); i++){
        printf("\nDigite os seguintes dados para registrar:\n");

        printf("\nDigite Nombre:\n");
        scanf(" %[^\n]s", &clientes[i].nombre);

        printf("\nDigite numero de cuenta:\n");
        scanf("%d",&clientes[i].cuenta);

        printf("\nDigite el saldo inicial:\n");
        scanf("%f",&Facturas[i].saldo);

        Facturas[i].numero_de_factura = i;
        Facturas[i].cuenta_de_cliente = clientes[i].cuenta;

        printf("\nCliente: %s factura: %d Saldo inicial: %1.2f\n\n",
        clientes[i].nombre, Facturas[i].numero_de_factura, Facturas[i].saldo);
    }
    printf("Pressione una tecla para continuar!\n\n");
    getch();
    system("CLS");
    opr();
}


void opr(){

int opciones;
int num_factura;
float valor;

    printf("\nMENU OPERACIONES\n");
    printf("\nSeleccione una Operacion:\n");
    printf("\n1-Retiro\n");
    printf("\n2-Deposito\n");
    printf("\n3-Salir \n");
    scanf("%d", &opciones);

        switch(opciones){

    case 1:

      printf("\nNúmero de cuenta:\n ");
      scanf("%d", &num_factura);

      printf("\nInforme el valor para retiro:\n ");
      scanf("%f",&valor);

      while(valor<=0){
        printf("\nValor Inválido! Ingresa un valor Valido!:\n ");
        scanf("%f",&valor);
      }

      for(int i=0; (i < NUMERO_DE_CLIENTES); i++){
        if (Facturas[i].numero_de_factura == num_factura) {
            if(Facturas[i].saldo > valor){
            Facturas[i].saldo -= valor;
            printf("\nretiro: %1.2f\n", valor);

                for(int j=0; j < NUMERO_DE_CLIENTES; j++){
                    if (clientes[j].cuenta == Facturas[i].cuenta_de_cliente)
                    printf("\n Saldo atual: %1.2f\n",Facturas[i].saldo);
                }
                printf("\nPrecione qualquier tecla para Volver al menu de Opciones!");
                getch();
                system("CLS");
                opr();
            }else{
                system("CLS");
                printf("No fue Posible realizar la Transaccion! Saldo Insuficiente.\n");
                opr();
            }
        }else{
            system("CLS");
            printf("Cuenta invalida o inexistente - intente de nuevo\n");
            opr();
        }

      }
        break;

    case 2:
      printf("\nDigite numero de cuente:\n ");
      scanf("%d", &num_factura);

      printf("\nDigite valor para deposito:\n ");
      scanf("%f",&valor);

    while(valor<=0){
        printf("\nValor Invalido! Ingresa un Valor valido!:\n ");
        scanf("%f",&valor);
      }

        for(int i=0; (i < NUMERO_DE_CLIENTES); i++){
            Facturas[i].saldo += valor;
            printf("\nDEPOSITO: %1.2f\n", valor);

            for(int j=0; j < NUMERO_DE_CLIENTES; j++){
                if (clientes[j].cuenta == Facturas[i].cuenta_de_cliente)
                printf("\nCliente: %s Saldo actual: %1.2f\n",
                clientes[j].nombre, Facturas[i].saldo);
            }
        }
            printf("\nPrecione qualquier tecla para Volver al MENU de Opciones!");
            getch();
            system("CLS");
            opr();
        break;
    case 3:
        system("CLS");
        printf("\nSaliendo...\n");
        exit(0);
    default:
        system("CLS");
        printf("Opcion Invalida - Digite una opcion Valida\n");
        opr();
    }
}
