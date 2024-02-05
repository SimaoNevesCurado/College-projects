#ifndef funcoes_H_INCLUDED
#define funcoes_H_INCLUDED

#include "auxiliares.h"
#include "funcoes.h"
#include "declaracoes.h"

int procurarFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios, int numero);
void listarDadosFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios);
int inserirNovoFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios);
void listarUmFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios);
void escreverFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS],int posicao);
float mediaVencimentos(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios);
void vencimentoSuperior(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios);
int AdmissaoNovembro(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS],int quantFuncionarios);

#endif