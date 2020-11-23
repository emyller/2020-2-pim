#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void leia_string(char* pergunta, char* resposta) {
	/*
	Lê uma string a partir de uma pergunta feita
	*/
	printf(">> %s", pergunta);  // Exibe pergunta
	fgets(resposta, 1024, stdin);  // Lê resposta
	resposta[strlen(resposta) - 1] = '\0';  // Remove quebra de linha ao final
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
