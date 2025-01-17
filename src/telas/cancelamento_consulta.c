#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"
#include "../lib/utils.h"
#include "./agendamento_consulta.h"


int cancelamento_consulta() {
	char nome_paciente[100] = "";
	char data[100] = "";
	char hora[100] = "";
	int remarcar_consulta;

	exibe_titulo("Cancelamento de Consulta");

	leia_resposta("Nome do paciente", nome_paciente);

	// Lê arquivo de usuários
	char linhas[100][500];  // Array de linhas
	int numero_linhas = leia_arquivo("agendamento_consulta.txt", 500, linhas);

	// Tenta encontrar usuário
	char linha[5][100];  // Array de valores em cada linha
	for (int i = 0; i < numero_linhas; i++) {
		// Compara usuários com valores das linhas
		leia_linha_csv(linhas[i], 100, linha);
		if (strcmp(nome_paciente, linha[0]) == 0) {
			printf("%s tem consulta no dia %s às %s.\n", nome_paciente, linha[3], linha[4]);
		}
	}

	// Pergunta ao paciente qual a data e hora da consulta que será desmarcada
	leia_resposta("Data da consulta que será cancelada", data);
	leia_resposta("Hora da consulta que será cancelada", hora);

	// Caso o paciente queira remarcar, executa tela de cadastro do paciente
	leia_decisao("Remarcar consulta", &remarcar_consulta);
	if (remarcar_consulta) {
		agendamento_consulta();
	}

	// Caso o paciente não queira remarcar, sua consulta é apenas cancelada
	else {
		// Insere resultados no arquivo CSV
		escreve_linha_csv(
			CANCELAMENTO_CONSULTA_ARQUIVO, 3,
			nome_paciente, data, hora  // TODO: Usar data e hora da consulta cancelada
		);
		exibe_sucesso("Consulta cancelada.");
	}

	return 0;
}
