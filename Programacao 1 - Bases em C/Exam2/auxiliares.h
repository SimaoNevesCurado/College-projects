#ifndef auxiliares_H_INCLUDED
#define auxiliares_H_INCLUDED

#include "auxiliares.h"
#include "funcoes.h"
#include "declaracoes.h"

#define MIN_ANO 2000
#define MAX_ANO 2024



typedef struct{
    int hora, minuto;
} tipoHorario;

tipoData lerData(char msg[]);
void escreverData(tipoData data);

tipoHorario lerHorario (void);
void escreverHorario(tipoHorario horario);

float lerFloat (char msg[], float limMin, float limMax);
int lerInteiro (char msg[], int limMin, int limMax);
void lerString (char msg[], char texto[], int tamMax);

void limparBuffer(void);
void converteMaiuscula(char texto[]);

#endif // FUNCOESGENERICAS_H_INCLUDED