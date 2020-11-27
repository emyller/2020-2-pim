#ifndef DATA_HORA_H
#define DATA_HORA_H

typedef struct datas {
	int ano;
	int mes;
	int dia;
} Data;

void obtem_data_atual(Data *hoje);

#endif
