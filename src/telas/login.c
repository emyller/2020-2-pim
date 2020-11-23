#include <stdio.h>
#include "../lib/entrada.h"


int login() {
	char usuario[20];
	char senha[20];

	// Lê dados do usuário
	leia_resposta("Usuário", usuario);
	leia_resposta("Senha", senha);

	// TODO: Verificar dados

	// Exibe mensagem de boas vindas
	printf("Bem vindo, %s!\n", usuario);

	return 0;
}
