#include <stdio.h>
#include "../lib/entrada.h"


int login() {
	char usuario[20];
	char senha[20];

	// Lê dados do usuário
	leia_string("Informe o usuário: ", usuario);
	leia_string("Informe a senha: ", senha);

	// TODO: Verificar dados

	// Exibe mensagem de boas vindas
	printf("Bem vindo, %s!\n", usuario);

	return 0;
}
