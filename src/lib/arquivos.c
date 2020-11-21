#include <stdio.h>


void escreve_arquivo(char* caminho, char* conteudo) {
	/*
	Abre um arquivo no sistema de arquivos (cria se necessário)
	*/
	FILE* file_pointer = fopen(caminho, "a");  // Abre arquivo, modo "a"ppend
	if (file_pointer == NULL) {
		printf("Erro ao abrir arquivo %s", caminho);
		return;
	}
	fprintf(file_pointer, "%s\n", conteudo);  // Escreve conteúdo numa linha nova no arquivo
	fclose(file_pointer);  // Fecha o ponteiro do arquivo
}
