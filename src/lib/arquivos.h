#ifndef ARQUIVOS_h
#define ARQUIVOS_h

void escreve_arquivo(char* caminho, char* conteudo);

void escreve_linha_csv(char* caminho, int quantidade, ...);

void substitui_texto(char* texto, char* remocao, char* insercao);

#endif
