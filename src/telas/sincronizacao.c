#include <stdio.h>
#include "../lib/arquivos.h"
#include "../lib/data_hora.h"
#include "../lib/entrada.h"
#include "../lib/utils.h"


void sincroniza_arquivos() {
	const size_t NUMERO_ARQUIVOS = 7;
	const char ARQUIVOS[][100] = {
		AGENDAMENTO_CONSULTA_ARQUIVO,
		CADASTRO_FUNCIONARIO_ARQUIVO,
		CADASTRO_MEDICO_ARQUIVO,
		CADASTRO_PACIENTE_ARQUIVO,
		CANCELAMENTO_CONSULTA_ARQUIVO,
		ELOGIOS_RECLAMACOES_ARQUIVO,
		LOGIN_ARQUIVO
	};
	exibe_titulo("Sincronização");

	// Lê endereço IP de destino
	char endereco_ip[100];
	leia_resposta_formato("Endereço IP", "x.x.x.x", endereco_ip);

	// TODO: Implementar sincronização via FTP
	Data hoje;
	obtem_data_atual(&hoje);
	printf("Conectando em ftp://%s:21...\n", endereco_ip);
	for (int i = 0; i < NUMERO_ARQUIVOS; i++) {
		printf(
			"Enviando arquivo %d/%d: ~/unidade01/%04d/%02d/%02d/%s\n",
			i + 1, NUMERO_ARQUIVOS, hoje.ano, hoje.mes, hoje.dia, ARQUIVOS[i]
		);
	}

	// Exibe resultado
	exibe_erro("Erro na sincronização.");
}
