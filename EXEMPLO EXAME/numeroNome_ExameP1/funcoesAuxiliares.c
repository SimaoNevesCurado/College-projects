#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "declaracoes.h"
#include "funcoesAuxiliares.h"


// ----------------------- FUNÇÕES AUXILIARES -----------------------------------------

tipoHorario lerHorario (void)
{
    tipoHorario horario;

    horario.horas = lerInteiro("\nHora: ", 0, 23);
    horario.minutos = lerInteiro("Minutos: ", 0, 59);

    return horario;
}


tipoData lerData (void)
{
    tipoData data;
    int diaMax;

    data.ano = lerInteiro("\nAno: ", ANO_MIN, ANO_MAX);
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


void lerString(char msg[TEXTO_LONGO], char str[TEXTO_LONGO], int tamanho)
{
    int tamTexto;

    do
    {
        printf("%s", msg);
        fgets(str, tamanho, stdin);

        tamTexto = strlen(str);

        if (tamTexto <= 1)
        {
            printf("\n\nERRO: tem de inserir um valor.\n");
        }
        else
        {
            if (str[tamTexto-1] == '\n')
            {
                str[tamTexto-1] = '\0';
            }
            else
            {
                limparBuffer();
            }
        }
    }
    while (tamTexto <= 1);
}


int lerInteiro (char msg[TEXTO_LONGO], int limMin, int limMax)
{
    int num, res;


    do
    {
        printf("%s", msg);
        res = scanf("%d", &num);
        limparBuffer();

        if (res != 1)
        {
            printf("\n\nERRO: o valor inserido tem que ser um numero inteiro.\n");
        }
        else
        {
            if (num < limMin || num > limMax)
            {
                printf("\n\nERRO: o numero tem de pertencer ao intervalo [%d, %d].\n", limMin, limMax);
            }
        }

    }
    while (num < limMin || num > limMax || res != 1);

    return num;
}


float lerFloat (char msg[TEXTO_LONGO], float limMin, float limMax)
{
    float num;
    int res;


    do
    {
        printf("%s", msg);
        res = scanf("%f", &num);
        limparBuffer();

        if (res != 1)
        {
            printf("\n\nERRO: o valor inserido tem que ser um numero inteiro.\n");
        }
        else
        {
            if (num < limMin || num > limMax)
            {
                printf("\n\nERRO: o numero tem de pertencer ao intervalo [%.2f, %.2f].\n", limMin, limMax);
            }
        }

    }
    while (num < limMin || num > limMax || res != 1);

    return num;
}


void limparBuffer (void)
{
    char lixo;

    do
    {
        lixo = getchar();

    }
    while (lixo != '\n' && lixo != EOF);
}


