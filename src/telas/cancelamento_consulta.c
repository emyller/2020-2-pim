#include <stdio.h>
#include <stdlib.h>
#include "../lib/arquivos.h"
#include "../lib/entrada.h"

#define CANCELAMENTO_CONSULTA_ARQUIVO "cancelamento_consulta.txt"


int cancelamento_consulta() {

    char nome_paciente[100] = ""; //nome do paciente
    char data[10] = ""; //data da consulta
    char hora[6] = ""; //horário da consulta
    int opcao;


    puts("Cancelamento de Consulta\n\n");

        //para fazer o cancelamento de uma consulta o usuario precisa inserir o nome do paciente para encontrar seu cadastro
    leia_string("Nome do paciente ", nome_paciente); 
    
    leia_digito("O paciente gostaria de remarcar a consulta?\n(1)Sim\n(2)Não\n\n", &opcao);//o usuário pergunta ao paciente se ele deseja remarcar a consulta
    
        //caso o paciente queira remarcar, é feito novamente um processo de agendamento
    if (opcao == 1) { 
        leia_string("Qual a data da consulta? ", data);

        leia_string("Horário da consulta: ", hora);

        puts("Consulta agendada com sucesso!");
    }
    
    else if (opcao == 2) { //caso o paciente não queira remarcar, sua consulta é apenas cancelada
        puts("Consulta cancelada");
    }
    else {
        return 1;
    }

		// Insere resultados no arquivo CSV
		escreve_linha_csv(
			CANCELAMENTO_CONSULTA_ARQUIVO, 3,
			nome_paciente, data, hora
		);

return 0;

}
