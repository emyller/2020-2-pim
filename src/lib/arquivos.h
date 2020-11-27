#ifndef ARQUIVOS_h
#define ARQUIVOS_h

// Nomes dos arquivos usados
#define AGENDAMENTO_CONSULTA_ARQUIVO "agendamento_consulta.txt"
#define CADASTRO_FUNCIONARIO_ARQUIVO "cadastro_funcionario.txt"
#define CADASTRO_MEDICO_ARQUIVO "cadastro_medico.txt"
#define CADASTRO_PACIENTE_ARQUIVO "cadastro_paciente.txt"
#define CANCELAMENTO_CONSULTA_ARQUIVO "cancelamento_consulta.txt"
#define ELOGIOS_RECLAMACOES_ARQUIVO "elogios_reclamacoes.txt"
#define LOGIN_ARQUIVO "login.txt"

int leia_arquivo(char* caminho, int tamanho_linha, char conteudo[][tamanho_linha]);

void leia_linha_csv(char* linha, int tamanho_valor, char valores[][tamanho_valor]);

void escreve_arquivo(char* caminho, char* conteudo);

void escreve_linha_csv(char* caminho, int quantidade, ...);

void substitui_texto(char* texto, char* remocao, char* insercao);

#endif
