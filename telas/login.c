#include<stdio.h>
#include<stdlib.h>

int main() {
	char usuario[200];
	char senha[10];

	// Lê usuário da tela
	printf("Insira seu usuário: ");
	fgets(usuario, 200, stdin);

	// Lê a senha
	printf("Insira sua senha: ");
	fgets(senha, 10, stdin);

	// Autentica usuário
	printf("Bem vindo, %s!\n", usuario);

	return 0;
}