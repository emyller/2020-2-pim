#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"


bool login() {
	char usuario[100];
	char senha[100];

	// Lê dados do usuário
	leia_resposta("Usuário", usuario);
	leia_resposta("Senha", senha);

	// Lê arquivo de usuários
	char linhas[100][200];  // Array de linhas
	leia_arquivo("login.txt", 200, linhas);

	// Tenta encontrar usuário e senha
	char linha[2][100];  // Array de valores em cada linha
	for (int i = 0; i < 100; i++) {
		// Compara usuário e senha com valores das linhas
		leia_linha_csv(linhas[i], 100, linha);
		if (strcmp(usuario, linha[0]) == 0 && strcmp(senha, linha[1]) == 0) {
			// Exibe mensagem de boas vindas
			printf("Bem vindo(a), %s!\n", usuario);
			return true;
		}
	}

	// Não achou usuário e senha
	puts("Usuário ou senha incorretos.");
	return false;
}
