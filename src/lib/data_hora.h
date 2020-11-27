#ifndef DATA_HORA_H
#define DATA_HORA_H

typedef struct datas {
	int ano;
	int mes;
	int dia;
} Data;

void obtem_data_atual(Data *hoje);

void string_para_data(char* data_string, Data *data);

#endif
