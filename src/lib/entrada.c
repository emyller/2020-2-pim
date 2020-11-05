#include <stdio.h>


void leia_string(char* pergunta, char* resposta) {
	/*
	Lê uma string a partir de uma pergunta feita
	*/
	printf(pergunta);  // Exibe pergunta
	fgets(resposta, 100, stdin);  // Lê resposta
	resposta[sizeof(resposta) - 1] = '\0';  // Remove quebra de linha ao final
}
