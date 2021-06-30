#include <stdio.h>	
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 100
void envcd(int sock);

int main(int argc, char *argv[]){
	int sock;
	struct sockaddr_in server;
	
	//Create socket
	sock = socket(AF_INET , SOCK_STREAM , 0);
	if (sock == -1){
		printf("No pudo crearse el socket!");
	}
	puts("Socket creado exitosamente!");
	
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons( 8888 );

	//Connect to remote server
	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0){
		perror("Conexion fallida. Error");
		return 1;
	}
	
	puts("Conectado..\n");
	
	envcd(sock);
	
	close(sock);
	return 0;
}

void envcd(int sock){
	char n1[MAX], n2[MAX], resultado[MAX] = {0};

	printf("Ingrese el numero 1: ");
	scanf("%s", n1);
	send(sock, n1, strlen(n1), MAX);
	printf("Ingrese el numero 2: ");
	scanf("%s", n2);
	send(sock, n2, strlen(n2), MAX);

	read(sock, resultado, MAX);

	printf("El resultado recibido del servidor es: %s\n", resultado);
}
