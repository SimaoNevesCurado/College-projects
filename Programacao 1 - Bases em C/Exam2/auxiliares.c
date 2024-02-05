#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliares.h"
#include "funcoes.h"
#include "declaracoes.h"

void converteMaiuscula(char texto[])
{
    int i, tam;
    tam=strlen(texto);

    for (i=0; i < tam; i++)
    {
        texto[i] = toupper(texto[i]);
    }
}

tipoData lerData (char msg[])
{
    tipoData data;
    int diaMax;


    printf("\n %s", msg);
    data.ano = lerInteiro("\nAno: ", MIN_ANO, MAX_ANO);
    data.mes = lerInteiro("Mes: ", 1, 12);

    switch (data.mes)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            diaMax = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diaMax = 30;
            break;
        case 2:
            if (data.ano % 400 == 0 || (data.ano % 4 == 0 && data.ano % 100 != 0))
            {

                diaMax = 29;
            }
            else
            {
                diaMax = 28;
            }
    }

    data.dia = lerInteiro("Dia: ", 1, diaMax);

    return data;
}

void escreverData(tipoData data)
{
    printf("%02d-%02d-%d", data.dia, data.mes, data.ano);
}


tipoHorario lerHorario (void)
{
    tipoHorario horario;

    horario.hora = lerInteiro("\nHora: ", 0, 23);
    horario.minuto = lerInteiro("Minuto: ", 0, 59);

    return horario;
}

void escreverHorario(tipoHorario horario)
{
    printf("%02d-%02d", horario.hora, horario.minuto);
}

float lerFloat (char msg[], float limMin, float limMax)
{
    float num;
    int controlo;

    do
    {
        printf("%s[%.2f, %.2f]: ", msg, limMin, limMax);
        controlo = scanf("%f", &num);
        limparBuffer();

        if (num < limMin || num > limMax || controlo == 0)
        {
            printf("\nERRO: o valor nao pertence ao intervalo [%.2f, %.2f]", limMin, limMax);
        }
    }
    while (num < limMin || num > limMax || controlo == 0);
    return num;
}


int lerInteiro (char msg[], int limMin, int limMax)
{
    int num, controlo;

    do
    {
        printf("%s[%d, %d]:", msg, limMin, limMax);
        controlo = scanf("%d", &num);
        limparBuffer();

        if (num < limMin || num > limMax || controlo == 0)
        {
            printf("\nERRO: o valor nao pertence ao intervalo [%d, %d]", limMin, limMax);
        }
    }
    while (num < limMin || num > limMax || controlo == 0);
    return num;
}

void lerString (char msg[], char texto[], int tamMax)
{
    int tamString;

    do
    {
        printf("%s", msg);
        fgets(texto, tamMax, stdin);

        if (texto[0] == '\n' || texto[0] == ' ')
        {
            printf("\nERRO: insira um valor valido");
        }
    }
    while (texto[0] == '\n' || texto[0] == ' ');

    tamString = strlen(texto);

    if (texto[tamString-1] != '\n')
    {
        limparBuffer();
    }
    else
    {
        texto[tamString-1] = '\0';
    }
}


void limparBuffer(void)
{
    char letra;

    do
    {
        letra = getchar();
    }
    while (letra != '\n' && letra != EOF);
}