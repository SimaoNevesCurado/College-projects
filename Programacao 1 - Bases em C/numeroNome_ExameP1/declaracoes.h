#ifndef DECLARACOES_H_INCLUDED
#define DECLARACOES_H_INCLUDED

/** ------------------------ Constantes ----------------------- **/
#define MAX 150

#define TEXTO_LONGO 100
#define TEXTO_BREVE 20

#define ANO_MIN 2000
#define ANO_MAX 2500

#define CONTRIBUITE_MIN 111111111
#define CONTRIBUITE_MAX 999999999

#define TELEFONE_MIN 0
#define TELEFONE_MAX 999999999



/** ------------------------ Estruturas de dados ----------------------- **/

typedef struct
{
    int dia, mes, ano;
} tipoData;


typedef struct
{
    int horas, minutos;
} tipoHorario;


typedef struct
{
    int numContribuinte;
    char nome [TEXTO_BREVE];
    char morada [TEXTO_LONGO];
    int telefone;
} tipoCliente;

typedef struct

{

    int codigo;
    int numContribuinte;
    tipoData data;
    char descricao [TEXTO_LONGO];
    int custo;
    int grauSatisfacao;

}tipoAgendamento;





#endif // DECLARACOES_H_INCLUDED
