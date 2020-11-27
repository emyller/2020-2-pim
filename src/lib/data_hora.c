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
