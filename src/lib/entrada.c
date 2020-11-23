#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void _leia_resposta(char* pergunta, char* formato, char* resposta) {
	/*
	Função base para leitura de strings
	*/
	// Exibe pergunta
	if (formato != NULL) {
		printf(">> %s [%s]: ", pergunta, formato);  // Com formato definido
	} else {
		printf(">> %s: ", pergunta);  // Sem formato definido
	}

	// Lê resposta do stdin
	fgets(resposta, 1024, stdin);
	resposta[strlen(resposta) - 1] = '\0';  // Remove quebra de linha ao final
}


void leia_resposta(char* pergunta, char* resposta) {
	/*
	Lê uma string a partir de uma pergunta feita (sem formato definido)
	*/
	_leia_resposta(pergunta, NULL, resposta);
}


void leia_resposta_formato(char* pergunta, char* formato, char* resposta) {
	/*
	Lê uma string a partir de uma pergunta feita (com formato definido)
	*/
	_leia_resposta(pergunta, formato, resposta);
}


int leia_decisao(char* pergunta) {
	/*
	Lê uma decisão (booleano) a partir de uma pergunta feita
	*/
	char resposta_str[2];
	leia_resposta_formato(pergunta, "s/n", resposta_str);
	return (strcmp(resposta_str, "s") == 0);
}


void leia_digito(char* pergunta, int* resposta) {
	/*
	Lê um dígito a partir de uma pergunta feita
	*/
	char resposta_str[10];

	printf(pergunta);  // Exibe pergunta
	fgets(resposta_str, 10, stdin);  // Lê resposta
	*resposta = atoi(resposta_str);
}
