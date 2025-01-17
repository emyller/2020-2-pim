#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"
#include "../lib/utils.h"


bool login() {
	char usuario[100];
	char senha[100];

	exibe_titulo("Login");

	// Lê dados do usuário
	leia_resposta("Usuário", usuario);
	leia_resposta("Senha", senha);

	// Lê arquivo de usuários
	char linhas[100][200];  // Array de linhas
	int numero_linhas = leia_arquivo(LOGIN_ARQUIVO, 200, linhas);

	// Usuário padrão
	if (numero_linhas == 0 && strcmp(usuario, "admin") == 0 && strcmp(senha, "admin") == 0) {
		exibe_sucesso("Usuário ADMINISTRADOR.");
		return true;
	}

	// Tenta encontrar usuário e senha
	char linha[2][100];  // Array de valores em cada linha
	for (int i = 0; i < numero_linhas; i++) {
		// Compara usuário e senha com valores das linhas
		leia_linha_csv(linhas[i], 100, linha);
		if (strcmp(usuario, linha[0]) == 0 && strcmp(senha, linha[1]) == 0) {
			// Exibe mensagem de boas vindas
			printf("Bem vindo(a), %s!\n", usuario);
			exibe_sucesso("Usuário autenticado.");
			return true;
		}
	}

	// Não achou usuário e senha
	exibe_erro("Usuário ou senha incorretos.");
	return false;
}
