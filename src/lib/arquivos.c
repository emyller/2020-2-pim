#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include "./arquivos.h"
#include "./utils.h"


void leia_arquivo(char* caminho, int tamanho_linha, char linhas[][tamanho_linha]) {
	/*
	Lê o conteúdo de um arquivo de texto e retorna na memória
	*/
	FILE* ponteiro_arquivo = fopen(caminho, "r");  // Abre o arquivo, modo "r"ead
	if (ponteiro_arquivo == NULL) {
		exibe_erro("Erro ao abrir arquivo.");
		return;
	}

	// Determina tamanho do arquivo
	fseek(ponteiro_arquivo, 0, SEEK_END);  // Navega para o final do arquivo
	size_t tamanho_arquivo = ftell(ponteiro_arquivo);  // Lê a posição do último byte
	fseek(ponteiro_arquivo, 0, SEEK_SET);  // Navega para o começo do arquivo

	// Faz leitura do arquivo em linhas, caractere por caractere
	int posicao_linha = 0;
	int posicao_caractere = 0;
	char caractere;
	for (int i = 0; i < tamanho_arquivo; i++) {
		caractere = fgetc(ponteiro_arquivo);  // Lê próximo caractere

		// Quebra de linha
		// TODO: Dar suporte a EOF
		if (caractere == '\n') {
			linhas[posicao_linha][posicao_caractere] = '\0';  // Finaliza string
			posicao_linha++;  // Pula para a próxima linha
			posicao_caractere = 0;  // Reseta posição do caractere
			continue;  // Pula loop
		}

		// Insere caractere na linha (até no máximo o seu tamanho)
		if (posicao_caractere < tamanho_linha - 1) {
			linhas[posicao_linha][posicao_caractere] = caractere;
			posicao_caractere++;
		}
	}

	// Nulifica ponteiro após última linha
	linhas[posicao_linha][0] = 0;

	fclose(ponteiro_arquivo);  // Fecha o ponteiro do arquivo
}


void leia_linha_csv(char* linha, int tamanho_valor, char valores[][tamanho_valor]) {
	/*
	Lê campos de uma linha CSV
	*/
	int posicao_valor = 0;
	int posicao_caractere = 0;
	size_t tamanho_linha = strlen(linha);

	for (int i = 0; i < tamanho_linha; i++) {
		// Encontra separador (vírgula)
		if (linha[i] == ',') {
			valores[posicao_valor][posicao_caractere] = '\0';  // Finaliza string
			posicao_valor++;  // Pula para o próximo valor
			posicao_caractere = 0;  // Reseta posição do caractere
			continue;  // Pula loop
		}

		// Insere caractere no valor (até no máximo o seu tamanho)
		if (posicao_caractere < tamanho_valor - 1) {
			valores[posicao_valor][posicao_caractere] = linha[i];
			posicao_caractere++;
		}

		// Está no último caractere da linha
		if (i == tamanho_linha - 1) {
			valores[posicao_valor][posicao_caractere] = '\0';
		}
	}
}


void escreve_arquivo(char* caminho, char* conteudo) {
	/*
	Escreve uma nova linha em um arquivo
	*/
	FILE* ponteiro_arquivo = fopen(caminho, "a");  // Abre arquivo, modo "a"ppend
	if (ponteiro_arquivo == NULL) {
		exibe_erro("Erro ao abrir arquivo.");
		return;
	}
	fprintf(ponteiro_arquivo, "%s\n", conteudo);  // Escreve conteúdo numa linha nova no arquivo
	fclose(ponteiro_arquivo);  // Fecha o ponteiro do arquivo
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
