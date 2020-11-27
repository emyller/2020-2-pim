#include <stdio.h>
#include "./cores.h"


void exibe_titulo(char* titulo) {
	/*
	Padroniza e exibe um título na tela
	*/
	printf(COR_AZUL "\n\n*** %s ***\n" COR_NORMAL, titulo);
}


void exibe_sucesso(char* mensagem) {
	/*
	Exibe mensagem de sucesso
	*/
	printf(COR_VERDE "\n%s\n" COR_NORMAL, mensagem);
	printf("(Pressione <Enter> para continuar)");
	getchar();
}


void exibe_erro(char* mensagem) {
	/*
	Exibe mensagem de erro
	*/
	printf(COR_VERMELHO "\n%s\n" COR_NORMAL, mensagem);
	printf("(Pressione <Enter> para continuar)");
	getchar();
}
