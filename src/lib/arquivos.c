#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "./arquivos.h"


void escreve_arquivo(char* caminho, char* conteudo) {
	/*
	Escreve uma nova linha em um arquivo
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
	char valor[1024] = ""; // Buffer para valores (máximo 1024 bytes)
	char linha[4096] = "";  // Buffer da linha (máximo 4096 bytes)

	va_start(valores, quantidade);
	for (int i = 0; i < quantidade; i++) {
		// Insere valor na linha
		strcpy(valor, va_arg(valores, char*));
		substitui_texto(valor, ",", " ");  // Previne conflito com vírgulas do CSV
		strcat(linha, valor);

		// Insere separador (vírgula) até antes do último valor
		if (i < (quantidade - 1)) { strcat(linha, ","); }
	}
	va_end(valores);

	// Escreve linha CSV no arquivo de texto
	escreve_arquivo(caminho, linha);
}


void substitui_texto(char* texto, char* remocao, char* insercao) {
	/*
	Substitui um caractere por outro(s) em uma string
	*/
	size_t tamanho_texto = strlen(texto);
	size_t tamanho_remocao = strlen(remocao);
	size_t tamanho_insercao = strlen(insercao);
	char resultado[tamanho_texto * tamanho_insercao + 1];
	char teste_remocao[tamanho_remocao + 1];

	// Percorre todos os caracteres da string
	for (int i = 0, r = 0; i < tamanho_texto; i++) {
		// Monta a amostra de teste
		for (int s = 0; s < tamanho_remocao; s++) {
			teste_remocao[s] = texto[i + s];  // Copia próximo caractere
		}
		teste_remocao[tamanho_remocao] = '\0';  // Sinaliza final da amostra

		// Amostra de teste bate com string de remoção
		if (strcmp(teste_remocao, remocao) == 0) {
			// Substitui texto no resultado
			for (int s = 0; s < tamanho_insercao; s++) {
				resultado[i + s] = insercao[s];
			}
			i = i + tamanho_remocao - 1;  // Pula índice no texto
			r += tamanho_insercao;  // Incrementa índice do resultado
		}

		// Amostra de teste não bate
		else {
			resultado[r] = texto[i];  // Copia próximo caractere para o resultado
			r++;  // Incrementa índice do resultado
		}

		resultado[r] = '\0';  // Sinaliza final do resultado
	}

	strcpy(texto, resultado);  // Modifica texto original
	resultado[0] = '\0';  // Esvazia resultado
}
