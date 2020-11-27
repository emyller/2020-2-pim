#include <time.h>
#include <stdio.h>
#include "./data_hora.h"


void obtem_data_atual(Data *hoje) {
	/*
	Obtém a data atual do sistema
	*/
	// Obtém o momento atual do sistema
	time_t agora_segundos;
	time(&agora_segundos);  // Segundos desde 1970-01-01T00:00:00

	// Converte segundos para formato de calendário
	struct tm *agora_calendario = localtime(&agora_segundos);

	// Converte formato de calendário para o nosso formato
	hoje->ano = agora_calendario->tm_year + 1900;
	hoje->mes = agora_calendario->tm_mon + 1;
	hoje->dia = agora_calendario->tm_mday;
}

void string_para_data(char* data_string, Data *data) {
	/*
	Lê uma data no formato de string e grava numa variável tipo data
	*/
	// Lê os números da data para variáveis numéricas
	int dia, mes, ano;
	sscanf(data_string, "%d-%d-%d", &dia, &mes, &ano);

	// Escreve os números nos atributos da data
	data->dia = dia;
	data->mes = mes;
	data->ano = ano;
}
