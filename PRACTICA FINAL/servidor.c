#include<stdio.h>
#include<string.h>	//strlen
#include<sys/socket.h>
#include<arpa/inet.h>	//inet_addr
#include<unistd.h>	//write

#define MAX 1000

void suma(int cliente_sock);

int main(int argc , char *argv[]){
	int socket_desc , client_sock , c , read_size;
	struct sockaddr_in server , client;
	
	//Create socket
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1){
		printf("No pudo crearse el socket!");
	}
	puts("Socket creado exitosamente..");
	
	//Prepare the sockaddr_in structure
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( 8888 );
	
	//Bind
	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0){
		//print the error message
		perror("bind failed. Error!!!");
		return 1;
	}
	puts("Bind hecho correctamente!");
	
	//Listen
	listen(socket_desc , 3);
	
	//Accept and incoming connection
	puts("Esperando conexion...");
	c = sizeof(struct sockaddr_in);
	
	//accept connection from an incoming client
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0){
		perror("Conexio fallida!");
		return 1;
	}
	puts("Conexion acpetada!");
	
	//Receive a message from client
	suma(client_sock);
	
	if(read_size == 0){
		puts("Client disconnected");
		fflush(stdout);
	}
	else if(read_size == -1){
		perror("Rcepcion de datos fallida!");
	}
	return 0;
}

void suma(int client_sock){
	char N1[MAX] = {0}, N2[MAX] = {0}, resultado[MAX] = {'0'}, aux[MAX], n1[MAX], n2[MAX], res[MAX] = {0};
	int n, LN1, LN2, len, tmp, cadena1, cadena2, m=0, z;

	read(client_sock, N1, MAX);
	printf("\n%s es el primer numero recibido del cliente\n", N1);
	read(client_sock, N2, MAX);
	printf("%s es el segundo numero recibido del cliente\n", N2);
	
	LN1=strlen(N1);
	LN2=strlen(N2);
	
	strcpy(n1, N1);
	strcpy(n2, N2);

	if(LN1>=LN2){
		len = LN1+1;
	}
	else{
		strcpy(aux, n1);
		strcpy(n1, n2);
		strcpy(n2, aux);
		LN1=strlen(n1);
		LN2=strlen(n2);
		len=LN2+1;
	}
	int x, y=LN2-1;
	if(LN1 >= LN2){
		for(x=LN1-1; x>=0; x--){
			cadena1=(n1[x])-48;
			if (y>=0){
				cadena2=(n2[y])-48;
				y--;
			} 
			else{
				cadena2=0;
			}
			tmp=(cadena1+cadena2+m);
			if(tmp>=10){
				resultado[x+1]=(tmp - 10)+48;
				m = 1;
			} 
			else{
				resultado[x+1]=(tmp)+48;
				m = 0;
			}
		}
		for(z=0; z<len;z++){
			resultado[z]=resultado[z+1];
		}
	send(client_sock, resultado, strlen(resultado), MAX);
	printf("Resultado enviado exitosamente al cliente\n");
	}
}
