#ifndef EXAME_H_INCLUDED
#define EXAME_H_INCLUDED

#define TIPO_APROVADO 1
#define TIPO_REPROVADO 2
#include "funcoesGenericas.h"
#include "veiculo.h"


typedef struct
{
  int codigo;
  char matricula[TAM_MATRICULA];
  int totalKms;
  tipoData dataInspecao;
  int resultado;
  char anotacoes[TEXTO_LONGO];
  float custo;
 

} tipoInspecao;

void listarVeiculosPesados(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

tipoInspecao *inserirNovaInspecao(tipoInspecao *vetorInspecoes, int *quantInspecoes, tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

void atualizarKms(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

void listarDadosInspecoes(tipoInspecao *vetorInspecoes, int quantInspecoes, tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

int procurarInspecao(tipoInspecao *vetorInspecoes, int quantInspecoes, char matricula[]);

void escreverFicheiroTextoInspecoes(tipoInspecao *vetorInspecoes, tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, int quantInspecoes);

void listarVeiculosPorMarca(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

void VeiculosInfiaveis(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int quantVeiculos, int quantInspecoes);

#endif // EXAME_H_INCLUDED
