#include <stdarg.h>
#include <stdio.h>
#include <string.h>


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


void escreve_linha_csv(char* caminho, int quantidade, ...) {
	/*
	Escreve uma linha de valores CSV em um arquivo

	Os parâmetros aqui são dinâmicos, podendo passar quantos for necessário para
	compor a linha de texto. Atenção ao tamanho máximo do buffer!
	*/
	va_list valores;  // Argumentos da função
	char linha[1024] = "";  // Buffer da linha (1024 bytes)

	va_start(valores, quantidade);
	for (int i = 0; i < quantidade; i++) {
		// Insere valor na linha
		strcat(linha, va_arg(valores, char*));

		// Insere separador (vírgula) até antes do último valor
		if (i < (quantidade - 1)) { strcat(linha, ","); }
	}
	va_end(valores);

	// Escreve linha CSV no arquivo de texto
	escreve_arquivo(caminho, linha);
}
