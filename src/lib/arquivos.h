#ifndef ARQUIVOS_h
#define ARQUIVOS_h

void leia_arquivo(char* caminho, int tamanho_linha, char conteudo[][tamanho_linha]);

void leia_linha_csv(char* linha, int tamanho_valor, char valores[][tamanho_valor]);

void escreve_arquivo(char* caminho, char* conteudo);

void escreve_linha_csv(char* caminho, int quantidade, ...);

void substitui_texto(char* texto, char* remocao, char* insercao);

#endif
